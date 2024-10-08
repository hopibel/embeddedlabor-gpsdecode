#include <iostream>
#include <chrono>
#include <vector>

int dot_product(std::vector<int> a, std::vector<int> b, unsigned int delta) {
	int product = 0;
	for (int i = 0; i < a.size(); ++i) {
		product += a[i] * b[(i+delta) % b.size()];
	}
	return product;
}

int main() {
	std::vector<int> a, b;
	for (int i = 0; i < 1023; ++i) {
		if (!(i % 3)) {
			a.push_back(1);
			b.push_back(1);
		} else {
			a.push_back(-1);
			b.push_back(-1);
		}
	}

	auto start = std::chrono::high_resolution_clock::now();
	int total = 0;
	for (int i = 0; i < 10000; ++i) {
		for (int delta = 0; delta < a.size(); ++delta) {
			total += dot_product(a, b, delta);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << "Total: " << total << "\n";
	std::cout << "Time: " << std::chrono::duration<double, std::milli>(end - start).count() << "ms" << std::endl;

	return 0;
}
