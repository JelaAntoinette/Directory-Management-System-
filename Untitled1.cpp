#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void showDirectoryMenu() {
    int dirChoice;

    cout << endl
         << "---------------------\n"
         << "   LIST FILE DETAIL   \n"
         << "---------------------\n"
         << "1.List all Files\n"
         << "2.List of Extension files\n"
         << "3.List of Name files\n"
         << "Enter the number: ";
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

    cout << endl
         << "----------------------\n"
         << "   CHANGE DIRECTORY MENU   \n"
         << "----------------------\n"
         << "1.Move one step back (to the parent directory)\n"
         << "2.Move to the root directory\n"
         << "3.Move to a specific directory\n"
         << "Enter the number: ";
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
        cout << endl
             << " ----------------\n"
             << "    MAIN MENU    \n"
             << "------------------\n"
             << "1.To display list of files\n"
             << "2.To create a new directory\n"
             << "3.To change the Working directory\n"
             << "4.Exit\n"
             << "Enter the number: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                showDirectoryMenu();
                break;
            }
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

