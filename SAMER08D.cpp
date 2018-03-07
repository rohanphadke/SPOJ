#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0)	break;
		char a[1005],b[1005];
		int dp[1005][1005],lencs[1005][1005];

		// initial read and assign
		scanf("%s",a);
		scanf("%s",b);
		int sa=strlen(a);
		int sb=strlen(b);
		lencs[0][0]=0;
		for(int i=0;i<1005;i++){
			dp[i][0] = 0;
			dp[0][i] = 0;
		}
		
		// logic for lcs
		for(int i=1;i<=sa;i++){
			for(int j=1;j<=sb;j++){
				
				// max of 2 instead of 3 - 3rd has modification
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				
				// keep count of longest segment ending at indices i and j for strings a and b
				if(a[i-1]==b[j-1]){
					lencs[i][j]=lencs[i-1][j-1]+1;
				}else{
					lencs[i][j]=0;
				}

				// if longest segment is of length greater than k, only then update
				if(lencs[i][j]>=n){
					for(int k=n;k<=lencs[i][j];k++){
						dp[i][j]=max(dp[i][j],dp[i-k][j-k]+k);
					}
				}
			}
		}
		cout<<dp[sa][sb]<<endl;
	}
	return 0;
}