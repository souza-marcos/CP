#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(int n){

    stack<int> s; 
    queue<int> q;
    priority_queue<int> pq;

    bool ok[3] = {1, 1, 1};
    for(int i = 0; i < n; i ++){
        int t, v; cin >> t >> v ;
        if(t == 1){
            s.push(v), q.push(v), pq.push(v);
        }
        else {
            if(ok[0] and (!sz(s) or v != s.top())) ok[0] = 0;
            if(ok[1] and (!sz(q) or v != q.front())) ok[1] = 0;
            if(ok[2] and (!sz(pq) or v != pq.top())) ok[2] = 0;
            
            if(ok[0] and sz(s)) s.pop();
            if(ok[1] and sz(q)) q.pop(); 
            if(ok[2] and sz(pq)) pq.pop();
        }
    }
    int cnt = ok[0] + ok[1] + ok[2];
    if(cnt == 0)
        cout << "impossible\n";
    else if(cnt > 1){
        cout << "not sure\n";
    }else{
        if(ok[0]) cout << "stack\n";
        else if(ok[1]) cout << "queue\n";
        else if(ok[2]) cout << "priority queue\n";
    }
}

int main(){ _
    int n;
    while(cin >> n) solve(n);
} 
