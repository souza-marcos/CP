#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int N, K;
vector<int> h;
int memo[MAX];

int custo(int i){
    if(i >= h.size() - 1) return 0;
    int& p = memo[i];

    if(p != -1) return p;

    int minfator = INF;
    for(int j = i + 1; j <= min(i + K, N - 1); j ++){
        minfator = min(custo(j) + abs(h[i] - h[j]), minfator);
    }
    return p = minfator;
}

int main(){ _
    cin >> N >> K;
    h.resize(N);
    for(auto& el: h) cin >> el;

    memset(memo, -1, sizeof memo);

    cout << custo(0) << endl;
    
    return 0;
} 
