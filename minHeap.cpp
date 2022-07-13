#include "minHeap.h"
#include <iostream>

//Given a position, sifts the element up to a node so that no heap rules are broken
void minHeap::siftUp(int pos)
{
	int nodeAbove = 0;
	if(pos == 0) return;
	if(pos % 2 == 1) nodeAbove = pos / 2;
	else nodeAbove = pos / 2 - 1;
	if(pos == 1 || pos == 2) nodeAbove = 0;
	if(heap[nodeAbove] > heap[pos])
	{
		swap(heap[pos], heap[nodeAbove]);
		siftUp(nodeAbove);
	}
}

//Given a position, sifts the element down to a node so that no heap rules are broken
void minHeap::siftDown(int pos)
{
	int leftNodeBelow = pos * 2 + 1;
	if(pos == 0) leftNodeBelow = 1;
	int rightNodeBelow = pos * 2 + 2;
	if(pos == 0) rightNodeBelow = 2;
	if(rightNodeBelow < heap.size())
	{
		int rightValue = heap[rightNodeBelow];
		int leftValue = heap[leftNodeBelow];
		if(heap[pos] > rightValue && rightValue < leftValue)
		{
			swap(heap[pos], heap[rightNodeBelow]);
			siftDown(rightNodeBelow);
		}
		else if(heap[pos] > leftValue && leftValue < rightValue)
		{
			swap(heap[pos], heap[leftNodeBelow]);
			siftDown(leftNodeBelow);
		}
	}
	else if(leftNodeBelow < heap.size() && heap[leftNodeBelow] < heap[pos])
	{
		swap(heap[pos], heap[leftNodeBelow]);
		siftDown(leftNodeBelow);
	}
}

//Constructor that puts an int vector into a heap vector
minHeap::minHeap(vector<int> data)
{
	for(int i = 0; i < data.size(); i++)
	{
		heap.push_back(data[i]);
		siftUp(heap.size() - 1);
	}
}

//Inserts a value into the heap
void minHeap::insert(int value)
{
	heap.push_back(value);
	siftUp(heap.size() - 1);
}

//Removes the minimum value of a heap (aka the head node)
int minHeap::removeMin()
{
	int returnInt = heap[0];
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	siftDown(0);
	return returnInt;
}