#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long int
#define mod 1000000007
void dfs(int src,vector<pair<int,int>> adj[],int p,int val,int dp[])
{
	dp[src]=val;
	for(auto pp:adj[src])
	{
		if(pp.first!=p)
		{
			int x=pp.first;
			int w=pp.second;
			dfs(x,adj,src,val^w,dp);
		}
	}
}
int32_t main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int power[60];
	power[0]=1;
	int j;
	for(j=1;j<=59;j++)
	{
		power[j]=2*power[j-1];
	}
	int n;
	cin>>n;
	vector<pair<int,int>> adj[n+1];
	for(j=0;j<n-1;j++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int dp[n+1]={0};
	dfs(1,adj,-1,0,dp);
	int count[60]={0};
	for(j=1;j<=n;j++)
	{
		int val=dp[j];
		int i;
		for(i=59;i>=0;i--)
		{
			if(val>=power[i])
			{
				count[i]++;
				val-=power[i];
			}
		}
	}
	int answer=0;
	int i;
	for(i=0;i<=59;i++)
	{
		int ones=count[i];
		int zeros=n-count[i];
		int here=ones*zeros;
		here%=mod;
		int here2=power[i];
		here2%=mod;
		here*=here2;
		here%=mod;
		answer+=here;
		answer%=mod;
	}
	cout<<answer<<endl;
}
