#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

vector<int> id;

int find(int x){
    return id[x] = (id[x] == x? x:find(id[x]));
}

void uni(int a, int b){ 
    a = find(a), b = find(b);
    id[a] = b;
}

int main(){ _

    int n, m;
    cin >> n >> m;

    id = vector<int>(n + 2);
    iota(id.begin(), id.end(), 0);

    while(m --){
        char c; int q;
        cin >> c;
        cin >> q;
        if(c == '-') uni(q, q + 1);
        else cout << (find(q) == n + 1 ? -1 : find(q)) << endl;
    }

    exit(0);
} 
