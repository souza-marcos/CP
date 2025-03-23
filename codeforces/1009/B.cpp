#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n; priority_queue<ll> pq;
    while(n --) {
        int a; cin >> a;
        pq.push(-a);
    }
    while(sz(pq) > 1){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        a = -a, b = -b;
        pq.push(-1 * (a + b - 1));
    }   
    cout << -pq.top() << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
