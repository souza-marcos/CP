#include <iostream>
using namespace std;
int main(){
	int n, t, p = 0; cin >> n;
	for(int i=0; i < n;i ++){
		cin >> t;
		if(t % 2 == 0) p ++;
	}
	cout << min(p, n - p) << "\n";
	return 0;
}
