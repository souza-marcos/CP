#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int n, m;
vector<int> stand;
vector<vector<int>> memo;

int dp(int i, int mask){
    if(i == n) return (mask == ((1 << m) -1) ? 0: INF);

    int& p = memo[i][mask];
    if(p != -1) return p;

    return p = min(
        dp(i + 1, mask),
        dp(i + 1, mask | stand[i]) + 1
    );
}

int main(){ _
    cin >> n >> m;
    stand.resize(n);
    memo.assign(n, vector<int>(1 << m, -1));
    for(int& el: stand){
        string s; cin >> s;
        el = 0;
        for(char c: s){
            el = el << 1;
            el = el | (c == 'o');
        }
    }

    cout << dp(0, 0) << endl;


    return 0;
} 
