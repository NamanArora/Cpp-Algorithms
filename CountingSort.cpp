#include <stdio.h>
#include <algorithm> 
#include <bits/stdc++.h> 
#define N 9 
using namespace std;

void counting(int a[])
{
    int count[9]={0};
    int out[9]={0};
    for(int i=0; i<9; i++)
        ++count[a[i]];
    
    //So that we know how many max spaces we need for a number(incase of repitions)
    //we reserve space according
    //Other numbers don't matter because they add nothing to the sum. So no space for them.
    for(int i=1; i<9; i++)
        count[i]+=count[i-1];
        
    for(int i=0; i<9; i++)
    {
        //because the first number will have count of 1 and we need to 
        //make it 0 in order to correctly fit inside sorted array.
        out[count[a[i]]-1]=a[i];
        --count[a[i]];
    }
    for(int i=0; i<9; i++)
        cout << out[i] << " ";
}

int main()
{
    int a[]={1,4,2,5,8,5,2,2,6};
    counting(a);
}
