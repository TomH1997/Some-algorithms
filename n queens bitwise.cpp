#include <iostream>

const int max = 10;	//the length of the answer array
int columns;	// the length and width of the chess board
int result;	  // the answer of a particular column length
void nQueens(int row, int ld, int rd);

int main()
{
	int answer[max] = {0};
	for(int i = 1; i<max; i++)	// fill the output array with answers
	{
		columns = i;
		result = 0;
		nQueens(0,0,0);
		answer[i-1] = result;	
	}
	
	for(int j=0; j<max;j++)
		std::cout<<answer[j]<<" ";
	
	return 0;
}

void nQueens(int row, int ld, int rd)
{
	int pos, p;
	int full = (1<<columns)-1;	//every digit is 1, which indicates it's been occupied
	if(row != full)	// test if there's space to put another queen
	{
		pos = full&~(row|ld|rd);	// pos represents places available to put a queen
		while(pos)				// while a queen can be put
		{
			p = pos&(~pos+1);	//p is the very right '1' of pos
			pos -= p;	// take p away from pos since now place p is occupied
			nQueens(row+p,(ld+p)<<1,(rd+p)>>1);	// proceed to the next row
		}
	}
	else result++;
}
