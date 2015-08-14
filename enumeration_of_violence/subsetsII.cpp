#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &vec) {
        //int len = S.size();
        //if (len < 1)
            //return;
        sort(vec.begin(), vec.end());
        vector<vector<int> > result;
        vector<int>  path;
        //int step = 0;
        subset(result, path, 0, vec);

        return result;
    }
private:
    static void subset(vector<vector<int> > &res, vector<int> &path, int step, vector<int> &S)
    {
        res.push_back(path);
        
        //subset(res, path, step + 1, S);
        
		for (int i = step; i < S.size(); ++i)
		{
        	if (i != step && S[i] == S[i-1]) continue;
			path.push_back(S[i]);
        	subset(res, path, i + 1, S);
        	path.pop_back();
		}
    }     
};


int main()
{   
    Solution S;
    int a[] = {1, 2, 2};
    vector<int> vec(a, a+3);
    vector<vector<int> > result = S.subsets(vec);
    
    int m = result.size();
    //int n = result[15].size();
    for (int i = 0; i < m; ++i)
    {   
        int n = result[i].size();
        for(int j = 0; j < n; ++j)
        {
            cout<<result[i][j]<<" ";
        }

        cout<<endl;
    }    
    return 0;
}
