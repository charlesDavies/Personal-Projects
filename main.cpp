#include <iostream>
#include <fstream>
using namespace std;

//Class made for course
class course{
   public:
      string subject;
      string courseName;
      char courseLevel;
      string courseBeginning;
      string courseEnding;
      int courseAssessmentAmount;
      
      //Function to get the user to enter data on course
      void getCourseData(){
        cout << "\n\tEnter Course Subject: ";
        cin >> subject;
        cout << "\n\tEnter Course Name: ";
        cin >> courseName;
        cout << "\n\tEnter Course Level: ";
        cin >> courseLevel;
        cout << "\n\tEnter Course Beginning: ";
        cin >> courseBeginning;
        cout << "\n\tEnter Course Ending: ";
        cin >> courseEnding;
        cout << "\n\tEnter Amount of Course Assessments: ";
        cin >> courseAssessmentAmount;

      }
       // Function that shows the data that has been inputted
       void putCourseData(){
        cout << "\n" << "Course Subject: " << subject << "\n" << "Course Name: " << courseName << "\n" << "Course Level: " << courseLevel << "\n" << "Course Start: " << courseBeginning << "\n" << "Course End: " << courseEnding << "\n" << "Course Assessment Amount: " << courseAssessmentAmount << "\n" << "\n";

      
      }
       // Function that writes that data to a text file
       void putCourseToFile(){
        ofstream myfile;
        myfile.open ("Courses.txt", ios_base::app);
        if (myfile.is_open())
        {
          myfile << "\t" << "Course Subject: " << subject << endl;
          myfile << "\t" << "Course Name: " << courseName << endl;
          myfile << "\t" << "Course Level: " <<courseLevel << endl;
          myfile << "\t" << "Course Start: " << courseBeginning << endl;
          myfile << "\t" << "Course End: " << courseEnding << endl;
          myfile << "\t" << "Course Assessment Amount" << courseAssessmentAmount << endl;
          myfile << "\n";
        
          myfile.close();
        }
        else cout << "Unable to open file";
      }
    

};


// Class for a student
class student{
    public:
      int age;
      int id;
      string firstName;
      string lastName;
      string course1;
      string course2;
      
      //Function to get user input about students
      void getStudentData(){
        
        cout << "\n\tEnter Student age: ";
        cin >> age;
        while (cin.fail()) {
        cout << "\nPlease enter a whole number: ";
        cin.clear();
        cin.ignore();
        cin >> age;
        }

        cout << "\n\tEnter Student ID: ";
        cin >> id;
        while (cin.fail()) {
        cout << "\nPlease enter an ID number: ";
        cin.clear();
        cin.ignore();
        cin >> id;
        }

        cout << "\n\tEnter Student First Name: ";
        cin >> firstName;
        cout << "\n\tEnter Student Last Name: ";
        cin >> lastName;
        cout << "\n\tEnter Student Course 1: ";
        cin >> course1;
        cout << "\n\tEnter Student Course 2: ";
        cin >> course2;

      }

      //Function to show user input about students
      void putStudentData(){
        cout << "\n" << "Student Age: " << age << "\n" << "Student ID: " << id << "\n" << "Student First Name: " << firstName << "\n" << "Student Last Name: " << lastName << "\n" << "Course One: " << course1 << "\n" << "Course Two: " << course2 << "\n" << "\n";

      
      }
      
      //Function write data to text file
      void putStudentToFile(){
        ofstream myfile;
        myfile.open ("Students.txt", ios_base::app);
        if (myfile.is_open())
        {
          myfile << "STUDENT NUMBER " << id << endl;
          myfile << "\t" << "Student Age: " << age << endl;
          myfile << "\t" << "Student ID: " << id << endl;
          myfile << "\t" << "Student First Name: " << firstName << endl;
          myfile << "\t" << "Student Last Name: " << lastName << endl;
          myfile << "\t" << "Course One: " << course1 << endl;
          myfile << "\t" << "Course Two: " << course2 << endl;
          myfile << "\n";
        
          myfile.close();
        }
        else  cout <<  "Unable to open file.";
      }

      
};


int main() {

  
  //Choosing whether you want course or students
  cout << "Please choose area of interest:\n";
  cout << "\t 1: Students\n";
  cout << "\t 2: Course\n";
  int choice;
  cout << "\n";
  cout << "Enter 1 for Student or 2 for Courses here: ";
  cin >> choice;
  //Catches any input errors and keeps asking user for an input
  while (cin.fail()) {
    cout << "\nPlease enter 1 or 2, nothing else: ";
    cin.clear();
    cin.ignore();
    cin >> choice;
  }
  cout << "\n";

  if (choice == 1)
  {
     cout << "Would you like to add details or view details: \n";
     cout << "\t 1: Add\n";
     cout << "\t 2: View\n";
     
     int choiceTwo;
     cout << "\n";
     cout << "Enter choice here: ";
     cin >> choiceTwo;

     //catches any input errors and asks user for another input
     while (cin.fail()) {
     cout << "\nPlease enter 1 or 2, nothing else: ";
     cin.clear();
     cin.ignore();
     cin >> choiceTwo;
     }
     cout << "\n";

     if (choiceTwo == 1)
     {

      int i;
      int amountToInput;
      cout << "Please input the amount of students you would like to add: ";
      cin >> amountToInput;

      //catches any input error etc
      while (cin.fail()) {
      cout << "\nPlease input a whole number: ";
      cin.clear();
      cin.ignore();
      cin >> amountToInput;
      }

      student E[amountToInput];

      for(i = 0; i < amountToInput; i++)
      {
        cout <<"\nEnter details of " << i + 1 << " Student";
        E[i].getStudentData();
      }

      cout << "\nDetails of Students\n\n" ;
      for (i = 0; i < amountToInput; i++){
        cout << "STUDENT " << i + 1 << " DETAILS";
        E[i].putStudentData();
        E[i].putStudentToFile();
          }

    }
      //This chooses whether to just simply display everything on the file or two search for something and display only that information
      if (choiceTwo == 2)
      {
        cout << "Would you like to: 1. View everything or 2. Search for something: ";
        int searchOrView;
        cin >> searchOrView;
        while (cin.fail()) {
          cout << "\nPlease input either 1 or 2: \n ";
          cin.clear();
          cin.ignore();
          cin >> searchOrView;
        }
        string search;
        string line;
        if (searchOrView == 1){

        ifstream myfile ("Students.txt");
        if (myfile.is_open())
        {
          while ( getline (myfile,line) )
          {
            cout << line << '\n';
          }
          myfile.close();
        } 
        else cout << "Unable to open file.";
 
        }
        
        //checks for the ID you inputted to see if its in the file and then prints all relevant information to the console
        if (searchOrView == 2){
          ifstream myfile ("Students.txt");
          if (myfile.is_open())
          {
            cout <<"\nEnter ID to search for: ";
            cin >> search;
            size_t pos;
            while(myfile.good())
            {
              getline(myfile, line);
              pos = line.find(search);
              if (pos!=string::npos)
              {
                cout << "\n";
                cout << line << "\n";

                for (int i = 0; i < 6; i++)
                {
                getline(myfile, line);
                cout << line << "\n";
                
                

                }

                break;
              }
              
            }
          }
        }

        
      }
  }


  if (choice == 2){
    cout << "Would you like to add details or view details: \n";
     cout << "\t 1: Add\n";
     cout << "\t 2: View\n";
     
     int choiceTwo;
     cin >> choiceTwo;

     if (choiceTwo == 1){
       int i;
       int amountToInput;
       cout << "Please input the amount of courses you would like to add: ";
       cin >> amountToInput;
       course E[amountToInput];

       for(i = 0; i < amountToInput; i++)
        {
          cout <<"\nEnter details of Course " << i + 1;
           E[i].getCourseData();
        }


        cout << "\nDetails of Courses\n\n" ;
        for (i = 0; i < amountToInput; i++){
        cout << "COURSE " << i + 1 << " DETAILS";
        E[i].putCourseData();
        E[i].putCourseToFile();
        }

     }

     if (choiceTwo == 2)
      {
        string line;
        ifstream myfile ("Courses.txt");
        if (myfile.is_open())
        {
          while ( getline (myfile,line) )
          {
            cout << line << '\n';
          }
          myfile.close();
        } 
        else cout << "Unable to open file.";

         
      }
  }



   

}