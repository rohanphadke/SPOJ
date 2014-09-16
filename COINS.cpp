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
long long ctoi(){
	char c;
	while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
	bool flag=(c=='-');
	if(flag)
		c=getchar();
	long long x=0;
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

//The trick here is to use 'map'. Map sotres values of previously computed smaller value coin answers and saves multiple computations of the same value. If the value hasn't been computed, it is set to 0 by default. If the value is not zero, the value has been already calculated. We can't store the precomputed values in an array as the limit (10^9) exceeds the capacity of an array

map<int,long long> dp;

long long f(int n){
    if(n==0) return 0;                            //return 0 if n==0
    if(dp[n]!=0) return dp[n];                    //if value is not zero, return the value as it has been previously computed
    long long temp=f(n/2)+f(n/3)+f(n/4);          //if answer hasn't been previously computed, compute the answer if we go ahead with the exchange
    if(temp>n) dp[n]=temp;                        //if the exchange is indeed profitable, store the value after the exchange as the answer
    else dp[n]=n;                                 //if exchange isn't profitable, don't go ahead with the exchange
    return dp[n];
}

int main(){
    long long n;
    while(~scanf("%lld",&n)){                     //take in input till EOF
        printf("%lld\n",f(n));
    }
    return 0;
}
