#include "kopiec.cpp"

class Heap {
    Kopiec iHTab[];

    Heap();
    ~Heap();

    int checkLeft(int i);
    int checkRight(int i);
    int checkParent(int i);
    unsigned int getSize();
    bool isEmpty();

    void pushElement();
    void popElement();

    void HeapifyDown();
    void HeapifyUp(int i);

    void displayAll();
};