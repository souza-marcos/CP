#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n, q; cin >> n >> q;
    string a; cin >> a; string b; cin >> b;

    vector<vector<int>> prefa(n+1, vector<int>(26, 0)), prefb(n+1,vector<int>(26, 0));

    for(int i = 0; i < n;i++){
        for(int j=0; j < 26;j++){
            prefa[i+1][j] = prefa[i][j];
            prefb[i+1][j] = prefb[i][j];
        }

        prefa[i+1][a[i]-'a'] ++;
        prefb[i+1][b[i]-'a'] ++;
    }

    while(q --){
        
        int l, r; cin >> l >> r;
        
        int res = 0;
        for(int i = 0; i < 26; i ++){
            int qa = prefa[r][i] - prefa[l-1][i];
            int qb = prefb[r][i] - prefb[l-1][i];

            if(qa > qb) res += (qa - qb);
        }
        cout << res << endl;
    }

}

int main() { _
    int t; cin >> t;
    while(t --) solve();
}