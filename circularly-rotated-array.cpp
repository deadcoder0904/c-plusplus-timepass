#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <numeric>
#include <complex>

using namespace std;

#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REP1(i,n,step) for (int i = 0; i < n; i+=step)
#define REP2(i,x,y) for (int i = x; i < y; i++)
#define REP3(i,x,y,step) for (int i = x; i < y; i+=step)
#define NREP(i,n) for (int i = n-1 ; i >= 0; --i)
#define NREP1(i,n,step) for (int i = n-1 ; i >= 0; i-=step)
#define NREP2(i,x,y) for (int i = x; i >= y; i--)
#define NREP3(i,x,y,step) for (int i = x; i >= y; i-=step)
#define sortv(a) sort(a.begin(),a.end())

#define pb push_back
#define mp make_pair
 
const float PI=3.1415926535897932384626433832795;
const int MOD=1e9+7;
 
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool even(int x) { return x%2==0?true:false; }
bool odd(int x) {return x%2==1?true:false; }
ull fact(int a){ ull f=1; REP(i,a) f*=1; return f;}
ull gcd(int a, int b){ return b == 0 ? a : gcd(b,a%b); }
ull lcm(int a,int b){ return a*b/gcd(a,b);}
ll fast_expo(ll a,ll b)
{
    if(b==1) return a;
    if(b==2) return a*a;
    return b&1 ? a*fast_expo(fast_expo(a,(b-1)/2),2) : fast_expo(fast_expo(a,b/2),2);
}

int min_index(int a[],int n){
	int low=0,high=n-1;
	while(low<=high){
		if(a[low]<=a[high])
		return low;
		int mid = (low+high)/2;
		int next=(mid+1)%n,prev=(mid+n-1)%n;
		if(a[next]>=a[mid] && a[prev]>=a[mid])
			return mid;
		else if(a[mid]<=a[high])
				high=mid-1;
			else if(a[low]<=a[mid])
				low=mid+1;
	}
	return -1;
}

int main()
{
	int n,i=0;
	cin>>n;
	int a[n];
	while(i<n)
		cin>>a[i++];
	int index = min_index(a,n);
	int final_index =min(index,(n-index)%n);
	cout<<final_index<<endl;
	return 0;
}

/*
(1)
Input-
5
5 1 2 3 4
Output-
1

(2)
Input-
5
2 3 4 5 1
Output-
2
*/