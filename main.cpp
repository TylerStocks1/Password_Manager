#include <iostream> 
#include <string>

#include "optionHandler.h"

using namespace std;

int main()
{
    
    string PASS;    
    int USR_OPTION;

    cout << "What do you want to do?\n";
    cout << "1. Enter a password\n" << "2. Retreive a password\n" << "3. Check passwords\n";
    cout << "Option: ";
    cin >> USR_OPTION;

    option Choice;

    switch (USR_OPTION)
    {
    case 1:
        Choice.EnterPassword();
        break;
    
    case 2:
        Choice.RetreivePass();
        break;
    
    case 3:
        
        break;
    
    default:
        cout << "Invalid option";
        break;
    }

    return 0;
}