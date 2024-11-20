#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _
    int n; ll k; cin >> n >> k;
    vector<int> p(n); for(int&el : p) cin >> el, el --;

    auto bin = [&](vector<int>& res, vector<int>& fr, vector<int>& snd){
        vector<int> ans(n);
        for(int i = 0; i < n; i ++){
            ans[i] = fr[snd[i]];
        }
        res = ans;
    };

    k = k % n;
    vector<int> ans = p;
    while(k > 0){
        if(k & 1) bin(ans, ans, p);
        bin(p, p, p);
        k >>= 1;
    }

    for(int el : ans) cout << el + 1 << " "; 
    cout << endl;
    return 0;
} 
