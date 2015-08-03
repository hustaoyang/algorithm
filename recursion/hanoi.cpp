#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	void hanoi(int n, string frome, string mid, string to) {
		if(n <= 0)
			return;
		if(n == 1)
			cout<<frome<<" through "<<mid<<" to "<<to<<endl;
		else
		{
			hanoi(n-1, frome, to, mid);
			hanoi(1, frome, mid, to);
			hanoi(n-1, mid, frome, to);
		}
	
		return;
	}
};

int main()
{
	string a("from");
	string b("midl");
	string c("too");
	
	Solution S;
	int n = 0;
	while(cin>>n)
	{
		S.hanoi(n, a, b, c);
	}

	return 0;
}
