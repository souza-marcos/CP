#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& el: a) cin >> el;
    for(int& el: b) cin >> el;
    int res = 0;
    for(int i = n-1; i >= 0; i --){
        if(a[i] == b[i]) {
            res = i + 1;
            break;
        }
    }
    for(int i = n-1; i > 0; i --){
        if(a[i] == a[i-1] or b[i] == b[i-1]){
            res = max(res, i);
        }
        if(i > 1 and (a[i] == b[i-2] or b[i] == a[i-2])){
            res = max(res, i-1);
        }
        if(i > 2 and (a[i] == b[i-3] or b[i] == a[i-3])){
            res = max(res, i-2);
        }
    }
    cout << res << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
