#pragma once
#ifndef PROFILE_MANAGER_H
#define PROFILE_MANAGER_H

#include <iostream>
#include <fstream>

using namespace std;

// User Account Manager Class
class ProfileManager{
    private:
        // User Account Form
        struct Profile{
            char name[100];
            char password[100];
        };
        bool profile_exist = false; // flag to check whether profile data file exist or not
        string username;
    public:
        // constructor
        ProfileManager()
        {
            if(FILE *fp = fopen(".profile.dat", "r")) // try to open profile data file 
            {
                fclose(fp);
                profile_exist = true;
            }
        }
        void setup_user();
        bool login_user();
        bool get_exist_flag();
        string get_username();
};

#endif 
