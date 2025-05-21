#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


// 0 1 4 9 16 25 ...

void solve(){
    int n; cin >> n;
    vector<int> res(n);

    auto getMax = [&](int i, int ai) -> int {
        int val = floor(sqrt(i + ai));
        return val*val;
    };
    int cur=n-1;

    while(cur >= 0){
        int top = getMax(cur,cur);
        for(int i = top - cur;
            i <= cur; i ++){
                res[i]=top-i;
        }
        cur = top - cur -1;
    }
    for(auto el : res) cout << el << " ";
    cout << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
