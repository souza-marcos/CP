#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;

struct Matrix{
    vector<vector<ll>> cont;
    Matrix(int n, int m){cont.resize(n, vector<ll>(m));}

    friend Matrix operator*(const Matrix& a, const Matrix& b){
        assert(sz(a.cont[0]) == sz(b.cont));
        Matrix res(sz(a.cont), sz(b.cont[0]));
        auto& cc = res.cont;

        for(int i = 0; i < sz(a.cont); i ++){
            for(int j = 0; j < sz(b.cont[0]); j ++){
                cc[i][j] = 0;
                ll val = 0;
                for(int k = 0; k < sz(b.cont); k ++){
                    val += (a.cont[i][k] * b.cont[k][j]) % MOD;
                    if(val >= MOD) val -= MOD;
                }
                cc[i][j] = val;
            }
        } 

        return res;
    }


    friend Matrix operator^(Matrix a, ll n){
        Matrix res(sz(a.cont), sz(a.cont));
        for(int i = 0; i < sz(a.cont); i ++) res.cont[i][i] = 1;
        while(n){
            if(n&1) res = res * a; 
            a = a * a;
            n >>= 1;
        }
        return res;
    }
    
};


int main(){ _

    cout << fixed << setprecision(10);
    int n, m, k; cin >> n >> m >> k;
    Matrix a(n, n);
    for(int i = 0; i < m; i ++){
        int v, u; cin >> v >> u; v --, u --;
        a.cont[v][u] = 1;
    }

    Matrix fr(n, 1); 
    for(int i = 0; i < n; i ++) fr.cont[i][0] = 1; // One way of get out of vertex i

    Matrix res = (a ^ k) * fr;
    ll cnt = 0;
    for(int i = 0; i < n; i ++){
        cnt += res.cont[i][0];
        if(cnt >= MOD) cnt -= MOD;
    }
    cout << cnt << endl;
    return 0;
} 
