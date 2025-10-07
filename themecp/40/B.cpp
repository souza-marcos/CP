// https://codeforces.com/problemset/problem/1733/D1
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, x, y; cin >> n >> x >> y;
    string s, t; cin >> s >> t;
    int cnt = 0;
    
    vector<bool> arr(n);
    for(int i = 0; i < n; i ++) cnt += arr[i] = s[i] != t[i];
    if(cnt & 1) return void(cout << -1 << endl);


    int res = 0;
    for(int i = 0; i < n ; i++){
        if(arr[i] == 0) continue;
        int first = -1, second = -1;
        for(int j = i + 1; j < n; j ++){
            if(arr[j] and first == -1) first = j;
            else if(arr[j] and second == -1){
                second = j;
                break;
            } 
        }
        if(second >= 0){
            res += y;
            arr[i] = arr[second] = 0;
        }
        else {
            if(first == i + 1){
                if(2 * y < x and n > 3) res += 2*y;
                else res += x;
            }
            else {
                res += y;
            }
            arr[i] = arr[first] = 0;
        }
    }
    cout << res << endl;
}


int32_t main(){ _ 
    int t; cin >> t;
    while(t --) solve();
} 
