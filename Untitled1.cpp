#include <iostream>

using namespace std;
void showFileListMenu();

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
            case 2:
        		cout << "Creating new directory.....>\n";
        		break;
        	case 3:
        		cout << "Changing working directory......\n";
        		break;
        	case 4:
        		cout << "Press any key to ext\n";
        		break;
        	default:
        		cout << "Invalid choice. Please try again";
        		break;

            
        }
    } while (choice != 4);

    return 0;
	}
