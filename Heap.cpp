#include "Heap.h"
/* Heap Default Constructor */
// sets size of array to 0
Heap::Heap() { numItems = 0; }
/* Heap Destructor */
// sets arr as null
Heap::~Heap() { 
    arr[MAX_HEAP_SIZE] = nullptr;
}
/* Print function */
// if arr has at least one element, prints the arr element with highest priority (root)
void Heap::print() const {
    if (numItems > 0) {
        cout << "Priority: " << arr[0]->getPriority()
             << ", Job Number: " << arr[0]->getJobNumber() 
             << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
}
/* Highest function */
// if arr has at least one item it returns the element with highest priority (root)
// otherwise returns null
PrintJob* Heap::highest() const {
    if (numItems > 0) { return arr[0]; }
    return nullptr;
}
/* Enqueue function */
// if arr has space, adds a new PrintJob p to the end of arr
// then uses the private function trickleUp to restore max heap properties
void Heap::enqueue(PrintJob* p) {
    if (numItems < MAX_HEAP_SIZE) {
        numItems++;
        arr[numItems - 1] = p;
        if (numItems != 1) { trickleUp(p->getPriority()); }
    }
}
/* Dequeue function */
// if arr has at least 1 item it swaps the element with highest priority (root) with the last element
// then decreases the total numItems by 1, removing the old root from array
// finally uses private function trickleDown on the new root to restore max heap properties
void Heap::dequeue() {
    if (numItems > 0) {
        swap(arr[0], arr[numItems - 1]);
        numItems--;
        trickleDown(arr[0]->getPriority());
    }
}
/* SearchIndex private function */
// is used in trickleUp and trickleDown functions to help search for indices
int Heap::searchIndex(int value) const {
    for (int i = 0; i < numItems; i++) {
        if (arr[i]->getPriority() == value) { return i; }
    }
    return -1;
}
/* TrickleUp private function */
// is used in enqueue function to restore max heap properties
// finds the index of the node with the priority value in parameter
// if the node's priority is greater than its parent's priority, swap and repeat process with parent
// loop terminates once the root is reached and max-heap properties are restored
void Heap::trickleUp(int value) {
    int nodeIndex = searchIndex(value);
    while (nodeIndex > 0) {
        int parentIndex = (nodeIndex - 1) / 2;
        if (arr[nodeIndex]->getPriority() <= arr[parentIndex]->getPriority()) { return; }
        else {
            swap(arr[nodeIndex], arr[parentIndex]);
            nodeIndex = parentIndex;
        }
    }
}
/* TrickleDown private function */
// is used in dequeue function to restore max heap properties
// finds the node with maximum priority (root) and swaps with the last element in arr
// then deletes the last element of the array (old root)
// if the new root's priority is less than its children's priority, swap new root with the largest child & repeat
// loop terminates once end of array is reached and max-heap properties are restored
void Heap::trickleDown(int value) {
    int nodeIndex = searchIndex(value);
    if (nodeIndex != -1 && nodeIndex < numItems) {
        int childIndex = 2 * nodeIndex + 1;
        int n = arr[nodeIndex]->getPriority();
        while (childIndex < numItems) {
            int maxValue = n;
            int maxIndex = -1;
            for (int i = 0; i < 2 && i + childIndex < numItems; i++) {
                if (arr[i+childIndex]->getPriority() > maxValue) {
                    maxValue = arr[i + childIndex]->getPriority();
                    maxIndex = i + childIndex;
                }
            }
            if (maxValue == value) { return; }
            else {
                swap(arr[nodeIndex], arr[maxIndex]);
                nodeIndex = maxIndex;
                childIndex = 2 * nodeIndex + 1;
            }
        }
    }
}