#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

bool ckmax(int& a, int b){
    if(a >= b) return false;
    a = b;
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> cows_by_card(n * m);
    vector<bool> used(n, false);

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int a; cin >> a; 
            cows_by_card[a] = i;
        }
    }

    // for(auto el : cows_by_card) cout << el << endl;

    vector<int> perm;
    for(int i = 0; i < n; i ++){
        if(used[cows_by_card[i]]){
            cout << -1 << endl;
            return;
        }
        used[cows_by_card[i]] = true;
        perm.push_back(cows_by_card[i]);
    }

    int cur = 0;
    assert(sz(perm) == n);

    for(int i = n; i < n*m; i ++){
        if(perm[cur] != cows_by_card[i]){
            cout << -1 << endl;
            return;
        }
        cur = (cur+1) % n;
    }

    for(auto el: perm) cout << el + 1 << " ";
    cout << endl;

}

int main(){ //_
    int t; cin >> t;
    while(t--) solve();
} 
