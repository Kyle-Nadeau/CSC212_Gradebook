#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
//Students.cpp is Gradebook.cpp

int get_obj_from_name(std::string name);

int main(int argc, char* argv[])
{
    std::string file_line;

    //This should all be input by the file, in the same order.
    int num_of_students;
    std::string student_name;
    std::vector<std::string> lab_names;
    std::vector<float> lab_grades;
    std::vector<std::string> assignment_names;
    std::vector<float> assignment_grades;
    std::vector<std::string> project_names;
    std::vector<float> project_grades;
    std::string exam_name;
    float exam_grade;

    //These two should be gotten from the class, I'm just creating them now in case of testing purposes(We can remove them later.)
    float total_grade;
    char letter_grade;

    //Needed in the for loop to break up whitespace input so that they can be input to vectors
    std::string lab_name;
    int lab_grade;
    std::string assignment_name;
    int assignment_grade;
    std::string project_name;
    int project_grade;

    //Basic variables created to read from files.
    std::ifstream file_stream;
    std::string input_line;
    std::string temp;

    //Getting the text file from user
    std::string file_name = (argv[1]);
    file_stream.open(file_name);

    std::getline(file_stream, file_line);
    std::istringstream s_stream(file_line);

    //Getting number of students, which will be used for a for loop.
    s_stream >> input_line;

    num_of_students = std::stoi(input_line); //This works because the number of students SHOULD be at the start of the file, aka the first line

    gradebook* student_objs = new gradebook[num_of_students];//This should dynamically create n amount of objects, with n being
    //the num_of_students given by the file


    //Creating a loop to get the required data from the text file, and assigning it to different students.
    //A for loop is necessary to iterate through the objects being created. If you use a while, you'll need to define a counter and use that with it
    //or there will be no way to iterate through the objects.
    for (int i = 0; i < num_of_students; i++)
    {
        //The following code is a mess, there definetely is a way to clean it up later, but it should all run, and assign the values to a new object.
        //Getting name
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.seekg(0);
        student_objs[i].set_name(file_line);

        //Getting the labs
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.seekg(0);
        while (s_stream >> lab_name)//This will go through the line, skipping any white space character, and then assign them to the lab name vector
        {
            lab_names.push_back(lab_name);
        }
        student_objs[i].set_lab_names(lab_names);

        //Getting the lab grades
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> lab_grade)
        {
            lab_grades.push_back(lab_grade);

        }
        student_objs[i].set_lab_grades(lab_grades);

        //Getting assignment names
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> assignment_name)
        {
            assignment_names.push_back(assignment_name);

        }
        student_objs[i].set_assignment_names(assignment_names);

        //Getting assignment grades
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> assignment_grade)
        {
            assignment_grades.push_back(assignment_grade);

        }
        student_objs[i].set_assignment_grades(assignment_grades);

        //Getting project names
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> project_name)
        {
            project_names.push_back(project_name);

        }
        student_objs[i].set_project_names(project_names);

        //Getting project grades
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> project_grade)
        {
            project_grades.push_back(project_grade);

        }
        student_objs[i].set_project_grades(project_grades);

        //Getting exam name
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> exam_name)
        {
            student_objs[i].set_exam_name(exam_name);

        }

        //Getting exam grade
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> exam_grade)
        {
            student_objs[i].set_exam_grade(exam_grade);

        }

        std::getline(file_stream, file_line);//This gets rid of the white space between each student
        s_stream.str(file_line);
        s_stream.clear();
    }

    /*Quick for loop test to make sure everything went in properly.
    for (int i = 0; i < num_of_students; i++)
    {
        student_name = student_objs[i].get_name();
        std::cout << student_name << std::endl;
    }
    */
    //User interface menu

    std::string name = "";
    std::string input = "";
    int in;
    std::string secondary = "";
    std::string tertiary = "";
    while(input != "Exit") {
        std::cout << "Choose student name:" << std::endl;
        for (int i = 0; i < num_of_students; i++) {
            std::cout << student_objs[i].get_name() << std::endl;
        }
        std::cin >> name;
        int index1= get_obj_from_name(name);
        while(index1==-1){
            std::cout<<"Invalid student name."<< std::endl;
            std::cout << "Choose student name:" << std::endl;
            for (int i = 0; i < num_of_students; i++) {
                std::cout << student_objs[i].get_name() << std::endl;
            }
            std::cin >> name;
            index1= get_obj_from_name(name);
        }
        std::cout << "Type 1 to view or 2 to change grades." << std::endl;
        std::cin >> in;
        if(std::cin.fail()){
            std::cout<<"Invalid input."<<std::endl;
            std::cin >> in;
        }
        else {
            if (stoi(input) == 1) {
                std::cout << "Choose number of desired output:" << std::endl;
                std::cout << "1. Individual" << std::endl;
                std::cout << "2. Category" << std::endl;
                std::cout << "3. Course" << std::endl;
                std::cout << "Type Exit to end program." << std::endl;
                std::cin >> input;
                if (input == "Exit") {
                    break;
                }
                //Might want an error checker to make sure input is a valid input
                switch (stoi(input)) {
                    case 1:
                        std::cout << "Choose number of category:" << std::endl;
                        std::cout << "1. Labs\n2.Assignments\n3.Project\n4.Exam" << std::endl;
                        std::cin >> secondary;
                        switch (std::stoi(secondary)) {
                            case 1:
                                std::cout << "Enter lab number:" << std::endl;
                                std::cin >> tertiary;


                                break;
                            case 2:
                                std::cout << "Enter assignment number:" << std::endl;
                                std::cin >> tertiary;

                                break;

                            case 3:
                                std::cout << "Enter project name:" << std::endl;
                                std::cin >> tertiary;

                                break;

                            case 4:

                                break;
                            default:
                                std::cout << "Invalid input." << std::endl;
                        }

                        break;
                    case 2:
                        std::cout << "Choose number of category:" << std::endl;
                        std::cout << "1. Labs\n2.Assignments\n3.Project\n4.Exam" << std::endl;
                        std::cin >> secondary;
                        switch (std::stoi(secondary)) {
                            case 1:

                                break;
                            case 2:

                                break;

                            case 3:

                                break;

                            case 4:

                                break;

                            default:
                                std::cout << "Invalid input." << std::endl;
                        }
                        break;

                    case 3:
                        std::cout << "Choose number of type:" << std::endl;
                        std::cout << "1. All grades and course total" << std::endl;
                        std::cout << "2. Only category totals and course overall" << std::endl;
                        std::cout << "3. Only course total" << std::endl;
                        std::cin >> secondary;

                        switch (std::stoi(secondary)) {
                            case 1:

                                break;
                            case 2:

                                break;

                            case 3:

                                break;

                            default:
                                std::cout << "Invalid input." << std::endl;
                        }

                        break;

                    default:
                        std::cout << "Invalid input." << std::endl;
                }
            }
        }
    }

    file_stream.close();
    //delete[] student_objs; //The dynamic objects need to be deleted before the program ends.
    return 0;
}

int get_obj_from_name(std::string name){
    int index;
    if(name == "kyle"){
        index = 0;
        return index;
    }
    if(name == "stephen"){
        index = 1;
        return index;
    }
    if(name == "zach"){
        index = 2;
        return index;
    }
    if(name == "alex"){
        index = 3;
        return index;
    }
    else
        return -1;
}
