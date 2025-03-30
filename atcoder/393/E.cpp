#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, k; cin >> n >> k;
    
    vector<int> cnt(1e6 + 1);
    int maxel = -INF;
    vector<int> arr(n); 
    for(auto& el: arr) cin >> el, maxel = max(maxel, el), cnt[el] ++;

    vector<int> isRes(maxel + 1);
    vector<int> ans(maxel + 1, 1);

    for(int d = 2; d <= maxel; d ++){
        for(int el = d; el <= maxel; el += d) 
            isRes[d] += cnt[el]; 

        if(isRes[d] >= k){
            for(int el = d; el <= maxel; el += d) 
                ans[el] = d;
        }
    }

    for(auto el : arr) cout << ans[el] << endl;

    return 0;
} 
