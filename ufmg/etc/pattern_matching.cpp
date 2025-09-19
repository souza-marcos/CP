#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){
    int n, m, k; cin >> n >> m >> k;
    vector<string> pat(n);
    map<string, int> mp; // idx of the pattern 
    for(int i = 0; i < n; i ++) {
        cin >> pat[i];
        mp[pat[i]] = i;
    }

    vector<vector<int>> g(n);
    vector<int> indegree(n), order;

    for(int i = 0; i < m; i ++){
        string s; cin >> s;
        int mt; cin >> mt;
        mt --;

        bool ok = false;
        for(int mask = 0; mask < (1 << k); mask++){
            string snew = s;
            for(int j = 0; j < k; j ++){
                if((mask>>j)&1) snew[j] = '_';
            }
            if(mp.count(snew)){
                if(mp[snew] == mt) ok = true; 
                else {
                    g[mt].push_back(mp[snew]);
                    indegree[mp[snew]] ++;
                }
            }
        }
        if(!ok) {
            cout << "NO\n";
            return 0; 
        }
    }



    priority_queue<int> q;
    for(int i = 0; i < n; i ++){
        if(indegree[i] == 0) q.push(i);
    }


    while(sz(q)){
        int el = q.top();
        q.pop();
        order.push_back(el);
        for(int u : g[el]){
            if(--indegree[u] == 0) q.push(u);
        }
    }

    if(sz(order) < n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto el : order) cout << el + 1 << " ";
    cout << endl;
}

