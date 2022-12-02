#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int iterations = 0; // number of iterations set globally becuase when I tried to use it in main it was not working.
bool found = false;
string c = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
// string c = "0123456789";
    


string generatePassword(int p_size) {
    //Generates a password using random ASCII values when given the length of the password and prints it out too 
    char* password = new char[p_size]; 
    srand(time(NULL));
    for (int i = 0; i < p_size; i++) {
        password[i] = 33 + (rand() % 94);
    }
    return password;
}


void crack(string start, string password, int l) {
    
        for (int i = 0; i < c.length(); i++) {
            if (found == true) {
                break;
            }

            string currentTestCase = start + c[i];
            if (currentTestCase != password && !found && start.length() < l) { // (test !== input && !done && start.length < maxLength)
                crack(currentTestCase,password,l);
            } else if (currentTestCase == password) {
                found = true;
                cout << "Your password is: " + currentTestCase << endl;
                cout << iterations << " combinations tried before success" << endl;
                break;
            }
            else {
                iterations++;
                // cout << currentTestCase << endl;
            }
        }
    }

int main(){
    string password = generatePassword(4);    //  "9bE2";   "7y\\M"
    cout << "Generated password: " << password << endl;
    int l = password.length() - 1;
    string start = "";
    clock_t begin = clock();
    crack(start,password,l);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time taken: " << elapsed_secs << ".s"<< endl;


    return 0;
};