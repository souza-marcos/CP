#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

bool closed(int cur_index, int n, vector<bool>& vis){
    if(cur_index > 0 and cur_index < (n - 1)){
        if(vis[cur_index -1] and vis[cur_index +1]) return true;
        return false;
    }
    if (cur_index == 0 and n == 1) return true;
    if (cur_index == 0) return (vis[cur_index + 1]); 
    return vis[cur_index - 1];
}

void solve(){
    int n; cin >> n;
    string prefix, infix; cin >> prefix >> infix; 
    map<char, int> index;
    for(int i = 0; i < n; i++) index[infix[i]] = i;


    // processing prefix
    vector<bool> vis(n, 0); 
    stack<char> st;
    for(int i = 0; i < n; i++) {
        char cur = prefix[i]; 
        vis[index[cur]] = true;

        // cout << cur << ": " << closed(index[cur], n, vis) << endl; 
        if(!closed(index[cur] , n, vis)) st.push(cur);
        else{
            cout << cur;
            while(!st.empty() and closed(index[st.top()] , n, vis)){
                cout << st.top(); st.pop();
            }
        }
    }
    while(!st.empty()) { cout << st.top(); st.pop();}
    cout << endl;
}

int main(){_
    int t; cin >> t;
    while(t --) solve();
    return 0;
}