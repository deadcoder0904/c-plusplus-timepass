#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/*
find binary of power
if b=1 (d^2)%modular,(d*m)%modular
if b=0 (d^2)%modular
*/

ll modular_division(ll m,ll power,ll modular){
	vector<short> bit(10);
	ll d = 1, c = 0;
	while(power){
		bit.push_back(power%2);
		power /= 2;
		c++;
	}
	for (ll i = bit.size() - 1; i >= 0 && c--; --i)
		if(bit[i])
		{
			d = (d * d) % modular;
			d = (d * m) % modular;
		}
		else d = (d * d) % modular;
	return d;	
}

int main()
{
	ll m,power,modular;
	cin>>m>>power>>modular;
	cout<<modular_division(m,power,modular);
	return 0;
}

/*

If we need to calculate - 111111111111111111111111111111 ^ 111111111111 % 12312 then it does it faster than a 
Pythonic Compiler

Input-
111111111111111111111111111111 111111111111 12312

Output-
46122792424001

*/