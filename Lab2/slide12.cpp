#include <iostream>
#include <vector>

// 2.
template <class T>
void printEnumerable(const T &enumerable) {
	bool first = true;
	for (const auto& item : enumerable) {
		if (first) first = false;
		else std::cout << ", ";

		std::cout << item;
	}
	std::cout << std::endl;
}

// 4.
template <class T, typename V>
void replaceFirstLast(T& enumerable, const V& newValue) {
	*std::begin(enumerable) = newValue;
	*std::rbegin(enumerable) = newValue;
}

// 5.
template <class T>
void erase5th(T& enumerable) {
	enumerable.erase(std::begin(enumerable) + 4);
}

int main() {
	// 1.
	std::vector<int> v {8, 4, 6, 1, 5, 3, 9, 5, 8, 123, 1, 2, 31, 24, 124, 12, 42, 131};
	
	// 2.
	printEnumerable(v);

	// 4.
	replaceFirstLast(v, 7);

	// 5.
	erase5th(v);

	// Print again to see changes
	printEnumerable(v);

	return 0;
}