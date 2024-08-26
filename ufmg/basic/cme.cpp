#include <iostream>
using namespace std;
int main(){
	int q, n; cin >> q;
	while(q-- > 0){
		cin >> n;
		if(n == 2) cout << 2;
		else if(n%2 == 0) cout << 0;
		else cout << 1;
		cout << "\n";
	}
	return 0;
}	
