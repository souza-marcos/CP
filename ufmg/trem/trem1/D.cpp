#include <bits/stdc++.h>
using namespace std;

using std::cout;
typedef long long ll;

int main(){
	
	int n; cin >> n;

    cout << 1 << endl;
    if(n == 25){
        cout << 50 << endl;
        for(int i = 0; i < n; i++) cout << 5 << " " << 5 << " ";
        cout << endl;
        return 0;
    }

    cout << n * 2 + 1 << endl;
    cout << n << " ";
    for(int i = 0; i < n * 2; i++) cout << 1 << " ";    
    cout << endl;
	
	return 0;
}