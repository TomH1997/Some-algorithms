#include <iostream>
#include <algorithm>

using namespace std;
const int length = 10;
void printArray(int* array);
void bubbleSort(int* array);
void readArray(int* array);

int main()
{
	int array[length];
	std::cout<<"Enter "<<length<<" intergers.\n";
	readArray(array);
	std::cout<<"After sorting:\n";
	bubbleSort(array);
	printArray(array);
	return 0;
	
}

void bubbleSort(int array[length])
{
	int i, j;
	for(j=0; j<length-1; j++)
	{
		for(i=0; i<length-1-j; i++)
		{
			if(array[i]>array[i+1])
				swap(array[i],array[i+1]);
		}
	}
}

void printArray(int array[length])
{
	for (int i=0; i<length; i++)
		cout<<array[i]<<" ";
	cout<<endl;
}
void readArray(int* array)
{
	for(int i = 0; i<length; i++)
		cin>>array[i];
}
