#include <iostream>

using namespace std;

void showFileListMenu() {
    cout << "Showing file list menu...\n";
    
}

int main() {
    int choice;

    do {
        cout << endl
             << " ---------------\n"
             << "MAIN MENU\n"
             << "---------------\n"
             << "1 - List files in the current directory\n"
             << "2 - Create a new directory\n"
             << "3 - Change the working directory\n"
             << "4 - Exit the program\n"
             << "Enter your choice and press return: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                showFileListMenu();
                break;
            } 
            case 2:
                cout << "Creating new directory.....>\n";
                break;
            case 3:
                cout << "Changing working directory......\n";
                break;
            case 4:
                cout << "Press any key to exit\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

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
    cin >> DIRChoice;

    switch (DIRChoice) {
        case 1:
            cout << "Listing all files...\n";
            break;
        case 2:
            cout << "Listing files based on extension...\n";
            break;
        case 3:
            cout << "Listing files based on a pattern...\n";
            break;
        default:
            cout << "Invalid choice in directory management menu.\n";
            break;
    }
}

