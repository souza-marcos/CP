#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    int i = 0;
    for(auto& el: v) {
        cin >> el.first;
        el.second = i++; 
    }
    sort(v.begin(), v.end(), ::greater<>());
    int soma = 0, temp;

    for(int i = 0; i < n-1; i++){
        for(int j = i + 1;j < n; j++){
            
            if(temp > soma) soma = temp;
        }
    }
    cout << soma << endl;


    return 0;
} 
