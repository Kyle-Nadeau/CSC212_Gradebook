#include "gradebook.h"
#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
//Incredibly basic setup right now

gradebook::gradebook() {};

//Setters
void gradebook::set_name(std::string student_name)
{
    //This is setting the private variable of name to the student name variable passed in.
    name = student_name;
}

//
void gradebook::set_lab_names(std::vector<std::string> names_of_labs)
{
    //Setting the private vector string of lab names to the variable passed in
    lab_names = names_of_labs;
}

//
void gradebook::set_assignment_names(std::vector<std::string> names_of_assignments)
{
    //Setting the private vector string of assignment names to the variable passed in
    assignment_names = names_of_assignments;
}

//
void gradebook::set_project_names(std::vector<std::string> names_of_projects)
{
    //Setting the private vector string of project names to the variable passed in
    project_names = names_of_projects;
}

//
void gradebook::set_exam_name(std::string name_of_exam)
{
    //Setting the private string of exam name to the variable passed in
    exam_name = name_of_exam;


}
void gradebook::set_individual_lab(int index, float value)
{
    lab_grades[index - 1] = value;
}
void gradebook::set_individual_assignment(int index, float value)
{
    assignment_grades[index - 1] = value;
}
void gradebook::set_individual_project(int index, float value)
{
    project_grades[index - 1] = value;
}


//
void gradebook::set_lab_grades(std::vector<float> grades)
{
    //Setting the private vector of floats lab grades to the variable passed in
    lab_grades = grades;
}

//
void gradebook::set_assignment_grades(std::vector<float> grades)
{
    assignment_grades = grades;
}

//
void gradebook::set_project_grades(std::vector<float> grades)
{
    project_grades = grades;
}

//
void gradebook::set_exam_grade(float grade)
{
    exam_grade = grade;

}
//
void gradebook::set_total_grade(float grade)
{
    total_grade = grade;
}
//
void gradebook::set_letter_grade(std::string grade)
{
    letter_grade = grade;
}

//This is all the getters
std::string gradebook::get_name()
{
    return name;

}

std::vector<std::string> gradebook::get_lab_names()
{

    return lab_names;
}
std::vector<std::string> gradebook::get_assignment_names()
{
    return assignment_names;
}
std::vector<std::string> gradebook::get_project_name()
{

    return project_names;
}
std::string gradebook::get_exam_name()
{
    return exam_name;
}

std::vector<float> gradebook::get_lab_grades()
{

    return lab_grades;
}
std::vector<float> gradebook::get_assignment_grades()
{

    return assignment_grades;
}
std::vector<float> gradebook::get_project_grades()
{
    return project_grades;
}

float gradebook::get_exam_grade()
{


    return exam_grade;
}
float gradebook::get_total_grade()
{
    total_grade = 0;//This is to reset the total grade back to zero between calls.
    for (int i = 0; i < lab_grades_after_drop.size(); i++)
    {
        total_grade += lab_grades_after_drop[i];
    }
    for (int i = 0; i < assignment_grades.size(); i++)
    {
        total_grade += assignment_grades[i];
    }
    for (int i = 0; i < project_grades.size(); i++)
    {
        total_grade += project_grades[i];
    }
    total_grade += exam_grade;
    return total_grade;
}
std::string gradebook::get_letter_grade()
{
    int percentage_grade;
    percentage_grade = total_grade / 100;

    if (percentage_grade >= 94)
    {
        letter_grade = 'A';
    }
    else if (percentage_grade < 94 && percentage_grade >= 90)
    {
        letter_grade = 'A-';
    }
    else if (percentage_grade < 90 && percentage_grade >= 87)
    {
        letter_grade = 'B+';
    }
    else if (percentage_grade < 87 && percentage_grade >= 83)
    {
        letter_grade = 'B';
    }
    else if (percentage_grade < 83 && percentage_grade >= 80)
    {
        letter_grade = 'B-';
    }
    else if (percentage_grade < 80 && percentage_grade >= 77)
    {
        letter_grade = 'C+';
    }
    else if (percentage_grade < 77 && percentage_grade >= 73)
    {
        letter_grade = 'C';
    }
    else if (percentage_grade < 73 && percentage_grade >= 70)
    {
        letter_grade = 'C-';
    }
    else if (percentage_grade < 70 && percentage_grade >= 67)
    {
        letter_grade = 'D+';
    }
    else if (percentage_grade < 67 && percentage_grade >= 63)
    {
        letter_grade = 'D';
    }
    else if (percentage_grade < 63 && percentage_grade >= 60)
    {
        letter_grade = 'D-';
    }
    else
    {
        letter_grade = 'F';
    }
    return letter_grade;
}
void gradebook::drop_lowest_labs()
{
    //Making sure the lab grades after drop is cleared, so it doesn't keep the values between calls if it is called more than once.
    lab_grades_after_drop.clear();
    //This function should sort the vector of labs, then drop the lowest 2. By default there will ALWAYS be 12 labs, even if the student didn't do one.

    for (int i = 0; i < lab_grades.size(); i++)
    {
        lab_grades_after_drop.push_back(lab_grades[i]);
    }

    sort(lab_grades_after_drop.begin(), lab_grades_after_drop.end());
    //Removing the bottom two grades.
    lab_grades.erase(lab_grades_after_drop.begin(), lab_grades_after_drop.begin() + 2);
}
//The display functions
void gradebook::display_individual(std::string category, std::string num)
{
    int number = std::stoi(num)-1;
    switch (std::stoi(category)) {
        case 1:
            std::cout<< "Lab name: "<<lab_names[number] <<":\n"<<lab_grades[number]<<"/20 points."<<std::endl;
            break;
        case 2:
            std::cout<< "Assignment name: "<<assignment_names[number] <<":\n"<<assignment_grades[number]<<"/50 points." <<std::endl;
            break;

        case 3:
            if(std::stoi(category)==1) {
                std::cout << "Project name: "<<project_names[number] << ":\n" << project_grades[number]<<"/150 points."<<std::endl;
                break;
            }
            else{
                std::cout << "Project name: "<<project_names[number] << ":\n" << project_grades[number]<<"/350 points."<<std::endl;
                break;
            }
    }
}
void gradebook::display_category(std::string category)
{
    float cat_total;
    int cat = std::stoi(category);
    switch(cat){
        case 1:
            for(int i=0;i<lab_grades.size();i++){
                cat_total += lab_grades[i];
            }
            std::cout<<"Lab category total:\n"<<cat_total<<"/200 points."<<std::endl;
            break;
        case 2:
            for(int i=0;i<assignment_grades.size();i++){
                cat_total += assignment_grades[i];
            }
            std::cout<<"Assignment total:\n"<<cat_total<<"/200 points."<<std::endl;
            break;


        case 3:

            break;
    }


}
void gradebook::display_course()
{

}

