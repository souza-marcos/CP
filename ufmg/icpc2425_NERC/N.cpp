#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    
    while(t --) {
        string s; cin >> s;
        int fr = s[0]-'0';
        int sn = s[2]-'0';
        if(fr == sn) s[1] = '=';
        else if(fr > sn) s[1] = '>';
        else s[1]='<';

        cout << s << endl;
    }
}
