#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    auto query = [&](int i, int j, int k) -> int {
        cout << "? " << i << " " << j << " " << k << endl;
        cout.flush();
        int res; cin >> res;
        if(res == -1) exit(0);
        return res;
    };

    int n; cin >> n;
    int p[3]; p[0] = 1, p[1] = 2, p[2] = 3;
    while(true){
        int res = query(p[0], p[1], p[2]);
        if(res==0) {
            cout << "! " << p[0] << " " << p[1] << " " << p[2] << endl;
            cout.flush();
            return;
        }
        p[rand()%3] = res;
    }

    
}

int main(){ _
    srand(time(0));
    int t; cin >> t;
    while(t--) solve();
} 
