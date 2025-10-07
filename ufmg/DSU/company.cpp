#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){  _
    int n, m; cin >> n >> m;

    vector<int> id(n), next(n), szo(n, 1);
    iota(id.begin(), id.end(), 0);
    iota(next.begin(), next.end(), 1);

    function<int(int)> find = [&](int a) -> int {
        return id[a] = (id[a] == a ? a : find(id[a]));
    };

    auto uni = [&](int a, int b) -> void {
        a = find(a), b = find(b);
        if(a == b) return;
        if(szo[a] < szo[b]) swap(a, b);
        id[b] = a;
        szo[a] += szo[b];
    };

    
    auto uni2 = [&](int l, int r) -> void {
        while(l < r) {
            uni(l, l + 1);
            int ne = next[l];
            next[l] = r;
            l = ne;
        }
    };

    for(int i = 0; i < m; i ++){
        int t, a, b; cin >> t >> a >> b;
        a --, b--;
        if(t == 1) uni(a, b);
        if(t == 2) uni2(a, b);
        if(t == 3){
            a = find(a), b = find(b);
            cout << (a == b ? "YES\n" : "NO\n");
        }
    }

    return 0;
} 
