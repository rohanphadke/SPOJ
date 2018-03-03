#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[10001];
bool vis[10001];

int main() {
	int n;

	// populate graph
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// check graph

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<v[i].size();j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	// bfs from random node 1 to find node furthest from 1
	queue< pair<int,int> > q;
	q.push(make_pair(1,0));
	int maxdist=0;
	int maxdistvert=-1;
	for(int i=0;i<=n;i++){
		vis[i]=false;
	}
	while(!q.empty()){
		pair<int,int> vert = q.front();
		q.pop();
		// cout<<"at vert "<<vert.first<<" at dist "<<vert.second<<endl;
		vis[vert.first]=true;
		for(int i=0;i<v[vert.first].size();i++){
			if(!vis[v[vert.first][i]]){
				q.push(make_pair(v[vert.first][i],vert.second+1));
				if(vert.second+1>maxdist){
					maxdist=vert.second+1;
					maxdistvert=v[vert.first][i];
				}
			}
		}
	}

	// set visited to false for all nodes
	for(int i=0;i<=n;i++){
		vis[i]=false;
	}

	// bfs from the farthest node from 1, to find the end point of longest path from that node
	q.push(make_pair(maxdistvert,0));
	maxdist=0;
	maxdistvert=-1;
	
	// cout<<"starting second bfs"<<endl;
	while(!q.empty()){
		pair<int,int> vert = q.front();
		q.pop();
		// cout<<"at vert "<<vert.first<<" at dist "<<vert.second<<endl;
		vis[vert.first]=true;
		for(int i=0;i<v[vert.first].size();i++){
			if(!vis[v[vert.first][i]]){
				q.push(make_pair(v[vert.first][i],vert.second+1));
				if(vert.second+1>maxdist){
					maxdist=vert.second+1;
					maxdistvert=v[vert.first][i];
				}
			}
		}
	}
	cout<<maxdist<<endl;
	return 0;
}
