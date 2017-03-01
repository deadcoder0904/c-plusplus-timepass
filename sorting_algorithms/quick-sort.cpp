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

int partition(int a[],int start, int end){
	int pivot = a[end];
	int pivotIndex = start;
	REP2(i,start,end-1){
		if(a[i] < pivot){
			swap(&a[i],&a[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(&a[end],&a[pivotIndex]);
	return pivotIndex;
}

void quicksort(int a[], int start, int end){
	if(start < end){
		int pivot = partition(a,start,end);
		quicksort(a,start,pivot - 1);
		quicksort(a,pivot + 1,end);
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		input_array(a,n);
		print_array(a,n);
		quicksort(a,0,n-1);
		print_array(a,n);
	}
	return 0;
}