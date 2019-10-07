// Lab Work 15
/* Doubly Circular Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;          //Declaring an info field
	struct node *next; // next node pointer 
	struct node *prev; // previous pointer
};

void insert_beg();
int insert_position();
void insert_end();
int display();
int search();
int del_beg();
int del_specified();
int del_end();

struct node *start = NULL;  //global external pointer to point first node
struct node *last = NULL;

//Main Function
int main()
{
int choice;
int flag =1;
do
{
printf("\n\n MENU");
printf(" \n\n\t 1: Insert at Begnning ");
printf(" \n\n\t 2: Insert at given position ");
printf(" \n\n\t 3: Insert at End ");
printf(" \n\n\t 4: Delete at Beginning");
printf(" \n\n\t 5: Delete at specified position");
printf(" \n\n\t 6: Delete at End");
printf(" \n\n\t 7: Display all nodes ");
printf(" \n\n\t 8: Search Item");
printf("\n\n\t 9: Exit");
printf("\n\n\n Enter of your choice:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:
		insert_beg();
		break;
case 2:
		insert_position();
		break;
case 3:
		insert_end();
		break;
case 4:  del_beg();
		 break;
case 5:   del_specified();
		break;
case 6:
		del_end();
		break;
case 7: 
		display();
		break;
case 8: search();
		break;
case 9:
		flag = 0;
		break;
		
default:
		printf("\n Invalid Choice");
}
}while(flag);
system("pause");
return 0;
}

void insert_beg() // inserting a node at the beginning
{
	int item;
	struct node *nnode;
	
	printf("\Enter the item\t	");
	scanf("%d",&item);
	nnode = (struct node *) malloc(sizeof(struct node));
	nnode->info = item;
	if(start == NULL)
	{
      nnode->next = nnode;
      nnode ->prev = nnode;
	   start = nnode;
	   last = nnode;
	}
	else
	{
		nnode->next= start;
		nnode->prev= last;
		start->prev = nnode;
		start = nnode;
		last->next = nnode;
	}
}

int insert_position()
{
	int item;
	struct node *nnode,*temp;
	int pos,i;
	
	printf("\n Enter the position of node to add ");
	scanf("%d",&pos);
	
	if(pos==1)
	{
		insert_beg();
		return 0;
	}
	else if(start ==NULL)
	{
	printf("\n The list is empty!!!  Insufficient nodes... ");
	return 0;
	}
	else
	{
      printf("\Enter the item\t	");
	  scanf("%d",&item);
      temp = start;
      for(i=1;i<pos-1;i++)
         {
         	temp=temp->next;
         	if(temp==start)
         	 {
         	 	printf("\n The list has less number of node than position.");
				return 0;	
         	 }
         }
         
       	nnode = (struct node *) malloc(sizeof(struct node));
		nnode->info = item;
         if(temp->next==start)  
		    {
		    	last->next= nnode;
	    		nnode->prev= last;
	    		last= nnode;
	   			 nnode->next = start;
	    		start->prev= nnode;
		    	
		    }
		else
		{
	 	nnode->next = temp->next;
		nnode->prev= temp;
		temp ->next->prev=nnode;
		temp->next = nnode;
	    }
	}
}

void insert_end()
{
	int item;
	struct node *nnode,*temp;
	
	printf("\Enter the item\t	");
	scanf("%d",&item);
	nnode = (struct node *) malloc(sizeof(struct node));
	nnode->info = item;
	
	if(start ==NULL)
	 {
		
	   start = nnode;
	   last = nnode;
	   nnode->prev = nnode;
	   nnode->next= nnode;
	   start = last = nnode;
      }
	 else
	 {
	    last->next= nnode;
	    nnode->prev= last;
	    last= nnode;
	    nnode->next = start;
	    start->prev= nnode;
	   }
}

int del_beg()
{
	int item;
	struct node *temp;
	
	if(start ==NULL)
	{
		printf("\n Empty List !!!");
		return 0;
	}
	else if (start==last)
	{
		temp=start;
		start = NULL;
		last = NULL;
		free(temp);
	}
	else
	{
		temp= start;
		printf("\n The deleted item is %d",start->info);
		start = start->next;
		start->prev= last;
		last->next= start;
		free(temp);
	}
	
}

int del_end()
{
	int item;
	struct node *temp, *hold;
	
	if(start ==NULL)
	{
		printf("\n Empty List !!!");
		return 0;
	}
	else if( start==last)
	{
		temp = start;
		printf("\n Deleted item is %d",start->info);
		start = NULL;
		last = NULL;
		free(temp);
	}
	else
	{
		temp= last;
		start->prev = last->prev;
		last= last->prev;
		last->next = start;
	    printf("\n The deleted item is %d",temp->info);
		free(temp);
		
	}
	
}

int del_specified()
{
	int item;
	int pos,i;
	struct node *temp,*hold;
	
	printf("\n Enter the position");
	scanf("%d",&pos);
	
	if(start ==NULL)
	{
		printf("\n Empty List !!!");
		return 0;
	}
	else if(pos == 1)
	 {
		 		del_beg();
		 		return 0;
	  }
   else 
   	{
		temp= start;
		for(i=1;i<pos-1;i++)
		 {
		 	temp=temp->next;
		 	if(temp==last)
		 	   {
		 	   	printf("\n Not enough nodes in the list");
		 	   	return 0;
		 	   }
		 }
		 hold = temp->next;
		 if(hold->next ==start)
		 	{
		 		temp->next =start;
		 		last = temp;
		 		start->prev = temp;
		 		
		 	}
		 else
		 {	
		    hold->next->prev = temp;
		    temp->next= hold->next;  
	     }
		 printf("\n The deleted item is %d", hold->info);
		 free(hold);
	    
	}	
}

int search()
{
	struct node *temp;
	int key;
	if(start ==NULL)
	{
		printf("\n The list is empty");
		return 0;
	}
	else
	{
		printf("\n Enter search item");
		scanf("%d",&key);
		
		temp = start;
		while(temp!=last)
		
		{
			if(temp->info==key)
			{
				printf("\n Search successful .....");
				return 0;
			}
			temp=temp->next;
		}
		if(key==last->info)
		 printf("\n successful Search !!!");
		else
		 printf("\n Unsuccessful Search");
	}
}

int display()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("\n The list is empty");
		return 0;
    }
    else
    {
    	temp=start;
    	printf("\n The list is:");
    	while(temp!=last)
    	{
    		printf("%d ",temp->info);
    		temp=temp->next;
    	}
    		printf("%d ",temp->info);
    	
    }
	
}
