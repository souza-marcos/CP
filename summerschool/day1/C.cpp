#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, m; cin >> n >> m;
    int mink = INF;
    for(int i =0; i <m; i ++){
        int l, r; cin >> l >> r;
        mink = min(mink, r-l+1);
    }
    cout << mink << endl;
    for(int i = 0; i < n; i ++){
        cout << i % mink << " ";
    }
    cout << endl;
} 
