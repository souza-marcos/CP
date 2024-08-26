#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;

#define sz(x) (int)x.size()

ll memo[20][180][2];
vector<int> digits;


ll dp(int i, int sum, int is_lim){
    if(i < 0) return sum;
    ll &p = memo[i][sum][is_lim];

    if(p != -1 and !is_lim) return p;

    ll ans = 0;
    int k = (is_lim)? digits[i] : 9;
    for(int j = 0; j <= k; j++){

        int new_lim = (digits[i] == j) ? is_lim : 0;
        ans += dp(i-1, sum + i, new_lim);
    }

    if(!is_lim) p = ans;
    return ans;
}

void to_digits(int n){
    while(n) digits.push_back(n%10), n /= 10;
}

void solve(){
    int n; cin >> n;
    to_digits(n);

    memset(memo, -1, sizeof memo);
    cout << dp(sz(digits)-1, 0, 1);

}

int main(){_
    solve();
    return 0;
}