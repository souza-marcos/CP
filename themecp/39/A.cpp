// https://codeforces.com/problemset/problem/1860/B
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

    int t; cin >> t;
    while(t --){
        int m, k, a1, ak; cin >> m >> k >> a1 >> ak;

        int buy = 0;
        if(m >= k){
            int use = min(m/k, ak);
            int falta = m/k - use;
            buy += falta;
            m %= k;

            // cout << "OK 1 - " << m << " " << use << " " << endl;
        }

        if(a1 >= m) {
            a1 -= m, m = 0;
            int blocks = a1/k;
            buy = max(0ll, buy - blocks);
            // cout << "OK 2 - " << a1 << " " << blocks << endl;
        } else{
            m -= a1;
            buy += m;
        }
        cout << buy << endl;
    }


} 
