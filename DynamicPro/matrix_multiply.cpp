#include<iostream>
#include<vector>
#define MAX  99999

using namespace std;

class Solution {
public:
    int minMatrixMultiply(vector<int> & matrix)
    {
        int len = matrix.size();
        if(len <= 2)
            return 0;
        vector<int> init(len-1, MAX);
        vector<vector<int> > vec(len-1, init);
        
        for(int i = 0; i < len-1; i++)
        {
            for(int j = 0; j < i
        } 
    }
};

int main()
{
    return 0;
}
