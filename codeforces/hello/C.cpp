#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    cout << "=====================\n";
    int l, r; cin >> l >> r;
    int maxval = -INF;
    tuple<int, int, int> res;
    for(int i = l; i <= r; i ++)
        for(int j = i+1; j <= r; j ++)
            for(int k=j+1; k <= r; k ++){
                int val = (i ^ j) + (j ^ k) + (i ^ k);
                if (val >= maxval){
                    maxval = val;
                    res = make_tuple(i, j, k);
                    cout << i << " " << j << " " << k << " => " << val << endl;
                }
            }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
