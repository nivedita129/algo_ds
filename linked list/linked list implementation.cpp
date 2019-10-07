///labwork 14
/*linked list implementation*/
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node *next;
};

void insert_beg();
int insert_position();
void insert_end();
int display();
int search();
int del_beg();
int del_specified();
int del_end();

struct node *start;

int main()
{
	int choice;
	int flag;
	
	do
	{
		printf("\n\n  MENU");
		printf("\n1. Insert at Begining");
		printf("\n2. Insert at given Position");
		printf("\n3. Insert at End");
		printf("\n4. Delete at Begining");
		printf("\n5. Delete at given Position");
		printf("\n6. Delete at End");
		printf("\n7. Display all nodes");
		printf("\n8. Search Items");
		printf("\n9. Exit");
		printf("\n\nEnter your Choice: ");
		scanf("%d",&choice);
		
		
		switch(choice)
		{
			case 1 : insert_beg();
					break;
			case 2 : insert_position();
					break;
			case 3 : insert_end();
					break;
			case 4 : del_beg();
					break;
			case 5 : del_specified();
					break;
			case 6 : del_end();
					break;
			case 7 : display();
					break;
			case 8 : search();
					break;
			case 9 : flag=0;
					
					break;			
					
			default: 
					printf("\n\nInvalid Choice!!");
		}
	}
	while(flag);
	
	getch();
	return 0;
}


void insert_beg()
{
	int item;
	struct node *nnode;
	
	printf("Enter the node: ");
	scanf("%d",&item);
	nnode=(struct node *)malloc (sizeof(struct node));
	nnode->info=item;
	nnode->next=start;
	start=nnode;
}


int insert_position()
{
	int item;
	struct node *nnode, *temp;
	
	int pos,i;
	printf("Enter the item: ");
	scanf("%d",&item);
	printf("Enter the position: ");
	scanf("%d",&pos);
	
	if(start==NULL)
	{
		printf("The List is Empty!!  InSufficient Nodes");
		return 0;
	}
	
	else
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("The list has Less number of nodes than position");
				return 0;
				
			}
		}
		nnode=(struct node *) malloc (sizeof (struct node));
		nnode->info=item;
		nnode->next=temp->next;
		temp->next=nnode;
		
	}
}


void insert_end()
{
	int item;
	struct node *nnode,*temp;
	printf("Enter the item: ");
	scanf("%d",&item);
	nnode=(struct node *) malloc (sizeof(struct node));
	nnode->info=item;
	nnode->next=NULL;
	
	if(start==NULL)
	{
		start=nnode;
		
	}
	
	else
	{
		temp=start;
			while(temp->next!=NULL)
			temp=temp->next;
		temp->next=nnode;
		
	}
}


int del_beg()
{
	struct node *temp;
	int x;
	
	if (start==NULL)
	{
		printf("Empty List");
		return 0;
	}
	else
	{
		x=temp->info;
		start=start->next;
		free(temp);
	}
}

int del_end()
{
	struct node *temp;

	
	if (start==NULL)
	{
		printf("Empty List");
		return 0;
	}
	else if(start->next==NULL)
	{
		temp=start;
		printf("Deleted item: %d",start->info);
		start=NULL;
		free(temp);
	}
	else
	{
		temp=start;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
			
		}
		
		free(temp->next);
		temp->next=NULL;
		
	
	
	}
}

int del_specified()
{
	int pos,i;
	struct node *temp, *hold;
	printf("Enter the position: ");
	scanf("%d",&pos);
	
	if(start==NULL)
	{
		printf("List is empty");
		return 0;
	}
	else
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("Not Enough Nodes!");
			}
		}
		
		hold=temp->next;
		printf("The Deleted node is: %d",hold->info);
		temp->next=hold->next;
		free(hold);
	}
}

int search()
{
	struct node *temp;
	int key;
	
	printf("Enter the Key to search: ");
	scanf("%d",&key);
	
	if (start==NULL)
	{
		printf("Empty List");
		exit(0);
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			if(key==temp->info)
			{
				printf("Search Successful!");
				break;
			}
			temp=temp->next;
		}
		if(temp==NULL)
		{
			printf("Item not found!");
		}
	}
}

int display()
{
	struct node *temp;

	
	if (start==NULL)
	{
		printf("Empty List");
		exit(1);
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}
	}
}
