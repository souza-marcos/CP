#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
using namespace std;



#define N 200010

LL a[N],b[N],sum[N];
LL dp[N];
LL ans;
int n,m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			sum[i]=sum[i-1]+b[i];
		}
		sum[n+1]=sum[n];
		int id=n+1;
		for(int j=n;j>=1;j--)
		{
			dp[j]=dp[id]+sum[id-1]-sum[j]+a[j];
//			cout<<"dp "<<j<<" is from "<<id<<",cost"<<dp[j]<<endl;
			if(sum[j-1]+dp[j]<sum[id-1]+dp[id]) id=j;
		}
		ans=1234567890123456ll;
		for(int i=1;i<=m;i++)
		{
			if(dp[i]<ans) ans=dp[i];
		}
		cout<<ans<<endl;


		for(int i=1;i<=n+5;i++) a[i]=b[i]=sum[i]=dp[i]=0;
	}
	return 0;
}