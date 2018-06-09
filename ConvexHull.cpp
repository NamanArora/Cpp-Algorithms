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

struct Point{
    int x,y;
};

bool cmp(Point a, Point b)
{
    if(a.x < b.x)
        return true;
    else if(a.x== b.x && a.y <= b.y)
        return true;
    return false;
}

ll cross(Point a, Point b, Point c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

vector<Point> convexHull(vector<Point> a, int n)
{
    sort(a.begin(), a.end(), cmp);
    int size=0;
    vector<Point> hull(2*n);
    //upper convex
    for(int i=0; i<n; i++)
    {
        while(size>1 && cross(hull[size-2],hull[size-1], a[i])<=0)
            --size;
        hull[size++]=a[i];
    }
    //lower convex
    for(int i=n-2, j=size+1; i>=0; i--)
    {
        //j=size+1, j is 2 points incl the last and first point after that
        //j=minimum 2 points in order to remove points
        while(size>=j && cross(hull[size-2],hull[size-1], a[i])<=0)
            --size;
        hull[size++] = a[i];
    }
    //to remove the unused points out of 2*n
    hull.resize(size-1);
    return hull;
}

int main()
{
    std::ios::sync_with_stdio(false);
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    vector<Point> a;
    int n = sizeof(points)/sizeof(points[0]);
    for(int i=0; i<n; i++)
    a.pb(points[i]);
    
    vector<Point> c = convexHull(a,n);
    for(int i=0; i<c.size(); i++)
    cout << c[i].x << " " << c[i].y << endl;
    return 0;
}
