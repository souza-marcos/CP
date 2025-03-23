#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()

int main(){ _

    int n, m; cin >> n >> m;
    vector<ll> wei(n), cap(m);
    for(auto& el : wei) cin >> el;
    for(auto& el : cap) cin >> el;

    auto put = [&](auto&& self, int i) -> bool {
        if(i >= n) return true;

        bool ok = false;
        for(int j = 0; j < m; j ++){
            if(wei[i] <= cap[j]){
                cap[j] -= wei[i];
                bool can = self(self, i + 1);
                cap[j] += wei[i];
                if(can) {
                    ok = true;
                    break;
                }
            }
        }
        return ok;
    };

    bool ok = put(put, 0);  
    cout << (ok ? "sim": "nao") << endl;
    return 0;
} 
