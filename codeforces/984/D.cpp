#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for(auto& s:arr) cin >> s;

    ll cnt = 0;
    for(int i = 0; i < min(n, m)/2; i ++){

        string cur;
        // up
        for(int j = i; j < m-i-1; j ++){
            cur.push_back(arr[i][j]);
        }

        // right
        for(int j = i; j < n-i-1; j ++){
            cur.push_back(arr[j][m-i-1]);
        }

        // down
        for(int j = m-i-1; j > i; j --){
            cur.push_back(arr[n-i-1][j]);
        }

        // left
        for(int j = n-i-1; j > i; j --){
            cur.push_back(arr[j][i]);
        }

        for(int j= 0; j < sz(cur); j ++){
            if(cur[j]=='1' and cur[(j+1)%sz(cur)] == '5' and cur[(j+2)%sz(cur)] == '4' and cur[(j+3)%sz(cur)] == '3') 
                cnt ++;
        }
    }
    cout << cnt << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
