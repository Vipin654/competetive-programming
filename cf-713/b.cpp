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
		int mincol=1000000;
		int maxcol=-1;
		int minrow=1000000;
		int maxrow=-1;
		int n;
		cin>>n;
		char mat[n][n];
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			  cin>>mat[i][j];
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mat[i][j]=='*')
				{
					minrow=min(minrow,i);
					maxrow=max(maxrow,i);
					mincol=min(mincol,j);
					maxcol=max(maxcol,j);
				}
			}
		}
		if(minrow==maxrow)
		{
			if(minrow+1<n)
			{
				maxrow++;
			}
			else
			  minrow--;
		}
		else if(mincol==maxcol)
		{
			if(mincol+1<n)
			  maxcol++;
			else
			  mincol--;
		}
		mat[minrow][mincol]='*';
		mat[minrow][maxcol]='*';
		mat[maxrow][mincol]='*';
		mat[maxrow][maxcol]='*';
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<mat[i][j];
			}
			cout<<endl;
		}
	}
}

