#include <iostream>

using namespace std;

const int length = 10;

void printArray(int *array);
void readArray(int* array);
void sortingInc(int *array);
void sortingDec(int *array);

int main()
{
	cout<<"Enter "<<length<<" intergers.\n";
	int array[length];
	readArray(array);
	sortingInc(array); 
	cout<<"Increasing:\n";
	printArray(array);
	cout<<"Decreasing:\n";
	sortingDec(array); 
	printArray(array);
	return 0;
	
}


void sortingInc(int *array)
{
	int key, i, j;
	for(j=1; j<length; j++)
	{
		key = array[j];
		i = j - 1;
		while(i>=0&&array[i]>key)
		{
			array[i+1] = array[i];
			i = i - 1;
		}
		array[i+1] = key;
	}
}

void sortingDec(int *array)
{
	int key, i, j;
	for(j = 1; j<length; j++)
	{
		key = array[j];
		i = j-1;
		while(i>=0&&array[i]<key)
		{
			array[i+1] = array[i];
			i = i - 1;
		}
		array[i+1] = key;
	}
}

void readArray(int* array)
{
	for(int i = 0; i<length; i++)
		std::cin>>array[i];
}

void printArray(int *array)
{
	for (int i=0; i<length; i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

