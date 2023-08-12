#include <iostream>
#define int unsigned long long int
using namespace std;

int gcd(int a , int b){
	int r ;
    
	while(b != 0){
    	r = a % b ;
    	a = b ;
    	b = r ;
	}
	return a ;
}

int power(int a , int m , int n){
	int res = 1 ;
    
	while(m > 0){
    	if(m & 1){
        	res = (res*a) % n ;
    	}
    	m = m >> 1 ;
    	a = (a*a) % n ;
	}
	return res ;
}

bool is_prime(int n){
    
	if(n <= 1 || n == 4)
    	return false ;
	if(n <= 3)
    	return true ;
   	 
	int k = 100 ;    
	while(k > 0){
    	int a = 2 + rand() % (n-4) ;
    	if(gcd(n,a) != 1)
        	return false ;
    	if(power(a,n-1,n) != 1 )
        	return false ;
    	k-- ;    
	}    
	return true ;
}

signed main()
{
	int n ;
	cout << "enter the number: " ;
	cin >> n ;
   	 
	if(is_prime(n)){
    	cout << "given input number " << n << " is prime " << endl ;
	}
	else{
    	cout << "given input number " << n << " is not prime " << endl;
	}

	return 0;
}

