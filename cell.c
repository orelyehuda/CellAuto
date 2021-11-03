
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define AGE 70
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

	for(i = 1; i < WIDTH-1; i++)
	{
		if(head[i-1] && head[i] && head[i+1])
		{
			next[i] = RULES[0];
		}

		else if(head[i-1] && head[i] && !head[i+1])
		{
			next[i] = RULES[1];
		}

		else if(head[i-1] && !head[i] && head[i+1])
		{
			next[i] = RULES[2];
		}
		else if(head[i-1] && !head[i] && !head[i+1])
		{
			next[i] = RULES[3];
		}
		else if(!head[i-1] && head[i] && head[i+1])
		{
			next[i] = RULES[4];
		}
		else if(!head[i-1] && head[i] && !head[i+1])
		{
			next[i] = RULES[5];
		}
		else if(!head[i-1] && !head[i] && head[i+1])
		{
			next[i] = RULES[6];
		}
		else if(!head[i-1] && !head[i] && !head[i+1])
		{
			next[i] = RULES[7];
		}

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
	
	head[((WIDTH)/2)] = 1;

	int next[WIDTH];
	next[0] = 0;
	next[WIDTH-1] = 0;
	
	for(i = 0; i < AGE; i++)
	{
		pp(head);
		generation(head, next, RULES);
        	idup(head, next);
	}


	return 0;
}


