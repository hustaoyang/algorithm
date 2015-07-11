#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /*
    int uniquePaths(int m, int n) {
        if(n < 1 || m < 1)
            return 0;
        if(m == 1 && n == 1)
            return 1;

        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
    */

    int uniquePaths(int m, int n) {
        vector<int>   result(n, 0);
        result[0] = 1;

        for(int i=0; i < m; i++)
        {
            for(int k = 1; k < n; k++)
            {
                result[k] = result[k-1] + result[k];
                //cout<<result[k]<<" ";
            }

            //cout<<endl;
        }

        return result[n-1];

    }
};

int main()
{
    int m = 2;
    int n = 7;

    Solution S;

    cout<<"In unique paths: "<<endl;
    cout<<S.uniquePaths(m, n)<<endl;

    //vector<int> s = S.uniquePaths(m, n);
    // for(vector<int>::iterator iter = s.begin(); iter < s.end(); iter++)
    //    cout<<*iter<<" ";
    return 0;
}
