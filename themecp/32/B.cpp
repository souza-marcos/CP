#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int cnt[6][54]; // size of word - val sum

int main(){ _
    int n; cin >> n;
    vector<string> arr(n);
    for(auto& el : arr) cin >> el;

    ll res = 0;
    for(int i = 0; i < n; i ++){
        string& cur = arr[i];
        vector<int> suf(sz(cur) + 1, 0);
        for(int j = sz(cur) -1; j >= 0; j --)
            suf[j] = suf[j+1] + (cur[j]-'0');

        
        // (pre + suf) + res
        // pre (sum) == suf(suf[j+1]) + res (sum - suf[j+1])
        // pre (j digit) <-> suf(m-j) + res(2j - m) (j digit)


        int sum = 0;
        for(int j = 0; j < sz(cur); j ++){
            sum += (cur[j] - '0');
            int l = 2*(j + 1) - sz(cur);
            int need = suf[j + 1] - sum;
            if(need >= 0 and l >= 0){
                res += cnt[l][need];
            }
            if(need >= 0 and l < 0) 
                res += cnt[-l][need];
        }
        res += cnt[sz(cur)][sum];
        cnt[sz(cur)][sum] ++;
    }

    cout << 2 * res + n << endl;
    return 0;
} 
