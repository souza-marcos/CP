#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n, k; cin >> n >> k;
    vector<string> arr;
    for(int i = 0; i < k; i++){
        string s; cin >> s;
        arr.push_back(s);
    }
    for(int i=k;i < n; i ++){
        string s; cin >> s;

    }
    sort(arr.begin(), arr.end());
    for(auto el: arr) cout << el << endl;
} 
