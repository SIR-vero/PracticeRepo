#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int mod97 = 1000000000+7;
long long expo(long long p,long long q)
{
    long long z=1;
    while(q>0)
    {
        if(q%2==1)
            z= (z*p)%mod97;
        p=(p*p)%mod97;
        q >>=1;
    }
    return z;
}

int main(){
string s;
cin >> s;
cout << endl;
int co=0;
for (char c : s)
    if (c == ','){
        cout << " ";
        co++;
    }
    else
        cout << c ;

cout << "comma ; " << co << endl;
return 0;}
