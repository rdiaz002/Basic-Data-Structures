//RONUEL DIAZ
//Data Structures
//12/18/16
//ASSIGNMENT 7

#include <cstdlib>
#include "priority_queue.h"
using namespace std;

/*
 * 
 */
int main() {
    priority_queue<int> que1;
    int i = 1;
    while (i <= 100) {
        priority_queue<int>::process* j = new priority_queue<int>::process(i, i);
        que1.push(j);
        i++;
    }
    que1.print();
    que1.pop();
    priority_queue<int>::process* k = new priority_queue<int>::process(100,234);
    que1.push(k);
    que1.print();
    que1.change_Priority(k,-235);
    que1.print();

    return 0;
}


