#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

vector<int> id, sz; // parent, cost jump

int acc;

int jump(int x){
    if(id[x] == x){
        acc = 0;
        return x;
    }else{
        id[x] = jump(id[x]);
        sz[x] += acc;
        acc = sz[x];
    }
    return id[x];
}

void uni(int a, int b){
    id[a] = b;
    sz[a] = sz[b] + 1;
}

int main(){ _

    int n, m; cin >> n >> m;
    id.resize(n);
    sz.resize(n, 0);
    iota(id.begin(), id.end(), 0);

    int type, a, b;
    while(m --){
        cin >> type;
        if(type == 1){
            cin >> a >> b; a--, b--;
            uni(a, b);
        }else{
            cin >> a; a --;
            jump(a);
            cout << sz[a] << endl;
        }
    }
    return 0;
} 
