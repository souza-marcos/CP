#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;
set<pair<int, int>> intervals; // l r

int find(int x){
    return id[x] = (id[x] == x? x : find(id[x]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b]) swap(a, b);
    id[a] = b;
    sz[b] += sz[a];
}

void uni2(int l, int r){
    int a = find(l);

    // find in intervals
    int begin = l, end = r;

    for(auto it: intervals){
        if(founda and foundb) break;
        if(!founda and a >= it.f){
            begin = it.s;
            moda = &(it.first);
        }
        if(!foundb and r <= it.s) {
            end = it.f;
        }
    }

    for(int i = begin; i < end; i++) {
        uni(i, i + 1);
    }
}

int main(){ _
    int n, m; cin >> n >> m;

    id.resize(n);
    sz.resize(n, 1);
    iota(id.begin(), id.end(), 0);

    int type, a, b;
    while (m --)
    {
        cin >> type >> a >> b; a--, b--;
        if(type == 1) {
            uni(a, b);
        }
        else if(type == 2) uni2(a, b);
        else cout << (find(a) == find(b)? "YES": "NO") << endl;
    }
    return 0;
} 
