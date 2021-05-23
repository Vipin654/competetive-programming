#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
#define int long long int
// count1 for rock
// count2 for scissor
// count3 for paper
double function(int initial,int final,double w,double e,int count1,int count2,int count3,double memo[62][62][62],int turn[62][62][62])
{
	if(initial>final)
	{
		return 0.00000000000;
	}
	if(memo[initial][count1][count2]!=-1)
	  return memo[initial][count1][count2];
	else
	{
		if(initial==1)
		{
			double answer1=(w+e)/3+function(initial+1,final,w,e,count1+1,count2,count3,memo,turn);
			double answer2=(w+e)/3+function(initial+1,final,w,e,count1,count2+1,count3,memo,turn);
			double answer3=(w+e)/3+function(initial+1,final,w,e,count1,count2,count3+1,memo,turn);
			double answer=max(answer1,max(answer2,answer3));
			if(answer==answer1)
			{
				turn[initial][count1][count2]=1;
			}
			else if(answer==answer2)
			{
				turn[initial][count1][count2]=2;
			}
			else
			{
				turn[initial][count1][count2]=3;
			}
			memo[initial][count1][count2]=answer;
			return answer;
		}
		else
		{
			int rock=count1,scissor=count2,paper=initial-1-count1-count2;
			double r=(double)(scissor)/(double)(initial-1);
			double s=(double)(paper)/(double)(initial-1);
			double p=(double)(rock)/(double)(initial-1);
			double answer1=s*w+r*e+function(initial+1,final,w,e,count1+1,count2,count3,memo,turn);
			double answer2=p*w+s*e+function(initial+1,final,w,e,count1,count2+1,count3,memo,turn);
			double answer3=r*w+p*e+function(initial+1,final,w,e,count1,count2,count3+1,memo,turn);
			double answer=max(answer1,max(answer2,answer3));
			if(answer==answer1)
			{
				turn[initial][count1][count2]=1;
			}
			else if(answer==answer2)
			{
				turn[initial][count1][count2]=2;
			}
			else
			{
				turn[initial][count1][count2]=3;
			}
			memo[initial][count1][count2]=answer;
			return answer;
			
		}
	}
}
int32_t main()
{
	int t;
	cin>>t;
	int x;
    cin>>x;
	for(int T=1;T<=t;T++)
	{
		cout<<"Case #"<<T<<": ";
		double w,e;
		cin>>w>>e;
		double memo[62][62][62];
		int turn[62][62][62];
		int i,j,k;
		for(i=0;i<=61;i++)
		{
			for(j=0;j<=61;j++)
			{
				for(k=0;k<=61;k++)
				{
					memo[i][j][k]=-1;
					turn[i][j][k]=-1;
				}
			}
		}
		double answer=function(1,60,w,e,0,0,0,memo,turn);
	//	cout<<answer<<endl;
		int initial=1;
		int final=60;
		int count1=0,count2=0,count3=0;
		string str="";
		while(initial<=final)
		{
			if(turn[initial][count1][count2]==1)
			{
				str.insert(str.size(),1,'R');
				count1++;
				initial++;
			}
			else if(turn[initial][count1][count2]==2)
			{
				str.insert(str.size(),1,'S');
				count2++;
				initial++;
			}
			else
			{
				str.insert(str.size(),1,'P');
				count3++;
				initial++;
			}
		}
		cout<<str<<endl;
	}
}
