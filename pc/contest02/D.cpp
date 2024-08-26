#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

set<char> colors = {'R', 'G', 'B'};

char getDiff(char l, char r){
    for(char c: colors){
        if(c != l and c != r) return c;
    }
}

int main(){_

    int n; cin >> n;
    string s; cin >> s;

    int cont = 0;

    for(int i = 1; i < n; i ++){
        if(s[i] == s[i - 1]){
            cont ++;
            char r = ((i == n - 1)?s[i - 1]:s[i + 1]);
            s[i] = getDiff(s[i - 1], r);
        }
    }

    cout << cont << endl;
    cout << s << endl;

    return 0;
}