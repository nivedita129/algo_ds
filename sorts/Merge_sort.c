#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void merge_sort(int a[],int);
void m_sort(int a[],int temp[],int left,int right);

int main()
{
	int i,n,a[20];
	printf("Enter the number of item in array[less than 20]:-   \n");
	scanf("%d",&n);
	printf("Enter the %d items in array:-   \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		merge_sort(a,n);
		printf("\nAfter quick sort The list of data is:- \n\n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
getch();
return 0;
}

void merge_sort(int a[],int n)
{
	int *temp;
	temp=(int *)malloc(sizeof(int)*n);
	m_sort(a,temp,0,n-1);
}

void m_sort(int a[],int temp[],int left,int right)
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		m_sort(a,temp,left,mid);
		m_sort(a,temp,mid+1,right);
		merge(a,temp,left,mid+1,right);
	}
}

merge(int a[],int temp[],int lpos,int rpos,int rightend)
{
	int i,leftend,num_elements,tmp_pos;
	leftend=rpos-1;
	tmp_pos=lpos;
	num_elements=rightend-lpos+1;
	while(lpos<=leftend&&rpos<=rightend)
		if(a[lpos]<=a[rpos])
			temp[tmp_pos++]=a[lpos++];
		else
			temp[tmp_pos++]=a[rpos++];
	while(lpos<=leftend)
		temp[tmp_pos++]=a[lpos++];
	while(rpos<=rightend)
		temp[tmp_pos++]=a[rpos++];
	for(i=0;i<num_elements;i++&&rightend--)
		a[rightend]=temp[rightend];
}
