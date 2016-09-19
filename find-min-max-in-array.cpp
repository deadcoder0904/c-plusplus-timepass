#include <bits/stdc++.h>

using namespace std;

void minmax(int a[],int n){
	int min=a[0],max=a[0];
	for (int i = 1; i < n; ++i)
		if(a[i] < min) min = a[i];
		else if(a[i] > max) max = a[i];
	cout<<"Min: "<<min<<"\nMax: "<<max<<endl;	
}

int main()
{
	int n;
	cout<<"Enter size of array: "<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the array elements: "<<endl;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	minmax(a,n);
	return 0;
}