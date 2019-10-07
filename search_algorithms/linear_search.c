
#include <stdio.h>

int main()
{

    int a[30], n, key;
    printf("Enter the size of array(less than 30): ");
    scanf("%d", &n);

    int  i;
    int pos =0;

    printf("Enter the array numbers\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number to be searched for ");
    scanf("%d", &key);

      for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            pos = i + 1;
            break;
        }

    }

      if(pos==0)
            printf("\nNot Found !\n");

    else
    {
        printf("\nNumber %d is present at the position [ %d ] in array.\n", key, pos);
    }
    
     
    return 0;
}