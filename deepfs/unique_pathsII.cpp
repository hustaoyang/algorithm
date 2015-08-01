#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& grid) {

    	const int m = grid.size();
	const int n = grid[0].size();

	
	
	if (m < 1 || n < 1)
		return 0;
	vector<int> f(n, 0);

	for (int j = 0; j < n; j++)
		f[j] += grid[0][j];
	if ( m > 1)
	{
	for (int i = 1; i < m; i++)
		for(int j = 0; j < n; j++)
	{
		f[j] = (j == 0 ? f[0] : min(f[j], f[j-1])) + grid[i][j];
	}
	}
	
    /*
	if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
	vector<int> f(n, 0);
	f[0] = obstacleGrid[0][0] ? 0 : 1;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			f[j] = obstacleGrid[i][j] ? 0 : (j == 0 ? 0 : f[j - 1]) + f[j];

	return f[n - 1];

        / *
        cout<<m<<" "<<n<<endl;

        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;

        
        for(int i = 0; i < n; i++)
            result[i] = (1 == obstacleGrid[m-1][n-i-1]) ? 0 : 1;

        for(int i=m-1; i > 0; i--)
        {
            for(int k = n-1; k >= 0; k--)
                result[k] = obstacleGrid[i][k] ? 0 : (k == 0 ? 0 : (result[k-1] + result[k]));
        }

        return result[0];
        */
    return f[n-1];
    }
};

int main()
{
    int m = 3;
    int n = 3;

    Solution S;
    vector<vector<int> > vec(m, vector<int>(n, 0));
    
    vec[0][0] = 1;
    vec[0][1] = 3;
    vec[0][2] = 1;
    vec[1][0] = 1;
    vec[1][1] = 5;
    vec[1][2] = 1;
    vec[2][0] = 4;
    vec[2][1] = 2;
    vec[2][2] = 1;

    cout<<S.uniquePathsWithObstacles(vec)<<endl;

    return 0;
}
