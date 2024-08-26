#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &el: arr) cin >> el;

    sort(arr.begin(), arr.end());
    
    int minsum = INF;
    for(int i = 0; i < n; i++) minsum = min(minsum, arr[i] + arr[n - i - 1]);

    cout << minsum << endl;
    return 0;
} 
