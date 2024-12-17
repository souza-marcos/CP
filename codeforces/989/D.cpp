#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; cin >> n;
    int cnt[4] = {0};
    vector<int> arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        cnt[arr[i]] ++;
    }
    vector<int> right(n);
    int cur = 0;
    for(int i = 0 ; i < n; i ++){
        while(cur < 3 and cnt[cur] == 0) cur ++;
        right[i] = cur;
        cnt[cur] --;
    }

    for(auto el : right) cout << el << " ";
    cout << endl;

    // Trocar pares otimos => 1 => 2 2 => 1 etc caso existam

    queue<int> q[3][3]; 
    vector<pair<int , int>> res;
    for(int i = 0; i < n; i ++){
        q[arr[i]][right[i]].push(i);
    }

    


}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
