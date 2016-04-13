/* buffer implementation */
#include <stdio.h>
#include <string.h>

//constants and static variables
#define SIZE 5
int pushIndex, popIndex;
int num = 1;
int buffer[SIZE];

//function prototypes
void push();
void pop();
int next();

int next()
{
	if (pushIndex < SIZE-1) return pushIndex+1;
	else return 0;
}

void printState()
{
	printf("Buffer state: [%d, %d, %d, %d, %d]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
}

void push()
{
	buffer[pushIndex] = num;
	num++;

	//decide to increment the popIndex or not
	if(pushIndex == popIndex && buffer[next()] != '\0')
	{
		popIndex++;
	}

	//always increment push index
	pushIndex++;

	//reset indices if necessary
	if(pushIndex == SIZE) pushIndex = 0;
	if(popIndex == SIZE) popIndex = 0;
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

		printState();

}



}
