#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<cmath>

#define pb push_back
#define ll long long int
#define mp make_pair 
#define ms(a,b) memset(a,b,sizeof a)
#define MOD 1000000007

using namespace std;

int n;
int f[100007];
int g[100007];
int diameter = -1;
void edge(vector< int> adj[] , int a, int b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}

void dfs(vector<int> adj[], int V, int pV)
{
    vector<int> fval;
    for(auto v: adj[V]){
        if(v==pV) continue;
        dfs(adj, v, V);
        fval.pb(f[v]);
    }
    sort(fval.begin(), fval.end());
    if(!fval.empty()) f[V] =1 + fval[fval.size()-1];
    if(fval.size()>=2)
    g[V] = 2 + fval[fval.size()-1] + fval[fval.size()-2];
    diameter = max(diameter, max(f[V],g[V]));
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> adj[n+1];
    ms(f,0);
    ms(g,0);
    for(int i=0; i<n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        edge(adj, x, y);
    }
    dfs(adj, 1, 0);
    cout << diameter << endl;
    return 0;
}
