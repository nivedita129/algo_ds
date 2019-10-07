  // Lab Work 5
	/*program to convert infix to postfix expression*/
	#include<stdio.h>
    #include<stdlib.h>
	#include<string.h>
	#include<ctype.h>
    
    int pushopstack( struct opstack *s, char ch);
    int appendpostfix(struct poststring *ps, char ch);
    char popopstack(struct opstack *s);
   	int precedency(char);
	
    struct opstack      // stack for operators
	{
           char opitems[100];
           int otos;
    };
    
    struct poststring  // stack for postfix notation
    {
           char postitems[100];
           int ptos;
    };
               
	int main()
	{
        struct opstack s;
        struct poststring ps;
		int i, l;
		char infix[100];
        
        
        s.otos=-1;  // top of opstack set -1 to indicate empty stack
        ps.ptos=-1; // top of poststring set -1 to indicate empty string
		
        printf("Enter a valid infix\n");
		gets(infix);
		
        l=strlen(infix);
		
        for(i=0;i<l;i++)
		{
			if(infix[i]=='(')
			{
                pushopstack(&s , infix[i]);
			 }
			else if(isalpha(infix[i]))
			{
				appendpostfix(&ps,infix[i]);
			}
           else if(infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-'||infix[i]=='$')
			{
                if(s.otos!=-1)
                {
			        while(precedency(s.opitems[s.otos])>=precedency(infix[i]))
			        {
				          appendpostfix(&ps,popopstack(&s));
			        }
                 }   
			    pushopstack(&s , infix[i]);
			}
			else if(infix[i]==')')
			{
              while(s.opitems[s.otos]!='(')
				{
				   appendpostfix(&ps,popopstack(&s));			
				
				}
				s.otos--;
			}
      	}
		while(s.otos!=-1)
		{
			  appendpostfix(&ps,popopstack(&s));
		}
		
   /********for displaying***************/
     for(i=0;i<=ps.ptos;i++)
		{
		   printf("%c",ps.postitems[i]);
		}
     printf("\n");
     system("pause");
     return 0;
	
}

	/****************precedency function*********************/
 int precedency(char ch)
	{
		switch(ch)
		{
			case '$':
			     return(4);
			   //  break;
			case'*':
			case'/':
			     return(3);
			    // break;
			case'+':
			case'-':
			     return(2);
			   //  break;
			default:
			     return(1);
		  }
	}
int pushopstack( struct opstack *s, char ch)
{
     if(s->otos==99)
     {
          printf("\n stack is full.");
          return 0;
    }
    else
    {
        s->opitems[++s->otos]=ch;
        return 0;
    }    
                        
 }

 int appendpostfix(struct poststring *ps, char ch)
 {
      if(ps->ptos==99)
      {
                      printf("\n stack is full.");
                      return 0;
      }
      else
      {
          ps->postitems[++ps->ptos]= ch;
          return 0;
      }    
                                     
  }
char popopstack(struct opstack *s)
{
     char x;
     if(s->otos ==-1)
       {
           printf("\nThe stack is empty.");
           exit(1);
       }    
       else
       {
           x= s->opitems[s->otos--];
           return x;
        }
 }             
