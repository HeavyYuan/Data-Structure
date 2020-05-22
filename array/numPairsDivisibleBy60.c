#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>

typedef struct Data{
    int len;
    int array[0];
}Data;

int numPairsDivisibleBy60(int *array, int len);
int numPairsDivisibleBy60Advance(int *array, int len);
int numPairsDivisibleBy60Optimise(int *array, int len);

#define MAX_MOD 500

Data *mem_alloc(int len)
{
    int true_size;
    Data *p = NULL;
    true_size = sizeof(struct Data) + len;
    p =  (Data *)malloc(true_size);
    if(!p)
        return(NULL);

    return(p);
}

int rand_num(unsigned int seed)
{
    time_t t;
    int num; 
    //srand((unsigned)array(&t));
    srand(seed);
    num = rand() % MAX_MOD; 
    return(num);

}

Data *dynamic_array(int len)
{
    int pos = 0;
    int seed = 100000;

    Data *data = mem_alloc(len);
    if(!data)
        return(NULL);

    data->len = len;
	while(pos < len){
		int num = rand_num(seed);
        data->array[pos] = num;
        pos++;
        seed++;
	}

    return(data);


    
}

/*
* from leetcode,when the lenth of #array is large, the performance does not meet the requirement that the run array arrayout
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

/*
 *from leetcode
 *
 * */
int numPairsDivisibleBy60Optimise(int *array, int len)
{
    int count = 0;
    int store[60] = {0};
    int i;
    for(i = 0;i < len;i++){
        array[i] %= 60;
        store[array[i]]++;
    }

    for(i = 0;i < len;i++){

        store[array[i]]--;

        if(array[i] == 0){
            count += store[array[i]];
        }
        else{
            count += store[60 - array[i]];
        }
    }
    printf("%d\n",count);
}


int main(int argc, char **argv)
{
	if(argc != 2){
		printf("usage: %s lenth_of_array\n",argv[0]);
		exit(1);
	}
	int len = atoi(argv[1]);
    Data *data = dynamic_array(len);
	numPairsDivisibleBy60(data->array, data->len);
	numPairsDivisibleBy60Advance(data->array, data->len);
	numPairsDivisibleBy60Optimise(data->array, data->len);
	exit(0);
}
