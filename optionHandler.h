#pragma once
#include <string>
using namespace std;
class option
{

    public: 
    int Menu();
    void EnterPassword();
    void RetreivePass();

    private:
    void AppendPasswords(string PASS);
    string hashPassword(const string& password);


};
