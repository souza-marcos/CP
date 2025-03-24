#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MAX = 1e3 + 10;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> cnt(MAX);

    int maxval = -INF, minval = INF;

    for(auto& el: arr) cin >> el, cnt[el] ++, maxval = max(maxval, el), minval = min(minval, el);
    
        
    auto balanced = [&](int init) -> bool {
        for(int i = init; i < MAX; i ++){
            if(cnt[i] % 2 != 0) return false;
        }
        return true;
    };

    for(int i = minval; i < MAX-1; i ++){
        
        if(balanced(i)){
            cout << "Yes\n";
            return;
        }
        
        if(cnt[i] == 0) continue;
        if(cnt[i] < 2) {
            cout << "No\n";
            return;
        }
        cnt[i + 1] += cnt[i]-2;
        cnt[i] = 0;
    }
    cout << "No\n";
}

int32_t main(){ _

    int t; cin >> t;
    while(t --) solve();
}