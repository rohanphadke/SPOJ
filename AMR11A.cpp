#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
 
int min(int a,int b){
	return (a<b)?a:b;
}

int main(){
	int t;
	scanf("%d",&t);
	int r,c,i,j;
	while(t--){
		scanf("%d %d",&r,&c);

		int arr[r+1][c+1];
		for(i=0;i<r;i++){
			arr[i][0]=0;
		}
		for(i=0;i<c;i++){
			arr[0][i]=0;
		}
		for(i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				arr[i][j]=ctoi();
			}
		}
		arr[r][c]=1;
		for(j=c-1;j>0;j--){
			arr[r][j]=arr[r][j+1]-arr[r][j];
			if(arr[r][j]<1) arr[r][j]=1;
		}
		for(i=r-1;i>0;i--){
			arr[i][c]=arr[i+1][c]-arr[i][c];
			if(arr[i][c]<1) arr[i][c]=1;
		}
		for(i=r-1;i>0;i--){
			for(j=c-1;j>0;j--){
				arr[i][j]=min(arr[i+1][j],arr[i][j+1])-arr[i][j];
				if(arr[i][j]<1) arr[i][j]=1;
			}
		}
		printf("%d\n",arr[1][1]);
	}
	return 0;
}