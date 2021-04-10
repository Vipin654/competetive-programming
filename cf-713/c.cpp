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
		int a,b;
		cin>>a>>b;
		string str;
		cin>>str;
		int n=str.size();
		multimap<int,pair<int,int>> mp;
		int j;
		bool result=true;
		for(j=0;j<=n-1-j;j++)
		{
			if(str[j]=='?'&&str[n-1-j]=='?')
			{
				if(j==n-1-j)
				{
					mp.insert({1,{j,n-1-j}});
				}
				else
				  mp.insert({2,{j,n-1-j}});
			}
			else if(str[j]!='?'&&str[n-1-j]!='?')
			{
				if(str[j]!=str[n-1-j])
				   result=false;
			}
			else
			{
				if(str[j]!='?')
				  str[n-1-j]=str[j];
				else
				  str[j]=str[n-1-j];
			}
		}
		if(!result)
		{
			cout<<-1<<endl;
			continue;
		}
		for(char x:str)
		{
			if(x=='0')
			  a--;
			if(x=='1')
			  b--;
		}
		if(a<0||b<0)
		{
			cout<<-1<<endl;
			continue;
		}
		while(mp.size()!=0)
		{
			if(a<0||b<0)
			  break;
			if(a==0&&b==0)
			  break;
			if(a>=b)
			{
				auto it=mp.end();
				it--;
				a-=it->first;
				int index1=it->second.first;
				int index2=it->second.second;
				str[index1]='0';
				str[index2]='0';
				mp.erase(it);
			}
			else
			{
				auto it=mp.end();
				it--;
				b-=it->first;
				int index1=it->second.first;
				int index2=it->second.second;
				str[index1]='1';
				str[index2]='1';
				mp.erase(it);
			}
		}
		if(a==0&&b==0)
		  cout<<str<<endl;
		else
		  cout<<-1<<endl;
	}
}

