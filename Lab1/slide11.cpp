// For std::string
#include <string>
// For std::cout
#include <iostream>
// For std::sort
#include <algorithm>

class Human
{
public:
    Human();
    ~Human();
    std::string name;
    int age;
};

// Implementation
Human::Human() : name{}, age{} {}
Human::~Human() {}

int main() {
	// 1. Create 4 humans
	Human humans[4];

	// 2. Give them names and ages.
	humans[0].name = "Joe";
	humans[0].age = 18;
	humans[1].name = "Jane";
	humans[1].age = 19;
	humans[2].name = "Jim";
	humans[2].age = 20;
	humans[3].name = "John";
	humans[3].age = 21;

	// 3. Retrieve the data from all humans 
	//    and print it to the screen.
	for (int i = 0; i < 4; i++) {
		std::cout 
			<< "name=" << humans[i].name 
			<< ", age=" << humans[i].age 
			<< std::endl;
	}

	// 4. Print the data for the youngest
	//    human.
	Human& youngest = humans[0];
	for (int i = 1; i < 4; i++) {
		if (humans[i].age < youngest.age) {
			youngest = humans[i];
		}
	}
	std::cout 
		<< "Youngest:"
		<< " name=" << youngest.name
		<< ", age=" << youngest.age
		<< std::endl;

	// 5. Print all humans' names in
	//    descending order by their
	//    names.
	std::sort(humans, humans + 4, [](const Human &h1, const Human &h2) { 
		return h1.name <= h2.name;
	});
	for (int i = 0; i < 4; i++) {
		std::cout << humans[i].name << ", ";
	}
	std::cout << std::endl;

	return 0;
}
