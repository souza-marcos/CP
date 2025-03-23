#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll 

int32_t main(){ _
    ll h, w; ll x; cin >> h >> w >> x;
    ll p, q; cin >> p >> q;
    p --, q--;

    vector<vector<ll>> s(h, vector<ll>(w));
    vector<vector<bool>> vis(h, vector<bool>(w, false));

    for(int i = 0; i < h ; i ++)
    for(int j = 0; j < w; j ++){
        cin >> s[i][j];
    }
    
    vis[p][q] = true;
    ll cur = s[p][q];

    priority_queue<pair<ll, pair<int, int>>> pq;
    vector<pair<ll, ll>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto getadj = [&](int i, int j){
        for(auto [newi, newj] : mvs){
            newi += i, newj += j;
            if(min(newi, newj) < 0 or newi >= h or newj >= w) continue;
            if(vis[newi][newj]) continue;
            pq.push({-s[newi][newj], {newi, newj}});
            vis[newi][newj] = true;
        }
    };

    getadj(p, q);
    while(sz(pq)){
        auto [weight, pos] = pq.top();
        pq.pop(), weight = -weight;
        if((__int128_t)x * (__int128_t)weight < (__int128_t)cur) {
            cur += weight, getadj(pos.first, pos.second);
        }
        else break;
    }
    cout << cur << endl;
    return 0;
} 
