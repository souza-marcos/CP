#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

int maxit(vector<int>& a, vector<int>& b, int& ai, int& bi){    
    if(ai == a.size()) return b[bi++];
    if(bi == b.size()) return a[ai++];

    if(a[ai] >= b[bi]) return a[ai ++];
    else return b[bi ++];
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &el: a) cin >> el;
    for(auto &el: b) cin >> el;

    sort(b.rbegin(), b.rend());

    int ai = 0, bi = 0;
    for(int i = 0; i < n + m; i++){
        cout << maxit(a, b, ai, bi) << " ";
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
