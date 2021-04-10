#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define int long long int
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int j,arr[n];
		for(j=0;j<n;j++)
		  cin>>arr[j];
		multiset<int> st;
		for(j=0;j<n;j++)
		  st.insert(arr[j]);
		for(j=0;j<n;j++)
		{
			if(st.count(arr[j])==1)
			{
				cout<<j+1<<endl;
				break;
			}
		}
	}
}

