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
    int n; cin >> n;
    int arr[n][n];

    int ans[n];
    for(int i = 0; i < n; i ++) ans[i] = (1 << 30) - 1;

    int temp;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> arr[i][j];
            if(i == j) continue;
            ans[i] &= arr[i][j];
        }
    }


    // Testing values
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            if(i == j) continue;
            if((ans[i] | ans[j]) != arr[i][j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(auto el: ans) cout << el << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
