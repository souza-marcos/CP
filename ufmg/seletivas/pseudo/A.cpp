#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n ; cin >> n;
    priority_queue<tuple<int, int, string>> pq; 
    for(int i = n -1; i >= 0; i--){
        string s; string t;
        cin >> s >> t;
        int p = 0;
        if(t == "man") p = 1;
        else if(t == "woman" or t == "child") p =2;
        else if(t == "rat") p = 3; 
        pq.push({p, i, s});
    }
    while(!pq.empty()){
        auto [val, i, name] = pq.top(); pq.pop();
        cout << name << endl;
    }

    return 0;
} 
