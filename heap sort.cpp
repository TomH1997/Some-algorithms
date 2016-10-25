#include<iostream>
#include<algorithm>

const int length = 10;
int heapsize = length;
void printArray(int* array);
void readArray(int* array);
void heapSort(int* array);
void biuldMaxHeap(int* array);
void maxHeapify(int*array, int n);


int main()
{
	int array[length];
	std::cout<<"Enter "<<length<<" intergers.\n";
	
	readArray(array);
	heapSort(array);
	
	std::cout<<"After sorting:\n";
	printArray(array);
	
	return 0;
}

void biuldMaxHeap(int* array)
{
	for(int i = length/2; i>=0; i--)
		maxHeapify(array, i);
}

void maxHeapify(int*array, int index)
{
	int largest = index;
	if(index*2<=heapsize-1&&array[index*2]>array[index])
		largest = index*2;
	if(index*2+1<=heapsize-1&&array[index*2+1]>array[largest])
		largest = index*2+1;
	if (largest != index)
	{
		std::swap(array[index], array[largest]);
		maxHeapify(array, largest);
	}

}

void heapSort(int* array)
{
	biuldMaxHeap(array);
	for(int i = length-1; i>0; i--)
		{
			std::swap(array[0], array[i]);
			heapsize--;
			maxHeapify(array, 0);
		}
}

void printArray(int* array)
{
	for(int i = 0; i<length; i++)
		std::cout<<array[i]<<" ";
}

void readArray(int* array)
{
	for(int i = 0; i<length; i++)
		std::cin>>array[i];
}


