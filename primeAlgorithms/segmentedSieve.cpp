//================================================================================
//code_not_complete


#include<iostream>
#include<cmath>
#include<string>

using namespace std;

#define MAX 45556       //the square root of the maximum input sqrt(2^32)
#define SIEVEEND 216    //sqrt of max
#define LEN 4830        //the maximum possible different primes stored by range
                        //on which seg sieve will run and collect primes
#define RANGE 100032

#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

unsigned base[MAX/64], segment[RNG/64], primes[LEN];


//generated a sieve of prime numbers stored in the array primes[]
//using base[] as a way of checking if a number is prime
void sieve(){
    unsigned i, j, k;
    for(i=3; i<SIEVEEND; i+=2)
        if(!chkC(base, i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(base, j);
    for(i=3, j=0; i<MAX; i+=2)
        if(!chkC(base, i))
            primes[j++] = i;
}

// Returns the prime-count within range [a,b] and marks them in segment[] 
int segmented_sieve(int a, int b)
{
    unsigned i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
    if(b<2) return 0;   //if upper bound is too low, return 0;
    if(a<3) a = 3;      //make sure to start at 3
    if(a%2==0) a++;     //make sure to start on an odd number
    mset(segment,0);    //set up memory for segment
    for(i=0; sq(primes[i])<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        if(j%2==0) j += primes[i];
        for(k=primes[i]<<1; j<=b; j+=k)
            if(j!=primes[i])
                setC(segment, (j-a));
    }
    for(i=0; i<=b-a; i+=2)
        if(!chkC(segment, i))
            cnt++;
    return cnt;
}

int main(){
	int numTestCases;
	cin >> numTestCases;

    int lowerBound, upperBound;
	for(int i = 0; i < numTestCases; i++){
        cin >> lowerBound >> upperBound;
        if(segmented_sieve(lowerBound, upperBound)){
        	 int size = sizeof(segment) / sizeof(unsigned);
             for(int j = 0; j < size; j++){
        	    cout << segment[j] << "\n";
             }
        }
        else cout << "\n";
       
	}

	return 0;
}