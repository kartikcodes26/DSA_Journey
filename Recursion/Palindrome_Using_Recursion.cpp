#include <iostream>
#include <string>
using namespace std;

bool ispalindrome(string str, int i)
{
    if(i >= str.size()/2)
    {
        return true;
    }
    else if (str[i] != str[str.size() - i - 1])
    {
        return false;
    }
    return ispalindrome(str, i + 1);
}

int main() {
    
    cout << ispalindrome("madsm", 0);

    return 0;
}
