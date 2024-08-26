#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    int arr[n];

    bool sorted = true;

    cin >> arr[0];
    for(int i = 1; i < n; i ++){
        cin >> arr[i];
        if(arr[i] < arr[i -1]) sorted = false;
    }
    cout << (sorted?"YES":(k > 1? "YES": "NO")) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
