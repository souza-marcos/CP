#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    int q; cin >> q;
    int left = 0, right = 1;
    ll cnt = 0;
    while(q --){
        char t; cin >> t; int pos; cin >> pos; pos --;
        cout << "L => " << left << " " << "R => " << right << ", ";
        if(t == 'L'){
            // l = 0
            int newpos = (pos - left + 2 * n) % n; 
            int newright = (right - left + 2 * n) % n;
            int toright = 0;
            if(newright < pos) toright = INF;
            else toright = newpos;

            int toleft = 0;
            if(newright > pos) toleft = INF;
            else toleft = n-newpos;

            left = pos;
            cout << min(toleft, toright) << endl;
            cnt += min(toleft, toright); 
        }else{
            int newpos = (pos - right + 2 * n) % n; 
            int newleft = (left - right + 2 * n) % n;
            int toright = 0;
            if(newleft < pos) toright = INF;
            else toright = newpos;

            int toleft = 0;
            if(newleft > pos) toleft = INF;
            else toleft = n-newpos;

            right = pos;
            cout << min(toleft, toright) << endl;
            cnt += min(toleft, toright);
        }
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
} 
