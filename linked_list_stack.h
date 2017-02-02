/*Ronuel Diaz
 Data Structures
 12/4/16
 */

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H
#include <stdlib.h>

template<typename T>
class linked_list_stack {

    struct stack {
        T data;
        stack * next = NULL;
    };
public:
    //Constructors
    //PRECONDITION: N/A
    //POSTCONDITION: Creates a linked list that uses a stack.

    linked_list_stack(const T& data) {
        stack * beg = new stack();
        beg->data = data;
        top_ = beg;
    };

    linked_list_stack() {
        top_ = NULL;
    }
    
    // Member Functions 
    //PRECONDITION: MUST BE A VALUE IN THE PARAMETERS
    //POSTCONDITION: PUSHES THE VALUE GIVEN TO THE TOP OF THE STACK AND PUSHES EVERYTHING ELSE IN THE STACK DOWN.
    void push(const T& data);
    
    //PRECONDITION: N/A
    //POSTCONDITION:Removes what is on the top of the stack and returns the value. 
    T pop();
    
    //PRECONDITION:N/A
    //POSTCONDITiON: Returns whether the stack is empty or not.  
    bool is_empty() const;
    
    //PRECONDITION:N/A
    //POSTCONDITION:Returns what is the top value in the stack. 
    T top()  ;
    
    // Deconstructor

    ~linked_list_stack() { //Destructors can not be called recursively within them selves. Each destructor is called at the end of the life of the object. 
        while(!is_empty()){
            pop();
        }
    };
private:
    stack * top_ = NULL; // Keeps track of whats on top of the stack. 

};
#include "linked_list_stack.cpp"
#endif /* LINKED_LIST_STACK_H */

