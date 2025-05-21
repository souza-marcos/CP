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
    vector<int> arr(m); for(auto& el : arr) cin >> el;
    sort(arr.begin(), arr.end());

    // Save a interval cost 2 times.
    vector<int> intervals;
    for(int i = 0; i < m-1; i ++){
        if(arr[i + 1] - arr[i] - 1 > 0)
            intervals.push_back(arr[i + 1] - arr[i] - 1);
    }
    if(arr[0] + n - arr[m-1]-1 > 0)
        intervals.push_back(arr[0] + n - arr[m-1]-1);

    sort(intervals.rbegin(), intervals.rend());

    int time = 0;
    ll cnt = 0;
    for(auto it : intervals){
        if(it-2*time <= 0){
            break;
        }
        if(it-2*time == 1) cnt ++;
        else {
            cnt += it-2*time-1;
        }
        time += 2;
    }
    cout << n - cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
