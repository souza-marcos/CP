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
    string s; cin >> s;

    stack<char> remain_lett;

    bool st = false;
    for(int i = 0; i < s.size() -1; i++){
        if((!remain_lett.empty()) and s[i] == remain_lett.top()){
            remain_lett.pop();
            st = !st;
        } else {
            remain_lett.push(s[i]);
        }
    }
    cout << (!st?"No":"Yes")<< endl;

    // babababababababbababababababab

    return 0;
} 
