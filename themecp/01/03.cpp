#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

vector<int> id, szo;
vector<vector<int>> g;

int find(int a){
    return id[a] = (a == id[a]? a : find(id[a]));
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(szo[a] > szo[b]) swap(a, b);
    id[a] = id[b];
    szo[b] += szo[a];
}


int main(){ _
    int n, m; cin >> n >> m;
    id.resize(n), szo.assign(n, 1);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i < m; i ++){
        int k; cin >> k;
        int last;
        if(k > 0){
            cin >> last; last --;
            k --; 
        }
        while(k --){
            int a; cin >> a; a --;
            uni(a, last);
        }
    }
    for(int i = 0; i < n ;i ++){
        cout << szo[find(i)] << " ";
    }
    cout << endl;

    return 0;
} 
