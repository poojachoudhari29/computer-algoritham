#include<iostream>
using namespace std;
int a[100];
int minn,maxx;

void MinMaxAlgo(int x,int y)
{
	int min1,max1;
	if(x==y)
	{
		minn=maxx=a[x];
	}
	else if(x==y-1)
	{
		if(a[x]<a[y])
		{
			maxx=a[y];
			minn=a[x];
		}
		else
		{
			maxx=a[x];
			minn=a[y];
		}	
	}
	else
	{
		int mid;
		mid=(x+y)/2;
		MinMaxAlgo(x,mid);
		max1=maxx;
		min1=minn;
		MinMaxAlgo(mid+1,y);
		if(max1>maxx)
		{
			maxx=max1;
		}
		else
		{
			minn=min1;
		}
	}
}

int main()
{
	int n,i;
	cout<<"\nenter the size of array: ";
	cin>>n;
	
	cout<<"\nenter the elements of array:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	minn=a[0];
	maxx=a[0];
	MinMaxAlgo(0,n-1);
	
	cout<<"\nthe max element in array:"<<maxx<<endl;
	cout<<"\nthe min element in array:"<<minn<<endl;
	return 0;
}