#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int main(int ac, char **av)
{
	(void)ac;
	int n=atoi(av[1]),i;
	bool arr[10000]={0};
	time_t t;
	srand((unsigned)time(&t));
	for(i=0;i<n;++i)
	{
		int r=rand()%10000;
		if(!arr[r])
			printf("%d ",r);
		else
			i--;
		arr[r]=1;    
	}
}
