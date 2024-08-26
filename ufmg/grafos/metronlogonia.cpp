#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void dfs(vector<vector<int>> g, vector<int> dis, int pos){
    for(auto el: g[pos]){
        if(dis[el] == -1) {
            dis[el] = dis[pos] + 1;
            dfs(g, dis, el);
        }
    }
}


int indexmaxdist(int ini, vector<vector<int>> g, vector<int> dist){
    dist[ini] = 0;
    dfs(g, dist, ini);
    int max = -1, pos = -1;
    for(int i = 0; i < dist.size(); i++){
        if(dist[i] > max) {
            max = dist[i];
            pos = i;
        }
    }
    return pos;
}

int main(){ _

    
    // Identificar o diametro de cada um  e depois pegar a estação que está na metade desse diametro
    int m, n; cin >> m >> n;

    vector<vector<int>> m1(m), m2(n); 
    vector<int> dist1(m), dist2(n);


    for(int i = 0; i < m -1; i++){
        int a, b; cin >> a >> b; a--, b--;
        m1[a].push_back(b);
        m1[b].push_back(a);
    }
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;
        m2[a].push_back(b);
        m2[b].push_back(a);
    }
    
    int pos1 = indexmaxdist(0, m1, dist1);
    indexmaxdist(pos1, m1, dist1);

    int pos2 = indexmaxdist(0, m2, dist2);
    indexmaxdist(pos2, m2, dist2);



    return 0;
} 
