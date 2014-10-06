#include<iostream>
#include<cmath>

using namespace std;


void primeGenerator(int m, int n){
    bool* numList = new bool[n];
	for(int i = 2; i <= n; i++){
        numList[i] = true;
	}

	for(int i = 2; i <= sqrt(n); i++){
		if(numList[i]){
			for(int j = i * i; j <= n; j += i){
				numList[j] = false;
			}
		}
	}

	
	for(int i = m; i <= n; i++){
		if(numList[i]) cout << i << "\n";
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