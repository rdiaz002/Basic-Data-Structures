/*Ronuel Diaz
 Data Structures
 12/4/16
 */
#include "linked_list.h"

template<typename T>
void linked_list<T>::insert_Tail(const T value) {
    node * temp = new node();
    temp->data = value;
    if (num_nodes = 0) {
        HEAD = temp;
        TAIL = temp;
    } else {
        node * buff = TAIL;
        buff->link = temp;
        TAIL = temp;
    }
    num_nodes++;
}

template<typename T>
void linked_list <T>::insert_Head(const T value) {
    node *temp = new node();
    temp->data = value;

    if (num_nodes == 0) {
        HEAD = temp;
        TAIL = temp;
    } else {
        node * buff = HEAD;
        temp->link = HEAD;
        HEAD = temp;
    }
    placeholder = HEAD;
    num_nodes++;
}

template<typename T>
void linked_list <T>::insert_at(const int index, const T value, node* place) {
    if (index > num_nodes) {
        std::cout << "Index exceeds number of nodes" << std::endl;
    } else {
        if (index == 0) {
            insert_Head(value);

        } else if (index == 1 && num_nodes == 1) {
            insert_Tail(value);
        } else {
            if (count != index - 1) {
                count++;
                insert_at(index, value, placeholder = placeholder->link);
            } else {
                node *temp = new node();
                temp->data = value;
                temp->link = place->link;
                place->link = temp;
                num_nodes++;
                count = 0;
                placeholder = HEAD;
            }
        }
    }
}

template<typename T>
void linked_list <T>::remove_Head() {
    node *buff = new node();
    buff = HEAD;
    if (num_nodes == 1) {
        HEAD = TAIL = NULL;
        delete buff;
        num_nodes--;
    } else {
        HEAD = buff->link;
        delete buff;
        num_nodes--;
    }
}

template<typename T>
void linked_list <T>::remove_Tail() {
    node *buff = new node();
    node *curr = HEAD;
    if (num_nodes == 1) {
        HEAD = TAIL = NULL;
        delete curr;
    } else {
        while (curr->link->link != NULL) {
            curr = curr->link;
        }
        buff = TAIL;
        TAIL = curr;
        curr->link = NULL;
        delete buff;
    }
    num_nodes--;
}

template<typename T>
void linked_list <T>::remove_from(const int index, node * place) {
    if (index >= num_nodes) {
        std::cout << "Index exceeds number of nodes" << std::endl;
    } else {
        if (index == 0) {
            remove_Head();

        } else if (index == num_nodes - 1) {
            remove_Tail();
        } else {
            if (count != index - 1) {
                count++;
                remove_from(index, placeholder = placeholder->link);
            } else {
                node * buff = place->link;
                place->link = place->link->link;
                buff->link = NULL;
                delete buff;
                num_nodes--;
                count = 0;
                placeholder = HEAD;
            }
        }
    }
}

template<typename T>
void linked_list<T>::print_List() {
    if (placeholder->link != NULL) {
        std::cout << placeholder->data << " ";
        placeholder = placeholder->link;
        print_List();
    }
    placeholder = HEAD;
}

template<typename T>
bool linked_list<T>::is_empty()const {
    if (num_nodes == 0) {
        return true;
    }
    return false;
}




