#ifndef __HEAP_H
#define __HEAP_H

#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10;

class Heap {
    private:
        PrintJob* arr[MAX_HEAP_SIZE]; // array of PrintJob pointers
        int numItems; // total number of items in array
        void trickleDown(int value);
        void trickleUp(int value);
        int searchIndex(int value) const;
    public:
        Heap();
        ~Heap();
        Heap(const Heap& cpy) {}; // copy constructor
        void enqueue(PrintJob* p);
        void dequeue();
        PrintJob* highest() const;
        void print() const;
        
};

#endif