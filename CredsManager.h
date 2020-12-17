#ifndef REPORT_MAKER_CREDSMANAGER_H
#define REPORT_MAKER_CREDSMANAGER_H
#include <iostream>

class CredsManager{
private:
    char Username[30];
    int Passcode;
public:
    void Register_Account();
    bool Login_Account(std::string user, int pass);
};

#endif //REPORT_MAKER_CREDSMANAGER_H
