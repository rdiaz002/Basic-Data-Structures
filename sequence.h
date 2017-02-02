//Ronuel Diaz 
//DATA STRUCTURES
//Sequence Class 

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <stdlib.h>
#include <iostream>
typedef int int_t; // Defined to change the type to allow bigger values.

class sequence {
public:
    sequence(const unsigned int&);
    //PRECONDITION: Sequence must have a size no larger than a unsigned integer.
    //POSTCONDITION: Sequence class objected is created. Allows for the storing of integer values.

    sequence(const sequence &);
    //PRECONDITION:Parameter must be a sequence class object
    //POSTCONDITION:Creates a copy of the sequence class that was passed 
    //as the parameter. 

    sequence();
    //POSTCONDITION:Creates an instance of a sequence object with default container size.

    void erase_first(int_t value);
    //PRECONDITION:Argument that is passed must be an integer value 
    //POSTCONDITION: Will erase the first instance of the value that was passed in the sequence container.

    void erase_last(int_t value);
    //PRECONDITION:Argument that is passed must be an integer value
    //POSTCONDITION:Will erase the last instance of the value that was passed in the sequence container.

    void erase_occurrence(unsigned int occurrence, int_t value);
    //PRECONDITION:Occurrence must be greater than 0 and value must be an integer
    //POSTCONDITION:Erases the specified occurrence of a value in the sequence.

    void erase_from(int_t index);
    //PRECONDITION: The argument must be an index value which is an integer that is greater or equal to zero.
    //POSTCONDITION:Erases what ever value is stored at the specified index and shifts the rest of the 
    //sequence container to eliminate any empty spaces.

    void insert(int_t value);
    //PRECONDITION:Value to be inserted must be an integer. 
    //POSTCONDITION:Inserts any integer value into the sequence container. 

    void insert_first(int_t value);
    //PRECONDITION:Argument value must be an integer.
    //POSTCONDITION:Inserts the value at the beginning of the sequence.

    void insert_at(int_t index, int_t value);
    //PRECONDITION:Index must not exceed the size of the sequence minus one. Value must be an integer
    //POSTCONDITION:Inserts the given value in the sequence at the given index. 

    int_t count(const int_t) const;
    //PRECONDITION:Argument value must be an integer.
    //POSTCONDITION:Counts how many occurrences of a value there are in the sequence. 

    int_t size() const;
    //PRECONDITION: N/A
    //POSTCONDITION: Returns the number of elements in the sequence container. 

    sequence& operator+(const sequence&);
    //PRECONDITION:Argument must be a sequence object 
    //POSTCONDITION:Adds two sequences and creates a third one from the result.

    sequence& operator+(const int& value);
    //PRECONDITION:Argument must be an integer
    //POSTCONDIITON: creates a new sequence that will contain the first sequence and the value. 

    void operator+=(const sequence&);
    //PRECONDITION:Argument must be a sequence object 
    //POSTCONDITION:Adds the second sequence to the first sequence. 

    void operator+=(const int& value);
    //PRECONDITION: Argument must be an integer
    //POSTCONDITION: Integer Value will be added into the sequence.

    bool operator==(const sequence&) const;
    //PRECONDITION:Argument must be a sequence object 
    //POSTCONDITION:Checks the sequences to see if they are equal. 

    sequence& operator=(const sequence&);
    //PRECONDITION:Argument must be a sequence object 
    //POSTCONDITION:Copies all fields and elements of a sequence object into a new or existing sequence object. 

    friend std::ostream& operator<<(std::ostream &os, const sequence &seq);

    friend std::istream& operator>>(std::istream &is, const sequence &seq);

    ~sequence();

private:
    void shifter();
    //precondition:N/A
    //postcondition:Will shift your sequence if 50% or more of the sequence is empty.
    void size_checker();
    //precondition:N/A
    //postcondition: Will Check the size of the array and add or subtract more capacity.
    void resize_data();
    //precondition:N/A
    //postcondition:will add more space into your sequence if more than 85% has been used and increases the capacity. 
    void shrink_data();
    //precondition:N/A
    //postcondition:Will subtract space from your sequence,if less than 40% is being ,used by decreasing your capacity.
    int_t *data; // Where all the values are stored
    int_t capacity; // How many values the sequence can hold
    int_t used; // how much space is used up in the sequence.
    static const size_t default_capacity = 20;
};

#endif /* SEQUENCE_H */

