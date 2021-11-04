
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define AGE 50
#define WIDTH AGE*2 + 1

void idup(int *head, int *next)
{
    int i;
    for(i = 0; i < WIDTH; i++){
        head[i] = next[i];
    }
}


void pp(int head[])
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

void generation(int *head, int *next, int *RULES)
{
	int i;
	int idx;
	int x;
	int y;
	int z;

	for(i = 1; i < WIDTH-1; i++)
	{
		x = 4*head[i-1];
		y = 2*head[i];
		z = head[i+1];
		idx = z +x+y;
		//printf("%d \n",head[i+1] );
		next[i] = RULES[7-idx];
		continue;
	}
}

int main()
{
	int RULES[] =  {1,0,1,1,0,1,1,0};
	
	int head[WIDTH]; 
	int i;

	for(i = 0; i < WIDTH; i++){
		head[i] = 0;
	}
	pp(head);	
	head[((WIDTH)/2)] = 1;

	int next[WIDTH];
	idup(next, head);	
	for(i = 0; i < AGE; i++)
	{
		pp(head);
		generation(head, next, RULES);
        	idup(head, next);
	}


	return 0;
}


