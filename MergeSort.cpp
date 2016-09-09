#include <stdio.h>
#include <algorithm> 
#include <bits/stdc++.h> 

using namespace std;

void merge(int a[], int lower, int high, int middle)
{
    int i=0;
    int b[9];
    int m=middle+1;
    int low=lower;
    while(low<=middle && m<=high)
    {
        if(a[low]<a[m])
        {
            b[i++]=a[low];
            low++;
        }
        else{
            b[i++]=a[m];
            m++;
        }
    }
    while(low<=middle)
        b[i++]=a[low++];
    while(m<=high)
        b[i++]=a[m++];
    for(int j=0; lower<=high; lower++,j++)
        a[lower]=b[j];
    
}

void mergesort(int a[],int low, int high)
{
    if(low<high)
    {
        int middle=(high+low)/2;
        mergesort(a,low,middle);
        mergesort(a,middle+1,high);
        merge(a,low,high,middle);
    }
}



int main()
{
    int a[]={3,2,5,4,78,47,8,453,46};
    mergesort(a,0,8);
    for(int i=0; i<9; i++)
        cout << a[i] << " ";
    return 0;
}
