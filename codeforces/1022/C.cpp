#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n ; cin >> n;
    vector<int> arr;
    arr.push_back(-INF);
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        if(arr.back() != a)
            arr.push_back(a); 
    }
    arr.push_back(-INF);
    int cnt=0;
    for(int i = 1; i < sz(arr)-1; i ++){
        cnt += (arr[i-1] < arr[i] and arr[i] > arr[i+1]);
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
