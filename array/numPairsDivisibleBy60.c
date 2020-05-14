#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

int numPairsDivisibleBy60(int *array, int len);

/*
* from leetcode,when the lenth of #array is large, the performance does not meet the requirement that the run time timeout
*/
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

/*
* The program can meet the performance requirement,and pass the leetcode test.
* when the lenth of #array is large(10000+),it takes 48ms to get the result.
* The fast implemention from leetcode can arrive 20ms, can we arrive that goal?
*/

int numPairsDivisibleBy60Advance(int *array, int len)
{
	int count[60]={0};
	int i,j;
	int pairs=0;
	for(i = 0; i < len; i++){
		array[i] %= 60;
		count[array[i]]++;
	}

	if(count[0] != 0)	
		pairs=count[0]*(count[0]-1)/2;
	
		
	for(j = 1; j <= 30; j++){

		if(j == 30 && count[30] != 0){
			pairs += count[30]*(count[30]-1)/2;
			continue;
		}

		if( count[j] != 0 && count[60-j] != 0)
			pairs += count[j] * count[60-j];

	}

	printf("%d\n",pairs);
}

int main()
{
	int array[ ] = {30,20,150,100,40,90,100,120,120};
	int len = sizeof(array)/sizeof(int);
	numPairsDivisibleBy60(array, len);
	numPairsDivisibleBy60Advance(array, len);

	exit(0);
}
