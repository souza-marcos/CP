#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    int x, n, m;
    while(t--){
        cin >> x >> n >> m;
        while(n-- && x > 20){
            x = x/2 +10;
        }
        while(m --){
            x -= 10;
        }
        if(x <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
} 
