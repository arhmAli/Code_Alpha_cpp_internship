//File manager system by Arham khan 
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include <cstdio>
#include <cstdlib>
#include <direct.h>

using namespace std;

class file_manager {
public:
    void readFile() {
        cout << "Enter name of file you want to open" << endl;
        string name;
        getline(cin, name);
        ifstream file(name);
        string currLine;
        while (getline(file, currLine)) {
            cout << currLine << endl;
        }
    }

    void writeFile() {
        cout << "Enter the filename you want to edit" << endl;
        string name;
        getline(cin, name);
        ofstream file(name);
        string in;
        while (in != "exit") {
            getline(cin, in);
            file << in << endl;
        }
        cout<<"*******-------Closing file-------*********"<<endl;
        file.close();
    }

    void renaming() {
        cout << "Enter old name of file" << endl;
        string old;
        getline(cin, old);
        cout << "Enter new name" << endl;
        string newName;
        getline(cin, newName);
        rename(old.c_str(), newName.c_str());
        cout << "FILE RENAMED SUCCESSFULLY" << endl;
    }

    void makeFolder() {
        cout << "Enter name of directory" << endl;
        string name;
        getline(cin, name);
        string cmd = "mkdir " + name;
        if (system(cmd.c_str()) == 0) {
            cout << "Directory made successfully" << endl;
        }
    }

    void openExplorer(const string& path) {
        string command = "explorer \"" + path + "\"";
        system(command.c_str());
    }

    void changeDir() {
        cout << "Enter the path to change directory" << endl;
        string path;
        getline(cin, path);
        string cmd="cd "+ path;
        openExplorer(cmd);
        // if (_chdir(path.c_str()) == 0) {
        //     cout << "PATH CHANGED" << endl;
        //     openExplorer(path);
        // } else {
        //     cout << "Failed to change directory" << endl;
        // }
    }
    void moveFile(){
        cout<<"Enter file name which you want to move"<<endl;
        string name;
        getline(cin,name);
        cout<<"Enter Destination of the file"<<endl;
        string dest;
        getline(cin,dest);
        string cmd="move "+name+" "+dest;
        system(cmd.c_str());
    }
    void echoFile(){
        cout<<"Enter file name which you want to copy"<<endl;
        string name;
        getline(cin,name);
        cout<<"Enter Destination of the file"<<endl;
        string dest;
        getline(cin,dest);
        string cmd="copy "+name+" "+dest;
        system(cmd.c_str());
    }
};

int main() {
    file_manager a;
    // a.echoFile();
    int choice;
    cout << "-----------Welcome to File Manager system by Arham Khan ---------" << endl;
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Read a file" << endl;
        cout << "2. Write to a file" << endl;
        cout << "3. Rename a file" << endl;
        cout << "4. Make a folder" << endl;
        cout << "5. Change directory" << endl;
        cout << "6. Move directory or a File" << endl;
        cout << "7. Copy directory or a file" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                a.readFile();
                break;
            case 2:
                a.writeFile();
                break;
            case 3:
                a.renaming();
                break;
            case 4:
                a.makeFolder();
                break;
            case 5:
                a.changeDir();
                break;
            case 6:
                a.moveFile();
                break;           
            case 7:
                a.echoFile();
                break;
            case 8:
                cout << "Exiting program" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
