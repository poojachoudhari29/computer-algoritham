#include<stdio.h>

int binarysearch(int arr[],int low,int high,int search)
{
	if(low==high)
	{
		if(search==arr[low])
		{
			return low;
		}
		else
		{
			return 0;
		}
	}
	int mid;
	mid=(low+high)/2;
	if(search<mid)
	{
		binarysearch(arr,low,mid-1,search);
	}
	else
	{
		binarysearch(arr,mid+1,high,search);
	}
		
}

int main()
{
	int i,n,result,search,low,high;
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	
	int arr[n];
	printf("\nEnter the elements of array:");
	for(i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	low=0,high=n-1;
	printf("\nEnter search value :");
	scanf("%d",search);
	
	result=binarysearch(arr,low,high,search);
	if(result!=0)
	{
		printf("\n%d element is found at %d ",search,result);
	}
	else
	{
		printf("\n%d element is not found",search);
	}	
}
