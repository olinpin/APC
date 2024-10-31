#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

/* Solution described in README.txt */

const std::string ERROR{"error"};
constexpr long long mod  = 1e9 + 7;
constexpr long long maxa = 1ll << 20;

int main() {
	int n;
	std::cin >> n;
	std::vector<long long> b(n);
	for(auto &x : b) std::cin >> x;

	long long a = 1;
	// becomes true when we reach 2^20, when shortage of bacteria can not occur anymore
	bool can_have_shortage = true;
	for(auto x : b) {
		// double the number of bacteria
		a *= 2;

		// check for shortage
		if(can_have_shortage) {
			if(x > a) {
				std::cout << ERROR << "\n";
				return 0;
			}
		}

		// take away the bacteria we need
		a -= x;

		// should we start using modulo?
		if(a >= maxa) {
			can_have_shortage = false;
		}

		// apply modulo
		if(!can_have_shortage) a = (a % mod + mod) % mod;
	}
	std::cout << a % mod << "\n";
}
