#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
#define int long long int
#define function function2
int n;
int answer=0;
set<int> st;
int power(int a,int b)
{
	int x=pow(a,b);
	return x;
}
void function(int initial,int final,int j,int val)
{
	if(initial>final)
	{
		val=val*pow(10,j)+val;
		if(val<=n)
		{
			st.insert(val);
		}
	}
	else
	{
		if(initial==0)
		{
			int i;
			for(i=1;i<=9;i++)
			{
				function(initial+1,final,j,val*10+i);
			}
		}
		else
		{
			int i;
			for(i=0;i<=9;i++)
			{
				function(initial+1,final,j,val*10+i);
			}
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int j=1;j<=6;j++)
	{
		function(0,j-1,j,0);
	}
	cout<<st.size()<<endl;
}
