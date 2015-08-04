#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int cut_rod(vector<int> &sev, int l)
    {
        //if(l <= 0)
          //  return 0;

        vector<int> result(l+1, 0);
        for(int i = 0; i <= l; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int sum = sev[j] + sev[i-j];
                result[i] = sum > result[i] ? sum : result[i];
            }
        }
           
        return result[l];
        
    }    
};

int main()
{
    int a[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    vector<int> sev(a, a+11);
        
    Solution S;
    int m;
    while(cin>>m)
    {
        cout<<S.cut_rod(sev, m)<<endl;
    }
    return 0;
}
