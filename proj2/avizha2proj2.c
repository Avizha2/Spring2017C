#include <stdio.h>
#include <string.h>

typedef struct Stack
    {
        char *p;//pointer to the dynamic array that holds the stack
        int arraySize;//specifies the current size of the dynamic array
        int topOfStack;//specifies the top of stack;
    
    }Stack;

void pushStack()//Places an object on the top of the stack
{
    
}

void popStack()//removes an object from the top of the stack 
{
    
}

void isStackEmpty()//Checks if stack is empty
{
    
}

void growStack()// copys stack array to new larger array
{
    
}

char *createStack()//pretty self explanitory
{
    
}

void stackTop()//acessing the top element on the stack
{
    
}

void resetStack()//resets the stack to empty to be used again
{
    
}

void readInput()
{
    
}

int main(int argC, char** argV)
{
    int debug = 0;//set debug to false       1= true    0=false
   /* printf("%d \n",argC);    test printfs to check console input
    printf("%s \n", argV[1]);*/ 
    if(argC == 2) // 2 counts in console so check for debug mode
    {
        if(strcmp(argV[1],"-d") == 0)
        {
             debug = 1; //debug set to true
              
        }
        
    }
    printf("%d\n", debug);
    
    
    return 0;    
}