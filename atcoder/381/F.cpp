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
    vector<int> arr(n); for(int& el: arr) cin >> el;
    vector<int> cnt(21, 0);

    auto clear = [&](){
        for(auto& el: cnt) el = 0;
    };

    int maxv = 0;
    for(int i = 0; i < n; i ++){
        if(cnt[arr[i]] == 1)
    }

    return 0;
} 
