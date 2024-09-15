#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a + 1 != c) { cout << -1 << endl; return; }
    if(a + b + c == 1) { cout << 0 << endl; return; }
    if(a == 0) { cout << b << endl; return; }

    int m = 1, cont = 0;
    while(m - 1 < a) m *= 2, cont ++; 
    m /= 2;
    int cur_level = m --;

    b -= (cur_level - (a - m)); // Completar o ultimo level
    cur_level += (a - m);
    while(b > 0){
        b -= cur_level; cont ++;
    }

    cout << cont << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
