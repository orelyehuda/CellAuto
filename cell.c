
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void idup(int *head, int *next, const int WIDTH)
{
    int i;
    for(i = 0; i < WIDTH; i++){
        head[i] = next[i];
    }
}


void pp(int head[], const int WIDTH)
{
	int i;
    	for(i = 0; i < WIDTH; i++){
		if(head[i])
		{
			printf("#");
		}
		else
		{
			printf(" ");
		}
	
		//printf("%d  ", head[i]);
	}
	printf("\n");
}

void generation(int *head, int *next, const int *RULES, const int WIDTH)
{
	int i;
	int idx;
	int x,y,z;

	for(i = 1; i < WIDTH-1; i++)
	{
		x = 4*head[i-1];
		y = 2*head[i];
		z = head[i+1];
		idx = z + x + y;
		//printf("%d \n",head[i+1] );
		next[i] = RULES[7-idx];
		continue;
	}
}

int main(int argc, char *argv[])
{
	size_t age;
	if(argc == 2)
	{
		char *a = argv[1];
		age = atoi(a); 
	}
	else
	{
		age = 50;
	}
	const int WIDTH = 2*age +1;
	const int RULES[] =  {1,0,1,1,0,1,1,1};
	
	int head[WIDTH]; 
	int i;

	for(i = 0; i < WIDTH; i++){
		head[i] = 0;
	}

	head[((WIDTH)/2)] = 1;

	int next[WIDTH];
	idup(next, head, WIDTH);	
	for(i = 0; i < age; i++)
	{
		pp(head, WIDTH);
		generation(head, next, RULES, WIDTH);
        	idup(head, next, WIDTH);
	}

	return 0;
}


