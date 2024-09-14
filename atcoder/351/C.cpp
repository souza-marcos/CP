#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> v(n); for(int& el: v) cin >> el;
    stack<int> s;

    for(int i = 0; i < n; i ++){
        s.push(v[i]);
        while (s.size() > 1)
        {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if(a != b){
                s.push(a);
                s.push(b);
                break;
            } 
            s.push(a + 1);
        }
    }
    cout << s.size() << endl;
    return 0;
} 
