#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> h(n); for(int& el: h) cin >> el;
    int memo[n];
    memo[n-1] = 0, memo[n-2] = abs(h[n-1]-h[n-2]);

    for(int i = n-3; i>= 0; i --)
        memo[i]=min(memo[i+1] + abs(h[i]-h[i+1]), memo[i+2] + abs(h[i]-h[i+2]));

    cout << memo[0] << endl;
    return 0;
} 
