#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s, int i, int n)
{
    if(i >= n/2)
    {
        return true;
    }
    else if(s[i] != s[n - i - 1])
    {
        return false;
    }
    isPalindrome(s, i + 1, n);
}
int main()
{
    string s = "a";
    cout << isPalindrome(s, 0, s.size());
}
