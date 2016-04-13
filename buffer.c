#include <stdio.h>
#include <string.h>

/* buffer implementation */

#define SIZE 5
int pushIndex, popIndex;
char buffer[5];
void push();
void pop();

void push()
{

}

void pop()
{

}

void main(){
	char input[SIZE];

	printf("Hello, World!\n");

	while(1)
	{
		int isPush, isPop;
		int last = SIZE-1;

		//get data from stdin
		printf("Please enter 'push' or 'pop'.\n");
		fgets(input, SIZE, stdin);
		printf("You said: %s \n", input);

		//process stdin
		if (input[last-1] == '\n')
		{
			//strip newline
			input[last-1] = '\0';
		}
		else if (input[last-1] == '\0')
		{
			//do nothing (short input)
		}
		else
		{
			//there is extra input on stdin we need to get rid of
			scanf ("%*[^\n]"); (void) getchar ();
		}

		//file checking
		isPush = strcmp(input, "push") == 0 ? 1 : 0;
		isPop = strcmp(input, "pop") == 0 ? 1 : 0;

		if ( !isPush && !isPop )
		{
			printf("Please enter a valid input\n");
			continue;
		}
		else if (isPush)
		{
			push();
		}
		else
		{
			pop();
		}

}



}
