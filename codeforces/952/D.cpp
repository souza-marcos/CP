#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

void solve(){
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for(string& s: v) cin >> s;

    int up_j, down_i;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == '#'){
                up_j = j; break;
            }
        }
    }

    for(int j = 0; j < m; j++){
        for(int i =0; i < n; i ++){
            if(v[i][j] == '#'){
                down_i = i; break;
            }
        }
    }

    cout << down_i + 1 << " " << up_j + 1<< endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
