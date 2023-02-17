#include "Gradebook.h"
#include <iostream>
#include <string>
#include<vector>

//Incredibly basic setup right now


//Setters
void Gradebook::set_name(std::string student_name)
{
	name = student_name;
}

//
void Gradebook::set_lab_names(std::vector<std::string> names_of_labs)
{
	lab_names = names_of_labs;
}

//
void Gradebook::set_assignment_names(std::vector<std::string> names_of_assignments)
{
	assignment_names = names_of_assignments;
}

//
void Gradebook::set_project_names(std::vector<std::string> names_of_projects)
{
	project_names = names_of_projects;
}

//
void Gradebook::set_exam_name(std::string name_of_exam)
{
	exam_name = name_of_exam;
	

}


//
void Gradebook::set_lab_grades(std::vector<float> grades)
{
	lab_grades = grades;
}

//
void Gradebook::set_assignment_grades(std::vector<float> grades)
{
	assignment_grades = grades;
}

//
void Gradebook::set_project_grades(std::vector<float> grades)
{
	project_grades = grades;
}

//
void Gradebook::set_exam_grade(float grade)
{
	exam_grade = grade;

}
//
void Gradebook::set_total_grade(float grade)
{
	total_grade = grade;
}
//
void Gradebook::set_letter_grade(char grade)
{
	letter_grade = grade;
}

//This is all the getters
std::string Gradebook::get_name()
{
	return name;

}

std::vector<std::string> Gradebook::get_lab_names()
{

	return lab_names;
}
std::vector<std::string> Gradebook::get_assignment_names()
{
	return assignment_names;
}
std::vector<std::string> Gradebook::get_project_name()
{

	return project_names;
}
std::string Gradebook::get_exam_name()
{
	return exam_name;
}

std::vector<float> Gradebook::get_lab_grades()
{

	return lab_grades;
}
std::vector<float> Gradebook::get_assignment_grades()
{

	return assignment_grades;
}
std::vector<float> Gradebook::get_project_grades()
{
	return project_grades;
}

float Gradebook::get_exam_grade()
{

	return exam_grade;
}
float Gradebook::get_total_grade()
{

	return total_grade;
}
char Gradebook::get_letter_grade()
{

	return letter_grade;
}
void drop_lowest_labs()
{
	//This function should sort the vector of labs, then drop the lowest 2;
}
//The display functions
void Gradebook::display_individual()
{
	std::cout << name;
}
void Gradebook::display_category()
{
	
}
void Gradebook::display_course()
{

}
