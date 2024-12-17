#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    
    int liters = 0, last = 0;    
    while(n --){
        int t, v; cin >> t >> v;
        liters = max(0, liters - (t - last));
        last = t;
        liters += v;
    }   

    cout << liters << endl;

    return 0;
} 
