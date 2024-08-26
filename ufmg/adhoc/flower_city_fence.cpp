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
    vector<int> arr(n);
    for(auto &el : arr) cin >> el;

    if(n != arr[0]){ cout << "NO" << endl; return;}
    vector<int> b;

    for(int i = n -1; i >= 0; i--)
        while(b.size() < arr[i]) b.push_back(i + 1);


    for(int i = 0; i < n; i++){
        if(arr[i] != b[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
