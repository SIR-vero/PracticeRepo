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
int t;
cin>>t;
while(t--){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, vector<int> > m;

    int c = a[0];
    bool allSame = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != c)
            allSame = false;
        m[a[i]].push_back(i+1);
    }

    if (allSame && n != 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        int ss = n+1;
        int gang = 0;
        int around = -1;
        for (auto i : m)
        {
            if (i.second.size() < ss)
            {
                ss = i.second.size();
                around = i.second[0];
                gang = i.first;
            }
        }

        if (ss == 1)
        {
            for (int i = 1; i <= n; i++)
                if (i != around)
                    cout << around << " " << i << endl;
        }

        else
        {
            set<int> da;
            for (auto i : m[gang])
                da.insert(i);

            set<int> att;
            att.insert(around);
            int satt;
            for (int i = 1; i <= n; i++)
                if (i != around && da.count(i) == 0){
                    cout << around << " " << i << endl;
                    satt = i;
                    att.insert(i);
                }

            for (auto i : da)
            {
                if (i != around)
                    cout << satt << " " << i << endl;
            }
        }
    }
}
return 0;}
