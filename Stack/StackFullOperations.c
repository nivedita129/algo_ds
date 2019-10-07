// Array implementation of stack
#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#define MAX 100

struct Stack
{
    int item[MAX];
    int top;
};

typedef struct Stack  stack;


void CreateEmptyStack(stack *st)
{
   st-> top = -1;
}

bool isEmpty(stack *st)
{
    if(st -> top == -1)
    {
        return true;
    }
    
    else
    {
        return false;
    }
    
}


bool isFull(stack *st)
{
    if(st-> top == MAX-1)
    {
        return true;
    }
    
    else
    {
        return false;
    }
    
}


void PUSH(stack *st, int data)
{
    if(isFull(st)) //checking the stack overflow
    {
        printf("\nThe stack is full.");
    }
    
    
    else
    {
        st-> top = st->top+1;
        st->item[st->top] = data;
    }
      
}

int POP(stack *st)
{
    int item;
    if(isEmpty(st))
    {
        printf("Stack is Empty.\n");
        return (0);
    }

    else{
        item = st->item[st-> top];
        st-> top = st->top -1;
        return(item);
    }
}


void display(stack *st)
{
    int i,n;
     
    if(isEmpty(st))
    {
        printf("Stack is Empty.\n");

    }
   
    
    else
    {
        for(i=0;i<= st->top;i++)
        {
            printf("%d\t",st->item[i]);
        }
        printf("\n\n");
    }
    
}


int main()
{
    int ch,data,x;
    stack *st;
    CreateEmptyStack(st);
   
    printf("\n ---- Menu For Program ----\n");
    printf("\n Enter 1. for Push Operation \n ");
    printf("\n Enter 2. for Pull Operation \n ");
    printf("\n Enter 3. to Display Data \n ");
    printf("\n Enter 4. for Exit \n ");
     printf("\n --------------------------\n");
    
    
    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        
        switch (ch)
        {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                PUSH(st,data);
                break;

            case 2:
                x= POP(st);
                printf("Popped data is : %d",x);
                break;
            
            case 3:
                display(st);

            default:
                exit(1);
        }

    }


    return 0;
}