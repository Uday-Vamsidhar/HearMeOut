//Prototype of HearMeOut
#include<iostream>
#include<fstream>
#include<string.h>
//#include<cstring>
//for C strings
using namespace std;
int main()
{
    int bell=0;
    //bell =0 in off state and 1 in on state
    cout<<"Enter 1 to ring the bell!(Using sensor to recognise)";
    //takes bell input
    cin>>bell;
    //when the bell goes to off state, someone should remember that it was put to on state once
    int check=bell;
    if(bell==1)
    //do notifications part of the bell
    //TASK1 COMPLETED - NOTIFICATION
    {
        cout<<endl<<"NOTIFICATIONS SET at watch."<<endl;
        cout<<"The bell is rung. (From here, we will see the user part)."<<endl;
    }
    else
    {
        cout<<endl<<"No bell rung."<<endl;
        exit(0);
    }
    bell=0;
    //bell becomes off state
    if(check==1)
    {
        //series of questions in order to pass security conditions
        char answer0,answer1,answer2,answer3,answer11,answer22,confirm;
        string message;
        cout<<endl<<"Would you want to open camera?(Y/N)";
        cin>>answer0;
        if(answer0=='Y')
            //TASK2 COMPLETED - CAMERA REQUEST
            cout<<"Open camera / Access to camera. (Using java later on, we can access camera.)"<<endl;
        else
        {
            cout<<endl<<"Would you want to open microphone?(Y/N)";
            cin>>answer1;
            if(answer1=='Y')
                cout<<"Access to microphone (Java will be used again later)"<<endl;
            else
            {
                cout<<endl<<"Send a waiting message?(Y/N)";
                cin>>answer2;
                if(answer2=='Y')
                {
                    cout<<"What message do you want to send?";
                    string message;
                    cin.ignore();
                    getline(cin, message);
                    cout<<"At the door, 'Defaut' voice will read out this message."<<endl;
                    cout<<message;
                }
                else
                {
                    cout<<"Send a default message."<<endl;
                    cout<<"Please come back later, thank you, have a good day."<<endl;
                }
            }
        }
        if(answer0=='Y')
        {
            //TASK3 COMPLETED - ACCESS TO MICROPHONE
            cout<<endl<<"Would you want to open microphone as well?(Y/N)";
            cin>>answer11;
            if(answer11=='Y')
                cout<<"Access to microphone (Java will be used again later)"<<endl;
            else
            {
                cout<<endl<<"Send a waiting message?(Y/N)";
                    cin>>answer22;
                    if(answer22=='Y')
                    {
                        cout<<"What message do you want to send?";
                        cin.ignore();
                        getline(cin, message);
                        cout<<"At the door, 'Defaut' voice will read out this message."<<endl;
                        cout<<message<<endl;
                    }
            }
        }
        //TASK4 COMPLETED - MESSAGING SYSTEM TO DOOR
        //TASK5 COMPLETED - ACCESS TO THE DOOR ITSELF
        cout<<endl<<"Door Locked!"<<endl;
        cout<<"Do you want to open the door?(Y/N)";
        cin>>answer3;
        if(answer3=='Y')
        {
            if(answer0!='Y')
            {
                cout<<"We are force opening camera for security purposes, confirm if you want to allow this person inside?(Y/N)";
                cin>>confirm;
                if(confirm=='Y')
                    cout<<endl<<"Door Unlocked! (Will use java and hardware technology to allow lock/unlock of door.)"<<endl;
                cout<<"Door auto lock check initiated."<<endl;
            }
            else
            {
                cout<<endl<<"Door Uncloked!(Will use java and harware technology later for implementation)"<<endl;
                cout<<"Door auto lock check initiated."<<endl;
            }
        }
        else
            cout<<endl<<"Door remains locked."<<endl;
    }
    cout<<endl<<"Back at the door again, the system now does this for cloud security purposes."<<endl;
    //security system included
    //cloud will be used later, this is simple prototype working idea
    string
    command, //to choose what to do each time
    name, password, //the ones that are found in the file
    inName, inPassword, //the ones you are going to input from keyboard
    registerName, registerPassword; //also what you're going to input
    //and if you know C strings, just replace that with something like
    /*
    char
    command[9],
    name[31], password[31], //it could be any size, but like this you have got 30 characters at your
    //disposal, if you consider it to be enough
    inName[31], inPassword[31],
    registerName[31], registerPassword[31];
    */
    int stop;
    cout<<endl;
    cout<<"Sytem security check at the door end (Enter any to start process)";
    cin>>stop;
    while (1)
    {
        cout<<"(Register/Exit/Login)\n"
            <<"Command: ";
        getline(cin, command);
        //(for C strings)
        //cin.get(command, 9);
        //cin.get();
        if (command=="Exit") //(for C strings) if (!strcmp(command, "exit"))
        {
            exit(0);
        }
        if (command=="Register") //(for C strings) if (!strcmp(command, "register"))
        {
            //open file for registration
            ofstream g("registration.txt"); //ofstream is the one for getting data from the file, 
            //and the file does not even have to exist. If it's ofstream, it'll take care of it for you.
            //but be warned that if there is a file called "registration.txt" in the name folder as the
            //.exe file, the contents will be deleted
            if (!g.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"Could not open file.\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            cout<<"\n" //newline
                <<"New Username: ";
            getline(cin, registerName); //input from keyboard will go into registerName
            cout<<"New Password: ";
            getline(cin, registerPassword); //input from keyboard will go into registerPassword
            g<<registerName; //this basically says "put whatever's to the right (registerName) into
            //g ("registration.txt")".
            g<<'\n'; //and now there will be a new line
            g<<registerPassword; //and now the password
            //all placed safely in the file that g opened
            g.close(); //always make sure you close the file, or else you might end up with some nasty
            //stuff in the memory
        }
        if (command=="Login") //(for C strings) if (!strcmp(command, "login"))
        {
            //open file, and then put the name and password into the strings
            ifstream f("registration.txt"); //ifstream is the one for getting data from the file, and
            //let us assume you've already created a file called "registration.txt"
            if (!f.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"Could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            getline(f, name, '\n'); //reads the user name from file f (which is using "registration.txt")
            getline(f, password, '\n'); //reads the password from file f (which is using "registration.txt")
            //also, if you tell the file to get you that text up until '\n', that's when you know it reads
            //the whole line at most, and won't go any further
            //and that is done by the 3rd parameter
            f.close(); //you don't need it open now, since you have the name and password from the file

            //login
            while (1)
            {
                //you are going to input the name and password here
                cout<<"\n"
                    <<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                //or this, if you are working with C strings (second version of declaration)
                //cin.get(inName, 31);
                //cin.get();
                //cin.get(inPassword, 31);
                //cin.get();
                //and the "cin.get()" after each input line is necessary, or else[...]
                //no idea what's happening inside istream, but it's mandatory if you don't want your
                //input to get stuck or worse
                if (inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n" //the '\n' is a character, so that's why I can add it 
                    //and it will automatically output a newline in console, alongside the string
                        <<"Welcome, "
                        <<inName<<endl;
                    break; //just exit the while loop if you've entered the valid account
                }
                cout<<"Incorrect name or password\n"; //if you haven't entered the valid account,
                //then the while loop is not done yet. So that's why this output is without condition
            }
            //now do something about the account
        }
        cout<<"\n"; //give it newline
    }
    return 1;
}