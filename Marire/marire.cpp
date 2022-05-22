#include <iostream>		// std::cin, std::cout
#include <iomanip>		// std::setw, std::fixed, std::setprecision
#include <string>		// std::string
#include <vector>		// std::vector
#include <utility>		// std::pair
#include <numeric>		// std::accumulate
#include <algorithm>	// std::sort
#include <array>		// std::array
#include <cstdlib>		// std::rand, std::srand
#include <ctime>		// std::time

using std::cin;
using std::cout;
using std::endl;

class Student {
private:
	std::string _name;
	int _year;
	std::vector<std::pair<std::string, double>> _course_grades;

public:
	std::string get_name() const { return _name; }
	void set_name(const std::string &new_name) { _name = new_name; }
	int get_year() const { return _year; }
	void set_year(int new_year) { _year = new_year; }
	const std::vector<std::pair<std::string, double>>& get_course_grades() const { return _course_grades; }
	void set_course_grades(const std::vector<std::pair<std::string, double>> new_course_grades) { _course_grades = new_course_grades; }
	void add_course_grade(const std::string& course_name, double grade) {
		_course_grades.emplace_back(course_name, grade);
	}

	double get_average() const {
		return std::accumulate(
			_course_grades.begin(),
			_course_grades.end(),
			0.0,
			[](double acc, const std::pair<std::string, double> &next){
				return acc + next.second;
			}
		) / _course_grades.size();
	}
};

// for pretty printing:
int max_student_name = 12;

void list_students(const std::vector<Student>& students) {
	cout << "Listing " << students.size() << " student" << (students.size() == 1 ? "" : "s") << endl;
	int index = 1;
	for (const auto &student : students) {
		cout << index << ". " << student.get_name() << " (year " << student.get_year() << "):" << endl;
		for (const auto& course : student.get_course_grades()) {
			cout << "    " << course.first << " - " << std::fixed << std::setprecision(2) << course.second << endl;
		}

		index++;
	}
}

void list_averages(const std::vector<Student>& students) {
	cout << std::setw(max_student_name) << "Student Name" << " | " << "Average" << endl;
	for (const auto& student: students) {
		cout << std::setw(max_student_name) << student.get_name() << " | " << std::fixed << std::setprecision(2) << student.get_average() << endl;
	}
}

void list_sorted(std::vector<Student> students) {
	std::sort(
		students.begin(),
		students.end(),
		[](const Student &s1, const Student &s2) {
			const auto s1_avg = s1.get_average();
			const auto s2_avg = s2.get_average();
			if (s1_avg != s2_avg) { 
				return s1_avg > s2_avg; 
			}
			else {
				return s1.get_name() < s2.get_name();
			}
		}
	);
	cout << std::setw(max_student_name) << "Student Name" << " | Average | Year" << endl;
	for (const auto& student: students) {
		cout 
			<< std::setw(max_student_name) << student.get_name() 
			<< " | " 
			<< std::setw(7) << std::fixed << std::setprecision(2) << student.get_average() 
			<< " | "
			<< student.get_year()
			<< endl;
	}
}

void list_year3_agt8(const std::vector<Student>& students) {
	cout << "Students from year 3 with average over 8:" << endl;
	cout << std::setw(max_student_name) << "Student Name" << " | Year | Average" << endl;
	for (const auto& student: students) {
		if (student.get_year() == 3 && student.get_average() > 8) {
			cout 
				<< std::setw(max_student_name) << student.get_name() 
				<< " | " 
				<< std::setw(4) << student.get_year()
				<< " | "
				<< std::fixed << std::setprecision(2) << student.get_average() 
				<< endl;
		}
	}
}

void insert_student(std::vector<Student>& students) {
	std::string name;
	int year;
	std::vector<std::pair<std::string, double>> courses_grades;

	cout << "Name? ";
	do {
		std::getline(cin, name);
	} while (name.length() == 0);
	cout << "Year? ";
	cin >> year;
	// Workaround for newline stuck in buffer
	std::string tmp;
	std::getline(cin, tmp);
	while (true) {
		std::string course_name;
		double grade;

		cout << "Course name? (Enter without typing to stop) ";
		std::getline(cin, course_name);
		if (course_name.length() == 0) {
			break;
		}
		cout << "Grade? ";
		cin >> grade;
		// Workaround for newline stuck in buffer
		std::getline(cin, tmp);
		courses_grades.emplace_back(course_name, grade);
	}
	cout << "Added student." << endl;

	Student new_student;
	new_student.set_name(name);
	if (new_student.get_name().length() > max_student_name) {
		max_student_name = new_student.get_name().length();
	}
	new_student.set_year(year);
	new_student.set_course_grades(courses_grades);
	students.push_back(new_student);
}

int remove_alt5(std::vector<Student>& students) {
	std::vector<int> indeces_to_remove;
	for (int i = students.size() - 1; i >= 0; i--) {
		if (students[i].get_average() < 5) {
			indeces_to_remove.push_back(i);
		}
	}
	for (auto i : indeces_to_remove) {
		students.erase(students.begin() + i);
	}
	return indeces_to_remove.size();
}

std::array<const char *, 21> mock_names = {
	"Elena",
	"Mircea",
	"Cornel",
	"Ion",
	"Nicolae",
	"Mihai",
	"Lavinia",
	"Nicoleta",
	"Ana",
	"Denisa",
	"Diana",
	"Gheorghe",
	"Darius",
	"Sorin",
	"Dragos",
	"Stefan",
	"Ioan",
	"Viorel",
	"Virgil",
	"Octavian",
	"Alina"
};

std::array<const char *, 20> mock_courses = {
	"Maths",
	"IT",
	"C++",
	"Java",
	"Networking",
	"Design",
	"Class 7",
	"Class 8",
	"Class 9",
	"Class 10",
	"Class 11",
	"Class 12",
	"Class 13",
	"Class 14",
	"Class 15",
	"Class 16",
	"Class 17",
	"Class 18",
	"Class 19",
	"Class 20",
};

void fill_with_mock_data(std::vector<Student>& students) {
	// insert between 5 and 9 mock students
	int count = 5 + (std::rand() % 5); 
	for (int i = 0; i < count; i++) {
		int name_idx = std::rand() % mock_names.size();
		Student new_student;
		new_student.set_name(mock_names[name_idx]);
		if (new_student.get_name().length() > max_student_name) {
			max_student_name = new_student.get_name().length();
		}
		new_student.set_year(1 + std::rand() % 3);

		for (int j = 0; j < 10; j++) {
			int course_idx = std::rand() % mock_courses.size();
			new_student.add_course_grade(mock_courses[course_idx], (2 + (std::rand() % 19)) / 2.0);
		}

		students.push_back(new_student);
	}
}

int main() {
	// seed rand
	std::srand(std::time(nullptr));

	std::vector<Student> students;
	fill_with_mock_data(students);

	int choice;

	while (true) {
		cout << "1. List students" << endl;
		cout << "2. List averages" << endl;
		cout << "3. Display sorted by averages" << endl;
		cout << "4. Display students from year 3 with average > 8.0" << endl;
		cout << "5. Insert student data" << endl;
		cout << "6. Remove non-promoted students" << endl;
		cout << "0. Exit" << endl;

		if (!(cin >> choice)) {
			// Stop on end of input (Ctrl+D on Linux)
			break;
		}

		bool exit{false};
		switch (choice) {
		case 0:
			exit = true;
			break;
		case 1:
			list_students(students);
			break;
		case 2:
			list_averages(students);
			break;
		case 3:
			list_sorted(students);
			break;
		case 4:
			// list year 3 with average greater than 8
			list_year3_agt8(students);
			break;
		case 5:
			insert_student(students);
			break;
		case 6:
			// remove average less than 5
			int removed = remove_alt5(students);
			cout << "Removed " << removed << " student" << (removed == 1 ? "" : "s") << endl;
			break;
		}
		if (exit) {
			break;
		}
	}
}