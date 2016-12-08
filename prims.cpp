#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

#define V 5

int minIndex(bool visit[V], int key[V])
{
    int small = INT_MAX;
    int loc;
    for(int i=0; i<V; i++)
        if(visit[i]==false && small>key[i])
        {
            small=key[i];
            loc=i;
        }
            
    return loc;
}

void primMST(int graph[][V])
{
    //key holds the distance to adj vertices
    //parent stores the parent of a vertice
    int parent[V],key[V];
    bool visited[V];
    for(int i=0; i<V; i++)
    {
        key[i]=INT_MAX;
        visited[i]=false;
    }
    parent[0]=-1;
    key[0]=0;
    for(int i=0; i<V; i++)
    {
        int loc = minIndex(visited,key);
        visited[loc]=true;
        
        for(int j=0; j<V; j++)
            if(graph[loc][j] && visited[j]==false && graph[loc][j]<key[j])
        {
            key[v]=graph[loc][j];
            parent[j]=loc;
        }
    }
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primMST(graph);

    return 0;
}
