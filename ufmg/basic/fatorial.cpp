#include <iostream> 
using namespace std;

int main(){
   int n, i = 1;
   while(cin >> n){
	int p = n;
	while(n-- > 1){
	   int au = n;
	   while(au % 10 == 0) au /= 10;
	   p *= (au);
	   while(p % 10 == 0) p /= 10;
	   p %= 10;
	}
	cout << "Instancia " << i++;
	cout << "\n" << p << "\n";
   }

   return 0;
}
