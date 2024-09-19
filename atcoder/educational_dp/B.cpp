#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

int main(){ _
    int n, k, i = 0; cin >> n >> k;
    int memo[n];
    vector<int> h(n); for(int& el: h) cin >> el, memo[i++] = INF;
    memo[0] = 0;
    for(int i = 0; i < n; i ++){
        for(int j = i+1; j <= i+k and j < n; j ++){
            memo[j] = min(memo[j], memo[i] + abs(h[i] - h[j]));
        }
    }
    cout << memo[n-1] << endl;
    return 0;
} 
