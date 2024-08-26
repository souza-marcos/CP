#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L; 
#define sz(x) (int)x.size()

const int MOD = 1e6;

struct Matrix{
    vector<vector<ll>> cont;

    Matrix friend operator* (const Matrix& a, const Matrix& b){
        
        Matrix res;
        auto& cont = res.cont;
        int dim_a = sz(a.cont), dim_b = sz(b.cont[0]);

        cont.assign(dim_a, vector<ll>(dim_b, 0));
        for(int i = 0; i < dim_a; i ++) for(int j =0; j < dim_b; j++){
            for(int k = 0; k < sz(b.cont); k ++){
                cont[i][j] += a.cont[i][k] * b.cont[k][j];
                cont[i][j] %= MOD;
            }
        }
        return res;
    }

    void print(){
        for(int i = 0; i < sz(cont); i ++){
            for(int j = 0; j < sz(cont[0]); j++){
                cout << cont[i][j] << " ";
            }
            cout << endl;
        }
    }
};

Matrix powmat(Matrix base, ll n){
        Matrix res;
        int dim = sz(base.cont);
        auto& cont = res.cont;
        cont.assign(dim, vector<ll>(dim, 0));
        // Identidade
        for(int i = 0; i < dim; i ++) cont[i][i] = 1;
            
        while(n){
            if(n & 1) res = res * base;
            base = base * base;
            n >>= 1;
        }
        return res;
    }


void print_res(int res){
    res %= MOD;
    // cout << res << endl;
    vector<int> ans(6);
    int i = 5;
    while(res){
        ans[i--] = res%10;
        // cout << res << " "; 
        res /= 10;
    }
    for(auto el: ans) cout << el;
    cout << endl;
}

ll n, m, o; 

void solve(){

    n /= 5;
    m %= MOD, o %= MOD;

    if(n == 1) { print_res(m); return; }
    Matrix a, b;
    a.cont= {{m, o}, {1, 0}};
    b.cont= {{m}, {1}};

    Matrix c = (powmat(a, n-1)) * b;    
    print_res(c.cont[0][0]);
    // a.print(), b.print(), c.print();

}

int main(){
    
    while(cin >> n >> m >> o) solve();
}
