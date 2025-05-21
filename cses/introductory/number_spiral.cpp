#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    int t; cin >> t;
    while(t --) {
        int x, y; cin >> x >> y;

        if(x==1 and y==1) cout << 1 << endl;
        else {
            ll val = max(x, y);
            ll start = (val - 1) * (val - 1);
            if(val%2 == 0){
                if (x > y) x += x-y; 
                cout << start + x << endl;
            } else {
                if (y > x) y += y-x;
                cout << start + y << endl;
            }
        }
    }

    return 0;
} 
