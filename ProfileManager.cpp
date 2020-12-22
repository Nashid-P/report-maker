#include "ProfileManager.h"
#include <limits>



void ProfileManager::setup_user()
{
    Profile NewProfile; // User Account Form Object
    ofstream SaveProfile; // File Handler , output mode
    cout << "\n\n\t\t\t\t\033[1;32m CREATE PROFILE \n" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << " Enter new username : ";
    cin.getline(NewProfile.name, 100);
    cout << " Enter new password : ";
    cin.getline(NewProfile.password, 100);
    SaveProfile.open(".profile.dat", ios::binary); // open profile data file in binary output mode
    SaveProfile.write((char*)&NewProfile, sizeof(NewProfile)); // write user account form into profile data file
    SaveProfile.close(); // close File Handler
    cout << " Account creation successful , Re-run the program to login \033[0m \n" << endl;
}

bool ProfileManager::login_user()
{
    string username, pass;
    Profile ExistingProfile;
    ifstream LoadProfile; // File Handler , input mode
    LoadProfile.exceptions(fstream::badbit | fstream::failbit); // File Exceptions
    cout << "\n\n\t\t\t\t\033[1;34m LOGIN \n" << endl; 
    try{
        cout << " Enter your username : ";
        getline(cin, username);
        cout << " Enter your password : ";
        getline(cin, pass);
        LoadProfile.open(".profile.dat", ios::binary); // open profile data file in binary input mode
        LoadProfile.read((char*)&ExistingProfile, sizeof(ExistingProfile)); // read user account form from profile data file
        LoadProfile.close();
        if( username == ExistingProfile.name && pass == ExistingProfile.password )
        {
            this->username = username;
            cout << "\033[0m";
            return true;
        }
        else
            cout << "\033[1;31m Invalid Credentials, Please try Again \033[0m\n" << endl;
    }catch(fstream::failure e){
        cout << "\033[1;31m database file read failure , make sure you got permission to read and write \033[0m\n" << endl;
    }
    return false;
}

bool ProfileManager::get_exist_flag()
{
    return profile_exist;
}

string ProfileManager::get_username()
{
    return this->username;
}
