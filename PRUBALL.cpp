#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int problem,balls,floors;
		scanf("%d %d %d",&problem,&balls,&floors);
		int arr[balls+1][floors+1];
		for(int i=0;i<=floors;i++){
			arr[1][i]=i;
			arr[0][i]=99999999;
		}
		for(int i=1;i<=balls;i++){
			arr[i][0]=0;
			arr[i][1]=1;
		}
		arr[0][0]=0;
		for(int i=2;i<=balls;i++){
			for(int j=2;j<=floors;j++){
				arr[i][j]=99999999;
				// check for all prev floors
				for(int k=1;k<=j;k++){
					// if ball breaks and answer is 1+ arr[i-1][k-1] or ball doesnt break and answer is 1+ arr[i][j-k] - only consider siez of interval of floors and not the actual interval
					arr[i][j]=min(arr[i][j],1+max(arr[i-1][k-1],arr[i][j-k]));
				}
			}
		}
		cout<<problem<<" "<<arr[balls][floors]<<endl;
	}
	return 0;
}