#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    // Ideia do Iago: tentar biparticionar o grafo na força bruta e calcular o minimo de arestas removidas

    int n, m; cin >> n >> m;
    int minv = INF; 
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 0; i < (1 << 20); i ++){    

        int cnt = 0;
        for(int j = 0; j < n; j++){
            int color_v = (i >> j) & 1; 
            for(int el: g[j]){
                int color_u = (i >> el) & 1; 
                if(color_v == color_u) cnt ++;
            }   
        }

        minv = min(cnt/2, minv);
    }
    cout << minv << endl;

    return 0;
} 
