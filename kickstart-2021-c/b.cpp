#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
#define int long long int
int32_t main()
{
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		cout<<"Case #"<<T<<": ";
		int g;
		cin>>g;
		int p;
		set<int> st;
		for(p=1;p*p<=2*g;p++)
		{
			if((2*g)%p==0)
			{
				int q=(2*g)/p;
				if((q-p+1)>0&&(q-p+1)%2==0)
				{
					int val=(q-p+1)/2;
					if(val>=1)
					  st.insert(val);
				}
				if((p-q+1)>0&&(p-q+1)%2==0)
				{
					int val=(p-q+1)/2;
					if(val>=1)
					  st.insert(val);
				}
			}
		}
		cout<<st.size()<<endl;
	}
}
