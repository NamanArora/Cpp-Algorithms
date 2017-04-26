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


int findsmallest(int stamp[], int n)
{
    int i=1;
    int small=stamp[0];
    int loc=0;
    for(; i<n; i++)
        if(stamp[i]<small)
        {
            small=stamp[i];
            loc=i;
        }
    return loc;
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
    int stack[4]={-1,-1,-1,-1};
    int stamp[4]={0,0,0,0};
    while(i<n)
    {
        if(search(stack,a[i],pages))
        {
            int index= findsmallest(stamp,pages);
            printf("Replace %d with data %d\n", index,a[i]);
            stack[index]=a[i];
            stamp[index]++;
            printstack(stack, pages);
        }
        else
        {
            printf("Page found:%d\n",a[i]);
            int k=0;
            for(; k<pages;k++)
                if(a[i]==a[k])
                    break;
            stamp[k]=stamp[k]+1;
        }
        i++;

    }
    return 0;
}
