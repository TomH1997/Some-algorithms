#include <iostream>
#include <algorithm>

const int length = 10;
int target;

void printArray(int* array);
void readArray(int* array);
int selection(int* array,int left, int right, int target);
int partitionArray(int* array, int left, int right);

int main()
{
	int array[length];
	std::cout<<"Enter "<<length<<" distinct intergers.\n";
	readArray(array);
	std::cout<<"Enter your target.\n";
	std::cin>>target;
	std::cout<<"The number "<<target<<" largest number in the array is "<<selection(array, 0, length-1, target);
	return 0;
}

int selection(int* array,int left, int right, int target)
{
	if (left == right)
		return array[left];
	int pivot = partitionArray(array, left, right);
	printArray(array);
	int count = pivot - left +1;
	if(count==target)
		return array[pivot];
	else if (count<target)
		return selection(array, pivot+1, right, target - count);
	else return selection(array, left, pivot-1, target);
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
	std::cout<<std::endl;
}

void readArray(int* array)
{
	for(int i = 0; i<length; i++)
		std::cin>>array[i];
}
