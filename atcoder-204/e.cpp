#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#define int long long int
#define function function2
int function(int start,int end,int val)
{
    if(start>end)
       return -1;
    else
    {
		int mid=(start+end)/2;
		if(mid*mid<=val)
		{
			int x=mid;
			int y=function(mid+1,end,val);
			if(y==-1)
			   return x;
			else
			   return y;
		}
		else
		  return function(start,mid-1,val);
	}	
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> adj[n+1];
	int j;
	int arr[m+1][2];
	for(j=1;j<=m;j++)
	{
		int u,v;
		cin>>u>>v;
		int c,d;
		cin>>c>>d;
		arr[j][0]=c;
		arr[j][1]=d;
		adj[u].push_back({v,j});
		adj[v].push_back({u,j});
	}
	int dist[n+1];
	for(j=1;j<=n;j++)
	{
		dist[j]=1000000000000000000;
	}
	dist[1]=0;
	map<int,int> mp;
	map<int,set<int>> mp2;
	for(j=1;j<=n;j++)
	{
		mp.insert({j,dist[j]});
	}
	for(j=1;j<=n;j++)
	{
		mp2[dist[j]].insert(j);
	}
	while(mp.size()!=0)
	{
		auto it=mp2.begin();
		int src=*(it->second.begin());
		for(auto pp:adj[src])
		{
			int x=pp.first,road=pp.second;
			int c=arr[road][0],d=arr[road][1];
			int t=function(0,100000000,d);
			int minval=1000000000000000000;
			for(j=max(0LL,t-10);j<=t+10;j++)
			{
				int wait=max(0LL,j-dist[src]);
				int here=c+(d/(dist[src]+wait+1));
				minval=min(minval,dist[src]+wait+here);
			}
			if(dist[x]>minval)
			{
				mp2[dist[x]].erase(x);
				if(mp2[dist[x]].size()==0)
				   mp2.erase(dist[x]);
				mp2[minval].insert(x);
				dist[x]=minval;
				mp[x]=minval;
			}
		}
		mp.erase(src);
		it->second.erase(src);
		if(it->second.size()==0)
		  mp2.erase(it);
	}
	if(dist[n]==1000000000000000000)
	{
		cout<<-1<<endl;
	}
	else
	   cout<<dist[n]<<endl;
	
}
