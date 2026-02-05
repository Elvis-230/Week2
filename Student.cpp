#include <iostream>
#include <stdexcept>
#include "Student.h"

Student::Student() 
    : name(""), final(0), hw_grades(nullptr), number_of_homeworks(0) {
}

Student::Student(const std::string& _name, int _final, int _number_of_homeworks)
    : name(_name), final(_final), number_of_homeworks(_number_of_homeworks) {
    if (_number_of_homeworks < 0) {
        throw std::invalid_argument("Number of homeworks cannot be negative");
    }
    if (_final < 0 || _final > 100) {
        throw std::invalid_argument("Final grade must be between 0 and 100");
    }
    hw_grades = new int[_number_of_homeworks];
    for (int i = 0; i < _number_of_homeworks; i++) {
        hw_grades[i] = 0;
    }
}

Student::Student(const Student& student)
    : name(student.name), final(student.final), number_of_homeworks(student.number_of_homeworks) {
    std::cout << "COPY CONSTRUCTOR Student" << std::endl;
    if (number_of_homeworks > 0) {
        hw_grades = new int[number_of_homeworks];
        for (int i = 0; i < number_of_homeworks; i++) {
            hw_grades[i] = student.hw_grades[i];
        }
    } else {
        hw_grades = nullptr;
    }
}

Student::~Student() {
    std::cout << "DESTRUCTOR Student" << std::endl;
    if (hw_grades != nullptr) {
        delete[] hw_grades;
    }
}

Student& Student::operator=(const Student& student) {
    if (this != &student) {
        // Delete old array
        if (hw_grades != nullptr) {
            delete[] hw_grades;
        }
        
        name = student.name;
        final = student.final;
        number_of_homeworks = student.number_of_homeworks;
        
        // Copy homework grades
        if (number_of_homeworks > 0) {
            hw_grades = new int[number_of_homeworks];
            for (int i = 0; i < number_of_homeworks; i++) {
                hw_grades[i] = student.hw_grades[i];
            }
        } else {
            hw_grades = nullptr;
        }
    }
    return *this;
}

std::string Student::getName() const { 
    return name; 
}

void Student::setName(const std::string& _name) { 
    name = _name; 
}

int Student::getFinal() const {
    return final;
}

void Student::setFinal(int _final) {
    if (_final < 0 || _final > 100) {
        throw std::invalid_argument("Final grade must be between 0 and 100");
    }
    final = _final;
}

int Student::getHomeworkCount() const {
    return number_of_homeworks;
}

int Student::getHomeworkGrade(int index) const {
    if (index < 0 || index >= number_of_homeworks) {
        throw std::out_of_range("Homework index out of range");
    }
    return hw_grades[index];
}

void Student::setHomeworkGrade(int index, int score) {
    if (index < 0 || index >= number_of_homeworks) {
        throw std::out_of_range("Homework index out of range");
    }
    if (score < 0 || score > 100) {
        throw std::invalid_argument("Homework grade must be between 0 and 100");
    }
    hw_grades[index] = score;
}

Student get_student_struct_data(int numberOfHws) {
    std::string name;
    int final;

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Enter student name: ";
    std::cin >> name;

    std::cout << "Enter final grade (0-100): ";
    std::cin >> final;

    Student student(name, final, numberOfHws);

    std::cout << "Enter " << numberOfHws << " homework score(s):" << std::endl;
    for (int i = 0; i < numberOfHws; i++) {
        int score;
        std::cout << "Homework " << (i + 1) << " score (0-100): ";
        std::cin >> score;
        student.setHomeworkGrade(i, score);
    }

    std::cout << "-----------------------------" << std::endl;

    return student;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.getName()
        << " | Final: " << student.getFinal()
        << " | Homework scores: ";
    for (int i = 0; i < student.getHomeworkCount(); i++) {
        os << student.getHomeworkGrade(i);
        if (i < student.getHomeworkCount() - 1) {
            os << ", ";
        }
    }

    return os;
}