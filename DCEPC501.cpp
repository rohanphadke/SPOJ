#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		if(n<=3){
			int sum=0;
			for(int i=0;i<n;i++){
				sum+=arr[i];
			}
			cout<<sum<<endl;
		}else{
			long long dp[n];
			dp[n-1]=arr[n-1];
			dp[n-2]=arr[n-1]+arr[n-2];
			dp[n-3]=arr[n-1]+arr[n-2]+arr[n-3];
			for(int i=n-4;i>=0;i--){
				long long a=arr[i]+dp[i+2];
				long long b=arr[i]+arr[i+1];
				if(i+4<n)	b+=dp[i+4];
				long long c=arr[i]+arr[i+1]+arr[i+2];
				if(i+6<n)	c+=dp[i+6];
				dp[i]=max(a,max(b,c));
			}
			cout<<dp[0]<<endl;
		}
	}
	return 0;
}