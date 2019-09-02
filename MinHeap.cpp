/*
This solution contains the MinHeap implmentation with the following operations:
- getMin() : Get minimum element from the heap.
- insertElement() : Insert element in the heap and heapify to position it properly.
- deleteMin() : Delete the minimum element (root) from the heap.
- printHeapList() : Display the heap (in the form of list).
*/

#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
	vector<int> heapList;
public:
	MinHeap()
	{
		heapList.push_back(NULL);
	}

	int getMin()
	{
		if (heapList.size() == 1)
			return NULL;
		return heapList[1];
	}

	void swap(int pos1, int pos2)
	{
		int temp;
		temp = heapList[pos1];
		heapList[pos1] = heapList[pos2];
		heapList[pos2] = temp;
	}

	void insertElement(int newEle)
	{
		heapList.push_back(newEle);

		if (newEle > heapList[heapList.size() / 2])
			return;

		int temp, pos = heapList.size() - 1;
		while (pos!=1 && heapList[pos]< heapList[pos/2])
		{
			swap(pos, pos/2);
			pos = pos / 2;
		}
	}

	void deleteMin()
	{
		if (heapList.size() <= 1)
		{
			cout << "\nCannot delete! Heap is empty.";
			return;
		}

		cout << "\nDeleting " << heapList[1] << endl;
		heapList[1] = heapList[heapList.size() - 1];
		heapList.pop_back();

		int pos = 1;
		while (pos * 2 <= heapList.size() - 1)
		{
			if (pos * 2 + 1 <= heapList.size() - 1 && heapList[pos * 2] > heapList[pos * 2 + 1])
			{
				if (heapList[pos * 2 + 1] > heapList[pos])
					return;
				swap(pos, pos * 2 + 1);
				pos = pos * 2 + 1;
			}
			else
			{
				if (heapList[pos * 2] > heapList[pos])
					return;
				swap(pos, pos * 2);
				pos = pos * 2;
			}
		}
	}

	void printHeapList()
	{
		cout << "\nHeapList: ";
		for (int i = 1; i < heapList.size(); i++)
			cout<<heapList[i]<<" ";
		cout << endl;
	}
};

int main()
{
	MinHeap heap;
	heap.insertElement(10);
	heap.insertElement(15);
	heap.insertElement(13);
	heap.insertElement(25);
	heap.insertElement(18);
	heap.insertElement(4);
	heap.insertElement(7);
	heap.insertElement(-1);
	heap.insertElement(17);
	cout << "\nMinHeap:" << heap.getMin();

	heap.printHeapList();

	heap.deleteMin();
	heap.deleteMin();
	heap.printHeapList();
}
