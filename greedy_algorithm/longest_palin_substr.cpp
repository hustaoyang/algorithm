#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
	size_t len = s.size();
	string result;
	int max_len = 0;
	int max_left = 0 , max_right = 0;
	for(int i = 0; i < len; i++)
	{
	    int left = i -1;
	    int right = i + 1;
	    int max = 1;
	    while(left >= 0 && right < len && s[left] == s[right])
	    {
		 max += 2;
	         --left;
		 ++right;
	    }
	    if(max > max_len)
	    {
		max_len = max;
		max_left = left - 1;
		max_right = right - 1;
	    }
	}

	for(int i = max_left; i <= max_right; i++)
	    result.insert(result.end(), s[i]);
	
	return result;
    }
};


int main()
{
    Solution S; 
    string s("7892kdedk2");
    
    cout<<S.longestPalindrome(s)<<endl;
    

    return 0;
}
