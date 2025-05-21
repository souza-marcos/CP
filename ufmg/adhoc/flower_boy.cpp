#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


void solve(){
    int n, m; cin >> n >> m;
    vector<int> flowers(n); for(auto& el : flowers) cin >> el;
    vector<int> buck(m); for(auto& el: buck) cin >> el;

    int j = 0;
    
    bool ok = false;
    for(int i = 0; i < m; i ++){
        while(j < n and flowers[j] < buck[i]) j++;
        if(j < n and flowers[j] >= buck[i] and i == m-1) ok = true;
        j ++;
    }
    if(ok){
        cout << 0 << endl;
        return;
    }

    vector<int> pre(m + 1, INF), suff(m + 1, -INF);
    j = 0;
    pre[0] = -1, suff[m] = n;
    for(int i = 0; i < m; i ++){
        while(j < n and flowers[j] < buck[i]) j ++;
        if(j >= n) break;
        pre[i+1]=j;j++;
    }

    j = n-1;
    for(int i = m-1; i >= 0; i--){
        while(j >= 0 and flowers[j] < buck[i]) j --;
        if(j < 0) break;
        suff[i]=j;j--;
    }

    int mink = INF;
    for(int i = 1; i <= m; i ++){
        
        // cout << pre[i-1] << " - " << suff[i + 1] << endl;
        if(pre[i-1] < suff[i])
            mink = min(mink, buck[i-1]);
    }   
    cout << (mink == INF ? -1 : mink) << endl;
}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
