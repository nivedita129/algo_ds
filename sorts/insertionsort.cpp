#include<stdio.h>
#include<conio.h>
void insertionsort(int a[],int n);
#define MAX 100
int main()
{
	int i,n,a[MAX];
	printf("Enter the number of item in array[100]:  \n");
	scanf("%d",&n);
	printf("Enter the %d items in array:  \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		insertionsort(a,n);
		printf("\nAfter Sorting The data are: \n\n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
getch();
return 0;
}

void insertionsort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		
		for(j=i-1;j>=0&&a[j]>temp;j--)
		{
			a[j+1]=a[j];
		}
		
	a[j+1]=temp;
	}
}
