void update(int tree[],int start,int end,int point,int val,int index)
{
	if(point>end||point<start)
	   return ;
	if(start==end)
	{
		tree[index]+=val;
		tree[index]%=mod; // take care of mod
	}
	else
	{
		int mid=(start+end)/2;
		update(tree,start,mid,point,val,2*index);
		update(tree,mid+1,end,point,val,2*index+1);
		tree[index]=(tree[2*index]+tree[2*index+1])%mod;   // take care of mod
	}
}
int sum_query(int tree[],int start,int end,int left,int right,int index)
{
	if(left>end||start>right)
	  return 0;
	else if(start>=left&&end<=right)
	  return tree[index];
	else
	{
		int mid=(start+end)/2;
		int x=sum_query(tree,start,mid,left,right,2*index);
		int y=sum_query(tree,mid+1,end,left,right,2*index+1);
		return (x+y)%mod;  // take care of mod
	}
}
