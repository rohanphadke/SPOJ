#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
	while(1){
		int n,m;
		scanf("%d",&n);
		if(n==0)	break;
		scanf("%d",&m);
		
		double prob[101][101];
		for(int i=0;i<101;i++){
			for(int j=0;j<101;j++){
				prob[i][j]=0;
			}
		}

		int a,b,p;
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&a,&b,&p);
			prob[a][b] = prob[b][a] = (double)p/(double)100;
		}

		// floyd warshall
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					prob[i][j] = max(prob[i][j],prob[i][k]*prob[k][j]);
				}
			}
		}
		printf("%.6lf percent\n",prob[1][n]*100);
	}
	return 0;
}