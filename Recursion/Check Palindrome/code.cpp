#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    if(i > j)   return true;
    if(s[i] != s[j])    return false;
    return checkPalindrome(s, i + 1, j - 1);
}

int main()
{
    string s = "abbaa";
    bool isPalindrome = checkPalindrome(s, 0, s.length() - 1);

    if(isPalindrome)    cout << "It's a Palindrome" << endl;
    else cout << "It's not a palindrome" << endl;
}