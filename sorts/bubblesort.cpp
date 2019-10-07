/* q) WAP to arrange list of numbers in ascending order using function.(using bubble sort */

#include<stdio.h>
#include<conio.h>
#define size 100
void bubblesort(int);
int main()
{
    int n;
    printf("Enter how many number[<100]: ");
    scanf("%d",&n);
	bubblesort(n);
    
    
    getch();
    return 0;
}

void bubblesort(int n)
{	
	int a[size],i,j,temp;
	
	printf("Enter the %d numbers:\n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    /*   Bubble sorting begins */
    for (i=0;i<n;i++)
    {
        for (j=0;j<(n-i-1);j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The number in ascending order is:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
