/*This function program bruteforces a password that is first generated a random password when given a size by the user. When the user enters a size the program prints out the generated password and prints that it is beginning to crack the passwrod this is ton show that something is happening. The mainn function then calls the bruteForcePassword which starts cracking the password. Whenever the bruteForcePassword is about to run i pass an empty string to based on my assumption that the fuction knows nothing about the password including the size of it.*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int iterations = 0; // number of iterations set globally becuase when I tried to use it in main it was not working.
bool found = false;
string ascii = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"; //string holding all the values of the ascii table ranging from 33-93

string generatePassword(int p_size) {
    //Generates a password using random ASCII values when given the length of the password and prints it out too 
    char* password = new char[p_size];
    string test;
    srand(time(NULL));
    for (int i = 0; i < p_size; i++) {
        password[i] = 33 + (rand() % 94);
        test += password[i];
    }
    return test;
}


void bruteForcePassword(string start, string password, int l) {
    for (int i = 0; i < ascii.length(); i++) { // loops through the length of all the values in the ascii string
        if (found == true) { // breaks when the passwrod is found
            break;
        }

        string current_TestCase = start + ascii[i]; // uses the current ascii value to start filling the array with the current value and assigning the string with the values that in turn become the cracked password
        if (current_TestCase != password && start.length() < l) { // checks to see if the password is found and if the length of the generated password is found
            bruteForcePassword(current_TestCase, password, l); // if the password is not found and length of the generated password has not been met yet call the fucntion recursively and begin from the top
        }
        else if (current_TestCase == password) { //if password is found print the number of iterations and the cracked password
            found = true;
            cout << "Found your password " + current_TestCase << endl;
            cout << iterations << " combinations tried" << endl;
            break;
        }
        else {
            iterations++;  // if password is not found increase the interations 
           // cout << found_password << endl; // this prints the last comnbination the bruteforce tired and it failed to find the password only for testing when the password size is small example 3 or less
        }
    }
}

int main() {
    int size;

    cout << "Please enter the size of your password: "; // asking the user for the input
    cin >> size; // initializing the size of the password 
    string password = generatePassword(size); // generating the password given the user inputted size
    cout << "Generated password: " << password << endl;
    int l = password.length() - 1;
    string start = "";
    cout << "Beginning to brute force: " << password << endl;
    clock_t begin = clock(); // begin the timing 
    bruteForcePassword(start, password, l);
    clock_t end = clock(); // end the timing 
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Time taken: " << elapsed_secs << ".s" << endl;

    return 0;
}
