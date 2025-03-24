#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ // _

    int n, m; cin >> n >> m;
    vector<string> s(n), t(m);
    for(auto& el: s) cin >> el;
    for(auto& el: t) cin >> el;

    // cout << s[0] << endl << t[0] << endl;

    auto test = [&](int a, int b) -> bool {
        if(max(a, b) + m > n) return false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j ++){
                if(s[i + a][j + b] != t[i][j]) return false;
            }
        }
        return true;
    };

    for(int i = 0; i + m <= n; i ++){
        for(int j = 0; j + m <= n; j ++){
            // cout << "Testing " << i << " " << j << endl;
            bool ok = test(i, j);
            if(ok){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    assert(false);

    return 0;
} 
