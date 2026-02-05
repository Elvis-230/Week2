#ifndef SIMPLE_STUDENT_H
#define SIMPLE_STUDENT_H

#include <string>
#include <iostream>

struct Student {
    std::string name;
    int final;
    int* hw_grades;
    int number_of_homeworks;

    // Constructors
    Student();
    Student(const std::string& _name, int _final, int _number_of_homeworks);
    Student(const Student& student);
    
    // Destructor
    ~Student();
    
    // Assignment operator
    Student& operator=(const Student& student);
    
    // Getter methods
    std::string getName() const;
    void setName(const std::string& _name);
    int getFinal() const;
    void setFinal(int _final);
    int getHomeworkCount() const;
    int getHomeworkGrade(int index) const;
    void setHomeworkGrade(int index, int score);
};

std::ostream& operator<<(std::ostream& os, const Student& student);

Student get_student_struct_data(int numberOfHws);

#endif