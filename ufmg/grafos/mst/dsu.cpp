#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define siz(a) (int)(a).size()

vector<int> id, sz;
vector<pair<int, int>> att; // min, max, total_el
int find(int a){
    return id[a] = (a == id[a] ? a: find(id[a]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] > sz[b]) swap(a, b);
    id[a] = b;
    sz[b] += sz[a];

    att[b].first = min(att[b].first, att[a].first);
    att[b].second = max(att[b].second, att[a].second);
}

int main(){ _

    int n, q; cin >> n >> q;
    id.resize(n), sz.resize(n, 1), att.resize(n);
    iota(id.begin(), id.end(), 0);
    for(int i = 0 ; i < n; i++) att[i] = {i, i};

    int a, b;
    while(q --){
        string co; cin >> co;
        if(co == "union") { cin >> a >> b; a--, b--; uni(a, b); }
        else {
            cin >> a; a--;
            a = find(a);
            cout << att[a].first + 1 << " " << att[a].second + 1 << " " << sz[a] << endl;
        }
    }

    return 0;
} 
