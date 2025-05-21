#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _ 
    int n; cin >> n;
    ll cnt = 0;
    int a, last; cin >> a;
    last = a;
    for(int i = 1; i < n; i ++){
        cin >> a;
        cnt += max(0, last - a);
        last = max(last, a);
    }
    cout << cnt << endl;
    return 0;
} 
