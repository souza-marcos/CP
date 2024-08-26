#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n; cin >> n;
    ll sum = 0, level = 1;
    for(int i = 3; i <= n; i += 2){
        sum += level * ((i * i) - (i - 2)*(i - 2));
        level ++;
    }
    cout << sum << endl;
}


int main(){ _
    int t; cin >> t;
    while(t--) solve();


    return 0;
} 
