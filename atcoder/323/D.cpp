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
    map<ll, ll> cnt;
    for(int i = 0; i < n; i ++){
        ll szo, m; cin >> szo >> m;
        while(m > 0){
            if(cnt.count(szo)) {
                m += cnt[szo];
                cnt[szo] = m&1;
            } else{
                if(m&1) cnt[szo] = m&1;
            }
            m >>= 1;
            szo <<= 1;
        }
        
    }
    int res = 0;
    for(auto [idx, val] : cnt ) res += val > 0; 
    cout << res << endl;
} 
