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
    set<string> s;
    vector<string> arr(n); for(auto& el : arr) cin >> el;
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            s.insert(arr[i] + arr[j]);
            s.insert(arr[j] + arr[i]);
        }
    }
    cout << sz(s) << endl;
    return 0;
} 
