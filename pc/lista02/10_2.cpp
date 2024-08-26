#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

typedef long long ll;
#define sz(x) (int)x.size()
const int MOD = 1e9 + 7;

vector<int> dig;
ll memo[2][20][120];
int vis[2][20][120], cnt;


ll dp(int pos, int isSmall, int sum)
{
    if(pos == sz(dig)){
        return sum;
    }

    ll &ret = memo[isSmall][pos][sum];
    int &v = vis[isSmall][pos][sum];

    if(v == cnt){
        return ret;
    }
    v = cnt;

    int last = (isSmall) ? 9 : dig[pos];
    ret = 0;

    for(int i = 0; i <= last; i++){
        ret += dp(pos + 1, isSmall | i < dig[pos], sum + i);
        ret %= MOD;
    }

    return ret;
}

void to_digit(int k){
    dig.assign({});
    while(k) dig.push_back(k%10), k/=10;
    reverse(dig.begin(), dig.end());
}

int main(){_
    ll n, m;
    while(cin >> n >> m){
        to_digit(n-1);
        cnt++;
        ll a = dp(0, 0, 0);
        to_digit(m);
        cnt ++;
        ll b = dp(0, 0, 0);
        cout << b - a << endl;
    }

    return 0;
}