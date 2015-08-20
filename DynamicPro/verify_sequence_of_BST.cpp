#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySeq(vector<int> sequence) {
        int seq_start = 0;
        int seq_end = sequence.size();
        if (seq_end < 1)
            return false;

        return do_verify_seq(sequence, seq_start, seq_end - 1);   
    }
private:
    bool do_verify_seq(vector<int>& input, int start, int end)
    {
        int i = 0;
        while (i < end && input[i] < input[end])
            ++i;
        
        int j = i;
        for (; j < end; ++j)
        {
            if (input[j] < input[end])
                return false;
        }

        bool left = true;
        if (start < i - 1)
            left = do_verify_seq(input, start, i - 1);

        bool right = true;
        if (i < end - 1)
            right = do_verify_seq(input, i, end - 1);

        return left && right;
    }
};

int main()
{
    int a[] = {5, 9, 7, 13, 14, 6};

    vector<int> vec(a, a + 6);
    Solution S;
    
    if (S.VerifySeq(vec))
        cout<<"yes"<<endl;
    else
        cout<<"No"<<endl;
}
