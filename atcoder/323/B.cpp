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
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i ++){
        int cnt = 0;
        string s; cin >> s;
        for(auto c : s) if(c=='o') cnt ++;
        vec.push_back({-cnt, i});
    }
    sort(vec.begin(), vec.end());
    for(auto[ val, idx] : vec){
        cout << idx + 1 << " ";
    }
    cout << endl;
} 
