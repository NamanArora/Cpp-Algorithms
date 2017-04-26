#include <stdio.h>
#include <stdlib.h>

int search(int a[], int t, int n)
{
    int i=0;
    while(i<n)
    {
        if(a[i]==t)
            return 0;
        i++;
    }
    return 1;
}

void printstack(int stack[], int n)
{
    int i=0;
    for(; i<n; i++)
        printf("%d ",stack[i]);
    printf("\n");
}

int main()
{
    printf("No of pages: ");
    int pages;
    scanf("%d", &pages);
    printf("Lenght of string: ");
    int n;
    scanf("%d", &n);
    int i;
    int a[n];
    int cnt=0;
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    i=0;
    int j=0;
    int stack[3]={-1,-1,-1};
    while(i<n)
    {
        if(search(stack,a[i],pages))
        {
            printf("Page fault:%d\n", a[i]);
            stack[j]=a[i];
            j=(j+1)%pages;
            printstack(stack,pages);
            cnt++;
        }
        else
        {
            printf("Page found:%d\n",a[i]);
        }
        i++;

    }
    return 0;
}
