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

int first_occurrence(int a[],int n,int num){
	int low=0,high=n-1,mid,first_index=-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(num==a[mid])
			{
				first_index=mid;
				high=mid-1;
			}
		else if(num>a[mid])
				low=mid+1;
			else high=mid-1;
	}
	return first_index;
}

int main()
{
	int n;
	cin>>n;
	int a[n],i=0;
	while(i<n)
		cin>>a[i++];
	int no;
	cin>>no;
	cout<<first_occurrence(a,n,no)<<endl;
	return 0;
}