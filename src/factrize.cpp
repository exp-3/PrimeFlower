#include <vector>
#include <iostream>

std::vector<int> sieve(std::vector<int> vector) {
    if(!vector.empty()) {
        int first = vector.front();

        auto itr = vector.begin();

        while(itr != vector.end()) {
            if(*itr % first == 0) {
                vector.erase(itr);
            } else {
                itr++;
            }
        }
        vector = sieve(vector);
        vector.push_back(first);
    }

    return vector;
}

std::vector<int> subFactrize(std::vector<int> primes, int num) {
    int prime = primes.front();
    std::vector<int> factors;

    if(num == prime) {
        factors.push_back(1);
        factors.push_back(num);
    } else if(num % prime == 0) {
        factors = subFactrize(primes, num / prime);
        factors.push_back(prime);
    } else {
        primes.erase(primes.begin());
        factors = subFactrize(primes, num);
    }

    return factors;
}

std::vector<int> factrize(int num) {
    std::vector<int> factors;
    if(num == 1) {
        factors.push_back(1);
    } else if(num > 1) {
        std::vector<int> primes;
        for(int i = 2; i <= num; i++) {
            primes.push_back(i);
        }
        primes = sieve(primes);
        factors = subFactrize(primes, num);
    }

    return factors;
}
