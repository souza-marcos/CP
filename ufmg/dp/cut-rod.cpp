#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5;

int n;
vector<int> p;
vector<int> first_best_sol;

int memo[MAX];

int solve(int rod_length){
    if(rod_length == 0) return 0;
    cout << rod_length << " ";

    int& val = memo[rod_length];
    if(val != -1) return val;


    int max_val = p[rod_length -1];
    for(int i = 1; i < rod_length; i++){
        max_val = max(max_val, solve(i) + solve(rod_length - i));
    }
    return val = max_val;
}

void recupera(int n){
    for(int i = 0; i < n; i++){
        if(memo[i] + memo[n - i] == memo[n]) first_best_sol[i] = i;
    }
}

int main(){ _
    cin >> n;
    p.resize(n);
    for(auto& el: p) cin >> el;
    memset(memo, -1, sizeof memo);
    first_best_sol.resize(n + 1, -1);

    cout << solve(n) << endl;

    for(int i = 0; i <  n + 1; i++) cout << memo[i] << " ";
    cout << endl;

    for(int i = 0; i <  n + 1; i++) cout << first_best_sol[i] << " ";
    cout << endl;
    return 0;
} 
