//RONUEL DIAZ
//DATA STRUCTURE
//ASSIGNMENT 6
//12/23/16


#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<stdlib.h>

template<typename T>
class hashtable {
public:
    //STRUCT CLASSES

    struct node {
        T value;
        size_t key = 0;
        node * link = NULL; // THIS IS FOR THE LINKED LIST PHASE 
        node * left = NULL; // THIS IS FOR THE BINARY SEARCH TREE PHASE 
        node * right = NULL;

        node(size_t key = 0, T value = 0) {
            this->key = key;
            this->value = value;
        }

        ~node() {
            
        }
    };

    struct bucket_sizes {
        int size;
        bool converted = false;
    };
    //CONSTRUCTOR
    //PRECONDTION:SIZE MUST BE VALID AND NON NEGATIVE
    //POSTCONDITION: CREATES A HASH TABLE OF GIVEN SIZE 

    hashtable(size_t size = default_size) {
        capacity = size;
        table = new node*[capacity];
        bucket_size = new bucket_sizes[capacity];
        for (int i = 0; i < size; i++) {
            table[i] = NULL;
            bucket_size[i].size = NULL;
        }

    };
    //MEMBER FUNCTIONS

    //PRECONDITION:KEY MUST BE VALID AND UNIQUE
    //POSTCONDITION: INSERTS KEY AND VALUE INTO HASH TABLE
    void insert(int key, int value);

    //PRECONDITION: KEY MUST BE ALREADY IN THE HASH TABLE 
    //POSTCONDITION: ERASES THE GIVEN KEY FROM THE HASHTABLE
    void erase(int key);

    //PRECONDITION: N/A
    //POSTCONDITION: RETURNS WHETHER THE TABLE IS EMPTY OR NOT 
    bool is_empty();

    //PRECONDITION: KEY MUST ALREADY EXIST IN TABLE 
    //POSTCONDITION: RETURNS THE VALUE THAT IS ASSOCIATED WITH THAT KEY
    T at(int key);

    //PRECONDITION: N/A 
    //POSTCONDITION: RETURNS HOW MANY BUCKETS CONTAIN KEYS WITHIN THE HASH TABLES
    int num_buckets()const;

    //PRECONDITION: INDEX MUST BE POSITIVE
    //POSTCONDITION: RETURNS HOW MANY ELEMENTS IN THE BUCKET 
    size_t num_elements_bucket(size_t index) const;


    //DECONSTRUCTOR 
    ~hashtable();

private:
    //MEMBER FUNCTIONS
    //FINDS THE GIVEN KEY AND RETURNS THE NODE ASSOCIATED WITH IT
    node* find(int key, node* root = NULL);
    
    //TRANSVERSES THE LINKED LIST UNTIL THE LAST NODE
    node* traverse(size_t index);
    
    //CHANGES THE HASHTABLE AND EXPANDS IT TO ACCOMODATE SIZE 
    void larger_table();
    
    //INCHARGE OF REMOVAL FOR THE BINARY SEARCH TREE
    void tree_removal(node * root);
    
    //INCHARGE OF ASSIGNING VALUES TO NEW LARGER HASH TABLE 
    void new_table_insert(node * root, bool converted);
    
    //CONVERTS THE LINKED LIST INTO A BINARY SEARCH TREE 
    void converter(size_t index, node* root, node * next);
    
    //INSERTS ELEMENTS INTO THE BINARY SEARCH TREE
    void tree_insert(node * root, int key);
    
    //HASH FUNCTION 
    int hash(int key);

    node ** table; //HASH TABLE
    bucket_sizes * bucket_size; // ARRAY IN CHARGE OF BUCKET SIZES
    size_t capacity; // CAPACITY OF THE HASH TABLE 
    const static size_t default_size = 20; // DEFAULT SIZE OF THE HASH TABLE 

};
#include "hashtable.cpp"
#endif /* HASHTABLE_H */

