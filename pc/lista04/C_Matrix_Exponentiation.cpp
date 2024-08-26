#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

const int MOD = 1000000007;

struct Matrix{
    vector<vector<ll>> cont;
    Matrix(int n, int m){
        cont.resize(n, vector<ll>(m));
    }
    Matrix(vector<vector<ll>> c){
        cont = c;
    }

    Matrix friend operator*(const Matrix& a, const Matrix& b){
        Matrix res(sz(a.cont), sz(b.cont[0]));

        for(int i = 0; i < sz(a.cont); i++){
            for(int j = 0; j < sz(b.cont[0]); j++){
                for(int k = 0; k < sz(b.cont); k++){
                    res.cont[i][j] = (res.cont[i][j] + a.cont[i][k]*b.cont[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix friend operator^ (const Matrix& a, ll n){

        Matrix res(sz(a.cont), sz(a.cont[0]));
        for(int i = 0; i < sz(a.cont); i++) res.cont[i][i]= 1;

        Matrix base = a;

        while(n){
            if(n&1ll) res = res * base;
            base = base * base;
            n >>= 1;
        }
        return res;
    }
};


int main(){ _

    ll n; cin >> n;
    Matrix a({{1, 1}, {1, 0}});
    Matrix b(vector<vector<ll>>({{1}, {0}}));

    if(n <= 1) { cout << n << endl; return 0; }

    Matrix res = (a ^ (n - 1)) * b;

    cout << res.cont[0][0] << endl;

    return 0;
} 
