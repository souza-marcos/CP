#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    struct Node { int l, r; };
    vector<Node> g(n);
    for(int i = 0; i < n; i ++){
        int l, r; cin >> l >> r; l--, r--;
        g[i] = {l, r};
    }

    auto dfs = [&](auto&& dfs, int v) -> int {
        bool isLeave = (g[v].l + g[v].r == -2);
        if(isLeave) return 0;
        int minleft = (g[v].l == -1? INF : dfs(dfs, g[v].l));
        int minright = (g[v].r == -1? INF : dfs(dfs, g[v].r));

        return min(minleft + (s[v]!='L'), minright + (s[v] != 'R'));
    };  

    int val = dfs(dfs, 0);
    cout << val << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
