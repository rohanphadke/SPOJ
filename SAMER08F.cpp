#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define gc getchar
#define MOD 100000007
#define pc(x) putchar(x);
#define pi(n) printf("%d",n)
#define pll(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define INV 333333336
#define ll long long
#define EPS 1e-9
#define infi 2000000000

//fast input
int ctoi(){
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
	bool flag=(c=='-');
	if(flag)
		c=getchar();
	int x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-48;
		c=getchar();
    }
	return flag?-x:x;
}

//fast output
inline void wi(int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

//Find formula manually using brute force approach and precompute.

int main(){
    long long ans[105];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=100;i++){
        ans[i]=ans[i-1]+i*i;          //answer for i is sum of squares of all integers from 1 till i
    }
    while(1){
        int t=ctoi();
        if(t==0) break;
        printf("%lld\n",ans[t]);
    }
    return 0;
}
