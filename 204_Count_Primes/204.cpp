#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
		if(n <= 2) return 0;
		vector<int> primes;
		primes.push_back(2);
		for(int i = 3; i < n; i+=2){
			bool ifprime = true;
			for(int j = 1; j < primes.size() && primes[j]*primes[j] <= i; j++){
				if(i % primes[j] == 0){
					ifprime = false;
					break;
				}
			}
			if(ifprime) primes.push_back(i);
		}       
		return primes.size();
    }
};


// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n,true);
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid repeatedly calling an expensive function sqrt().
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i) 
                isPrime[j] = false;
        }
        int count = 0;
        for (int i = 2; i < n; i++) 
            if (isPrime[i]) count++;
        return count;
    }
};