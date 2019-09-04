// This implementation of max heap contains the following:
//	- insert element into the heap
//	- delete max of the heap
//	- print heap
//	- heapsort : in-place implementation using recursion
//	- heapsort : in-place implementation using iteration

#include<iostream>
#include<vector>
using namespace std;

class MaxHeap
{
	vector<int> heapList;
public:
	MaxHeap()
	{
		heapList.push_back(0);
	}

	void insertElement(int ele)
	{
		int pos, temp;

		heapList.push_back(ele);

		pos = heapList.size() - 1;
		while (pos / 2 >= 1 && heapList[pos / 2] < heapList[pos])
		{
			temp = heapList[pos / 2];
			heapList[pos / 2] = heapList[pos];
			heapList[pos] = temp;
			pos = pos / 2;
		}
	}

	void deleteMax()
	{
		if (heapList.size() < 2)
		{
			cout <<"\nHeap is empty!";
			return;
		}

		cout<<"\nElement being deleted:"<<heapList[1]<<endl;

		heapList[1] = heapList[heapList.size() - 1];
		heapList.pop_back();

		int temp, pos = 1;
		while (pos * 2 < heapList.size() - 1)
		{
			if (pos * 2 + 1 < heapList.size() - 1 && heapList[pos * 2] < heapList[pos * 2 + 1])
			{
				if (heapList[pos] > heapList[pos * 2 + 1])
					break;

				temp = heapList[pos * 2 + 1];
				heapList[pos * 2 + 1] = heapList[pos];
				heapList[pos] = temp;
				pos = pos * 2 + 1;
			}
			else
			{
				if (heapList[pos] > heapList[pos * 2])
					break;

				temp = heapList[pos * 2];
				heapList[pos * 2] = heapList[pos];
				heapList[pos] = temp;
				pos = pos * 2;
			}
		}	
	}

	void heapSort()
	{
		// In-place implementation of heap sort
		if (heapList.size() <= 2)
			return;

		int temp, pos, endIndex = heapList.size() - 1;
		while (endIndex >= 2)
		{
			temp = heapList[endIndex];
			heapList[endIndex] = heapList[1];
			heapList[1] = temp;

			--endIndex;

			pos = 1;
			while (pos * 2 <= endIndex)
			{
				if (pos * 2 + 1 <= endIndex && heapList[pos * 2] < heapList[pos * 2 + 1])
				{
					if (heapList[pos] > heapList[pos * 2 + 1])
						break;

					temp = heapList[pos * 2 + 1];
					heapList[pos * 2 + 1] = heapList[pos];
					heapList[pos] = temp;
					pos = pos * 2 + 1;
				}
				else
				{
					if (heapList[pos] > heapList[pos * 2])
						break;

					temp = heapList[pos * 2];
					heapList[pos * 2] = heapList[pos];
					heapList[pos] = temp;
					pos = pos * 2;
				}
			}
		}

		cout << "\nHeap has been sorted using iterative heapsort.";
	}

	void recursive_HeapSort()
	{
		// Recursive, In-place implementation of heap sort
		if (heapList.size() <= 2)
			return;

		int temp, pos, endIndex = heapList.size() - 1;
		while (endIndex >= 2)
		{
			temp = heapList[endIndex];
			heapList[endIndex] = heapList[1];
			heapList[1] = temp;

			--endIndex;

			pos = 1;

			heapify(pos, endIndex);
		}
		cout << "\nHeap has been sorted using recursive heapsort.";
	}

	void heapify(int pos, int endIndex)
	{
		// Base-condition
		if (pos * 2 > endIndex)
			return ;
		
		int temp;
		if (pos * 2 + 1 <= endIndex && heapList[pos * 2] < heapList[pos * 2 + 1])
		{
			if (heapList[pos] > heapList[pos * 2 + 1])
				return ;

			temp = heapList[pos * 2 + 1];
			heapList[pos * 2 + 1] = heapList[pos];
			heapList[pos] = temp;
			pos = pos * 2 + 1;
		}
		else
		{
			if (heapList[pos] > heapList[pos * 2])
				return ;

			temp = heapList[pos * 2];
			heapList[pos * 2] = heapList[pos];
			heapList[pos] = temp;
			pos = pos * 2;
		}

		heapify(pos, endIndex);
	}

	void printHeap()
	{
		cout << "\n\nHeapList:";
		for (int i = 1; i < heapList.size(); i++)
			cout << heapList[i] << " ";
	}
};

int main()
{
	MaxHeap heap1;
	heap1.insertElement(12);
	heap1.insertElement(11);
	heap1.insertElement(10);
	heap1.insertElement(9);
	heap1.insertElement(5);
	heap1.insertElement(7);
	heap1.insertElement(8);
	heap1.insertElement(4);
	heap1.insertElement(2);
	heap1.insertElement(1);
	heap1.insertElement(3);
	heap1.printHeap();
	
	heap1.insertElement(15);
	heap1.deleteMax();
	heap1.printHeap();

	// heap1.heapSort();
	
	heap1.recursive_HeapSort();
	heap1.printHeap();
}
