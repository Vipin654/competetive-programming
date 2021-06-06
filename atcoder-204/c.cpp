#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#define int long long int
#define function function2
void dfs(int src,vector<int> adj[],bool visited[],set<int> &st)
{
	if(visited[src])
	   return ;
	else
	{
		st.insert(src);
		visited[src]=true;
		for(int x:adj[src])
		  dfs(x,adj,visited,st);
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	int answer=0;
	vector<int> adj[n+1];
	int j;
	for(j=0;j<m;j++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(j=1;j<=n;j++)
	{
		bool visited[n+1]={false};
		set<int> st;
		dfs(j,adj,visited,st);
		answer+=(int)(st.size());
	}
	cout<<answer<<endl;
}
