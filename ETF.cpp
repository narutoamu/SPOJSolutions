#include <iostream>

using namespace std;


int ETF(int n)
{
	float ans = n;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
			ans -= ans/i;
		while (n%i == 0)
			n /= i;
	}
	if (n > 1)
		ans -= ans/n;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		if (n < 3)
			cout<<1<<endl;
		else
			cout<<ETF(n)<<endl;
	}
	
	return 0;
}