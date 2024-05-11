#include <iostream>
#include <string>
#include <fstream>
#include <openssl/sha.h>

#include "optionHandler.h"

using namespace std;
string FILE_NAME = "password.txt";

int option::Menu()
{
    string PASS;    
    int USR_OPTION;

    cout << "What do you want to do?\n";
    cout << "1. Enter a password\n" << "2. Retreive a password\n" << "3. Check passwords\n" << "4. Exit \n";
    cout << "Option: ";
    cin >> USR_OPTION;

    switch (USR_OPTION)
    {
    case 1:
       EnterPassword();
        break;
    
    case 2:
        RetreivePass();
        break;
    case 3:
        
        break;
    case 4:
        return 0;
        break;
    default:
        cout << "Invalid option";
        break;
    }

}

void option::EnterPassword()
{
    string Password;

    cout << "Enter a password: ";
    cin >> Password;
    

    //HASH
    string hashedPass = hashPassword(Password);
    cout << "Hashed password: " << hashedPass << std::endl;
    cout << "normal password: " << Password << std::endl;

    //Check to see if file exists, if not create it.
    ofstream outputFile;
    ifstream fileExists(FILE_NAME);

    if(fileExists)
    {
        AppendPasswords(Password);
    }
    else 
    { 
        cout << "Creating storage for passwords";
        outputFile.open(FILE_NAME); 
        AppendPasswords(Password);
    }
    outputFile.close();
    Menu();
}

void option::RetreivePass()
{
    string password;
    ifstream fileExists(FILE_NAME);

    cout << "Enter the password that you want to get: ";
    cin >> password;

    string line;
    string passFound;

    if(fileExists)
    {
        //if the file exists we open it up
        ifstream inputFile(FILE_NAME);

        while (std::getline(inputFile, line))
        {
            // Check if the line contains the password
            if (line.find(password) != std::string::npos) {
                std::cout << "Password found: " << line << std::endl;
                passFound = line;
                break; // Exit loop if password is found
            }
            else
            {
                cout << "Password does not exist!";
                break;
            }
        }
    }
    else 
    { 
        cout << "No Password file found!\n";   
    }

    Menu();
}

void option::AppendPasswords(string PASS)
{
    ofstream outputFile(FILE_NAME, std::ofstream::app);
        
    if (!outputFile) 
    {
        std::cerr << "Unable to open file" << std::endl;
    }

    outputFile << PASS << std::endl;
    Menu();
}

string option::hashPassword(const string &password)
{
    unsigned char hash[SHA256_DIGEST_LENGTH]; // Buffer to hold the hash
    SHA256_CTX sha256; // Context structure for SHA-256 hashing

    // Initialize the SHA-256 context
    if (!SHA256_Init(&sha256)) {
        std::cerr << "Error initializing SHA-256 context" << std::endl;
        return ""; // Return empty string on error
    }

    // Update the context with the password data
    if (!SHA256_Update(&sha256, password.c_str(), password.length())) {
        std::cerr << "Error updating SHA-256 context" << std::endl;
        return ""; // Return empty string on error
    }

    // Finalize the SHA-256 hash and store it in the hash buffer
    if (!SHA256_Final(hash, &sha256)) {
        std::cerr << "Error finalizing SHA-256 hash" << std::endl;
        return ""; // Return empty string on error
    }

    // Convert the binary hash to a hexadecimal string
    std::string hashedPassword;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        char buf[3];
        snprintf(buf, sizeof(buf), "%02x", hash[i]);
        hashedPassword += buf;
    }

    return hashedPassword;
    Menu();
}

