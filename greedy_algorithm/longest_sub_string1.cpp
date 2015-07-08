#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	const int ASCII_MAX = 256;
	int last[ASCII_MAX];    
	int start = 0;

	fill(last, last+ASCII_MAX, -1);
	int max_len = 0;

        for(int i = 0; i < s.size(); i++)
	{
	    int k  = s[i];
	    
	    
	    if(last[k] != -1)
	    {
		//start = start > last[k] ? start+1 : last[k]+1;
		if(start < last[k])
		   start = last[k] + 1;
		if(s[i] == s[i-1])
		   start += 1;
		
	    }
	    int len = i - start + 1;
	    max_len = len > max_len ? len : max_len;

            last[k] = i; 
	}
	
	return max_len;
    }
};

int main()
{
    string S("bdb");
    Solution S1;
    cout<<S1.lengthOfLongestSubstring(S)<<endl;


    return 0;
}
