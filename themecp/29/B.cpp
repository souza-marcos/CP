#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> divs; // O(n^(1/3))
    for(int i = 1; i < n; i ++){
        if(n%i == 0) divs.push_back(i);
    }

    vector<vector<bool>> res(n, vector<bool>(26, 1));
    vector<int> vals(n);
    for(int i = 0; i < n; i ++){
        // Get the first color available
        int color = -1;
        for(int j = 0; j < 26; j ++){
            if(res[i][j]) {
                color = j;
                break;
            } 
        }
        assert(color != -1);
        vals[i] = color;
        for(int d : divs){
            if(d + i >= n) break;
            res[d + i][color] = 0;
        }
    }
    for(auto el: vals) cout << (char)('a' + el);
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
