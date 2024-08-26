#include <iostream>
using namespace std;
#define endl "\n"
int main(){
	int t, n; cin >> t;
	
	while(t -- > 0){
		cin >> n;
		int a[n], cont = 0;
		for(int i= 0; i<n; i ++ ){
			cin >> a[i];
		}
		int low = a[n-1];
		for(int i = n - 2; i >= 0; i--){
			if(a[i] <= low){
			       	low = a[i];
			}
			else cont ++ ;
		}
		cout << cont << endl;
	}
	return 0;
}	
