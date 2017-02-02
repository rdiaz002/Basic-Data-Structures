/*Ronuel Diaz
 Data Structures
 12/4/16
 */

#include "linked_list_stack.h"
#include <iostream>

/* 
 * File:   linked_list_stack.cpp
 * Author: Ronny
 * 
 * Created on December 5, 2016, 3:59 PM
 */

template<typename T>
bool linked_list_stack<T>::is_empty() const {
    if (top_ == NULL ){
        return true;
    }
    return false; 
}

template<typename T>
T linked_list_stack<T>::pop() {
    if(is_empty()){
        std::cout<<"the stack is empty"<<std::endl;
        return -1;
    }
    stack * buff= new stack();
    buff=top_;
    top_=top_->next;
    return buff->data;
}

template<typename T>
void linked_list_stack<T>::push(const T& data) {
    stack * buff = new stack();
    buff->data=data;
    if (is_empty()){
        top_=buff;
    }else{
        buff->next=top_;
        top_=buff;
    }
}

template<typename T>
T linked_list_stack<T>::top()  {
    if(is_empty()){
        std::cout<<"The stack is empty"<<std::endl;
        return -1;
        
    }
    return top_->data;
}


