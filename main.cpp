#include "minHeap.cpp"
#include <vector>
#include <iostream>

int main()
{
	vector<int> input;
	for(int i = 1; i < 11; i++)
	{
		input.push_back(i);
	}
	
	vector<int> heapTest;
	for (int i=9; i>0; i--) swap(input[i], input[rand()%i]);
	minHeap h(input);
	for (int i=0; i<10; i++) heapTest.push_back(h.removeMin());
	cout << "output: ";
	for(int i = 0; i < 10; i++)
	{
		cout << heapTest[i] << " ";
	}
}