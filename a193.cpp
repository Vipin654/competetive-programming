#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#define int long long int
#define function function2
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		map<int,set<int>> mp;
		int answer=0;
		int r,c;
		cin>>r>>c;
		int mat[r][c];
		int i,j;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>mat[i][j];
			}
		}
		bool visited[r*c]={false};
		int arr[r*c];
		int count=0;
		int value[r][c];
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				arr[count]=mat[i][j];
				value[i][j]=count;
				count++;
			}
		}
		vector<int> adj[r*c];
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(i+1<r)
				{
					int u=value[i][j],v=value[i+1][j];
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
				if(j+1<c)
				{
					int u=value[i][j],v=value[i][j+1];
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
		}
		for(j=0;j<r*c;j++)
		{
			mp[arr[j]].insert(j);
		}
		auto it=mp.end();
		it--;
		queue<int> q;
		for(int x:it->second)
		  q.push(x);
		for(int x:it->second)
		{
			visited[x]=true;
		}
		mp.erase(it);
		while(!q.empty()&&mp.size()!=0)
		{
			int x=q.front();
			q.pop();
			for(int y:adj[x])
			{
				if(!visited[y])
				{
					visited[y]=true;
					if(arr[y]<arr[x]-1)
					{
						answer+=(arr[x]-1-arr[y]);
						mp[arr[y]].erase(y);
						if(mp[arr[y]].size()==0)
						  mp.erase(arr[y]);
						arr[y]=arr[x]-1;
						mp[arr[y]].insert(y);
					}
				}
			}
			if(mp.size()==0)
				  break;
			it=mp.end();
			it--;
			for(int x:it->second)
			{
				visited[x]=true;
			}
			for(int x:it->second)
			  q.push(x);
			mp.erase(it);
		}
		cout<<"Case #"<<T<<": "<<answer<<endl;
	}
}
