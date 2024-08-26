#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// a -> Total time
// b -> First alarm
// c -> Next alarm
// d -> Fall in sleep

// (a - b)/(c - d)
// if(d > c) return -1;

// 5 9 4 10

// 

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    ll time = 0;
    if(a <= b){
        cout << b << endl; return;
    }
    if(c <= d){
        cout << -1 << endl; return;
    }
    time = ceil((float)(a - b)/(c - d));

    cout << b + time * c << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
