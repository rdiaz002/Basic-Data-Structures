/*Ronuel Diaz
 Data Structures
 12/4/16
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>
#include<iostream>

template<typename T>
class linked_list {

    struct node {
        T data;
        node* link = NULL;
    };
public:
    //CONSTRUCTORS
    //PRECONDITION: Value was be valid 
    //POSTCONDITION: Creates a linked list that is made of nodes

    linked_list(const T value) {
        node * temp = new node();
        temp->data = value;
        HEAD = temp;
        TAIL = temp;
        placeholder = HEAD;
        num_nodes++;
    };
    //DEFUALT CONSTRUCTOR

    linked_list() {

    };
    //MEMBER FUNCTIONS
    //PRECONDITION:value must be the same type as the linked list
    //POSTCONDITION: inserts the value given as the tail node. 
    void insert_Tail(const T value);

    //PRECONDITION:N/A
    //POSTCONDITION: Removes the tail of the linked list
    void remove_Tail();

    //PRECONDITION:value must be the same type as the linked list
    //POSTCONDITION: Inserts the value given as the head node
    void insert_Head(const T value);

    //PRECONDITION: N/A
    //POSTCONDITION: Removes the head node and replaces it with the next node. 
    void remove_Head();

    //PRECONDITION: index must be within range of number of elements and value must be same type as linked list
    //POSTCONDITION: Inserts a new node in the index given with the value given. 
    void insert_at(const int index, const T value, node * place = NULL);

    //PRECONDITION: Index must be within range of number of nodes
    //POSTCONDITION: Removes the node from the linked list at the given index. 
    void remove_from(const int index, node * place = NULL);
    //PRECONDITION: N/A
    //POSTCONDITION:Prints the linked list
    void print_List();
    //PRECONDITION:N/A
    //POSTCONDITION:Returns true if the list is empty
    bool is_empty()const;
    //DECONSTRUCTOR

    ~linked_list() {
        while(!is_empty()){
            remove_Head();
        }
    }

private:
    node* HEAD = NULL; //HEAD NODE
    node*TAIL = NULL; //TAIL NODE
    node* placeholder = NULL; //PLACEHOLDER FOR RECURSION
    size_t num_nodes = 0; //NUMBER OF NODES
    size_t count = 0; // COUNTER
};
#include "linked_list.cpp"
#endif /* LINKED_LIST_H */

