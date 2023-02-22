#include "gradebook.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
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

    /*gradebook kyle;
    gradebook zach;
    gradebook stephen;
    gradebook alex;

    std::vector<gradebook> student_objs;
    student_objs.push_back(kyle);
    student_objs.push_back(stephen);
    student_objs.push_back(zach);
    student_objs.push_back(alex);*/

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
        lab_grades.clear();
        //Getting assignment names
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> assignment_name)
        {
            assignment_names.push_back(assignment_name);

        }
        student_objs[i].set_assignment_names(assignment_names);
        assignment_names.clear();
        //Getting assignment grades
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> assignment_grade)
        {
            assignment_grades.push_back(assignment_grade);

        }
        student_objs[i].set_assignment_grades(assignment_grades);
        assignment_grades.clear();
        //Getting project names
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> project_name)
        {
            project_names.push_back(project_name);

        }
        student_objs[i].set_project_names(project_names);
        project_names.clear();
        //Getting project grades
        std::getline(file_stream, file_line);
        s_stream.str(file_line);
        s_stream.clear();
        while (s_stream >> project_grade)
        {
            project_grades.push_back(project_grade);

        }
        student_objs[i].set_project_grades(project_grades);
        project_grades.clear();
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
    
    //User interface menu
    //TODO Check user inputs
    //TODO Call functions on objects for each option
    //TODO Output file

    std::string name = "";
    std::string input = "";
    int in;
    std::string secondary = "";
    std::string tertiary = "";
    // On main menu, while user chooses not to exit present with further options
    while (input != "Exit") {
        //Choose student which you want to view or change grades for via entering their name
        std::cout << "Choose student name:" << std::endl;
        //Give user all names possible to choose from
        for (int i = 0; i < num_of_students; i++) {
            std::cout << student_objs[i].get_name() << std::endl;
        }
        //Get user first input
        std::cin >> name;
        int index1 = get_obj_from_name(name);
        //Failsafe for menu incase user inputs an invalid name
        while (index1 == -1) {
            std::cout << "Invalid student name." << std::endl;
            std::cout << "Choose student name:" << std::endl;

            for (int i = 0; i < num_of_students; i++) {
                std::cout << student_objs[i].get_name() << std::endl;
            }
            std::cin >> name;
            index1 = get_obj_from_name(name);
        }
        //Next menu; view or change users grades
        std::cout << "Type 1 to view or 2 to change grades." << std::endl;
        std::cin >> in;
        //Failsafe for if user inputs a value that is not 1 or 2 (string etc)
        if (std::cin.fail() || (in < 1 || in>2)) {
            do {
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> in;
            } while (std::cin.fail() || (in < 1 || in>2));
        }
        //If user chose 1 give the view menu
        if (in == 1) {
            std::cout << "Choose number of desired output:" << std::endl;
            std::cout << "1. Individual" << std::endl;
            std::cout << "2. Category" << std::endl;
            std::cout << "3. Course" << std::endl;
            std::cout << "Type Exit to end program." << std::endl;
            std::cin >> input;
            if (input == "Exit") {
                break;
            }
            // Failsafe for next menu
            while (input != "1" && input != "2" && input != "3") {
                std::cout << "Enter 1, 2, or 3:" << std::endl;
                std::cin >> input;
            }

            //Allows user to choose category which they wish to view
            switch (stoi(input)) {
            case 1:
                std::cout << "Choose number of category:" << std::endl;
                std::cout << "1.Labs\n2.Assignments\n3.Project\n4.Exam" << std::endl;
                std::cin >> secondary;
                //Do while as a failsafe incase an invalid entry is input
                do {
                    std::cout << "Choose number of category:" << std::endl;
                    std::cout << "1.Labs\n2.Assignments\n3.Project\n4.Exam" << std::endl;
                    std::cin >> secondary;
                } while (secondary != "1" && secondary != "2" && secondary != "3" && secondary != "4");
                //If secondary is valid, convert to integer for switch
                switch (std::stoi(secondary)) {
                case 1:
                    //TODO add failsafes for tertiary inputs
                    do {
                        std::cout << "Enter lab number:" << std::endl;
                        std::cin >> tertiary;
                    } while (tertiary != "1" && tertiary != "2" && tertiary != "3" && tertiary != "4" && tertiary != "5" && tertiary != "6" && tertiary != "7" &&
                        tertiary != "8" && tertiary != "9" && tertiary != "10" && tertiary != "11" && tertiary != "12");
                    /*student_objs[get_obj_from_name(name)].display_individual(secondary, tertiary);*/ //Broken line
                    break;
                case 2:
                    do {
                        std::cout << "Enter assignment number:" << std::endl;
                        std::cin >> tertiary;
                    } while (tertiary != "1" && tertiary != "2" && tertiary != "3" && tertiary != "4");
                    break;

                case 3:
                    do {
                        std::cout << "Enter project number:" << std::endl;
                        std::cin >> tertiary;
                    } while (tertiary != "1" && tertiary != "2");
                    break;

                case 4:
                    //TODO Exam display
                    break;
                default:
                    std::cout << "Invalid input." << std::endl;

                }

                break;
            case 2:
                do {
                    std::cout << "Choose number of category:" << std::endl;
                    std::cout << "1.Labs\n2.Assignments\n3.Project\n4.Exam" << std::endl;
                    std::cin >> secondary;
                } while (secondary != "1" && secondary != "2" && secondary != "3" && secondary != "4");

                switch (std::stoi(secondary)) {
                case 1:
                    //TODO display lab category
                    break;
                case 2:
                    //TODO display assignment category
                    break;

                case 3:
                    //TODO display Project category
                    break;

                case 4:
                    //TODO display exam category (?? there's only one lol)
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
                    //TODO display all individual grades and course total
                    break;
                case 2:
                    //TODO display all category totals and course total
                    break;

                case 3:
                    //TODO display course total
                    break;

                default:
                    std::cout << "Invalid input." << std::endl;
                }

                break;

            default:
                std::cout << "Invalid input." << std::endl;
            }
        }
        //If user chose 2 give the change menu
        else {

        }
    }

    file_stream.close();
    delete[] student_objs; //The dynamic objects need to be deleted before the program ends.
    return 0;
}

int get_obj_from_name(std::string name) {
    int index;
    if (name == "kyle") {
        index = 0;
        return index;
    }
    if (name == "stephen") {
        index = 1;
        return index;
    }
    if (name == "zach") {
        index = 2;
        return index;
    }
    if (name == "alex") {
        index = 3;
        return index;
    }
    else
        return -1;
}
