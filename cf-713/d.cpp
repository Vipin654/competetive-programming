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
		int j,arr[n+2];
		for(j=0;j<n+2;j++)
		  cin>>arr[j];
		multiset<int> st;
		for(j=0;j<n+2;j++)
		  st.insert(arr[j]);
		sort(arr,arr+n+2);
		int sum=0;
		for(int x:st)
		  sum+=x;
		int x=-1;
		//bool result=false;
		for(j=n;j<=n+1;j++)
		{
			int left=sum-arr[j];
			int rem=left-arr[j];
			auto it=st.find(rem);
			if(it!=st.end())
			{
				if(*it==arr[j])
				{
					if(st.count(arr[j])==1)
					{
						
					}
					else
					{
						x=*it;
						break;
					}
				}
				else
				{
					x=*it;
					break;
				}
			}
		}
		if(x==-1)
		  cout<<-1<<endl;
		else
		{
			auto it=st.find(x);
			st.erase(it);
			int val=*st.rbegin();
			it=st.find(val);
			st.erase(it);
			for(int y:st)
			  cout<<y<<" ";
			cout<<endl;
		}
	}
}

