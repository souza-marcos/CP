#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int32_t main(){ _

    auto query = [&](string s) -> int {
        cout << "? " << s << endl;
        cout.flush();
        int cnt; cin >> cnt;
        return cnt;
    };

    int n; cin >> n;
    string s(n, 'X');
    for(int i = 0; i < n; i ++){
        vector<char> arr;
        for(char ch = 'a'; ch <= 'z'; ch ++) arr.push_back(ch);
        shuffle(arr.begin(), arr.end(), rng);

        s[i] = arr.back(); arr.pop_back();
        int cnta = query(s);

        string t = s;
        while(sz(arr)){
            t[i] = arr.back(); arr.pop_back();
            int cntb = query(t);

            if(cnta > cntb) break;
            else if(cnta < cntb){
                s[i] = t[i];
                break;
            }
        }
    }

    cout << "! " << s << endl;
    cout.flush();
}