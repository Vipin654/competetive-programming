#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
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
		int n,c;
		cin>>n>>c;
		int j,arr[n],arr2[n-1];
		for(j=0;j<n;j++)
		   cin>>arr[j];
		for(j=0;j<n-1;j++)
		  cin>>arr2[j];
		int value[n]={0};
		int prev[n]={0};
	    int answer[n];
	    answer[0]=(c+arr[0]-1)/arr[0];
	    int days=(arr2[0]+arr[0]-1)/(arr[0]);
	    int next=(arr[0]*days-arr2[0]);
	    prev[0]=days+1;
	    value[0]=next;
	    for(j=1;j<n;j++)
	    {
			int left=c-value[j-1];
			if(left<=0)
			  answer[j]=0;
			else
			  answer[j]=(left+arr[j]-1)/(arr[j]);
			answer[j]+=prev[j-1];
			days=(arr2[j]-value[j-1]+arr[j]-1)/arr[j];
			prev[j]=days+1+prev[j-1];
			next=(arr[j]*days-(arr2[j]-value[j-1]));
			value[j]=next;
		}
		int final=answer[0];
		for(j=1;j<n;j++)
		  final=min(final,answer[j]);
		cout<<final<<endl;
	}
}

