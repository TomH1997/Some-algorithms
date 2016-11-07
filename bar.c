#include <stdio.h>

int max(int a, int b);

int main()
{
	int i,j=0;
	char c;
	int count[26]={0};
	while((c=getchar())!=EOF)
		count[c-'a']++;
	char res[26][50];
	for(i=0;i<26;i++)
	{
		for(j=0;j<50;j++)
			res[i][j] = ' ';
	}
	
	for(i=0;i<26;i++)
	{
		for(j=0;j<count[i];j++)
			res[i][j] = '*';
	}
	int maxnum=count[0];
	for(i=1;i<26;i++)
		maxnum = max(maxnum,count[i]);
	for(j=maxnum-1;j>=0;j--)
	{
		for(i=0;i<26;i++)
			printf("%c",res[i][j]);
		printf("\n");
	}
	printf("abcdefghijklmnopqrstuvwxyz");
	return 0;
}

int max(int a, int b)
{
	return a>b?a:b;
}

