#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    ll n, k; cin >> n >> k;
    ll sum = 0;
    vector<ll> cards(n); 
    for(ll &el: cards) cin >> el, sum += el;
    sort(cards.rbegin(), cards.rend());
    
    for(int res = n; res >= 1; res --){
        ll minslots = res * cards[0];
        // cout << "SUM: " << sum << ", MINSLOTS: " << minslots << endl;
        if(sum <= minslots and (minslots - sum) <= k){
            // cout << "K= " << k << ",  " << (minslots - sum) << endl;
            cout << res << endl;
            return;
        }
        if(sum > minslots){
            int left = sum % res;
            left = (left == 0? 0: res - left);
            if(k >= left){
                cout << res << endl;
                return ;
            }
        }
    }
}

int main(){ _
    int t; cin >> t;;
    while(t --) solve();
    return 0;
} 
