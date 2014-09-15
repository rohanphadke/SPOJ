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

//We have a number only if 1) x and y are both 0 OR 2) x and y are both 1 OR 3) y is either equal to x or x-2 for any other x
//As can be seen from the image, outputs for 1) and 2) are trivial. output for 3) is 2*x or 2*x-2 for even x and is 2*x-1 or 2*x-3 for odd x
int main(){
    int t=ctoi();
    while(t--){
		int x=ctoi(),y=ctoi();
		switch(x){
        case 0:
            if(y==0){                           //case where x==0 and y==0
                wi(0);pn;
            }else{                              //case where x==0 but y!=0
                puts("No Number");
            }
            break;
        case 1:
            if(y==1){                           //case where x==1 and y==1
                wi(1);pn;
            }else{                              //case where x==1 but y!=1
                puts("No Number");
            }
            break;
        default:
            if(y==x){                           //case where y==x for x!=1 OR x!=0
                if(x&1){                              //odd x  --> bit operations are faster
                    wi(2*x-1);pn;
                }else{                                //even x
                    wi(2*x);pn;
                }
            }else if(y==x-2){                   //case wherey==x-2 for x!=1 OR x!=0
                if(x&1){                              //odd x
                    wi(2*x-3);pn;
                }else{                                //even x
                    wi(2*x-2);pn;
                }
            }else{                              //case where y has some other value for x!=1 OR x!=0
                puts("No Number");
            }
		}
	}
    return 0;
}
