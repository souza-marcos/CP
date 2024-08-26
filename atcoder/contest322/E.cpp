#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, K, P;
vector<vector<int>> a;
vector<int> cost;

// ll memo[110][10]; // add N procedure with min P 

ll solve(int item, vector<int> cap, ll cost){
    cout << item << " " << cost << endl;
    for(auto el: cap) cout << el << " ";
    cout << endl;

    ll min_el = *(min_element(cap.begin(), cap.end()));
    if(min_el >= P) return cost;
    if(item == N ) return LINF;

    // ll& p = memo[item][min_el];
    // if(p != -1) return p;


    vector<int> cur_cap(cap.size());
    for(int i = 0; i < cap.size(); i++) cur_cap[i] = cap[i] + a[item][i];
    return /*p =*/ min(solve(item + 1, cap, cost), solve(item + 1, cur_cap, cost + ::cost[item] ));
}

int main(){ _

    cin >> N >> K >> P;
    a.resize(N, vector<int>(K)), cost.resize(N);
    for(int i = 0; i<N; i++){
        cin >> cost[i];
        for(int j = 0; j<K; j++) cin >> a[i][j];
    }

    // memset(memo, -1, sizeof memo);
    ll res = solve(0, vector<int>(K, 0), 0);
    if(res == LINF) cout << -1 << endl;
    else cout << res << endl;   

    return 0;
} 
