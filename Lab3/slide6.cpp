#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
	// 1.
	std::vector<std::pair<int, int>> v {{2, 8}, {9, 6}, {4, 7}, {22, 4}, {123, 321}, {1, 1}, {-7, 5}};

	// 2.
	std::sort(std::begin(v), std::end(v), [](const auto& e1, const auto& e2) {
		return e1.first < e2.first;
	});

	// 3.
	bool odd {true};
	for (auto it {std::begin(v)}; it != std::end(v); ++it) {
		if (odd) {
			(*it).second = 0;
		}
		odd = !odd;
	}

	// Print the results
	bool first {true};
	for (const auto& item : v) {
		if (first) first = false;
		else std::cout << ", ";
		std::cout << "(" << item.first << ", " << item.second << ")";
	}
	std::cout << std::endl;

	return 0;
}