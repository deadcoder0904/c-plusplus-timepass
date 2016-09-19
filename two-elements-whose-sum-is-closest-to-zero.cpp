#include <bits/stdc++.h>

using namespace std;

void sum_equal_to_zero(int a[],int n){
	int min_sum=a[0]+a[1],min_i=0,min_j=1;
	for (int i = 1; i < n-1; ++i)
		for (int j = i+1; j < n; ++j)
			if(abs(min_sum)>abs(a[i]+a[j])) {
				min_sum = a[i]+a[j];
				min_i = i;
				min_j = j;
			}
	cout<<"Two elements whose sum is near to zero are "<<a[min_i]<<" & "<<a[min_j]<<endl;		
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
	sum_equal_to_zero(a,n);	
	return 0;
}