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
        Matrix res(2, 2);
        res.cont = {{1, 0}, {0, 1}};
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
    ll n; cin >> n;
    Matrix m(2,2);
    m.cont[0][0] = 19, m.cont[0][1] = 6,
    m.cont[1][0] = 7, m.cont[1][1] = 20;

    Matrix fr(2, 1); fr.cont[0][0] = 1;
    Matrix res = (m ^ n) * fr;

    cout << res.cont[0][0] << endl;

    return 0;
} 
