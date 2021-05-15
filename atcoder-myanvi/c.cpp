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
	string str;
	cin>>str;
	int i,j,k,l;
	int answer=0;
	for(i=0;i<=9;i++)
	{
		for(j=0;j<=9;j++)
		{
			for(k=0;k<=9;k++)
			{
				for(l=0;l<=9;l++)
				{
					set<int> st;
					st.insert(i);
					st.insert(j);
					st.insert(k);
					st.insert(l);
					int p;
					bool result=true;
					for(p=0;p<=9;p++)
					{
						auto it=st.find(p);
						if(str[p]=='o'&&it==st.end())
						  result=false;
						if(str[p]=='x'&&it!=st.end())
						  result=false;
					}
					if(result)
					  answer++;
				}
			}
		}
	}
	cout<<answer<<endl;
}
