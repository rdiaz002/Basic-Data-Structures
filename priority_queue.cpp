//RONUEL DIAZ
//Data Structures
//12/18/16
//ASSIGNMENT 7

#include <math.h>
#include <iostream>
#include <algorithm>

template<typename T>
priority_queue<T>::priority_queue() {
    data = new process;
    used = 0;
    key_id = 1;
}

template<typename T>
bool priority_queue<T>::empty() {
    if (used == 0) {
        return true;
    }
    return false;
}

template<typename T>
void priority_queue<T>::pop() {
    swap(data[0], data[used - 1]);
    for (int i = 0; i < used; i++) {
        data[i].priority = data[i].priority + data[used - 1].process_time;
    }
    data[used - 1].key = 0;
    data[used - 1].priority = 0;
    data[used - 1].process_time = 0;
    used--;
    heapify(0);
}

template<typename T>
void priority_queue<T>::push(const process * pro) { 
    data[used].key = pro->key;
    data[used].priority = pro->priority;
    data[used].process_time = pro->process_time;
    data[(used * 2) + 1] = process(0, 0, 0); // extra null values in the heap are like the null leaves in a tree
    data[(used * 2) + 2] = process(0, 0, 0);
    used++;
    heapify(used - 1);
}

template<typename T>
void priority_queue<T>::swap(process & one, process & two) {
    std::swap(one, two);
}

template<typename T>
T priority_queue<T>::top() {
    return data[0].priority;
}

template<typename T>
size_t priority_queue<T>::size() {
    return used;

}

template<typename T>
bool priority_queue<T>::heapify(size_t index) { // recursive function to order the max heap
    if (index == 0) {

    } else if (data[index].priority > data[((int) floor((index - 1) / 2))].priority) { // this is to bring the max process to the top. 
        swap(data[index], data[((int) floor((index - 1) / 2))]);
        heapify(floor((index - 1) / 2));
    }
    //this portion is to order the HEAP if the top most object is not top priority. it checks the children of the parent to determine highest priority. 
    if (data[(index * 2) + 1].priority > data[(index * 2) + 2].priority && data[index].priority < data[(index * 2) + 1].priority) {
        swap(data[(index * 2) + 1], data[index]);
        heapify((index * 2) + 1);
    } else if (data[(index * 2) + 1].priority < data[(index * 2) + 2].priority && data[index].priority < data[(index * 2) + 2].priority) {
        swap(data[(index * 2) + 2], data[index]);
        heapify((index * 2) + 2);
    }
    return true;
}

template<typename T>
//Running time of this function would be O(n log n) because it first has to search the array to identify the correct process
//which is O(n) amount of time then it will heapify the array to make it into a max heap which will require O(log n) time. 
void priority_queue<T>::change_Priority(process * & proc, T change) {
    for (int i = 0; i < used; i++) {
        if (data[i].key == proc->key) {
            if (data[i].priority + change < 0) {
                std::cout << "no negative priorities allowed" << std::endl;
                break;
            }
            data[i].priority = data[i].priority + change;
            std::cout << "priority changed" << std::endl;
            heapify(i);
        }
        if (i == used) {
            std::cout << "process not found" << std::endl;
        }
    }


}

template<typename T>
priority_queue<T>::~priority_queue() {
    delete[] data;

}

template<typename T>
void priority_queue<T>::print() {
    for (int i = 0; i < used; i++) {
        std::cout << data[i].priority << " ";
    }
    std::cout << std::endl<<std::endl;
}