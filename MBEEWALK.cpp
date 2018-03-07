#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[15][17][17]={0};

int main(){
	dp[0][8][8]=1;
	for(int i=1;i<15;i++){
		for(int j=1;j<17;j++){
			for(int k=1;k<17;k++){
				dp[i][j][k]=dp[i-1][j][k+1]+dp[i-1][j][k-1]+dp[i-1][j+1][k]+dp[i-1][j-1][k]+dp[i-1][j+1][k+1]+dp[i-1][j-1][k-1];
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		cout<<dp[n][8][8]<<endl;
	}
	return 0;
}