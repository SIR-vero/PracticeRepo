#include<bits/stdc++.h>
using namespace std;

long long compute(long long x, long long y, long long n){
long long res = 1;
while(y > 0){
    if (y & 1)
        res = (res * x)%n;
    x = (x*x)%n;
    y = y>>1;
}
return res%n;

}

int main(){
int t;
cin>>t;
while(t--){
    long long x, y, n;
    cin >> x >> y >> n;
    cout << compute(x,y,n) << endl;
}
}
