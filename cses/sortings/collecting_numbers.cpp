#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<pair<int, int>> arr; 
    for(int i =0; i < n; i ++){
        int a; cin >> a;
        arr.emplace_back(a, i);
    }
    sort(arr.begin(), arr.end());
    
    int cnt = 1, cur = arr[0].second;
    for(auto [fr, sn] : arr){
        if(sn < cur) cnt++;
        cur = sn;
    }
    cout << cnt << endl;
    return 0;   
} 
