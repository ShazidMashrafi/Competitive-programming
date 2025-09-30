/*
Consider this problem: There are N≤5000 workers. Each worker is available during 
some days of this month (which has 30 days). For each worker, you are given a set 
of numbers, each from interval [1,30], representing his/her availability. 
You need to assign an important project to two workers but they will be able to 
work on the project only when they are both available. Find two workers that are 
best for the job — maximize the number of days when both these workers are available.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; ++i)
    {
        int m;
        cin>>m;
        int days=0;
        for(int j=0; j<m; ++j)
        {
            int x;
            cin>>x;
            days= (days| (1<<x));
        }
        v[i]=days;
    }
    int mx=0, w1=-1, w2=-1;
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            int intersection = v[i] & v[j];
            int common = __builtin_popcount(intersection);
            if(mx<common)
            {
                mx=common;
                w1=i+1;
                w2=j+1;
            }
        }
    }
    cout<<mx<<" "<<w1<<" "<<w2<<endl;
}