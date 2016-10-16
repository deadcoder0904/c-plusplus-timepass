#include <bits/stdc++.h>

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
 
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const float PI=3.1415926535897932384626433832795;
const ull MOD=1e9+7;

void swap(int *a,int *b){int temp=*a;*a=*b;*b=temp;}
bool even(ull x) { return x%2==0?true:false; }
bool odd(ull x) {return x%2==1?true:false; }
ull fact(ull a){ ull f=1; REP2(i,1,a+1) f*=i; return f;}
ull gcd(ull a, ull b){ return b == 0 ? a : gcd(b,a%b); }
ull lcm(ull a,ull b){ return a*b/gcd(a,b);}
ll fast_expo(ll a,ll b)
{
    if(b==1) return a;
    if(b==2) return a*a;
    return b&1 ? a*fast_expo(fast_expo(a,(b-1)/2),2) : fast_expo(fast_expo(a,b/2),2);
}
void input_array(int a[],int n){ REP(i,n) cin>>a[i];}
void print_array(int a[],int n){ REP(i,n) cout<<a[i]<<" "; cout<<endl;}

void merge(int a[], int low, int mid, int high){
	int i=0,
		j=0,
		k=low;
	int n1=mid-low+1,
		n2=high-mid,
		L[n1],
		R[n2];
	REP(z,n1) L[z]=a[low+z];
	REP(z,n2) L[z]=a[mid+1+z];
	while(i<n1 && j<n2)
		if(L[i]<=R[j])
			a[k++]=L[i++];
		else a[k++]=R[j++];
	while(i<n1)	
		a[k++]=L[i++];
	while(j<n2)
		a[k++]=R[j++];
}

void mergesort(int a[],int low,int high){
	if(low<high){
		int mid=low+(high-low)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],b[n];
		input_array(a,n);
		print_array(a,n);
		mergesort(a,0,n-1);
		print_array(a,n);
	}
	return 0;
}
