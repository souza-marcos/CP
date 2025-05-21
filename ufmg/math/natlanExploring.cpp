// https://codeforces.com/contest/2037/problem/G
#include <bits/stdc++.h>
#define ll long long 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

#define sz(x) (int)x.size()
const int MOD = 998244353;

int main(){

    int n, maxv = -INF; cin >> n;
    vector<int> arr(n); for(auto& el: arr) cin >> el, maxv = max(maxv, el);

    vector<int> gdiv(maxv + 10); 
    iota(gdiv.begin(), gdiv.end(), 0);


    for(int i = 2; i <= maxv; i ++){
        if(gdiv[i] == i){ //eh primo
            for(int j = 2*i; j <= maxv; j += i)
                gdiv[j] = i;
        }
    }

    auto getDivs = [&](int el, vector<int>& divs) -> void {
        while(el != 1){
            divs.push_back(gdiv[el]); el /= gdiv[el];
            while(el % divs.back() == 0) el /= divs.back();
        }
    };  

    auto getMod = [&] (ll val) -> ll{
        return (val + MOD) % MOD; 
    };

    vector<ll> dp(maxv + 10, 0);
    ll res = 0;
    for(int i = 0; i < n; i ++){
        vector<int> divs;
        getDivs(arr[i], divs);

        ll cur = 0;
        for(int j = 1; j < (1 << sz(divs)); j ++){
            ll val = 1;
            int get = ((__builtin_popcount(j)&1)? +1 : -1);

            for(int k = 0; k < sz(divs); k ++){
                if((j >> k) & 1) val *= divs[k];
            }
            cur += get * dp[val];
            cur = getMod(cur);
        }        

        if(i == 0) cur = 1;

        for(int j = 1; j < (1 << sz(divs)); j ++){
            ll val = 1;
            for(int k = 0; k < sz(divs); k ++){
                if((j >> k) & 1) val *= divs[k];
            }
            dp[val] = getMod(cur + dp[val]);
        }
        
        //DEBUG
        // for(int i = 0; i < sz(dp); i ++){
        //     cout << dp[i] << " \n"[i == sz(dp)-1];
        // }
        res = cur;
    }
    cout << res << endl;
}