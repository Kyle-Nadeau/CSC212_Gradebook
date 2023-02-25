void gradebook::display_category(std::string category)
{
    float cat_total;
    float possible;
    int cat = std::stoi(category);
    switch(cat){
        case 1:
            for(int i=0;i<lab_grades.size();i++){
                cat_total += lab_grades[i];
                possible+=20;
            }
            std::cout<<"Lab category total:\n"<<cat_total<<"/"<<possible<<"."<<std::endl;
            break;
        case 2:
            for(int i=0;i<assignment_grades.size();i++){
                cat_total += assignment_grades[i];
                possible+=50;
            }
            std::cout<<"Assignment total:\n"<<cat_total<<"/"<<possible<<"."<<std::endl;
            break;


        case 3:
            for(int i=0;i<project_grades.size();i++){
                cat_total += project_grades[i];
            }
            
            std::cout<<"Projects total:\n"<<cat_total<<"/500 points."<<std::endl;
            break;
    }


}
