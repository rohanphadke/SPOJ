#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map< pair<int,int>, int> sqtonum;
map< int, pair<int,int> > numtosq;
vector<int> v[101];
bool vis[101];
int cnt;
bool pt;

int func(int vert){
	// cout<<"in func for "<<vert<<endl;
	vis[vert]=true;
	bool isMovePossible=false;
	int minLeft=99999;
	for(int i=0;i<v[vert].size();i++){
		if(!vis[v[vert][i]]){
			isMovePossible=true;
			minLeft=min(minLeft,func(v[vert][i]));
			// if(pt){
			// 	cout<<"in func for "<<vert<<endl;
			// 	return minLeft;
			// }
		}
	}
	if(!isMovePossible){
		minLeft=0;
		for(int i=1;i<cnt;i++){
			if(!vis[i])	minLeft++;
		}
	}
	// cout<<"Count for "<<vert<<" is "<<minLeft<<endl;
	vis[vert]=false;
	// if(minLeft==3){
	// 	pt=true;
	// 	cout<<"in func for "<<vert<<endl;
	// }
	return minLeft;
}

int main() {
	pt=false;
	int cs=0;
	while(1){
		sqtonum.clear();
		numtosq.clear();
		for(int i=0;i<101;i++){
			vis[i]=false;
		}

		cs++;
		int n;
		scanf("%d",&n);
		if(n==0){
			break;
		}
		int a,b;
		int start[n],end[n];
		cnt=1;
		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			start[i]=a;
			end[i]=a+b-1;
			for(int j=start[i];j<=end[i];j++){
				sqtonum[make_pair(i,j)]=cnt;
				numtosq[cnt]=make_pair(i,j);
				cnt++;
			}
		}

		cout<<" CS = "<<cs<<endl;
		
		if(cs==2){
			for(int i=0;i<n;i++){
				for(int j=start[i];j<=end[i];j++){
					cout<<sqtonum[make_pair(i,j)]<<" ";
				}
				cout<<endl;
			}
		}

		for(int i=1;i<cnt;i++){
			vis[i] = false;
			pair<int,int> p = numtosq[i];
			int x=p.first;
			int y=p.second;
			if(x+2>=0 && x+2<n && y+1>=start[x+2] && y+1<=end[x+2]){			// down 2 right 1
				v[i].push_back(sqtonum[make_pair(x+2,y+1)]);
			}
			if(x+2>=0 && x+2<n && y-1>=start[x+2] && y-1<=end[x+2]){			// down 2 left 1
				v[i].push_back(sqtonum[make_pair(x+2,y-1)]);
			}
			if(x-2>=0 && x-2<n && y+1>=start[x-2] && y+1<=end[x-2]){			// up 2 right 1
				v[i].push_back(sqtonum[make_pair(x-2,y+1)]);
			}
			if(x-2>=0 && x-2<n && y-1>=start[x-2] && y-1<=end[x-2]){			// up 2 left 1
				v[i].push_back(sqtonum[make_pair(x-2,y-1)]);
			}
			if(x+1>=0 && x+1<n && y+2>=start[x+1] && y+2<=end[x+1]){			// down 1 right 2
				v[i].push_back(sqtonum[make_pair(x+1,y+2)]);
			}
			if(x+1>=0 && x+1<n && y-2>=start[x+1] && y-2<=end[x+1]){			// down 1 left 2
				v[i].push_back(sqtonum[make_pair(x+1,y-2)]);
			}
			if(x-1>=0 && x-1<n && y+2>=start[x-1] && y+2<=end[x-1]){			// up 1 right 2
				v[i].push_back(sqtonum[make_pair(x-1,y+2)]);
			}
			if(x-1>=0 && x-1<n && y-2>=start[x-1] && y-2<=end[x-1]){			// up 1 left 2
				v[i].push_back(sqtonum[make_pair(x-1,y-2)]);
			}
		}

		// for(int i=1;i<cnt;i++){
		// 	for(int j=0;j<v[i].size();j++){
		// 		cout<<v[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		cout<<func(1)<<endl;
	}
	return 0;
}
