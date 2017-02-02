//RONUEL DIAZ
//DATA STRUCTURE
//ASSIGNMENT 6
//12/23/16

#include "hashtable.h"
#include <iostream>

template<typename T>
void hashtable<T>::insert(int key, int value) {
    int index = hash(key);
    node * buff = new node(key, value);
    if (bucket_size[index].size >= 9 && bucket_size[index].converted != true) {
        bucket_size[index].converted = true;
        converter(index, table[index], table[index]->link);
    }
    switch (bucket_size[index].converted) {

        case true:
            converter(index, table[index], buff);
            bucket_size[index].size++;
            break;
        case false:
            if (num_elements_bucket(index) == 0) {
                table[index] = buff;
                bucket_size[index].size++;
            } else {
                node * tail = traverse(index);
                tail->link = buff;
                bucket_size[index].size++;
            }
            break;
    }
    buff = NULL;
    delete buff;
    if ((float) num_buckets() / capacity >= 0.70) {
        larger_table();
    }
}

template<typename T>
int hashtable<T>::hash(int key) {
    int index = (int) key % capacity;
    return index;
}

template<typename T>
bool hashtable<T>::is_empty() {
    if (num_buckets() == 0) {
        return true;
    }
    return false;
}

template<typename T>
int hashtable<T>::num_buckets() const {
    int count = 0;
    for (int i = 0; i < capacity; i++) {
        if (bucket_size[i].size != 0) {
            count++;
        }
    }
    return count;
}

template<typename T>
size_t hashtable<T>::num_elements_bucket(size_t index) const {

    return bucket_size[index].size;

}

template<typename T>
T hashtable<T>::at(int key) {
    size_t index = hash(key);
    node *root = find(key, table[index]);
    switch (bucket_size[index].converted) {
        case true:
            if (root == NULL) {
                std::cout << "key not found" << std::endl;
                return 0;
            } else if (root->key > key) {
                return root->left->value;
            } else if (root->key < key) {
                return root->right->value;
            } else {
                return root->value;
            }
        case false:
            if (root == NULL) {
                std::cout << "key not found" << std::endl;
                return 0;
            } else if (root->key == key) {
                return root->value;
            } else if (root->link->key == key) {
                return root->link->value;
            }
    }
}

template<typename T>
void hashtable<T>::converter(size_t index, node * root, node* next) {
    if (next != NULL) {
        if (root == NULL) {
            insert(next->key, next->value);
        } else if (next->key >= root->key && root->right == NULL) {
            root->right = next;
            next = next->link;
            converter(index, table[index], next);
        } else if (next->key >= root->key && root->right != NULL) {
            root = root->right;
            converter(index, root, next);
        } else if (next->key < root->key && root->left == NULL) {
            root->left = next;
            next = next->link;
            converter(index, table[index], next);
        } else if (next->key < root->key && root->left != NULL) {
            root = root->left;
            converter(index, root, next);
        }


    }
}

template<typename T>
void hashtable<T>::erase(int key) {
    int index = hash(key);
    node* root = find(key, table[index]);
    switch (bucket_size[index].converted) {
        case false:
            if (root == NULL) {
                std::cout << "key not found" << std::endl;
            } else if (root->key == key) {
                node* buff = root;
                table[index] = buff->link;
                --bucket_size[index].size;
                delete buff;
            } else if (root->link != NULL && root != NULL) {
                node * buff = root->link;
                root->link = buff->link;
                delete buff;
                bucket_size[index].size--;
            } else {
                delete root;
                bucket_size[index].size--;
            }
            break;
        case true:
            if (key > root->key) {
                node * buff = root->right;
                root->right = NULL;
                tree_insert(buff, key);
                bucket_size[index].size--;
            } else if (key < root->key) {
                node*buff = root->left;
                root->left = NULL;
                tree_insert(buff, key);
                bucket_size[index].size--;
            } else if (key == root->key) {
                if (root == table[index]) {
                    std::swap(table[index]->key, table[index]->right->key);
                    std::swap(table[index]->value, table[index]->right->value);
                    tree_insert(root->right, root->right->key);
                    root->right = NULL;
                    bucket_size[index].size--;
                } else {
                    node*buff = root;
                    table[index] = NULL;
                    tree_insert(buff, key);
                    bucket_size[index].size--;
                }
            }
            break;
    }
}

template<typename T>
typename hashtable<T>::node* hashtable<T>::traverse(size_t index) {
    node* root = new node();
    root = table[index];
    while (root->link != NULL) {

        root = root->link;
    }
    return root;

}

template<typename T>
typename hashtable<T>::node* hashtable<T>::find(int key, node * root) {
    size_t index = hash(key);
    switch (bucket_size[index].converted) {

        case false:
            if (bucket_size[index].size == 0 || root == NULL) {
                return NULL;
            }
            if (root->key == key) {
                return root;
            }
            while (root->link != NULL && root->link->key != key) {
                root = root->link;
            }
            if (root->link != NULL && root->link->key == key) {
                return root;
            } else return NULL;
            break;
        case true:
            if ((root->right != NULL && key == root->right->key) || (root->left != NULL && key == root->left->key)) {
                return root;
            } else if (root->key == key) {
                return root;
            } else if (key > root->key) {
                find(key, root->right);
            } else if (key < root->key) {
                find(key, root->left);
            } else {
                return NULL;
            }
            break;
    }

}

template<typename T>
void hashtable<T>::tree_insert(node* root, int key) {
    int index = hash(root->key);
    if (root->right != NULL) {
        tree_insert(root->right, key);
        root->right = NULL;

    } else if (root->left != NULL) {
        tree_insert(root->left, key);
        root->left = NULL;
    }
    if (root->key != key) {
        tree_removal(root);
    }

}

template<typename T>
void hashtable<T>::new_table_insert(node *root, bool converted) {
    switch (converted) {
        case true:

            if (root->right != NULL) {
                new_table_insert(root->right, converted);
            } else if (root->left != NULL) {
                new_table_insert(root->left, converted);
            }
            insert(root->key, root->value);
            break;
        case false:
            while (root != NULL && root->link != NULL) {
                root = root->link;
            }
            if (root != NULL) {
                insert(root->key, root->value);
            }
            break;

    }
}

template<typename T>
void hashtable<T>::larger_table() {
    int oldcap = capacity;
    capacity = capacity * 2;
    node **old_table = table;
    table = new node * [capacity];
    bucket_sizes* old = new bucket_sizes[oldcap];
    for (int i = 0; i < oldcap; i++) {
        old[i].size = NULL;
        old[i].size = bucket_size[i].size;
        old[i].converted = bucket_size[i].converted;
    }

    delete bucket_size;
    bucket_size = new bucket_sizes[capacity];
    for (int i = 0; i < capacity; i++) {
        table[i] = NULL;
    }
    for (int j = 0; j < oldcap; j++) {
        new_table_insert(old_table[j], old[j].converted);

    }
}

template<typename T>
void hashtable<T>::tree_removal(node * root) {
    int index = hash(root->key);
    node * buff = new node(root->key, root->value);
    converter(index, table[index], buff);
    delete root;
    delete buff;
}

template<typename T>
hashtable<T>::~hashtable() {
    
    delete [] table;
    delete [] bucket_size;


}
