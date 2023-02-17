#ifndef REVIEW_PROJECT_GRADEBOOK_H
#define REVIEW_PROJECT_GRADEBOOK_H


#include <vector>
#include <string>

//TODO So after trying to define some of these functions I think we still need to decide as a group how exactly we want the program to function, like trace pseudocode from start to finish to determine whats necessary

class gradebook {
private:
    //Attributes

    std::string name;
    std::vector<std::string> lab_names;
    std::vector<std::string> assignment_names;
    std::vector<std::string> project_names;
    std::string exam_name;

    std::vector<float> lab_grades;
    std::vector<float> assignment_grades;
    std::vector<float> project_grades;

    float exam_grade;
    float total_grade;
    char letter_grade;

public:

    /*TODO Decide if we need all of these getter methods once we design other methods - Do we want getter fetching entire vector or a single item from vector?
    /TODO Will technically need to be able to do both, but we can handle selecting individual items from vector in another function?
     */

    //Getters

    std::string get_name();
    std::vector<std::string> get_lab_names();
    std::vector<std::string> get_assignment_names();
    std::vector<std::string> get_project_name();
    std::string get_exam_name();

    std::vector<float> get_lab_grades();
    std::vector<float> get_assignment_grades();
    std::vector<float> get_project_grades();

    float get_exam_grade();
    float get_total_grade();
    char get_letter_grade();

    //protected:
        /*
         * TODO with setters, we could take in a single value and append it to the vector attribute or take in an entire vector at once
         */

         //Setters

    void set_name(std::string student_name);
    void set_lab_names(std::vector<std::string> names_of_labs);
    void set_assignment_names(std::vector<std::string> names_of_assignments);
    void set_project_names(std::vector<std::string> names_of_projects);
    void set_exam_name(std::string name_of_exam);

    void set_lab_grades(std::vector<float> grades);
    void set_assignment_grades(std::vector<float> grades);
    void set_project_grades(std::vector<float> grades);

    void set_exam_grade(float grade);
    void set_total_grade(float grade);
    void set_letter_grade(char grade);

    //Display or ToString methods for printing to console for each category - Individual, Category, Course

    void display_individual(); // TODO Options: Take in just the values we want printed, find values in different method OR Take in vector of grades/names, and item we are searching for, logic for search included in single function
    void display_category();
    void display_course();
    void drop_lowest_labs();

};

#endif //REVIEW_PROJECT_GRADEBOOK_H
