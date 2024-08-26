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

    int n; cin >> n;
    vector<int> v(n);
    for(auto& el: v) cin >> el;
    int k; cin >> k;

    sort(v.begin(), v.end());
    vector<int> res;

    while(k --){

        int l, r; cin >> l >> r;
        auto lo = lower_bound(v.begin(), v.end(), l);
        auto hi = upper_bound(v.begin(), v.end(), r);

        cout << (hi - lo);
        if(k == 0) cout << endl;
        else cout << " ";
    }
    return 0;
} 
