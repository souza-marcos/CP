#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, m, q; cin >> n >> m >> q;
    deque<int> part;
    for(int i = 0; i < n; i ++){
        int el; cin >> el;
        part.push_back(el);
    }
    vector<bool> used(n + 1, false);

    bool ok = true;
    for(int i = 0; i < m; i ++){
        int a; cin >> a;
        if(used[a] == false){
            used[part.front()] = true;
            part.pop_front();
        }
        if(used[a]==false){
            ok = false;
        }
    }
    cout << (ok ? "YA\n" : "TIDAK\n");


}


int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
