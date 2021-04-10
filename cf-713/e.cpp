#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#define int long long int
int function(set<int> &st,int total)
{
	if(total==0)
	   return 0;
	auto it=st.begin();
	int answer=0;
	while(total!=0)
	{
		total--;
		answer+=*it;
		it++;
	}
	return answer;
}
int function2(set<int> &st,int total)
{
	if(total==0)
	  return 0;
	auto it=st.end();
	it--;
	int answer=0;
	while(total!=0)
	{
		total--;
		answer+=*it;
		it--;
	}
	return answer;
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,l,r,s;
		cin>>n>>l>>r>>s;
		int total=r-l+1;
		int minval=total*(total+1);
		minval/=2;
		int maxval=(((n)*(n+1))/2)-(((n-total)*(n-total+1))/2);
		if(s>maxval||s<minval)
		  cout<<-1<<endl;
		else
		{
			int arr[n+1];
			int j;
			for(j=1;j<=n;j++)
			  arr[j]=-1;
			set<int> st;
			for(j=1;j<=n;j++)
			  st.insert(j);
			for(j=l;j<=r;j++)
			{
				total--;
				set<int> st2=st;
				for(int x:st)
				{
					st2.erase(x);
					int minpossible=function(st2,total);
					int maxpossible=function2(st2,total);
					if(s-x>maxpossible||s-x<minpossible)
					{
						st2.insert(x);
					}
					else
					{
						s-=x;
						arr[j]=x;
						st.erase(x);
						break;
					}
				}
			}
			for(j=1;j<=n;j++)
			{
				if(arr[j]==-1)
				{
					arr[j]=*st.begin();
					st.erase(st.begin());
				}
			}
			for(j=1;j<=n;j++)
			  cout<<arr[j]<<" ";
			cout<<endl;
		}
	}
}

