#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

set<int> factors;
void factorize(int a){
    for(int i = 1; i * i <= a; i ++)
        if(a % i == 0) {
            if(i % 2 == 0) factors.insert(i/2 + 1);
            if((a / i) % 2 == 0) factors.insert((a / i) / 2 + 1);
        }
}

void solve(){
    int n, x; cin >> n >> x;
    int a = n + x - 2, b = n - x;
    factorize(a);
    factorize(b);

    long long ans = 0;
    for(auto el: factors) if(el >= x) ans++;
    
    cout << ans << endl;

}


int main(){ _
    int t; cin >> t;
    while(t --) {
        factors.clear();
        solve();
    }
    return 0;
} 
