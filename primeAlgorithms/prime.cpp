#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num){
	bool isPrime = true;

    if(num < 2) isPrime = false;   //no primes under 2
  
	for(int i = 2; i <= sqrt(num); i++){
		if(!(num % i)){
			 isPrime = false;  //It's not prime!!
			 break;
		}
	}
    return isPrime;
}

void primeGenerator(int m, int n){

	for(int i = m; i <= n; i++){
        if(isPrime(i)) cout << i << "\n";    //i is prime so print it out.
	}
	cout << "\n";
}

int main(){
	int numTestCases;
	cin >> numTestCases;

    int lowerBound, upperBound;
	for(int i = 0; i < numTestCases; i++){
        cin >> lowerBound >> upperBound;
        primeGenerator(lowerBound, upperBound);
	}

	return 0;

}