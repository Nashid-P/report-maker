/**
 * Developer : IKT HSS SSC BATCH
 * Program name : Report Maker
 * Description : A simple program in c++ for making students report card
 * 
 * <fstream> FILE I/O Operations , Eg: for storing input data to a text file
 * 			See : https://www.geeksforgeeks.org/file-handling-c-classes/
 * 
 * <ctime> Time header file , Retrieves localtime
 * 			See : https://www.geeksforgeeks.org/c-program-print-current-day-date-time/
 * 
 * Functions Overview :-
 * 
 * 	bool check(string arr)
 * 		data type bool , returns bool value (1/0) 
 * 		Argument type string, Accepts std::string data type variables for processing
 * 		Description : Check a string for the presence of numbers in it , returns true if found
 *			std::string See : https://www.geeksforgeeks.org/stdstring-class-in-c/ 	
 *	
 *  void Execute()
 * 		data type void , returns no value
 * 		Argument type void , doesn't accept any arguments
 * 		Description : Core function of the program , Ask user for inputs and store them into a file
 * 
 * 	void history(int n, char** arr)
 * 		data type void , returns no value
 * 		Argument type int , char** : Accepts a integer variable/value and char** which is pointer to char*
 * 			Reference for char** // https://stackoverflow.com/questions/13353807/what-is-char-in-c
 * 		Description : Accepts data from core function and store it to a log / history file 		
 * 
 * 	void manage(int n)
 * 		data type void , returns no value
 * 		Argument type int , Accepts integer variable/value
 * 		Description : Function to handle log / history file , Deleting log file and Reading log file are supported
 * 
 * 
 * 	void login(string uname, string pass)
 * 		data type void , returns no value
 * 		Argument type string , Accepts string value
 * 		Description : Function to validate username and password
 *  
 * 	int main()
 * 		data type int , returns integer value , return 0 on a successfull execution
 * 		Argument type void , doesn't accept any arguments
 * 		Description : Starting point of the program
 **/ 

#include <iostream>
#include <cstdio>
#include <cstring> 
#include <fstream> 
#include <ctime>
#include <ios>
#include <limits>
#ifdef _WIN32
    const char* cmd = "cls";
    const char* hold = "PAUSE";
#elif __linux__
    const char* cmd = "clear";
#endif 

using namespace std;

bool check(string arr); 
void Execute(); 
void manage(int );
struct students_details{ 
		string name;
		int marks[6]{};
		int roll_num{};
		int total{};
		double average{};
		double percentage{};
};
void history(int, struct students_details *report, const char **arr);
bool check_exist(int, int, struct students_details *report);

namespace colors{
	const char* red = "\033[1;31m";
	const char* green = "\033[1;32m";
	const char* white = "\033[0m";
    const char* cyan = "\033[1;36m";
};

int main()
{
	int op;
	system(cmd);
    cout << colors::red << R"(                                                      
		   _____                 _      _____     _           
		  | __  |___ ___ ___ ___| |_   |     |___| |_ ___ ___ 
		  |    -| -_| . | . |  _|  _|  | | | | .'| '_| -_|  _|
		  |__|__|___|  _|___|_| |_|    |_|_|_|__,|_,_|___|_|  
		            |_|                                       

  
	            Developed by IKT HSS SSC BATCH 2020
	)" << colors::white << endl;	
	cout << "\n\t\t\t\t 1. Create a New Report " << endl;
	cout << "\t\t\t\t 2. Check the Report log "  << endl;
	cout << "\t\t\t\t 3. Delete the Report log " << endl;
	cout << "\t\t\t\t 4. About the program " << endl;
	cout << "\t\t\t\t 0. Exit the program " << endl;
	cout << "\t\t\t\t Enter a option to continue : ";
	cin >> op;
	switch(op)
	{
		case 1:
			Execute(); 
			break;
		case 2:
		case 3:
			manage(op); 
			break;
		case 4:
			cout << colors::green << "\n\t\t\t\t Developed by IKT HSS SSC BATCH " << endl;
			cout << "\t\t\t\t Simple program to make report cards of students " << endl;
			cout << "\t\t\t\t History logs are stored in .report_history file and can be accessed using Option 3 in main menu " << endl;
			cout << "\t\t\t\t Thank you for using our program \n\n\n" << colors::white << endl;
			break;
		default:
			cout << "\n\t\t\t\t Exiting Program " << endl;
			system(cmd);
			break;
	}
    cout << colors::white << endl;
	system(hold);
	return 0;
}

void Execute()
{
	
	int number_of_reports;
	
    // Available Subjects
	const char* subjects[] = {
						" Chemistry : ",
						" Physics : ",
						" Maths : ",
						" Computer Science : ",
						" English : ",
						" First Language : "}; 
	
	cout << "\n\n\t\t\t\t STUDENTS MARK LIST \t\t\n";
	cout << "\n\t\t Enter the number of reports : ";
	cin >> number_of_reports;
    
    if(number_of_reports <= 0)
    {
        cout << " Number of reports can't be 0 or signed integer , Please re run the program and insert a valid number " << std::endl;
        exit(1);
    }

    struct students_details report[number_of_reports];
	
    for(int i=0; i < number_of_reports; i++) // Loop till i is not equal to number_of_reports
	{
		cout << "\n\t\t REPORT CARD " << i+1 << " :- " << endl;
		cout << "\t\t ----------------------------- \n";
		
        do{
            // clear buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\t Enter the name of the student : ";
			getline(cin, report[i].name); 
			if(check(report[i].name))
				cout << colors::red << "\t\t Name should not contain numbers , Please enter the name again in correct format " << colors::white << endl;
		}while(check(report[i].name));
		
        do{ 
            cout << "\t\t Enter the roll number : ";
		    cin >> report[i].roll_num;
		    if(check_exist(report[i].roll_num, i, report))
                cout << colors::red << "\t\t This roll number already exists in the current report , please enter correct roll number " << colors::white << endl;
        }while(check_exist(report[i].roll_num, i, report));
        
        for(int j = 0; j < 6; j++)
		{
			cout << "\t\t Enter the mark of" << subjects[j];
			cin >> report[i].marks[j];
			report[i].total = report[i].total + report[i].marks[j];
		}
		
        report[i].average = (double)report[i].total/6;
		report[i].percentage = ((double)report[i].total/600.0)*100.0;
	}
	char ch;
	
    cout << "\n\t\t Store this report to a file ? (y/n) : ";
	cin >> ch;
	
    if(ch == 'y') {
        for (int j = 0; j < number_of_reports; j++) {
            if (j == 0) {
                fstream tFile;  // Declaring variable to hold data for storing to or reading from a file

                tFile.open("student_report.txt",
                           ios::out);  // Open "student_report.txt" in Output Mode , Overwrites the file on each execution
                tFile << "\n\t\t\t STUDENTS MARKLIST \n\n"; // Data inserted to tFile variable is stored into stduent_report.txt
                tFile.close(); // Store all content in tFile variable to "student_report.txt" and close the file
            }
            fstream outFile;

            outFile.open("student_report.txt", ios::out | ios::app); /** Open file in Output Mode and Append Mode , Append Mode stores contents of variable
															   * at the end of the file , Thus preventing Overwriting on each execution **/
            outFile << "\n\n REPORT CARD " << j + 1 << "\n";
            outFile << " ------------------------ \n\n";
            outFile << " Name : " << report[j].name << endl;
            outFile << " Roll Number : " << report[j].roll_num << endl;
            outFile << " Total Mark : " << report[j].total << endl;
            outFile << " Average Mark : " << report[j].average << endl;
            outFile << " Percentage : " << report[j].percentage << "%" << endl;
            outFile.close();

        }
        cout << colors::green << "\n\t\t Done , Check students_report.txt in the current Directory !" << colors::white
             << endl;

        history(number_of_reports, report, subjects); // Calls history() with integer and char*
    } else{
		cout << "\n\t\t Exiting " << endl;
	}
}

bool check(string arr)
{
	for(int i=0; arr[i]!='\0'; i++) // Loop until the end of string
	{
		if(arr[i] >= '0' && arr[i] <= '9') // Check each character for between 0 and 9
		{
			return true; // if a character is a number , return true and exit the function
		}
	}
	return false; 
}

void history(int n, struct students_details *report, const char** arr)
{
	time_t tt; // Declaring variable to store time
	struct tm * ti; // Declaring pointer variable for structure tm
	time(&tt); 
	ti = localtime(&tt); 
	fstream historyFile;
	
    historyFile.open(".report_history", ios::out | ios::app);
	for(int i=0; i < n ; i++)
	{
		if(i==0)
			historyFile << "\n DATE : " << asctime(ti) << endl; // Store time and date 
		
        historyFile << " REPORT CARD " << i+1 << endl;
		historyFile << " ----------------------- " << endl;
		historyFile << " Name : " << report[i].name << endl;
		historyFile << " Roll Number : " << report[i].roll_num << endl;
		
        for(int j=0;j<6;j++)
		{
			historyFile << arr[j] << report[i].marks[j] << ",";
		}
		
        historyFile << endl;
		historyFile << " Total Mark : " << report[i].total << endl;
		historyFile << " Average Mark : " << report[i].average << endl;
		historyFile << " Percentage : " << report[i].percentage << "% \n" << endl; 
	}
}

void manage(int n)
{
	if(n == 2)
	{
		string line; // String variable to store contents of file
		fstream inFile; // Declaring variable to hold contents of file
		inFile.open(".report_history", ios::in);  // Open file in Input Mode / Read Mode
		
        if(!inFile) // If variable return 0 , Error in opening file
			cout << "\t\t No previous logs found \n" << endl;
		
        while(inFile) // Loop until the end of file
		{
			getline(inFile, line); // retrieve contents from file variable to string variable
			cout << colors::cyan << line << endl; // Display contents of string variable , That is , lines in the file
		}
		inFile.close(); // Close the file after Reading
		
	}
	else if(n == 3)
	{
		if(remove(".report_history")==0) // remove("file") , removes file named "file" in the current directory , returns 0 on successful remove 
			cout << "\n Logs Successfully Deleted " << endl;
		else
			cout << "\n Error while deleting file " << endl;
		
	}
}

bool check_exist(int roll_num, int i, struct students_details *report)
{
    for(int j=0;j<i;j++)
    {
        if(roll_num == report[j].roll_num)
            return true;
    }
    return false;
}
