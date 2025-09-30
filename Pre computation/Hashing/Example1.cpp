/* Problem
Given array a of N intergers. Given Q queries and in each query
given a number X, print count of that number in array.

Constrains 
1<=N<=10^5
1<=Q<=10^7
1<=a[i]<=10^7

*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) // O(N)=10^5
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--) // O(Q*N) = 10^5*10^5=10^10
    {
        int x;
        cin>>x;
        int ct=0;
        for(int i=0; i<n;i++) // O(N) = 10^5
        {
            if(a[i]==x) ct++;
        }
        cout<<ct<<endl;
    }
}
*/

/*
This code has time complexity of O(N^2) which is 10^10, which will result in TLE
To not get a TLE we need to use Hashing.
To use Hashing we will use an empty array or an array whose every value is 0.
Then we will store the count of the number in given to every corresponding 
index in hash array.
For example if we encounter 5 in given array, we will increase the value of hash_array[5] by one.
This way we can count the number of occurrences without nested loops.
https://youtu.be/efET3lxYCkM?t=691
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int hsh[N]; // Global arrays get initialized using 0;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) // O(N)=10^5
    {
        cin>>a[i];
        hsh[a[i]]++; // Suppose first input 5, then a[0]=5 and hsh[a[0]]==hsh[5] gets incremented
    }
    int q;
    cin>>q;
    while(q--) // O(Q) = 10^5 
    {
        int x;
        cin>>x;
        cout<<hsh[x]<<endl; // if x=5 then it will print out hsh[5] which is storing the number of occurrences of 5
    }
}