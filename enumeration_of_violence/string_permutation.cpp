#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        
        int len = str.size();
        if (len < 1)
            return result;
        //string mid;
        do_permutation(result, 0, len, str);

        return result;
    }
//private:
    void do_permutation(vector<string>& res,int i, int len, string& str1)
    {
        if (i == len)
        {
            res.push_back(str1);
            return;
        }
        
        //do_permutation(res, i + 1, j + 1, len, str1);
        for (int j = i; j < len; ++j)
        {
            if (j != i && str1[i] == str1[j])
                continue;
            
            swap(str1, i, j);
            sort(str1.begin() + i + 1, str1.end());
            do_permutation(res, i + 1, len, str1);
            sort(str1.begin() + i + 1, str1.end());
            ;
        }
        
    }

    void swap(string & temp, int i, int j)
    {
        char ch = temp[i];
        temp[i] = temp[j];
        temp[j] = ch;
    }
};

int main()
{
    string input("abcd");
    Solution S;
    
    vector<string> vec = S.Permutation(input);
    //S.swap(input, 0, 2);
    //cout<<input<<endl;
    int len = vec.size();
    cout<<len<<endl;
    for (int i = 0; i < len; ++i)
        cout<<vec[i]<<endl; 
    return 0;
}
