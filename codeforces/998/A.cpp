#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

bool ckmax(int& a, int b){
    if(a >= b) return false;
    a = b;
    return true;
}

void solve(){
    int v[5]; cin >> v[0] >> v[1] >> v[3] >> v[4];
    
    int mxv = -INF; int el = 0;
    for(int i = -110; i < 110; i ++){
        int cnt = 0;
        v[2] = i;
        for(int j = 0; j < 3; j ++){
            cnt += (v[j + 2] == v[j + 1] + v[j]); 
        }
        if(ckmax(mxv, cnt)) el = i;
    }
    cout << mxv << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
