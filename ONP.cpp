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

inline int sn()
{
    int n=0;
    int ch=gc();
    while( ch <48 )ch=gc();
    while( ch >47 )
    n = (n<<3)+(n<<1) + ch-'0', ch=gc();
        return n;
}

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

int arr[1000];

void partition(int low,int high);
void mergeSort(int low,int mid,int high);
void partition(int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(low,mid);
         partition(mid+1,high);
         mergeSort(low,mid,high);
    }
}

void mergeSort(int low,int mid,int high){

    int i,m,k,l,temp[1000];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }

    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

//Print alphabet as soon as you encounter one. Store opening brackets and operations is stack and print till the closest opening bracket from the top of stack on encountering a closed bracket.

int main(){
    int t=ctoi();
    while(t--){
		stack<char> oper;
		char str[500];
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++){
            if(str[i]=='(' || str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){     //store in stack
                oper.push(str[i]);
                continue;
            }
            if(str[i]>='a' && str[i]<='z'){                                                                 //print immediately
                putchar(str[i]);
                continue;
            }
            if(str[i]==')'){                                                                                //print operators in reverse order using the stack till the last opening bracket
                while(!oper.empty()){
                        char top=oper.top();
                        oper.pop();
                        if(top!='(')    putchar(top);
                        else{
                            break;
                        }
                }
            }
		}
		pn;
	}
    return 0;
}
