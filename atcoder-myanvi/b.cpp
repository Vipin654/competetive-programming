#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long int
int32_t main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	map<int,string> mp;
	int j;
	for(j=0;j<n;j++)
	{
		string str;
		int x;
		cin>>str>>x;
		mp.insert({x,str});
	}
	auto it=mp.end();
	it--;
	it--;
	cout<<it->second<<endl;
}
