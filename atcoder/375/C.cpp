#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _
    int n; cin >> n;
    vector<string> a(n);
    for(auto&s : a) cin >> s;

    vector<string> b(n, string(n,'.'));

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            int d = (min({ i, j, n-i-1, n-j-1}) + 1) % 4;
            pair<int, int> cur = {i, j};
            while(d--){
                auto [newi, newj] = cur;
                pair<int, int> aux = {newj, n-newi-1};
                cur = aux;
            }
            b[cur.first][cur.second] = a[i][j];
        }
    }
    // cout << endl;
    for(int i = 0; i < n; i ++){
        cout << b[i] << endl;
    }

} 
