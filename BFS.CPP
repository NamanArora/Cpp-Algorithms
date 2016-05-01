#include <stdio.h>
#include <stdlib.h> 
#include <bits/stdc++.h> 
#include <string>
using namespace std;

class Graph
{
    int V;
    list<int> *p;
public:
    Graph(int n)
    {
        V=n;
        p= new list<int>[n];
    }
    void addEdge(int v, int w)
    {
        p[v].push_back(w);
    }
    void bfs(int start)
    {
        int a[V]={0};
        bool *visited= new bool[V];
        for(int i=0; i<V; i++)
            visited[i]=false;
            
        list<int> queue;
        
        visited[start]=true;
        queue.push_back(start);
        
        list<int>::iterator it;
        
        while(!queue.empty())
        {
            start=queue.front();
            cout << start << " " << "level=" << a[start] << endl;
            queue.pop_front();
            for(it=p[start].begin(); it!=p[start].end(); it++)
                if(visited[*it]==false){
                a[*it]=a[start] + 1;
                //printf("Level of %d=%d\n",*it,a[*it]);
                queue.push_back(*it);
                visited[*it]=true;
                }
        }
        
        
    }
};

int main(int argc, char **argv)
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs(0);
	return 0;
}
