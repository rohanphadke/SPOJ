#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int val[101][101];

bool vis[101][101];

int main() {
	int m,n;
	scanf("%d %d", &n,&m);
	char str[m][n];
	int startx=-1,starty=-1,endx=-1,endy=-1;
	
	// populate graph and cow positions

	for(int i=0;i<m;i++){
		scanf("%s",str[i]);
		// cout<<str[i]<<endl;
		for(int j=0;j<n;j++){
			if(str[i][j]=='C'){
				if(startx==-1){
					startx=i;
					starty=j;
				}else{
					endx=i;
					endy=j;
				}
			}
		}
	}
	val[startx][starty]=0;

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			val[i][j]=999999;
			vis[i][j]=false;
		}
	}

	queue< pair<int,int> > q;
	q.push(make_pair(startx, starty));
	val[startx][starty]=-1;
	while(!q.empty()){
		pair<int,int> spot=q.front();
		q.pop();
		if(vis[spot.first][spot.second])	continue;

		vis[spot.first][spot.second]=true;
		// cout<<"------------------------"<<endl;
		// for(int i=0;i<m;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout<<val[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<"------------------------"<<endl;
		for(int i=spot.first-1;i>=0;i--){
			if(str[i][spot.second]=='*'){
				break;
			}
			val[i][spot.second]=min(val[i][spot.second],val[spot.first][spot.second]+1);
			if(!vis[i][spot.second])	q.push(make_pair(i,spot.second));
		}
		for(int i=spot.first+1;i<m;i++){
			if(str[i][spot.second]=='*'){
				break;
			}
			val[i][spot.second]=min(val[i][spot.second],val[spot.first][spot.second]+1);
			if(!vis[i][spot.second])	q.push(make_pair(i,spot.second));
		}
		for(int i=spot.second-1;i>=0;i--){
			if(str[spot.first][i]=='*'){
				break;
			}
			val[spot.first][i]=min(val[spot.first][i],val[spot.first][spot.second]+1);
			if(!vis[spot.first][i])	q.push(make_pair(spot.first,i));
		}
		for(int i=spot.second+1;i<n;i++){
			if(str[spot.first][i]=='*'){
				break;
			}
			val[spot.first][i]=min(val[spot.first][i],val[spot.first][spot.second]+1);
			if(!vis[spot.first][i])	q.push(make_pair(spot.first,i));
		}
	}
	// cout<<endx<<" "<<endy<<endl;
	cout<<val[endx][endy]<<endl;
	return 0;
}
