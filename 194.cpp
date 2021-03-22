// written by Vipin kumar
#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
#define int long long int
#define function function2
set<vector<vector<int>>> st;
void function(int h,int w,int a,int b,vector<vector<int>> &mat)
{
	if(a==0)
	{
		int i,j;
		vector<vector<int>> mat2=mat;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(mat2[i][j]==-1)
				  mat2[i][j]=5;
			}
		}
		st.insert(mat2);
	}
	else
	{
		int i,j;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(i+1<h)
				{
					if(mat[i][j]==-1&&mat[i+1][j]==-1)
					{
						mat[i][j]=1;
						mat[i+1][j]=2;
						function(h,w,a-1,b,mat);
						mat[i][j]=-1;
						mat[i+1][j]=-1;
					}
				}
				if(j+1<w)
				{
					if(mat[i][j]==-1&&mat[i][j+1]==-1)
					{
						mat[i][j]=3;
						mat[i][j+1]=4;
						function(h,w,a-1,b,mat);
						mat[i][j]=-1;
						mat[i][j+1]=-1;
					}
				}
			}
		}
	}
}
int32_t main()
{
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	vector<vector<int>> mat2(h+1,vector<int>(w+1,-1));
	function(h,w,a,b,mat2);
	cout<<st.size()<<endl;
}
