#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define function function2
int mat[2001][2001];
int memo[2001][2001][2];
int function(int i,int j,int x,int y,int status)
{
	if(i==x&&j==y)
	  return 0;
	if(memo[i][j][status]!=-1000000000)
	  return memo[i][j][status];
	else
	{
		if(status==0)
		{
			int answer=-1000000000;
			if(i+1<=x)
			{
				int val1=mat[i+1][j]+function(i+1,j,x,y,1);
				answer=max(answer,val1);
			}
			if(j+1<=y)
			{
				int val1=mat[i][j+1]+function(i,j+1,x,y,1);
				answer=max(answer,val1);
			}
			memo[i][j][status]=answer;
			return answer;
		}
		else 
		{
			int answer=1000000000;
			if(i+1<=x)
			{
				int val1=-mat[i+1][j]+function(i+1,j,x,y,0);
				answer=min(answer,val1);
			}
			if(j+1<=y)
			{
				int val1=-mat[i][j+1]+function(i,j+1,x,y,0);
				answer=min(answer,val1);
			}
			memo[i][j][status]=answer;
			return answer;
		}
	}
}
int32_t main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h,w;
	cin>>h>>w;
	int i,j;
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			char x;
			cin>>x;
			if(x=='+')
			  mat[i][j]=1;
			else
			  mat[i][j]=-1;
		}
	}
	int k;
	for(i=0;i<=h;i++)
	{
		for(j=0;j<=w;j++)
		{
			for(k=0;k<2;k++)
			  memo[i][j][k]=-1000000000;
		}
	}
	int answer=function(0,0,h-1,w-1,0);
	if(answer>0)
	{
		cout<<"Takahashi"<<endl;
	}
	else if(answer<0)
	{
		cout<<"Aoki"<<endl;
	}
	else
	  cout<<"Draw"<<endl;
	
}
