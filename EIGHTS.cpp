#include <iostream>
#include<stack>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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

//Find the expansion of (1000*a + 100*b + 10*c + d)^3 where a,b,c,d are digits from 0 to 9. Equate the units, tens and the hundreds place to get d=2, c=4 or c=9, and b=4 or b=9 when c=4 and b=1 or b=6 when c=9. This gives us the pattern that there are four such numbers 192,442,692,942 in the range of very 1000 numbers, with a difference of exactly 250 between the two consecutive nubmers. As a result, the nth such number would be 192 + (n-1) times 250.

int main(){
    long long t,n;
    t=ctoi();
    while(t--){
        n=ctoi();
        printf("%lld\n",192+(n-1)*250);
    }
    return 0;
}
