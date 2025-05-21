#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){

    int n, k; cin >> n >> k;
    int cnt = 0;
    vector<int> arr(n); 
    for(auto& el : arr) cin >> el, el = (el > k), cnt += (el == 0);//, cout << el << " ";
    // cout << endl;

    // No mínimo dois segmentos bons 
    // Escolho se o prefixo vai ser bom ou ruim 

    // min Prefixo e Sufixo
    auto f = [&](vector<int>& arr){
        int fr = INF, cur = 0; 
        for(int i = 0; i < n; i ++){
            int val = (arr[i] ? +1 : -1);
            if(cur + val <= 0) {
                fr = i;
                break;
            }
            cur += val;
        }
        int sn = 0; cur = 0;
        for(int i = n-1; i >= 0; i --){
            int val = (arr[i] ? +1 : -1);
            if(cur + val <= 0) {
                sn = i;
                break;
            }
            cur += val;
        }
        if(sn - fr > 1){
            return true;
        }

        // min max prefixo bom + meio
        sn = n, cur = 0;
        for(int i = fr + 1; i < n; i ++){
            int val = (arr[i] ? +1 : -1);
            if(cur + val <= 0) {
                sn = i;
                break;
            }
            cur += val;
        }
        if(sn < n- 1) return true;
        

        // mxprefixo
        int fr2 = INF; cur = 0; 
        for(int i = 0; i < n; i ++){
            int val = (arr[i] ? +1 : -1);
            if(cur < 0 and cur + val == 0) {
                fr2 = i;
                break;
            }
            cur += val;
        }

        sn = n, cur = 0;
        for(int i = fr2 + 1; i < n; i ++){
            int val = (arr[i] ? +1 : -1);
            if(cur + val <= 0) {
                sn = i;
                break;
            }
            cur += val;
        }

        if(sn < n-1) return true;
        return false;
    };

    bool ok = f(arr);
    reverse(arr.begin(), arr.end());
    ok |= f(arr);
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
