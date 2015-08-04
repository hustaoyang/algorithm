#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       /*
        const int ASCII_MAX = 256;
        int last[ASCII_MAX]; 
        int start = 0; 

        fill(last, last + ASCII_MAX, -1); 
        if(!s.size())
            return 0;

        int max_len = 1;
        for (int i = 0; i < s.size(); i++) {
            int k = s[i];
            if(last[k] != -1)
            {
                max_len = (i - start) > max_len ? (i - start) : max_len;
                start = last[k] + 1;
            }
            else 
                max_len = (i - start + 1) > max_len ? (i - start + 1) : max_len;

            last[k] = i;
        }
        return max_len;
        */
        if(s.empty())
    {
        return 0;
    }

    int maxLen = 0;
    int start = 0;
    vector<int> registry;
    registry.resize(256, -1); // char can be the index here
    int j = start;
    while(j < s.length())
    {
        if(registry[s[j]] != -1)
        {
            maxLen = max(maxLen, j - start);
            // clean up the registry up to the previous occurence of the current char, inclusively
            for(int k = start; k < registry[s[j]]; ++k)
            {
                registry[s[k]] = -1;
            }
            start = registry[s[j]] + 1;                
        }
        registry[s[j]] = j;
        ++j;
    }
    return max(maxLen, j - start);
    }	
};

int main()
{
    string S;
    Solution S1;
    while(cin>>S)
    {
        cout<<S1.lengthOfLongestSubstring(S)<<endl;
    }

    return 0;
}
