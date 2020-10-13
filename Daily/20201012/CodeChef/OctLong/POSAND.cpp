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

int ones(int x)
{
    int ans = 0;
    while(x)
    {
        if (x%2 == 1)
            ans++;
        x = x/2;
    }
    return ans;
}

int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin >> n;
    if (n == 1){
        cout << 1 << endl; continue;}
    if ( ones(n) == 1)
        cout << -1 << endl;
    else
    {
        if (n == 1)
            cout << 1 << endl;
        if (n >= 3)
        {
            cout << "2 3 1 ";
            for (int i = 4; i <= n; i++)
            {
                if (ones(i) == 1)
                {
                    cout << i+1 << " " << i << " ";
                    i++;
                }
                else
                    cout << i << " ";
            }
            cout << endl;
        }
    }
}
return 0;}
