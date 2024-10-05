#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()
#define endl '\n'

int main(){ _
    int n, k; cin >> n >> k;
    vector<int> arr(n); for(auto& el: arr) cin >> el;
    
    // maintain 
    deque<pair<int, int>> dqmin; 
    int i=0;
    for(; i < k; i ++){
        while(!dqmin.empty() and dqmin.back().first >= arr[i]){
            dqmin.pop_back();
        }
        dqmin.push_back({arr[i], i});
    }
    cout << dqmin.front().first << " ";
    for(; i < n; i ++){
        while(!dqmin.empty() and dqmin.front().second <= (i - k)) dqmin.pop_front();
        while(!dqmin.empty() and dqmin.back().first >= arr[i]) dqmin.pop_back();
        dqmin.push_back({arr[i], i});
        cout << dqmin.front().first << " ";
    }
    cout << endl;

    return 0;
} 
