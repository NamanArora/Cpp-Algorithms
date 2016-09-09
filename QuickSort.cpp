#include <stdio.h>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;

void swap(int *p, int *q)
{
    int temp= *p;
    *p = *q;
    *q= temp;
}

int partition(int a[], int low, int high)
{
    int pivot= a[low];
    int left=low+1,right=high;
    while(1)
    {
        while(a[left]<=pivot && left<=right)
            left++;
        while(a[right]>=pivot && left<=right)
            right--;
        if(left<right)
        swap(&a[left],&a[right]);
        else
        break;
    }
    swap(&a[low],&a[right]);
    return right;
}

void quicksort(int a[],int low, int high)
{
    if(low<high)
    {
        int t=partition(a,low,high);
        quicksort(a,low,t-1);
        quicksort(a,t+1,high);
    }
}


int main()
{
    int a[]={3,2,5,4,78,47,8,453,46};
    quicksort(a,0,8);
    for(int i=0; i<9; i++)
        cout << a[i] << " ";
    return 0;
}
