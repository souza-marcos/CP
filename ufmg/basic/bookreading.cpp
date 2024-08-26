#include <iostream>
using namespace std;
int main(){
	int q, n, m; cin >> q;
	while(q-- > 0){
		cin >> n >> m;
		int sum = 0;
		for(int i = 0; i < n; i+= m)
			sum += i%10;
		cout << sum << "\n";
	}
	return 0;
}
