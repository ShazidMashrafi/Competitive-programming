#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int s, int e)
{
    for(int i = s; i < e; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

bool binarySearch(int arr[], int s, int e, int k)
{
    print(arr, s, e);
    
    // base case
    if(s > e)   return false;  //element not found
    
    int mid = s + (e - s) / 2;
    if(arr[mid] == k)   return true; //element found

    if(arr[mid] < k)   return binarySearch(arr, mid + 1, e, k);
    else return binarySearch(arr, s, mid - 1, k);
}

int main()
{
    int arr[] = {2, 4, 6, 10, 14, 16};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 18 ;

    bool ans = binarySearch(arr, 0, size - 1, key);
    if(ans) cout << "Present" << endl;
    else cout << "Absent" << endl;
}