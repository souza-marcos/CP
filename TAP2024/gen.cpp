#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

int32_t main() { _
    int n = uniform(1, 1000), y = uniform(1, 20);
    cout << n << " " << y << endl;
    for(int i = 0; i < n; i++){
        cout << uniform(1, 10) << " ";
    }
}