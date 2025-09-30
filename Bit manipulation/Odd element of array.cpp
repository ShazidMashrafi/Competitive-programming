/*
Given an array 'a' of n integers. All integers are present in even count except one.
Find that one integer which has odd count in O(N) time and O(1) space.
N < 10 ^ 5
a[i] < 10 ^ 5
*/


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0; i<n; ++i)
    {
        int x;
        cin>>x;
        ans ^=x;
    }
    cout<<ans<<endl;
}