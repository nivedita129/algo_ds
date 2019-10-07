  // Lab Work 6
	/*program to evaluate postfix expression*/
	#include<stdio.h>
    #include<stdlib.h>
	#include<string.h>
	#include<ctype.h>
	#include <math.h>
	#define MAX 100
	
    
    int push( struct vstack *s, int val);
    int pop(struct vstack *s);
   	
	
    struct vstack      // stack for operandss
	{
           char operands[100];
           int top;
    };
      
                        
	int main()
	{
        struct vstack s;
        int result,op1,op2, value;
		int i, l;
		char postfix[MAX],ch;
        
        
        s.top=-1;  // top of opstack set -1 to indicate empty stack
        
		
        printf("Enter a valid postfix\n");
		gets(postfix);
		
        l=strlen(postfix);
		
        for(i=0;i<l;i++)
		{
		  if(isalpha(postfix[i]))
			{
				printf("\n Enter value of %c\t\t",postfix[i]);
				scanf("%d",&value);
				push(&s,value);
			}
           else if(postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='$')
			{
               ch = postfix[i];
			   op2=pop(&s) ;
			   op1 =pop(&s);
			   switch(ch)
			   {
			   	case '$':
			   		 push(&s,(int)pow(op1,op2));
				    break;
			    
				case'*':
				 	push(&s,op1*op2);
				    break;
				case'/':
			    	 push(&s,(int)op1/op2);
				    break;
				 case'+':
				    push(&s,op1+op2);
				    break;
		    	case'-':
			      push(&s,op1-op2);
				    break;
			   }
		}
   	}
	
	printf("\n The result is:\t");
	result = pop(&s);
	printf("%d",result);
	
     printf("\n");
     system("pause");
	system("pause");
     return 0;
	
}

	
int push( struct vstack *s, int val)
{
    if(s->top==MAX-1)
     {
          printf("\n stack is full.");
          return 0;
    }
    else
    {
        s->operands[++s->top]=val;
        return 0 ;
    }    
                        
 }

 
int pop(struct vstack *s)
{
     int n;
     if(s->top ==-1)
       {
           printf("\nThe stack is empty.");
           exit(1);
       }    
       else
       {
           n= s->operands[s->top--];
           return n;
        }
 }             
