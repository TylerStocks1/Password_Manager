#pragma once
#include <string>
using namespace std;
class option
{

    public: 
    int Menu();
    private:
    void EnterPassword();
    void RetreivePass();

    void AppendPasswords(string PASS);
    string hashPassword(const string& password);


};
