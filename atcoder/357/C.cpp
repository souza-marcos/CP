#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

vector<vector<bool>> m;

void white(int l, int r, int u, int d){
    for(int j = u; j <= d; j++){
        for(int i = l; i <= r; i++) m[j][i] = 1;
    }
}

void fill(int l, int u, int k){
    if(k == 0) {
        m[u][l] = 0;
        return;
    }
    int size = pow(3, k-1);

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            if(i == 1 and j == 1)
                white(l + j * size, l+(j+1)*size, u + i * size, u+ (i + 1)*size);
            else 
                fill(l + j * size, u + i * size, k-1);
        }
    }
}
int main(){ _

    int n; cin >> n;
    int l = pow(3, n);

    m.assign(l, vector<bool>(l, 0));

    fill(0, 0, n);
    for(int i = 0; i < l; i++){
        for(int j =0; j < l; j++){
            cout << (m[i][j]?".":"#");
        }cout << endl;
    }

    return 0;
} 
