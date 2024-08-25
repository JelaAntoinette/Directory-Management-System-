#include <iostream>
#include <cstdlib>  

using namespace std;


void showDirectoryMenu() {
    int dirChoice;

    cout << endl
         << "---------------\n"
         << "DIRECTORY MANAGEMENT MENU\n"
         << "---------------\n"
         << "1 - List all files\n"
         << "2 - List files based on a specific extension\n"
         << "3 - List files based on a pattern\n"
         << "Enter your choice and press return: ";
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

int main() {
    int choice;

    do {
        cout << endl
             << " ---------------\n"
             << "MAIN MENU\n"
             << "---------------\n"
             << "1 - Manage directories\n"
             << "2 - Create a new directory\n"
             << "3 - Change the working directory\n"
             << "4 - Exit the program\n"
             << "Enter your choice and press return: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                showDirectoryMenu(); 
                break;
            } 
            case 2:
                cout << "Creating new directory.....>\n";
                break;
            case 3:
                cout << "Changing working directory......\n";
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


