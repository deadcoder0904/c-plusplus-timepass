#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	cout<<"Enter the string: ";
	getline(cin,str);
	int len;
	for(len=0; str[len]!='\0'; len++);
    int len1=0;
 	for(int i=0; i<(len-len1);)
    {
        if(str[i]==str[i+1])
        {
            for(int j=i;j<(len-len1);j++)
                str[j]=str[j+1];
            len1++;
        }
        else i++;
    }
    cout<<"String after removing consecutive characters: "<<str;
	return 0;
}