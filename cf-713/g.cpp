#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#define int long long int
int answer[10000001]={0};
int divisor[10000001]={0};
void function()
{
	for(int j=0;j<=10000000;j++)
	  answer[j]=10000001;
	for(int i=1;i<=10000000;i++)
	{
		for(int j=1;i*j<=10000000;j++)
		{
			divisor[i*j]+=i;
		}
	}
	for(int j=1;j<=10000000;j++)
	{
		int val=divisor[j];
		if(val>10000000)
		   continue;
		answer[val]=min(answer[val],j);
	}
}
int32_t main()
{
	function();
	int t;
	cin>>t;
	while(t--)
	{
		int c;
		scanf("%lld",&c);
		if(answer[c]==10000001)
		  printf("-1\n");
		else
		  printf("%lld\n",answer[c]);
	}
}

