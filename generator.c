#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int main(int ac, char **av)
{
	int u;

	u = 1;
	(void)ac;
	int n=atoi(av[1]),i;
	bool arr[10]={0};
	time_t t;
	srand((unsigned)time(&t));
	for(i=0;i<n;++i)
	{
		u++;
		int r=rand()%10;
		if(!arr[r])
		{
				printf("%d ",r );
		}
		else
			i--;
		arr[r]=1;    
	}
}
