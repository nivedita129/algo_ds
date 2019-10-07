// Lab Work 16
/* Binary Search Tree implementation */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;          //Declaring an info field
	struct node *left; // left child pointer 
	struct node *right; // right child pointer
};


struct node * insert_element(struct node *head, int item);
struct node * delete_node(struct node *head, int item);
struct node *findmin(struct node *head);
void search_item(struct node *head, int key);
void preorder(struct node *head);
void inorder(struct node *head);
void postorder(struct node *head);
void display_leafs(struct node *head);
void display_Nodes_with_Onechild(struct node *head);
void display_Nodes_with_Twochild(struct node *head);
int countNodes(struct node *head);

//Main Function
int main()
{
int item,key;
	      
int choice;
int flag =1;
struct node *root = NULL;  //global external pointer to point root node
do
{
printf("\n\n MENU");
printf(" \n\n\t 1: Insert a node in binary search tree ");
printf(" \n\n\t 2: Deleting a node in binary search tree ");
printf(" \n\n\t 3: Pre-Order Traversal ");
printf(" \n\n\t 4: In-Order Traversal");
printf(" \n\n\t 5: Post-Order Traversal");
printf(" \n\n\t 6: Display Nodes with one child");
printf(" \n\n\t 7: Display all nodes with two children");
printf(" \n\n\t 8: Display all the leaf nodes");
printf("\n\n\t  9: Count Number of nodes in tree");
printf("\n\n\t  10: Search an item");
printf(" \n\n\t 11: Exit");
printf("\n\n\n Enter of your choice:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:
		printf("\Enter the item\t	");
		scanf("%d",&item);
		root = insert_element(root,item);
		break;
case 2:
		printf("\Enter the item to be deleted\t	");
	    scanf("%d",&item);
		root = delete_node(root, item);
		break;
case 3:
		preorder(root);
		break;
case 4: inorder(root);
		break;
case 5: postorder(root);
		break;
case 6:
		display_Nodes_with_Onechild(root);
		break;
case 7: 
		display_Nodes_with_Twochild(root);
		break;
case 8: display_leafs(root);
		break;
case 9: printf("\n The nunber of nodes in tree %d\t", countNodes(root));
		break;
case 10:
		printf("\n Enter the search item");
		scanf("%d",&key);
		search_item(root,key); 
		break;
case 11:
		flag=0;
		break;
default:
		printf("\n Invalid Choice");
 }
}while(flag);
 system("pause");
return 0;
}
struct node * insert_element(struct node *head, int item)
{
	struct node *nnode;
	if(head== NULL)
	{
	  head = (struct node *) malloc(sizeof(struct node));
	  head->info = item;
	  head->left =NULL;
	 head->right= NULL;
	}
	else if(item<head->info)
	  head->left = insert_element(head->left,item);
    else if(item>head->info)
        head->right= insert_element(head->right,item);
   return(head);	
	}

struct node * delete_node(struct node * head, int n)
{
	struct node *temp;
	if (head == NULL)
	{
		printf("\n The tree is empty");
		return head;
	}
	else if(n<head->info)
            
            	head->left = delete_node(head->left,n);
    else if(n>head->info) 
	         head->right = delete_node(head->right,n);
	else if(head->left!=NULL && head->right!=NULL)
	{
		 temp= findmin(head->right);
		 head->info = temp->info;
		 head->right= delete_node(head->right,head->info);
	}
	else
	{
		temp= head;
		if(head->left==NULL)
		    head=head->right;
		else if(head->right==NULL)
		    head=head->left;
		free(temp);
	}
	return head;
}

struct node * findmin(struct node * head)
{
	if(head==NULL)
	   return NULL;
	else if(head->left ==NULL)
	   return head;
	else
	   return(findmin(head->left));
}

void search_item(struct node *head, int key)
{
	if(head==NULL)
		printf("\n The item doesnot exist !!");
	else if(key==head->info)
			printf("\n The item found !!!");
	else if(key< head->info)
	     search_item(head->left,key);
	else
		search_item(head->right,key);
}
void preorder(struct node *head)
{
	if(head!=NULL)
	{
		printf("%d\t",head->info);
		preorder(head->left);
		preorder(head->right);
	}
}
void inorder(struct node *head)
{
	if(head!=NULL)
	{
		inorder(head->left);
		printf("%d\t",head->info);
		inorder(head->right);
	}
}

void postorder(struct node *head)
{
	if(head!=NULL)
	{
		postorder(head->left);
		postorder(head->right);
		printf("%d\t",head->info);
		
	}
}

void display_leafs(struct node *head)
{
	if(head!=NULL){
		if(head->left==NULL && head->right==NULL)
			printf("%d\t",head->info);
		display_leafs(head->left);
		display_leafs(head->right);
	}
}
void display_Nodes_with_Onechild(struct node *head)
{
	if(head!=NULL){
		if(head->left==NULL && head->right!=NULL || head->left!=NULL && head->right ==NULL)
			printf("%d\t",head->info);
		display_Nodes_with_Onechild(head->left);
		display_Nodes_with_Onechild(head->right);
	}
}
void display_Nodes_with_Twochild(struct node *head)
{
	if(head!=NULL){
		if(head->left!=NULL && head->right!=NULL)
			printf("%d\t",head->info);
		display_Nodes_with_Twochild(head->left)	;
		display_Nodes_with_Twochild(head->right);
	}
}
int countNodes(struct node *head)
{
	if(head==NULL)
	 return 0;
	return (1+ countNodes(head->left)+ countNodes(head->right));
}
