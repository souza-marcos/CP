#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sx(x) (int)x.size()
#define endl "\n"

void solve(){
    int n, k; cin >> n >> k;
    
        int a, min_diff = INF, cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> a;
            if(a % 2 == 0) cnt ++;

            if(a % k == 0) min_diff = 0;
            else min_diff = min(min_diff, k - a%k);
        }
        
        if(k != 4) { cout << min_diff << endl; return;}
    
        cout << min(min_diff, max(0, 2 - cnt)) << endl;
    
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
