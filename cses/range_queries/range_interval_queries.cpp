#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    // queries along in the time  
    // vou adicionando os elementos na ordem de magnitude 
    // faco as queries [0, c-1] ranges variados
    // faco as queries [0, d] ranges variados

    int n, q; cin >> n >> q;
    vector<pair<int, int>> arr(n); 
    for(int i = 0; i < n; i ++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    struct piece {int lq, rq, edge, idx_query, sign;};

    vector<piece> queries;
    for(int i = 0; i < q; i ++){
        int lq, rq, lb, ub; cin >> lq >> rq >> lb >> ub; lq --, rq--;
        queries.push_back({
            .lq = lq,
            .rq = rq,
            .edge = lb-1,
            .idx_query = i,
            .sign = -1
        });
        queries.push_back({
            .lq = lq,
            .rq = rq,
            .edge = ub,
            .idx_query = i,
            .sign = +1
        });
    }

    sort(queries.begin(), queries.end(), [](const auto& left, const auto& right){
        return left.edge < right.edge;
    });

    vector<int> fenwick(n);

    auto query = [&](int a, int b) -> int {
        ll res = 0; a--;
        while(a >= 0){
            res -= fenwick[a];
            a = (a & (a + 1)) -1; 
        }
        while(b >= 0){
            res += fenwick[b];
            b = (b & (b + 1)) -1;
        }
        return res;
    };

    auto add = [&](int a, int delta){
        while(a < sz(fenwick)){
            fenwick[a] += delta;
            a = a | (a + 1);
        }
    };

    vector<ll> res(q);
    int cur = 0;
    for(auto& [lq, rq, edge, idx, sign] : queries){
        while(cur < n and arr[cur].first <= edge){
            add(arr[cur].second, 1);
            cur ++;
        }
        res[idx] = res[idx] + sign * (query(lq, rq));
    }

    for(auto el : res) cout << el << endl;
    return 0;
} 
