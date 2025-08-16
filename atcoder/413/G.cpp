#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _ 
    
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<int> id(k), szo(k, 1);

    struct info {
        int min_h, max_h, min_v, max_v;
    };
    vector<info> nec(k);

    iota(id.begin(), id.end(), 0);
    
    map<pair<int, int>, int> holes;
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b; a--, b--;
        holes[{a, b}] = i;
        nec[i] = {a, a, b, b};
    }
    
    auto find = [&](auto&& self, int a) -> int {
        return id[a] = (id[a] == a ? a : self(self, id[a]));
    };

    auto uni = [&](int a, int b) -> void {
        a = find(find, a), b = find(find, b);
        if(a == b) return;
        if(szo[a] < szo[b]) swap(a, b);
        id[b] = a;
        szo[a] += szo[b];
        nec[a] = {
            .min_h = min(nec[a].min_h, nec[b].min_h),
            .max_h = max(nec[a].max_h, nec[b].max_h),
            .min_v = min(nec[a].min_v, nec[b].min_v),
            .max_v = max(nec[a].max_v, nec[b].max_v),
        };
    };  

    for(auto [key, val] : holes){
        auto [r, c] = key;
        for(int newr : {-1, 0, 1}){
            for(int newc : {-1, 0, 1}){
                ll rr = r + newr, cc = c + newc;
                if(min(rr, cc) >= 0 and rr < n and cc < m and holes.count({rr, cc})){
                    uni(holes[{r, c}], holes[{rr, cc}]);
                }
            }
        }
    }


    // Need a block that fills (up or right) and (down or left)
    bool ok = true;

    for(int i =0; i < k; i ++){
        int repr = find(find, i);
        auto fo = nec[repr];
        if(fo.min_h == 0 and fo.max_h == n-1) ok = false; // up - down
        if(fo.min_v == 0 and fo.max_v == m-1) ok = false; // left - right
        if(fo.min_h == 0 and fo.min_v == 0) ok = false; // up - left
        if(fo.max_h == n-1 and fo.max_v == m-1) ok = false; // down - right
    }
    
    if(ok) cout << "Yes\n";
    else cout << "No\n";

    return 0;
} 
