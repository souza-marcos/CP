#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n; cin >> n;
    map<int, int> dict = {{4, 0}, {8, 1}, {15, 2}, {16, 3}, {23, 4}, {42, 5}};

    vector<int> arr(n); for(int& el: arr) cin >> el;

    vector<int> cnt(6, 0);

    for(auto el : arr){
        int idx = dict[el];
        if(idx == 0) cnt[idx] ++;
        else {
            if (cnt[idx-1] > cnt[idx]) cnt[idx] ++; 
        }
    }
    // for(int el: cnt) cout << el << " ";
    // cout << endl;

    cout << n - cnt[5] * 6 << endl;
    return 0;   
} 
