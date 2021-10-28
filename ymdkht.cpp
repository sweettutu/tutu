#include <iostream>
using namespace std;
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	int t,m,n,dp[26][301]={0},i,a[25],b[25],r,sum=0;
	cin>>m>>n;
	m=m/100;
	for(i=1;i<n+1;i++)
	{
		cin>>a[i]>>b[i];
		b[i]=a[i]*b[i];
		a[i]=a[i]/100;
	}
	for(i=1;i<n+1;i++)
	{
		for(r=1;r<n;r++)
		{
			if(a[r]>a[r+1])
			{
				t=b[r];
				b[r]=b[r+1];
				b[r+1]=t;
				t=a[r];
				a[r]=a[r+1];
				a[r+1]=t;
			}
		}
	}
	for(i=1;i<n;i++)
	{
		for(r=1;r<=m;r++)
		{
			if(r<a[i])
			{
				dp[i][r]=dp[i-1][r];
			}
			else
			{
				dp[i][r]=max(dp[i-1][r],dp[i-1][r-a[i]]+b[i]);
			}
		}
	}
	for(i=1;i<n;i++)
	{
		for(r=1;r<=m;r++)
		{
			if(dp[i][r]>sum)
			{
				sum=dp[i][r];
			}
		}
	}
	cout<<sum;
	return 0;
}
