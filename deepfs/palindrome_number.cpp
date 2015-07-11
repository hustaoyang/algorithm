#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
	int ret = 0;
	int tmp = x;
	while(x)
	{
	    ret = ret*10 + x%10;
	    x /= 10;
	}

	return ret == tmp;
    }
};

int main()
{
     Solution S;
     int x;
     while(cin>>x)
     {
	if(S.isPalindrome(x))
	    cout<<x<<"is a palindrome number"<<endl;
	else
	    cout<<x<<"is not a palindrome number"<<endl;
     }
  
     return 0;
}
