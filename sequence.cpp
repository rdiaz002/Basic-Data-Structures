// Ronuel Diaz
//10/14/16
//Data Structures 

#include "sequence.h"
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <math.h>

sequence::sequence(const unsigned int& capacity) { //creates a sequence object with specified size
    this->capacity = capacity;
    data = new int_t [this->capacity];
    used = 0;

}

sequence::sequence(const sequence &copied) { // Copy constructor creates copy
    used = copied.used;
    capacity = copied.capacity;
    data = new int_t[copied.capacity];
    std::copy(copied.data, copied.data + used, data);

}

sequence::sequence() { // creates a sequence object with standard size 
    capacity = default_capacity;
    data = new int_t [this->capacity];
    used = 0;

}

void sequence::erase_first(int_t numb) {// erases the first occurrence of a value
    erase_occurrence(1, numb);
}

void sequence::erase_last(int_t numb) {// erases last occurrence of a value
    int_t occurence = count(numb);
    erase_occurrence(occurence, numb);
}

void sequence::erase_occurrence(unsigned int occurrence, int_t numb) {// erases a user defined occurrence of a value
    int_t check_count = count(numb);
    if (occurrence <= check_count && occurrence != 0) {// makes sure the occurrence isnt zero and also not greater than the available number of occurrences
        int_t counter = 0;
        for (int_t i = 0; i < used; i++) {
            if (data[i] == numb) {
                counter++;
                if (counter == occurrence) {
                    data[i] = 0;
                    shifter();
                    break;
                }
            }
        }

    } else {
        std::cout << "value does not occur " << occurrence << "times in this sequence" << std::endl;
    }
}

void sequence::erase_from(int_t idx) {// erases value from a certain index
    if (idx < used) {
        data[idx] = 0;
        shifter();
    } else {
        std::cout << "Index is out of range" << std::endl;
    }
}

void sequence::insert(int_t numb) {// inserts a value into the sequence
    insert_at(used, numb);
}

void sequence::insert_first(int_t numb) {// inserts a value at the beginning of the sequence 
    insert_at(0, numb);
}

void sequence::insert_at(int_t idx, int_t numb) {// inserts a value at a user defined index
    if (idx <= used || idx == 0) {
        int_t *temp = new int_t [used + 1];

        std::copy(data, data + idx, temp);

        temp[idx] = numb;

        std::copy(data + idx, data + used, temp + idx + 1);

        ++used;

        std::copy(temp, temp + used, data);
        size_checker();
    } else {
        std::cout << "index is out of range" << std::endl;
    }
}

int_t sequence::count(const int_t numb) const {// counts the number of occurrences of a value
    int_t counter = 0;
    for (size_t i = 0; i < used; i++) {
        if (data[i] == numb) {
            counter++;
        }
    }
    return counter;
}

int_t sequence::size() const {// returns the number of elements in the sequence
    return used;
}

sequence& sequence::operator+(const sequence &copied) { // adds two sequences together and creates a third sequence

    sequence *temp = new sequence(capacity + copied.capacity);
    std::copy(data, data + used, temp->data);
    temp->used += used;
    std::copy(copied.data, copied.data + copied.used, temp->data + temp->used);
    temp->used += copied.used;

    return *temp;
}

sequence& sequence::operator+(const int &value) {// creates a third sequence with the first sequence and the value
    sequence *temp = new sequence(capacity);
    std::copy(data, data + used, temp->data);
    temp->used += used;
    temp->insert(value);

    return *temp;
}

void sequence::operator+=(const sequence& seq2) {// inserts the second sequence into the first 
    size_checker();
    if (used + seq2.used <= capacity) {
        std::copy(seq2.data, seq2.data + seq2.used, data + used);
        used += seq2.used;
    } else {
        std::cout << "not enough space to add the sequence" << std::endl;
    }
}

void sequence::operator+=(const int &value) {// inserts the value into the sequence
    insert(value);
}

bool sequence::operator==(const sequence & copied)const {// compares two sequences 
    int counter = 0;
    if (used == copied.used) {
        for (int i = 0; i < used; i++) {
            if (data[i] == copied.data[i]) {
                counter++;
            }
        }
        if (counter == used) {
            return true;
        } else {
            return false;
        }
    } else {
        std::cout << "number of elements must be equal" << std::endl;
        return false;
    }

}

sequence & sequence::operator=(const sequence & copied) {// assignment constructor 
    used = copied.used;
    capacity = copied.capacity;
    delete[] data;
    data = new int_t[copied.capacity];
    std::copy(copied.data, copied.data + used, data);

}

void sequence::shifter() {
    int counter = count(0);

    if ((used != 0 && (counter / used) >= 0.5) || used == capacity) {
        std::remove(data, data + used, 0);
        used -= counter;
    }
}

void sequence::size_checker() {
    shifter();
    double seqsize = used / (double) capacity;
    if (seqsize <= 0.4) {
        shrink_data();
    } else if (seqsize >= 0.85) {
        resize_data();
    }
}

void sequence::resize_data() {
    int_t *temp = new int_t[2 * capacity];
    std::copy(data, data + used, temp);
    delete[] data;
    capacity = 2 * capacity;
    data = new int_t[capacity];
    std::copy(temp, temp + used, data);
}

void sequence::shrink_data() {
    int sm_size = floor(0.6 * capacity);
    int_t *temp = new int_t[sm_size];
    std::copy(data, data + used, temp);
    delete[] data;
    capacity = sm_size;
    data = new int_t[capacity];
    std::copy(temp, temp + used, data);
}

sequence::~sequence() {// deconstructor destroys all allocated data from dynamic memory.
    delete[]data;
}

