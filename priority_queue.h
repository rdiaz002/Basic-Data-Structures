//RONUEL DIAZ
//Data Structures
//12/18/16
//ASSIGNMENT 7

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <stdlib.h>
#include <vector>
static int key_id; // each process holds a special key that allows for easy identification when changing priority

template<typename T>
class priority_queue {
public:

    class process {
    public:
        T process_time;
        T priority;
        int key; //AUTO GENERATED ID FOR EACH PROCESS

        //PRECONDITION:time and priority must be positive.
        //POSTCONDITION: Creates a process

        process(T time, T priority = 0, int key = key_id++) {
            this->process_time = time;
            this->priority = priority;
            this->key = key;
        };
        //DEFAULT CONSTRUCTOR

        process() {
            this->process_time = 0;
            this->priority = 0;
            this->key = 0;
        };
        //DEFAULT DECONSTRUCTOR

        ~process() {

        }
    };

    //CONSTRUCTOR
    //PRECONDITION:N/A
    //POSTCONDITION: creates a priority queue (MAX HEAP)
    priority_queue();

    //PRECONDITION: N/A
    //POSTCONDITION: checks to see if the priority queue is empty
    bool empty();

    //PRECONDITION:N/A
    //POSTCONDITION: returns the priority of top element
    T top();

    //PRECONDITION: parameter must be a process pointer. 
    //POSTCONDITION: pushes the process into the priority queue
    void push(const process*);

    //PRECONDITION:N/A
    //POSTCONDITION: Pops the top element from the priority queue
    void pop();

    //PRECONDITION: N/A
    //POSTCONDITION: Returns the number of elements in the priority queue
    size_t size();

    //PRECONDITION: first parameter must be process pointer and second parameter must be save data type as priority queue
    //POSTCONDITION:Will change the priority of the given process
    void change_Priority(process * &, T);

    //PRECONDITION:N/A
    //POSTCONDITION: Prints out the priority queue(max heap) in an array format. 
    void print();

    //Deconstructor
    ~priority_queue();

private:
    //POSTCONDITION: swaps the information within the two processes
    void swap(process &, process &);
    //POSTCONDITION: Makes sure that the array is in max heap format at all times. 
    bool heapify(size_t index);

    process* data; //HEAP ARRAY
    int used; // NUMBER OF ELEMENTS USED
};

#include "priority_queue.cpp"
#endif /* PRIORITY_QUEUE_H */

