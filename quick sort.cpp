#include <iostream>
#include <algorithm>

const int length = 10;

void printArray(int* array);
void readArray(int* array);
void quickSort(int* array,int left, int right);
int partitionArray(int* array, int left, int right);

int main()
{
	int array[length];
	std::cout<<"Enter "<<length<<" intergers.\n";
	readArray(array);
	quickSort(array, 0, length-1);
	std::cout<<"After sorting:\n";
	printArray(array);
	return 0;
}

void quickSort(int* array,int left, int right)
{
	if(left<right)
	{
		int pivot = partitionArray(array, left, right);
		quickSort(array, left, pivot-1);
		quickSort(array, pivot+1, right);
	}

}

int partitionArray(int* array, int left, int right)
{
	int i = left - 1;
	int pivot = array[right];
	for(int j=left; j<right; j++)
	{
		if (array[j]<=pivot)
		{
			i++;
			std::swap(array[j],array[i]);
		}
	}
	std::swap(array[i+1], array[right]);
	return i+1;
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
