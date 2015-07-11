#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {

        vector<int> result;


        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();

        cout<<m<<" "<<n<<endl;


        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;

        for(int i = 0; i < n; i++)
            result[i] = (1 == obstacleGrid[0][i]) ? 0 : 1;

        for(int i=0; i < m; i++)
        {
            for(int k = 1; k < n; k++)
                result[k] = (1 == obstacleGrid[i][k]) ? 0: (k == 0 ? 0 : (result[k-1] + result[k]));
        }

        return result[n-1];

    }
};

int main()
{
    int m = 3;
    int n = 3;

    Solution S;
    vector<vector<int> > vec(m, vector<int>(n, 0));

    vec[1][1] = 1;



    cout<<S.uniquePathsWithObstacles(vec)<<endl;

    return 0;
}
