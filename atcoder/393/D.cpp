#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> arr;
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i ++){
        if(s[i] == '0') cnt ++;
        else arr.push_back(cnt);
    }

    int m1 = arr[sz(arr)/2];
    ll res = 0;
    for(auto el : arr) res += abs(el-m1);
    cout << res << endl;
    return 0;
} 
