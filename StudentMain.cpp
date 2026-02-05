#include <iostream>
#include <vector>
#include "Student.h"

void displayAllStudents(const std::vector<Student>& students);
void runEdgeCaseTests();

int main() {
    int numStudents;
    int numHomeworks;
    
    std::cout << "=== STUDENT MANAGEMENT SYSTEM ===" << std::endl;
    std::cout << "Enter number of homeworks: ";
    std::cin >> numHomeworks;
    
    std::cout << "Enter number of students to add: ";
    std::cin >> numStudents;
    
    std::vector<Student> students;
    
    // Input students
    for (int i = 0; i < numStudents; i++) {
        std::cout << "\nEntering student " << (i + 1) << ":" << std::endl;
        students.push_back(get_student_struct_data(numHomeworks));
    }
    
    // Display all students
    std::cout << "\n=== ALL STUDENTS ===" << std::endl;
    displayAllStudents(students);
    
    // Run edge case tests
    std::cout << "\n=== RUNNING EDGE CASE TESTS ===" << std::endl;
    runEdgeCaseTests();
    
    return 0;
}

void displayAllStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students to display." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < students.size(); i++) {
        std::cout << (i + 1) << ". " << students[i] << std::endl;
    }
}

void runEdgeCaseTests() {
    std::cout << "\n--- Test 1: Empty Student (default constructor) ---" << std::endl;
    try {
        Student emptyStudent;
        std::cout << "Empty student created: " << emptyStudent << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 2: Copy Constructor ---" << std::endl;
    try {
        Student original("Alice", 85, 3);
        original.setHomeworkGrade(0, 90);
        original.setHomeworkGrade(1, 88);
        original.setHomeworkGrade(2, 92);
        
        Student copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 3: Assignment Operator ---" << std::endl;
    try {
        Student student1("Bob", 75, 2);
        student1.setHomeworkGrade(0, 80);
        student1.setHomeworkGrade(1, 78);
        
        Student student2 = student1;
        std::cout << "Student 1: " << student1 << std::endl;
        std::cout << "Student 2 (assigned): " << student2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 4: Invalid Final Grade (> 100) ---" << std::endl;
    try {
        Student invalid("Charlie", 150, 1);
        std::cout << "This should not print!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 5: Invalid Final Grade (< 0) ---" << std::endl;
    try {
        Student invalid("Diana", -10, 1);
        std::cout << "This should not print!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 6: Negative Number of Homeworks ---" << std::endl;
    try {
        Student invalid("Eve", 80, -5);
        std::cout << "This should not print!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 7: Invalid Homework Grade (> 100) ---" << std::endl;
    try {
        Student student("Frank", 80, 1);
        student.setHomeworkGrade(0, 150);
        std::cout << "This should not print!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 8: Invalid Homework Index ---" << std::endl;
    try {
        Student student("Grace", 80, 3);
        student.getHomeworkGrade(5);  // Out of range
        std::cout << "This should not print!" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 9: Zero Homeworks ---" << std::endl;
    try {
        Student student("Henry", 95, 0);
        std::cout << "Student with 0 homeworks: " << student << std::endl;
        std::cout << "Homework count: " << student.getHomeworkCount() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 10: setFinal with Invalid Values ---" << std::endl;
    try {
        Student student("Ivy", 80, 1);
        student.setFinal(105);
        std::cout << "This should not print!" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 11: Edge case - Grade exactly 0 ---" << std::endl;
    try {
        Student student("Jack", 0, 1);
        student.setHomeworkGrade(0, 0);
        std::cout << "Student with 0 grades: " << student << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 12: Edge case - Grade exactly 100 ---" << std::endl;
    try {
        Student student("Kate", 100, 2);
        student.setHomeworkGrade(0, 100);
        student.setHomeworkGrade(1, 100);
        std::cout << "Student with perfect grades: " << student << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== EDGE CASE TESTS COMPLETE ===" << std::endl;
}
