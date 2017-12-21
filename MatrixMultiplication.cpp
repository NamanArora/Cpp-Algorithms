#include<bits/stdc++.h>
#include<iostream>
#define pb push_back
using namespace std;

vector< vector<int> > multiply(vector< vector<int> > &m1,vector< vector<int> > &m2)
{
    //for 2x2 matrix
    vector< vector<int> > c;
    int rows = m1[0].size(); //2
    int cols = m2.size(); //2
    
    int frows = m1.size(); //1
    int fcols = m2[0].size(); //2

    for(int i=0; i<frows; i++)
    {
        vector<int> row; 
        for(int j=0; j<fcols; j++)
        {
            int sum=0;
            for(int x=0; x<rows; x++)
                sum+=m1[i][x]*m2[x][j];

            row.pb(sum);
        }
        c.pb(row);
    }

    return c;
}

int main()
{
    vector< vector<int> > a,b,c;
    vector<int> row;

    row.pb(2);
    row.pb(3);
    a.pb(row);

    row.clear();

    row.pb(2);
    row.pb(3);
    b.pb(row);
    row.clear();
    row.pb(4);
    row.pb(5);
    b.pb(row);

    c = multiply(a,b);
    for(int i=0; i<1; i++)
    {
        cout << endl;
        for(int j=0; j<2; j++)
            cout << c[i][j];
    }
        
    
    return 0;
}
