#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n, m;

struct Matrix{
    vector<vector<int>> cont;
    Matrix(int n, int m){
        cont.assign(n, vector<int>(m));
    }

    Matrix friend operator* (const Matrix& a, const Matrix& b){
        Matrix res(sz(a.cont), sz(b.cont[0]));

        for(int i = 0; i < sz(a.cont); i++){
            for(int j = 0; j < sz(b.cont[0]); j++){
                for(int k = 0; k < sz(b.cont); k ++){
                    res.cont[i][j] += a.cont[i][k] * b.cont[k][j];
                }
            }
        }
        return res;
    }

    Matrix friend operator^ (Matrix a, int n){
        Matrix res(sz(a.cont),sz(a.cont));
        for(int i = 0; i < sz(a.cont); i ++) res.cont[i][i] = 1;
        while(n){
            if(n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};

void solve(){
    vector<int> p(n); for(auto& el: p) cin >> el, el --;
    string s;

    cin.ignore(INF, '\n');
    getline(cin, s);

    vector<int> p_inverse(n);
    for(int i = 0; i < n; i ++){
        p_inverse[p[i]] = i;
    }

    Matrix a(n, n);
    for(int i=0; i < n; i++){
        a.cont[i][p_inverse[i]] = 1;
    }

    Matrix b = a ^ m;
    for(int i = 0; i < n; i ++){
        for(int j =0; j < n; j++){
            if(b.cont[i][j]){
                cout << s[j]; break;
            }
        }
    }
    cout << endl;
}

int main(){ _
    while( cin >> n >> m and n != 0) solve();
    return 0;
} 
