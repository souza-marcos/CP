#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

ll getFloor(ll a, ll b){
    if(a > 0) return a/b;
    return a/b - (a % b != 0);
}

int32_t main() { _

    int n, p; cin >> n >> p;
    struct Weapon { int A, B, C; };
    vector<Weapon> weapons(n);
    for(auto& el : weapons) cin >> el.A >> el.B >> el.C;
    
    sort(weapons.begin(), weapons.end(), [&](Weapon &left, Weapon& right){
        ll resleft = left.B * (right.A - 1);
        ll resright = right.B * (left.A - 1);
        return resleft > resright;
    });


    vector<ll> dp(p + 1, -1); // max health i can beat with i first weapons and with p power remaining 
    dp[p] = 0;
    for(int j = 0; j < n; j ++){
        for(int i = 0; i <= p; i ++){
            if(dp[i] > -1){
                auto [A, B, C] = weapons[j];
                int newpower = getFloor((i-B),A);
                if (newpower < 0) continue;
                dp[newpower] = max(dp[newpower], dp[i] + C);
            }
        }
    }

    ll maxv = 0;
    for(auto el : dp) maxv = max(maxv, el);
    cout << maxv << endl;
}