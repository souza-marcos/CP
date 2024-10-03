#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, A, B;
vector<int> arr;

ll memo[41][41][41][41];

ll dp(int i, int nr, int ares, int bres){
    if(i >= n){
        // cout << nr << " " << ares << " " << bres << endl;
        if(nr == 0 or nr == n) return LINF; 
        if(ares > 0 or bres > 0) return LINF;
        return abs(nr - (n - nr));
    }

    ll& p = memo[i][nr][ares][bres];
    if(p != -1) return p;

    return p = min(
        dp(i + 1, nr + 1, (ares * 10 + arr[i]) % A, bres),
        dp(i + 1, nr, ares, (bres * 10 + arr[i]) % B)
    );
}

void solve(){
    cin >> n >> A >> B;
    string s; cin >> s;
    arr.resize(n);
    for(int i = 0; i < n; i ++){
        arr[i] = s[i]-'0';
    }
    memset(memo, -1, sizeof memo);
    ll val = dp(0, 0, 0, 0);
    // cout << val << endl;
    if(val == LINF) cout << -1 << endl;
    else {
        int i = 0, nr = 0, ares = 0, bres = 0;
        while(i < n){
            ll red = dp(i + 1, nr + 1, (ares * 10 + arr[i]) % A, bres);
            ll black = dp(i + 1, nr, ares, (bres * 10 + arr[i]) % B);
            if(red <= black){
                cout << "R";
                nr ++;
                ares = (ares * 10 + arr[i]) % A;
            }else{
                cout << "B";
                bres = (bres * 10 + arr[i]) % B;    
            }
            i ++;
        }
        cout << endl;
    }

    // for(int i = 0; i <= 40; i ++){
    //     for(int j = 0; j < 40; j ++){
    //         for(int k = 0; k < 40; k ++){
    //             for(int l = 0; l < 40; l ++){
    //                 if(memo[i][j][k][l] == -1) continue;
    //                 cout << i << ", " << j << ", " << k << ", " << l << "=> " << memo[i][j][k][l] << endl; 
    //             }
    //         }
    //     }
    // }
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
