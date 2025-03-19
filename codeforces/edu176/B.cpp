#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    int n, k; cin >> n >> k;
    vector<int> arr(n); for(auto& el: arr) cin >> el;
    if(k == 1){
        
        int maxval = -INF;
        for(int i = 0; i < n; i ++){
            int val = 0;
            if(n-1-i > i) val = arr[n-1];
            else if(n-i-1 == i) val = max(arr[n-1], arr[0]);
            else val = arr[0];
            maxval = max(maxval, arr[i] + val);
        }
        cout << maxval << endl;
    }
    else {

        ll maxval = -LINF;
        for(int i = 0; i < n; i ++){
            int maxbef = -1, maxafter = -1;

            for(int j = 0; j < i; j ++) if(arr[j] > maxbef) maxbef=arr[j];
            for(int j = i+1; j < n; j ++) if(arr[j] > maxafter) maxafter=arr[j];

            bool ok[3]; ok[0] = ok[1] = ok[2] = 0;
            vector<int> res;
            for(int j = 0; j < n; j ++){
                if(!ok[0] and arr[j] == maxbef){
                    ok[0] = true;
                    continue;
                }
                else if(!ok[1] and arr[j] == arr[i]){
                    ok[1] = true;
                    continue;
                }
                else if(!ok[2] and arr[j] == maxafter){
                    ok[2] = true;
                    continue;
                }
                res.push_back(arr[j]);
            }

            sort(res.rbegin(), res.rend());

            k -= (maxbef != -1) + (maxafter != -1);
            ll val = 0;
            for(int i = 0; i < k; i ++) val += res[i];
            maxval = max(maxval, val + arr[i] + (maxbef != -1?maxbef:0) + (maxafter != -1?maxafter:0));
        }
        cout << maxval << endl;

    }


}

int main(){ _
    int t; cin >> t;
    while(t --) solve();    
    return 0;
} 
