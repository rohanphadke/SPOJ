#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

bool customSort(pair<int,int> a, pair<int,int> b){
	if(a.first < b.first)	return true;
	return false;
}

bool canend(int endindex, int length, int anchor, int prevanchor, int n){
	if(endindex-length+1<=anchor && endindex-length+1>prevanchor)	return true;		// anchor must lite within boat span, and boat cannot overlap with anchor of previous boat (or index -1 for the 0th boat)
	return false;
}

int main(){

	//read data
	int n;
	scanf("%d",&n);
	int arr[n];
	long long sum[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(i==0)	sum[i]=arr[i];
		else	sum[i]=sum[i-1]+(long long)arr[i];
	}
	int bn;
	scanf("%d",&bn);
	int temp1,temp2;
	
	vector< pair<int,int> > v;
	for(int i=0;i<bn;i++){
		scanf("%d %d",&temp1,&temp2);
		v.push_back(make_pair(temp1-1,temp2));
	}

	// sort boat data in ascending order of anchors
	sort(v.begin(),v.end(),customSort);

	int dp[n];
	int index=0;
	
	// O(n) solution
	for(int i=0;i<n;i++){
		if(v[index].first==i)	index++;			// if anchor location, increment index
		if(index==0){				// no boat anchor crossed yet
			dp[i]=0;
		}else{
			int anchor = v[index-1].first;
			int length = v[index-1].second;
			int startindex = i-length+1;
			if(index==1){							// if (index-1)th boat can end at current location
				if(canend(i,length,anchor,-1,n)){
					dp[i]=sum[i]-sum[startindex]+arr[startindex];
					if(i>0)	dp[i]=max(dp[i],dp[i-1]);
				}else{
					dp[i]=dp[i-1];
				}
			}else{
				int prevanchor = v[index-2].first;
				if(canend(i,length,anchor,prevanchor,n)){
					dp[i]=sum[i]-sum[startindex]+arr[startindex];
					dp[i]+=dp[startindex-1];
					dp[i]=max(dp[i],dp[i-1]);
				}else{
					dp[i]=dp[i-1];
				}
			}
		}
		// cout<<dp[i]<<endl;
	}
	cout<<dp[n-1]<<endl;
	return 0;
} 
