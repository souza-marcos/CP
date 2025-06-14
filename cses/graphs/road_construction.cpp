#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int num_comp, max_comp;

vector<int> szo, id;
int find(int a){
    return id[a] = (id[a] == a? a : find(id[a]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(szo[a] < szo[b]) swap(a, b);
    id[b] = a;
    szo[a] += szo[b];
    num_comp --;
    max_comp = max(max_comp, szo[a]);
}


int32_t main(){ _ 

    int n, m; cin >> n >> m;
    id.resize(n), szo.assign(n, 1);
    iota(id.begin(), id.end(), 0);
    num_comp = n, max_comp = 1;

    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b; a--, b--;
        uni(a, b);
        cout << num_comp << " " << max_comp << endl;
    }

}
