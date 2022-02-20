#include <iostream>
#include <fstream>

using namespace std;

/*
    Code created by megyerikenez.

*/


/*
Opens the file in readmode,inputs data from the user and check if its not yet in the database
if it is in the database then its starts again the registration.
If the data is not in the database its closes the readmode opens a writemode and write the data in the base,
after that it returns to menu
*/

void userregister(){
    string userId,password1,password2,line;
    ifstream myread;
    myread.open("database.txt",ios::in);
    cout << "Please enter your registry data: " << endl;
    cout << "USERNAME: ";
    cin >> userId;
    while(getline(myread,line)){
        while(line == userId){
            cout << "Username already taken, please choose another username: " << endl;
            cin >> userId;
        }
    }
    cout << "PASSWORD FIRST TIME: ";
    cin >> password1;
    cout << "PASSWORD SECOND TIME: ";
    cin >> password2;
    while(password1 != password2){
        cout << "PASSWORD FIRST TIME: ";
        cin >> password1;
        cout << "PASSWORD SECOND TIME: ";
        cin >> password2;
    }
    cout << "Registration succesfull, you can login now!" << endl;
    myread.close();
    ofstream myfile;
    myfile.open("database.txt",ios::app);
    if(myfile.is_open()){
        myfile << userId << endl;
        myfile << password1 << endl;
        myfile.close();
    }
}

/*
Opens the database in readmode,checks if the username and password is correct,if its not correct
starts the userregister function.
*/

void userlogin(){
    string userId,password,line;
    ifstream myread;
    myread.open("database.txt",ios::in);
    cout << "USERNAME: ";
    cin >> userId;
    cout << "PASSWORD: ";
    cin >> password;
    int number = 1;
    string last_username = "";
    string last_password = "";
    bool logged = false;
    while(getline(myread,line)){
        if(!logged){
            if(number == 1){
                number = 2;
                last_username = line;
            }
            if(number == 2 && line != last_username){
                number = 1;
                last_password = line;
            }
            if(last_password == password && last_username == userId && !logged){
                logged = true;
                 cout << "Welcome " << userId << "!" << endl;
                 break;
            }
        }
    }
    if(!logged){
        cout << "Username or password is wrong please register a new account!" << endl;
        userregister();
    }

}

/*
Prints the menu in command line.
*/

void guiprint(){
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t Login System v0.1 created by: Kenez Megyeri" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t Welcome to my register/login system."<< endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Press 1 to Login" << endl;
    cout << "Press 2 to Register" << endl;
    cout << "Press 3 to EXIT" << endl;
    cout << "Your choice: ";
}


/*
Creates a switch depending on the users chooice, after printing the gui.
*/

int main()
{
    guiprint();
    int c;
    cin >> c;
    cout << endl;
    switch (c) {
        case 1:
            userlogin();
            break;
        case 2:
            userregister();
            system("cls");
            cout << "\t\tSuccessfull Registration try to login now!" << endl << endl;
            main();
        case 3:
            cout << "\t Thank you!" << endl;
            break;
        default:
            system("cls");
            cout << "Please select from the options given above" << endl;
            main();
    }

    return 0;
}
