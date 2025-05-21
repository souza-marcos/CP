#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

vector<int> id, szo;

int find(int a) {
    return id[a] = (id[a] == a ? a : find(id[a]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;

    if(szo[a] < szo[b]) swap(a, b);
    id[b] = a;
    szo[a] += szo[b];
}

void solve(){
    
    int n; cin >> n;
    id.resize(n), szo.assign(n, 1);
    iota(id.begin(), id.end(), 0);

    set<pair<int, int>> edges;

    while(sz(edges) < n-1){

        int a = 0, b;
        for(int i = 1; i < n; i ++){
            if(find(a) != find(i)) {b = i; break;}
        }

        while(true){
            cout << "? " << a + 1 << " " << b + 1 << endl;
            cout.flush();
            int res; cin >> res; res--;
            if(res == a){
                edges.insert({a, b});
                uni(a, b);
                break;
            }
            if(find(res) == find(b)) b=res;
            else a=res;
        }
    }
    cout << "! ";
    for(auto [a, b] : edges){
        cout << a + 1 << " " << b + 1 << " ";
    }
    cout << endl;
    cout.flush();
}

int main(){ //_
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
