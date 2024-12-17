#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n,m; cin >> n >> m;
    vector<string> arr(n);
    for(auto& el: arr) cin >> el;

    auto f = [&](char el){
        return (el - '0');
    };

    for(int i = 0; i+1 < n; i ++){
        for(int j = 0; j+1 < m; j ++){
            int cnt = 0;
            cnt = f(arr[i][j]) + f(arr[i + 1][j]) + f(arr[i + 1][j + 1]) + f(arr[i][j + 1]);
            if(cnt == 3) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";

}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
