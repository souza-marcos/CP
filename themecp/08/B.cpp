#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


int main(){ _
    int n, q; cin >> n >> q;
    map<int, int> history;
    int allValue = 0;
    ll res = 0;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        history[i] = a; 
        res += a;
    }

    while(q --){
        int t; cin >> t;
        if(t == 1){
            int i, x; cin >> i >> x; i--;
            if(history.count(i)){
                int delta = x - history[i];
                res += delta;
            } else {
                // prevval is allValue
                int delta = x - allValue;
                res += delta;
            }
            history[i] = x;
        }else {
            ll b; cin >> b;
            allValue = b;
            res = b * n;
            history.clear();
        }
        cout << res << endl;
    }
} 
