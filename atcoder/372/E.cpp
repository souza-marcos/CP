#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<int> id, szo;
vector<vector<int>> arrs;

int find(int a){    
    return id[a] = (id[a] != a? find(id[a]): a);
}

void uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;

    if(szo[a] > szo[b]) swap(a, b);

    id[a] = b;
    szo[b] += szo[a];


    // Merge
    vector<int> res; 
    int i = 0, j = 0;
    auto& left = arrs[a], &right = arrs[b];
    while(i < sz(left) and j < sz(right) and i + j < 10){
        if(left[i] > right[j]) res.push_back(left[i]), i ++;
        else res.push_back(right[j]), j ++;
    }
    while(i < sz(left) and i + j < 10) res.push_back(left[i]), i++;
    while(j < sz(right) and i + j < 10) res.push_back(right[j]), j++;
    arrs[b] = res;
}

int main(){ _

    int n, q, t, a, b; cin >> n >> q;
    id.resize(n), szo.assign(n, 1), arrs.resize(n);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i < n; i ++) arrs[i] = {i};

    while(q --){
        cin >> t >> a >> b;
        if(t == 1){
            a --, b--;
            uni(a, b);
        }else{
            a --;
            a = find(a);
            if(sz(arrs[a]) < b) cout << -1 << endl;
            else cout << arrs[a][b-1] + 1 << endl;
        }
    }

    return 0;
} 
