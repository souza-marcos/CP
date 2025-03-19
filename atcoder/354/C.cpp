#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
  
    int n; cin >> n;
    vector<tuple<int, int, int>> arr(n);
    for(int i = 0; i < n; i ++){
        auto& [a, c, idx] = arr[i];
        cin >> a >> c;
        idx = i + 1;
        a = -a;
    }
    sort(arr.begin(), arr.end());

    int minv = get<1>(arr[0]); 
    vector<int> res;
    res.push_back(get<2>(arr[0]));

    for(int i = 1; i < n; i ++){
        if(get<1>(arr[i]) < minv) minv = get<1>(arr[i]), res.push_back(get<2>(arr[i]));
    }
    sort(res.begin(), res.end());
    cout << sz(res) << endl;
    for(auto el: res) cout << el << " ";
    cout << endl;

    return 0;
} 
