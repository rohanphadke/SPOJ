#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector< vector<int> > v(100);		// normal graph
vector< vector<int> > u(100);		// reverse graph

vector<int> order;					// top sort order
bool visv[100];						// visited for normal graph
bool visu[100];						// visited for reverse graph

void dfsv(int i){
	visv[i]=true;
	for(int j=0;j<v[i].size();j++){
		if(!visv[v[i][j]])	dfsv(v[i][j]);
	}
	order.push_back(i);
}

void dfsu(int i){
	visu[i]=true;
	for(int j=0;j<u[i].size();j++){
		if(!visu[u[i][j]])	dfsu(u[i][j]);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		char str[n][n];
		
		// init
		order.clear();
		for(int i=0;i<n;i++){
			v[i].clear();
			u[i].clear();
			visv[i]=false;
			visu[i]=false;
		}

		// input
		for(int i=0;i<n;i++){
			scanf("%s",str[i]);
			for(int j=0;j<n;j++){
				if(str[i][j]=='Y'){
					v[i].push_back(j);
					u[j].push_back(i);
				}
			}
		}

		// one round of dfs for top sort
		for(int i=0;i<n;i++){
			if(!visv[i])	dfsv(i);
		}

		// second round of dfs to find SCC
		int grps = 0;
		for(int i=n-1;i>=0;i--){
			if(!visu[order[i]]){
				grps++;
				dfsu(order[i]);
			}
		}
		cout<<grps<<endl;
	}
	return 0;
}