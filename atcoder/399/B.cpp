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
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.rbegin(), arr.rend());
    vector<int> res(n);
    int cnt = 1;
    for(int i=0; i < n; i ++){
        if(i > 0 and arr[i].first != arr[i-1].first)
            cnt = i + 1;
        res[arr[i].second] = cnt;        
    }
    for(auto el : res) cout << el << endl;

    return 0;
} 
