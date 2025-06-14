#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n; cin >> n;
    vector<bool> ok(n);
    set<int> have_to_get; int size = 0;
    int res = 0;
    // Preciso pegar a menor qtd de itens possivel que satisfaca o segmento anterior
    set<int> getting;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        getting.insert(a);
        if(have_to_get.count(a) and ok[a] == 0) size --, ok[a] = 1;
        if(size == 0){
            have_to_get = getting;
            for(auto el: getting) ok[el] = 0;
            size=sz(have_to_get);
            res ++;
        }
    }
    cout << res  << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
