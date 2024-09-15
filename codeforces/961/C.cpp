#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> v(n);

    for(int &el : v) cin >> el;
    
    bool gret = false;
    for(int i = 0; i < n; i++){
        if(v[i] > 1) gret = true;
        if(v[i] == 1 and gret) { cout << -1 << endl; return; }
    }
 
    vector<int> pre(n);
    for(int i = 1; i < n; i++){
        ll a = v[i-1], b = v[i];
        if(a > b) swap(a, b);

        int cnt = 0;
        if(a != 1){
            while(a < b){
                // cout << a << " - ";
                a = a * a;
                cnt ++;
            }
            if(a > b and v[i] > v[i - 1]) cnt --;
        }
        pre[i] = cnt * ((v[i] < v[i -1]) ? 1 : -1);

    }

    ll cur = 0, cnt = 0;
    // cout << "Vec: ";
    for(auto el: pre){
        cur = max(0LL, cur + el);
        // cout << cur << " ";
        cnt += cur;
    }
    cout << cnt << endl;

}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
