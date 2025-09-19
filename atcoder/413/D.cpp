#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
   
int main(){ _
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        vector<ll> arr(n); for(auto& el: arr) cin >> el;

        sort(arr.begin(), arr.end(), [](auto left, auto right) {
            return abs(left) < abs(right);
        });


        bool ok = true;
        int cnt = 1;

        for(int i = 1; i < n; i ++){
            if(arr[i] == arr[0]) cnt++;
            else if(arr[i] == -arr[0]) cnt --;
            else ok = false;
        }
        if(ok and (abs(cnt) <= 1 or cnt == n)){
            cout << "Yes\n";
            continue;
        }

        ok = true;

        for(int i = 0; i + 2 < n; i ++){
            if(arr[i]*arr[i + 2] != arr[i+1] * arr[i + 1]){
                cout << "No\n";
                ok = false;
                break;
            }
        }
        if(ok) cout << "Yes\n";
    }
    return 0;
} 
