#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    double average;
};

int main() {
    int num;
    std::cin >> num;

    std::vector<Student> students(num);

    for (int i = 0; i < num; i++) {
        std::cin.ignore(); // Ignore the newline character left in the input buffer
        std::getline(std::cin, students[i].name);

        int num2;
        std::cin >> num2;

        std::vector<int> marks(num2);
        double sum = 0.0;

        for (int j = 0; j < num2; j++) {
            std::cin >> marks[j];
            sum += marks[j];
        }

        students[i].average = sum / num2;
    }

    std::cout << "Student Details:" << std::endl;

    for (const auto& student : students) {
        std::cout << "Name: " << student.name << std::endl;
        std::cout << "Average marks: " << std::fixed << std::setprecision(2) << student.average << std::endl;
    }

    return 0;
}