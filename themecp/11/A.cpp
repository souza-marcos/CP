#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    // Quero pegar o min val para ser divisivel de k

    vector<int> arr(n); for(auto & el: arr) cin >> el;
    
    if(k == 4){
        pair<int, int> minv = {INF, INF};
        int mv4 = INF;
        for(auto a: arr) { 
            
            bool select = false;
            for(int i = 0; i < k; i ++, a++) {
                if(a % 2 == 0 and !select){
                    auto l = min(minv.first, i);
                    pair<int, int> aux = {l, min(l ^ minv.first ^ i, minv.second)};
                    minv = aux;
                }
                if(a%4 == 0) mv4 = min(mv4, i);
            }
        }
        cout << min(mv4, minv.first + minv.second) << endl;
    }
    else {
        int minv = INF;
        for(auto a: arr) { 
            for(int i = 0; i < k; i ++, a++) {
                if(a%4 == 0) minv = min(minv, i);
            }
        }
        cout << minv << endl;
    }   
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
