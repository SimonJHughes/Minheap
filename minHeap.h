#pragma once

#include <vector>

using namespace std;

//This class defines a heap where each node has a
//less or equal value than all child nodes (min-heap)
//Implemented using a vector of integers representing the
//values at each node of a complete binary tree

class minHeap
{
    private:
        vector<int> heap;
        void siftUp(int pos);
        void siftDown(int pos);
    public:
        minHeap() {} //Default constructor, heap is initiallay an empty vector
        vector<int> getHeap() {return heap;} //Returns heap data for test cases
        minHeap(vector<int> data); //Build the heap from bottom-up
        void insert(int value); //Insert value into heap
        int removeMin(); //Removes minimum value
};