#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

// Menor capacidade que consigo atingir o prefixo i com o valor j

int main(){ _
    int n, w; cin >> n >> w;
    int maxval = 0;
    struct El{ int w, v; };

    vector<El> arr(n); for(auto& [w, v] : arr) cin >> w >> v, maxval += v;
    vector<vector<int>> memo(n+1, vector<int>(maxval + 1, INF));

    memo[0][arr[0].v] = arr[0].w;
    memo[0][0] = 0, memo[n-1][0] = 0;
    set<pair<int, int>> pos, pos2; 
    pos.insert({0, arr[0].v});
    pos.insert({0, 0});


    auto& cur = pos, next = pos2;

    auto dp = [&](){
        while(true){
            for(auto [i, val] : cur) { 
                if(i == n-1) return;
                
                memo[i+1][val] = min(memo[i+1][val], memo[i][val]);
                next.insert({i + 1, val});
                
                if(memo[i][val]+arr[i+1].w <= w){
                    memo[i+1][val+arr[i+1].v] = min(memo[i+1][val+arr[i+1].v], memo[i][val]+arr[i+1].w);
                    next.insert({i + 1, val + arr[i+1].v});
                }
            }
            auto& aux = cur;
            cur = next;
            next = aux;
            next.clear();
        }
    };
    dp();

    for(int j = maxval; j >= 0; j --) 
        if(memo[n-1][j] != INF) return cout << j << endl, 0;   
        
    return 0;
} 
