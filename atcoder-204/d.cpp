#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#define int long long int
#define function function2
int total=0;
int function(int arr[],int initial,int final,int memo[][100001],int sum)
{
	if(initial>final)
	{
		return max(total-sum,sum);
	}
	if(memo[initial][sum]!=-1)
	   return memo[initial][sum];
	else
	{
		int answer=function(arr,initial+1,final,memo,sum);
		int answer2=function(arr,initial+1,final,memo,sum+arr[initial]);
		answer=min(answer,answer2);
		memo[initial][sum]=answer;
		return answer;
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int j,arr[n];
	for(j=0;j<n;j++)
	{
		cin>>arr[j];
		total+=arr[j];
	}
	int sum=0;
	int memo[n+1][100001];
	int i;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=100000;j++)
		{
			memo[i][j]=-1;
		}
	}
	int answer=function(arr,0,n-1,memo,sum);
	cout<<answer<<endl;
}
