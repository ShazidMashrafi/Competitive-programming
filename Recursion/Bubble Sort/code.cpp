#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    if(n == 0 || n == 1) return;
    
    for(int i = 0; i < n - 1; ++i)
    {
        if(arr[i] > arr[n - 1]) swap(arr[i], arr[i + 1]);
    }

    bubbleSort(arr, n);
}

int main()
{
    int arr[] = {4, 2, 9, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
}