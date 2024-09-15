#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    
    int n, k; cin >> n >> k;
    int a[2 * n];
    for(int& el: a) cin >> el;

    vector<pair<int, int>> times;

    for(int i = 0; i < n; i ++) times.push_back({i, 0});

    for(int i = 0; i < n; i++){
        auto& [key, val] = times[a[i] - 1];
        key = a[i] - 1; //index
        val = val + 1; //qtd
    }

    sort(times.begin(), times.end(), [](pair<int, int> &left, pair<int, int> &right){
        return left.second > right.second; 
    });

    vector<int> esquerda, direita;
    for(auto& [key, val] : times){
        // cout << key << " - " << val << endl;

        if(val == 2 and esquerda.size() < 2 * k) {
            esquerda.push_back(key + 1);
            esquerda.push_back(key + 1);
        }
        if(val == 1 and esquerda.size() < 2 * k){
            esquerda.push_back(key + 1);
            direita.push_back(key + 1);
        }

        if(val == 0 and direita.size() < 2 * k) {
            direita.push_back(key + 1);
            direita.push_back(key + 1);    
        }
    }
    
    for(int i = 0; i < 2 * k; i++) cout << esquerda[i] << " ";
    cout << endl;
    for(int i = 2 * k - 1; i >= 0; i--) cout << direita[i] << " ";
    cout << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
