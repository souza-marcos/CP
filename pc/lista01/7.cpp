#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'


void solve(){



}

int main(){_

    int n; 
    while(cin >> n){
        int action, x;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        bool iS = true, isQ = true, isPQ = true;
        while(n --){
            cin >> action >> x;
            if(action == 1){
                s.push(x);
                q.push(x);
                pq.push(x);
            }else{
                if(iS and s.top() == x) s.pop();
                else iS = false;

                if(isQ and q.front() == x) q.pop();
                else isQ = false;

                if(isPQ and pq.top() == x) pq.pop();
                else isPQ = false;
            }
        }
        if(iS and !isQ and !isPQ) cout << "stack\n";
        else if(!iS and isQ and !isPQ) cout << "queue\n";
        else if(!iS and !isQ and isPQ) cout << "priority queue\n";
        else if(!iS and !isQ and !isPQ) cout << "impossible\n";
        else cout << "not sure\n";

    }

    return 0;
}