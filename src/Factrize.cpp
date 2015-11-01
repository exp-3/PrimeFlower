#include "Factrize.hpp"

/*与えられた集合内の素数を降順で返す*/
std::list<int> sieve(std::list<int> primes) {
    if(!primes.empty()) {
        int first = primes.front();

        auto itr = primes.begin();

        while(itr != primes.end()) {
            if(*itr % first == 0) {
                itr = primes.erase(itr);
            } else {
                itr++;
            }
        }
        primes = sieve(primes);
        primes.push_back(first);
    }

    return primes;
}

/*与えられた数の素因数の集合を昇順で返す*/
std::vector<int> subFactrize(std::list<int> primes, int num) {
    std::vector<int> factors;

    if(primes.empty()) {
        factors.push_back(1);
    } else {
        int prime = primes.front();

        if(num % prime == 0) {
            factors = subFactrize(primes, num / prime);
            factors.push_back(prime);
        } else {
            primes.pop_front();
            factors = subFactrize(primes, num);
        }
    }
    return factors;
}

/*与えられた数の素因数の集合を昇順で返す(実装の都合上で素因数と言いつつ1と4が入っている)*/
std::vector<int> Factrize::factrize(int num) {
    std::vector<int> factors;
    if(num > 0) {
        std::list<int> primes;
        for(int i = 2; i <= num; i++) {
            primes.push_back(i);
        }
        primes = sieve(primes);

        /*if(num >= 4) {
            std::vector<int> numStack;
            while(primes.back() < 4) {
                numStack.push_back(primes.back());
                primes.pop_back();
            }
            primes.push_back(4);
            while(!numStack.empty()) {
                primes.push_back(numStack.back());
                numStack.pop_back();
            }
        }*/

        factors = subFactrize(primes, num);
    }

    return factors;
}
