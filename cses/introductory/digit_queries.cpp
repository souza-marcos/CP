#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    string test;
    for(int i = 1; i < 10000; i ++)
        test.append(to_string(i));

    int q; cin >> q;
    while(q--){
        ll k; cin >> k;

        ll l = 0, r = 9, i = 1;
        while((r - l + 1) * i <= k){
            k -= (r - l + 1) * i;
            l = r + 1;
            r = r *10 + 9;
            i ++;
        }
        // cout << l << " " << r << " " << k << " " << i << endl; 
        // I need the k-th element in the range [l, r]
        ll j = k/i;
        l += j;
        cout << to_string(l)[k%i] << endl;
    }


    return 0;
} 
