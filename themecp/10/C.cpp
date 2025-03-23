#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> arr(n); for(auto& el: arr) cin >> el;

    vector<int> res;
    auto push = [&](int val){
        res.push_back(val);
        for(int i = 0; i < val; i ++) res.push_back(0);
    };

    if(arr.back() == 1){
        cout << "NO\n"; return;
    }

    int lastone = -1;
    bool zero = true;
    for(int i = 0; i < n; i ++){
        if(arr[i] == 0){
            if(lastone != -1){
                push(i - lastone);
                lastone = -1;
            } else push(0);

            zero = true;
        } else {
            if(zero) lastone = i, zero = false;
        }
    }
    reverse(res.begin(), res.end());
    cout << "YES\n";
    for(auto el : res) cout << el << " ";
    cout << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
