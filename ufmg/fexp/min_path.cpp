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
    Matrix(int n, int m){cont.resize(n, vector<ll>(m, LINF));}
    
    friend Matrix operator*(const Matrix& a, const Matrix& b){
        assert(sz(a.cont[0]) == sz(b.cont));
        Matrix res(sz(a.cont), sz(a.cont));
        auto& cc = res.cont;

        for(int i = 0; i < sz(a.cont); i ++){
            for(int j = 0; j < sz(a.cont); j ++){
                for(int k = 0; k < sz(a.cont); k++){
                    cc[i][j] = min(cc[i][j], a.cont[i][k] + b.cont[k][j]);
                }
            }
        }
        return res;
    }


    friend Matrix operator^(Matrix a, ll n){
        Matrix res(sz(a.cont), sz(a.cont));
        for(int i = 0; i < sz(a.cont); i ++) 
            res.cont[i][i] = 0;
        
        while(n){
            if(n&1) res = res * a; 
            a = a * a;
            n >>= 1;
        }
        return res;
    }
    
    void print(){
        for(int i = 0; i < sz(cont); i ++){
            for(int j = 0; j < sz(cont); j++){
                cout << cont[i][j] << " ";
            }
            cout << endl;
        }
    }

};


int main(){ _

    cout << fixed << setprecision(10);
    int n, m, k; cin >> n >> m >> k;
    Matrix a(n, n);
    for(int i = 0; i < m; i ++){
        int v, u, w; cin >> v >> u >> w; v --, u --;
        a.cont[v][u] = w;
    }
    Matrix res = (a ^ k);
    
    ll minv = LINF;
    for(int i = 0; i < sz(res.cont); i ++){
        for(int j = 0; j < sz(res.cont); j++){
            minv = min(minv, res.cont[i][j]);
        }
    }
    // res.print(); cout << endl;

    if(minv >= 4e18) cout << "IMPOSSIBLE\n";
    else cout << minv << endl;
    
    return 0;
} 
