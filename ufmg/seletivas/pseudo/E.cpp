#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n; vector<int> a, b;
vector<vector<int>> g;

const int MAX = 1e5 + 1;
ll memo[MAX];

ll dp(int i, int pi){

    ll &p = memo[i];
    if(p != -1) return p;


    if(g[i].size() == 0) return p = 0;
    if(g[i].size() == 1 and g[i][0] == pi) return p = 0;

    ll minv = LINF;
    for(int adj: g[i]){
        
        if(adj != pi) {
            // cout << i << " " << dp(adj, i) << " " << a[i] * b[adj] << endl;
            minv = min(minv, dp(adj, i) + (ll)a[i] * (ll)b[adj]);
        }
    }
    return p = minv;
}

int main(){ _

    cin >> n;
    a.resize(n), b.resize(n), g.resize(n);
    memset(memo, -1, sizeof memo);
    
    for(int& el: a) cin >> el;
    for(int& el: b) cin >> el;

    for(int i = 0; i < n -1; i++){
        int e1, e2; cin >> e1 >> e2; e1 --, e2--;
        g[e1].push_back(e2);
        g[e2].push_back(e1);
    }
    dp(0, 0);

    for(int i = 0; i < n; i++){
        cout << memo[i] << " ";
    }
    cout << endl;

    return 0;
} 
