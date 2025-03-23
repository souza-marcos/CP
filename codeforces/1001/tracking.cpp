#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


void solve(){
    int n ; cin>>n;
    vector<ll> arr(n);
    
    ll sum = 0;
    for(auto& el: arr) cin >> el, sum += el;

    // for(int i = 0; i < n-1; i ++){
    //     cout << arr[i + 1] << "\t(-)\t" << arr [i] << "\t" << arr[i + 1] - arr[i] << endl;
    // }

    // cout << sum << endl;
    int res = 269891;
    auto track = [&](auto&& self, vector<ll> aux, int level){
        ll sum = 0;
        for(int el: aux) sum += el;
        if(sum == res) return true;

        if(level <= 1) return false;

        if(sz(aux) > 1){
            vector<ll> newarr(sz(aux) -1);
            for(int i = 0; i < sz(newarr); i ++){
                newarr[i] = aux[i + 1] - aux[i];
            } 
            if(self(self, newarr, level - 1)){
                cout << "DIFF\n";
                for(auto el: newarr){
                    cout << el <<" ";
                }
                cout << endl;
                return true;
            }

        }

        reverse(aux.begin(), aux.end());
        if(self(self, aux, level - 1)){
            cout << "REVERSE\n";
            for(auto el: aux){
                cout << el << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    };
    track(track, arr, 3 * sz(arr));

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
