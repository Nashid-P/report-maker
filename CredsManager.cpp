#include "CredsManager.h"
#include <limits>

void CredsManager::Register_Account() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\t\t\t REGISTER NEW ACCOUNT \n";
    std::cout << " Enter username : ";
    std::cin.getline(this->Username, 30);
    std::cout << " Enter Password (Only Numbers) : ";
    std::cin >> this->Passcode;
}

bool CredsManager::Login_Account(std::string user, int pass) {
    if((std::string)this->Username == user && Passcode == pass)
        return true;
    return false;
}

