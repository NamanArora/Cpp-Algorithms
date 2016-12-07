#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int size;
    list<int> *adj;

public:
    Graph(int n)
    {
        size=n;
        adj = new list<int>[n];
    }
    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
    }

    void display(int start)
    {
        bool *visited = new bool[size];
        list<int> stack;
        for(int i=0; i<size; i++)
            visited[i]=false;

        list<int>::iterator i;

        stack.push_back(start);

        while(!stack.empty())
        {
            start=stack.back();
            if(!visited[start])
            {
                cout << start;
                visited[start]=true;
            }
            for(i=adj[start].begin(); i!=adj[start].end(); i++)
            {
                if(visited[*i]==false)
                    stack.push_back(*i);
            }
            int temp= stack.back();
            if(start==temp)
            {
                //nothing added in stack.. backtrack
                stack.pop_back();
            }

        }

    }

};

int main()
{
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);


    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.display(0);

    return 0;
}
