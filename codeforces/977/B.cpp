#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, x; cin >> n >> x;
    vector<int> arr(n); for(int& el: arr) cin >> el;
    sort(arr.begin(), arr.end());
    map<int, queue<int>> mp;

    int cur_mex = 0;
    for(int i = 0; i < n; i ++){
        mp[arr[i]%x].push(arr[i]);
    }
    
    for(int i = 0; i < n; i ++){

        if(mp.count(cur_mex%x) == 0) break;
        if(mp[cur_mex%x].size() == 0) break;

        int fr = mp[cur_mex%x].front(); mp[cur_mex%x].pop();
        if(fr <= cur_mex) cur_mex ++;
        else break;
    }
    cout << cur_mex << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();    

    return 0;
} 
