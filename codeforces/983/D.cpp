#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int query(int a, int b){
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int res; cin >> res;
    if(res == -1) exit(2226);
    return res;
}

void solve(){
    int n; cin >> n;
    // Enquanto obtiver 1 temos caminhos diferentes do 1
    vector<int> path = {1}; 
    vector<int> parent(n); parent[0] = -1, parent[1] = 0;
    set<int> ativo; ativo.insert(0);
    int a = 1, b = 2, res, i = 1;
    while(true){
        res = query(a, b);
        if(res == 0) { path[0] = b, parent[b] = 1; break; }
        parent[b] = 0;
        path.push_back(b);
        ativo.insert(i ++);
        b ++;
    }

    auto bef = ativo.begin();
    for(int i = b + 1; i < n; i ++){
        if(next(bef) == ativo.end()) bef = ativo.begin();
        else ++bef;

        vector<int> toRemove;
        auto cur = bef;
        bool ok = false;
        while(true){

            int res = query(path[*cur], i);
            if (res == 0) ok = true; 
            if (res == 1) {
                toRemove.push_back(*cur);
            }

            if(next(cur) == ativo.end() or ok) break;
            ++cur;
        }
        if(!ok){
            cur = ativo.begin();
            while(cur != bef){
                int res = query(path[*cur], i);
                if(res == 0) { ok = true; break; } 
                if(res == 1) toRemove.push_back(*cur);        
                ++ cur;
            }
        }

        if(ok) {
            parent[i] = path[*cur];
            path[*cur] = i;
        }

        for(int el: toRemove) ativo.erase(el);   
        bef = ativo.find(*cur);  
    }
    

    cout << "! ";
    for(int i = 1; i < n; i ++){
        cout << parent[i] << " ";
    }
    cout << endl;
    cout.flush();
}

int main(){
    int t; cin >> t;
    while(t --) solve();
    exit(0);
} 
