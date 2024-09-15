#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int t; cin >> t;
    while(t --){
        int a, b; cin >> b >> a;
        int lb = ceil(a/2.0);
        b -= (a/2) * 7 + (lb - a/2) * 11;
        if(b <= 0) cout << lb << endl; 
        else cout << lb + ceil(b/15.0) << endl;

    }

    return 0;
} 
