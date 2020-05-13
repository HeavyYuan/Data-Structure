#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

int numPairsDivisibleBy60(int *array, int len);

int numPairsDivisibleBy60(int *array, int len)
{
   int i,j,count;
   count=0;
   for(i = 0; i < len-1; i++)
   {
   		for(j = i+1; j < len; j++)
		{
			if((array[i] + array[j])%60 == 0 ){
				count++;
			}
				
		}
   		
   }
   printf("%d\n", count);
   
}

int main()
{
	int array[5] = {30,20,150,100,40};
	numPairsDivisibleBy60(array, 5);

	exit(0);
}
