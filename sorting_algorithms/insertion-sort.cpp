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

void insertion_sort(int a[],int n){
	cout<<"Insertion Sort"<<endl;
	int shifts=0,pass=0;
	REP2(i,1,n)
		{
			int temp = a[i],j=i;
			while(j>0 && a[j-1]>temp){
				cout<<"Shift "<<a[j]<<"<->"<<a[j-1]<<endl;	
				shifts++;
				a[j]=a[j-1];
				j--;
			}
			a[j] = temp;
			pass++;
		}
	cout<<"No. of Shifts = "<<shifts<<endl;
	cout<<"No. of Passes = "<<pass<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		input_array(a,n);
		insertion_sort(a,n);
		print_array(a,n);
	}
	return 0;
}

/*
Output --->
(1)
1
5
1 2 3 5 4
Insertion Sort
Shift 4<->5
No. of Shifts = 1
No. of Passes = 4
1 2 3 4 5 

(2)
1
5
5 2 3 4 1
Insertion Sort
Shift 2<->5
Shift 3<->5
Shift 4<->5
Shift 1<->5
Shift 5<->4
Shift 4<->3
Shift 3<->2
No. of Shifts = 7
No. of Passes = 4
1 2 3 4 5 
*/