#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n, x, y; cin >> n;
    set<int> zero, one;
    for(int i = 0; i < n; i ++){
        cin >> x >> y;
        if(y) one.insert(x);
        else zero.insert(x);
    }
    ll cnt = 0;
    for(int x_one: one){
        if(zero.count(x_one)){
            cnt += sz(zero) -1 + sz(one) -1;
        }
        cnt += (zero.count(x_one -1) and zero.count(x_one +1));
    }
    for(int x_zero: zero){
        cnt += (one.count(x_zero + 1) and one.count(x_zero - 1));
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
