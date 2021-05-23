#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define int long long int
#define mod 1000000007
int function(string &str,int initial,int final,int status,int k,int memo[][2])
{
	if(initial>final)
	{
		if(status==0)
		{
			string str2="";
			int n=str.size();
			int i;
			for(i=0;i<=final;i++)
			  str2.insert(str2.size(),1,str[i]);
			for(i=final+1;i<n;i++)
			{
				str2.insert(str2.size(),1,str2[n-i-1]);
			}
			if(str2<str)
			  return 1;
			return 0;
		}
		return 1;
	}
	if(memo[initial][status]!=-1)
	  return memo[initial][status];
	else
	{
		if(status==1)
		{
			int answer=k*function(str,initial+1,final,1,k,memo);
			answer%=mod;
			memo[initial][status]=answer;
			return answer;
		}
		else
		{
			int pos=str[initial]-96;
			int answer=(pos-1)*function(str,initial+1,final,1,k,memo);
			answer+=function(str,initial+1,final,0,k,memo);
			answer%=mod;
			memo[initial][status]=answer;
			return answer;
		}
	}
}
int32_t main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cout<<"Case #"<<T<<": ";
		int n,k;
		cin>>n>>k;
		string str;
		cin>>str;
		int memo[n+1][2];
		int i,j;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<2;j++)
			{
				memo[i][j]=-1;
			}
		}
		int answer=function(str,0,((n+1)/2)-1,0,k,memo);
		cout<<answer<<endl;
	}
}
