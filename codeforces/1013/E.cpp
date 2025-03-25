#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

const int MAX = 1e7 + 10;
bool isprime[MAX];


void solve(){
    int n; cin >> n;
    memset(isprime, 1, n * sizeof(bool) + 10);

    isprime[0]=isprime[1]=false;
    ll cnt = 0;
    for(int i = 2; i <= n; i ++){
        if(isprime[i]){
            cnt += n/i;
            // cnt -= i-1;
            for(int j = 2*i; j <=n; j += i){
                isprime[j] = false; // cnt --;
            }
        }
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
