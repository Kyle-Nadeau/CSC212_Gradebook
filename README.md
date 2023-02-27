# CSC212_Gradebook
### Summary
Hello! This repository was create to house our program for our gradebook review project within CSC212. It will allow us to document contributions of different group members as well as allow ease of access and replication as an open source hub. Our group consisted of four members; Alex Bergeron, Kyle Nadeau, Stephen Brown and Zach Albanese. Our group planned and met various times over the assignment timeframe, working together to debug, formulate creative ideas and imlpement our overall Gradebook program.

### Planning
For this project out first meeting was to discuss an overall structure we wanted to follow for our program.
We were able to come up with what we wanted our main gradebook class to be, its private and public data members & methods, and how we wanted our data to be input to the program. We came to the agreement each instantiation of the class as an object should represent a singular student; holding important factors such as their name, grades(as float vectors) for labs/assignments/projects and the exam, and string vectors for the names of each lab/assignment/project. We also figured for our input file we wanted the first line to be a number taken into the program as a singular integer, representing the number of students whose class profiles will be uploaded. This allows us to input multiple students information at a time only using a singular file- by modifying the file contents and number of students, the program will react accordingly. 

### Compilation Instructions

### Runtime Instructions
##### Input File Formatting
First you must ensure that your input file is in the correct format of:<br />

&ensp;  -Number of students in file<br />
&ensp;  -First student's name<br />
&ensp;  -Names of labs, any labs with multiple words in the title will have an underscore between them and the lab names are separated by spaces<br />
&ensp;  -Grades for labs out of 20 points separated by spaces<br />
&ensp;  -Names of assignments, same formatting as labs<br />
&ensp;  -Grades of assignments, out of 50 points separated by spaces<br />
&ensp;  -Names of projects, same formatting as labs and assignments<br />
&ensp;  -Grades of projects separated by a space the first one out of 150 points and the second one out of 350 points<br />
&ensp;  -Final_exam<br />
&ensp;  -Final exam grade out of 100 points<br />
&ensp;  -Empty line to signify end of student then repeat the student name to empty line formatting for each following student<br />

##### Select Student
After the input is taken in and the file runs you will be asked to type in a student name(case sensitive) to view or change their grades or an exit option to exit the program.

Once a student is chosen the next step in the menu will ask you to type 1 to view the chosen student's grades or 2 to change them.

##### View Grade
If you chose to view a grade or grades you will then be asked to enter a number for how you would like to view them:
  1. Individual<br />
      Here you will be asked to input a number for the category you want, then you will be asked to enter the number of the lab, assignment, or project that you would like to view unless you choose exam in that case you will be immediately shown the exam grade.<br />
  2. Category<br />
      Here you will be asked to input a number for the category you want to view after which you will be shown the total grade earned in that category out of the total possible number of points.<br />
  3. Course<br />
      Here you will be shown all of the grades for the course for the student along with their letter grade that has been calculated for you.<br />


##### Change Grade
If you chose to change a grade you will then be asked to choose with category of their grades you would like to change.<br />
To choose a category type in the corresponding number: 1 for labs, 2 for assignments, 3 for projects, 4 for exams.<br />

You will then be asked to enter the number of lab, assignment, or projects to change, if you chose exam this step is skipped because there is only one exam.<br />

Next you will be asked to input the updated grade value and then that updated grade will be written directly to the input file.<br />

##### Continue or Exit
After you have viewed or changed a grade you will be looped back to the first menu asking for a student name and you can continue to use the program with the steps above.

When you are finished using the program and you are on the first menu asking for a student name, you can type Exit(case sensitive) to exit the program.<br />
