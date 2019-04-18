#ifndef ARRAY_H
#define ARRAY_H

#define MAX_ARR_SIZE  128

#include <string>
#include "Book.h"
using namespace std;


class Array 
{  
    public:
        Array();
        ~Array();
        void addBook(Book* book);
        void print();
    private:
        Book* elements[MAX_ARR_SIZE];
        int size;
};

#endif
