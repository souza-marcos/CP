#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int n; vector<int> arr;

int main(){ _
    cin >> n; 
    arr.resize(n);
    for(auto &el : arr) cin >> el;
    sort(arr.begin(), arr.end());

    vector<bool> used(n, false);
    vector<int> res(n);
    for(int i = 0; i < n; i += 2)
        cout << arr[i] << " ", used[i] = true;

    for(int i = n-1; i >= 0; i --)
        if(!used[i]) cout << arr[i] << " ";

    cout << endl;
    return 0;
} 
