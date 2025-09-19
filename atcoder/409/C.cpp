#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _ 

    int n, l; cin >> n >> l;
    vector<int> d(n);
    d[0] = 0; 
    vector<int> cnt(l);
    cnt[0]=1;
    for(int i = 1; i < n; i ++){
        int a; cin >> a;
        a += d[i-1];
        a %= l;
        d[i] = a;
        cnt[a] ++;
    }
    if(l%3 != 0){
        cout << 0 <<endl;
    } else{
        ll res = 0;
        for(int i = 0; i < l/3; i ++){
            res += cnt[i] * cnt[i + l/3] * cnt[i + 2*l/3];
        }
        cout << res << endl;
    }
    return 0;
} 
