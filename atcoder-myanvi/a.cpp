#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long int
int32_t main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	n=3;
	int j,arr[n];
	for(j=0;j<n;j++)
	  cin>>arr[j];
	sort(arr,arr+n);
	if(arr[1]-arr[0]==arr[2]-arr[1])
	{
		cout<<"Yes"<<endl;
	}
	else
	  cout<<"No"<<endl;
}
