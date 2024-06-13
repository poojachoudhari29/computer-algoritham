#include<stdio.h>

void knapsack(int n,float weight[],float profit[],float capacity)
{
	float x[20],tp=0;
	int i,j,u;
	u=capacity;
	
	for(i=0;i<n;i++)
	{
		x[i]=0.0;
	}
	
	for(i=0;i<n;i++)
	{
		if(weight[i]>u)
			break;
		else
		{
			x[i]=1.0;
			tp=tp+profit[i];
			u=u-weight[i];
		}
	}
	if(i<n)
	x[i]=u/weight[i];
	tp=tp+(x[i]*profit[i]);
	
	printf("\nThe result is:");
	for(i=0;i<n;i++)
	{
		printf("%f\t",x[i]);
		}	
	printf("\nMaximum profit is:%f",tp);
		
}

int  main()
{
	float profit[20],weight[20],capacity;
	int i,j,num;
	float ratio[20],temp;
	
	printf("\nEnter the size of array:");
	scanf("%d",&num);
	
	printf("\nEnter the profit and weight:");
	for(i=0;i<num;i++)
	{
		scanf("%f  %f",&profit[i],&weight[i]);
	}
	
	printf("\nenter the capacity of sack:");
	scanf("%f",&capacity);
	
	for(i=0;i<num;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
	
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];
				ratio[j]=ratio[i];
				ratio[i]=temp;
				
				temp=profit[j];
				profit[j]=profit[i];
				profit[i]=temp;
				
				temp=weight[j];
				weight[j]=weight[i];
				weight[i]=temp;
			}
		}
	}
	
	knapsack(num,weight,profit,capacity);
	return 0;
}