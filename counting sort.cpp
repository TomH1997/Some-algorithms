#include <iostream>
#include <algorithm>

const int length = 10;
const int max = 10;
int counts[max+1] = {0};
int result[length];

void printArray(int* array);
void readArray(int* array);
int * countingSort(int*array, int length, int max);

int main()
{
	int array[length];
	std::cout<<"Enter "<<length<<" intergers.\n";
	readArray(array);
	std::cout<<"After sorting:\n";
	printArray(countingSort(array,length, max));
	return 0;
}

int * countingSort(int* array,int length, int max)
{

	for(int i=0; i<length; i++)
		counts[array[i]]++;
	for(int j=1; j<=max+1;j++)
		counts[j] += counts[j-1];
	for(int k=length-1;k>=0;k--)
	{
		result[counts[array[k]]-1] = array[k];
		counts[array[k]]--;
	}
	return result;
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
