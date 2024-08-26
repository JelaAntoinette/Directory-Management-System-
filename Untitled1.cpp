#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void showDirectoryMenu() {
    int dirChoice;

    cout << endl;
    cout << "---------------------\n";
    cout << "   LIST FILE DETAIL   \n";
    cout << "---------------------\n";
    cout << "1. List all Files\n";
    cout << "2. List files by Extension\n";
    cout << "3. List files by Name\n";
    cout     << "Enter the number: ";
    cin >> dirChoice;

    switch (dirChoice) {
        case 1: {
            cout << "Listing all files...\n";
            system("dir /a-d");
            break;
        }
        case 2: {
            string extension;
            cout << "Enter the file extension (e.g., .txt): ";
            cin >> extension;
            string command = "dir /a-d *" + extension;
            system(command.c_str());
            break;
        }
        case 3: {
            string pattern;
            cout << "Enter the pattern (e.g., *.txt): ";
            cin >> pattern;
            string command = "dir /a-d " + pattern;
            system(command.c_str());
            break;
        }
        default:
            cout << "Invalid choice in directory management menu.\n";
            break;
    }
}

void changeDirectoryMenu() {
    int changeDirChoice;
    string directory;

    cout << endl;
    cout << "----------------------\n";
    cout << "   CHANGE DIRECTORY   \n";
    cout << "----------------------\n";
    cout << "1. Move one step back (to the parent directory)\n";
    cout << "2. Move to the root directory\n";
    cout << "3. Move to a specific directory\n";
    cout << "Enter the number: ";
    cin >> changeDirChoice;

    switch (changeDirChoice) {
        case 1: {
            cout << "Moving one step back...\n";
            system("cd ..");
            break;
        }
        case 2: {
            cout << "Moving to the root directory...\n";
            system("cd \\");
            break;
        }
        case 3: {
            cout << "Enter the directory path: ";
            cin.ignore();  
            getline(cin, directory);
            string command = "cd \"" + directory + "\"";
            if (system(command.c_str()) == 0) {
                cout << "Successfully moved to: " << directory << endl;
            } else {
                cout << "Failed to move to: " << directory << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice in change directory menu.\n";
            break;
    }
}

void createDirectory() {
    string directoryName;

    cout << "Enter the name of the new directory: ";
    cin.ignore();  
    getline(cin, directoryName);
    
    string command = "mkdir \"" + directoryName + "\"";
    if (system(command.c_str()) == 0) {
        cout << "Directory successfully created: " << directoryName << endl;
    } else {
        cout << "Failed to create directory: " << directoryName << endl;
    }
}

int main() {
    int choice;

    do {
        cout << endl;
        cout << " ----------------\n";
        cout << "    MAIN MENU    \n";
        cout << "------------------\n";
        cout << "1. Display list of files\n";
        cout << "2. Create a new directory\n";
        cout << "3. Change the working directory\n";
        cout << "4. Exit\n";
        cout   << "Enter the number: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showDirectoryMenu();
                break;
            case 2:
                createDirectory();
                break;
            case 3:
                changeDirectoryMenu();
                break;
            case 4:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

