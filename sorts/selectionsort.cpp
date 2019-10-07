#include<stdio.h>
#include<conio.h>
void selection_sort(int a[],int n);
#define MAX 100
int main()
{
	int i,n,a[MAX];
	printf("Enter the number of item in array[100]:  \n");
	scanf("%d",&n);
	printf("Enter the %d items in array:  \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		selection_sort(a,n);
		printf("\nAfter Sorting The data are: \n\n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
getch();
return 0;
}

void selection_sort(int a[],int n)
{
	int i,j,temp,index,min;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				index=j;
			}
		}
	if(index!=i)
	{
		temp=a[i];
		a[i]=a[index];
		a[index]=temp;
	}
	}
}
