#include <iostream>
#include <limits>
using namespace std;

// Simulates permission checking logic from _Z25CheckUserPermissionAccessv
int CheckUserPermissionAccess() {
    // SECURITY VULNERABILITY:
    // Always returns access granted (2), with no actual logic or verification.
    // FIX RECOMMENDATION: Replace with credential check or user prompt logic.
    return 2;  // 1 = restricted, 2 = granted
}

// Displays user information similar to _Z11DisplayInfov
void DisplayInfo() {
    // SECURITY VULNERABILITY:
    // Displays sensitive client information without checking user permissions.
    // FIX RECOMMENDATION: Add permission check before displaying sensitive data.
    if (CheckUserPermissionAccess() == 2) {
        cout << "Displaying user/client information..." << endl;
        cout << "Account Name: John Doe" << endl;
        cout << "Balance: $5,000.00" << endl;
        cout << "Status: Active" << endl;
    } else {
        cout << "Access denied: insufficient permissions to view this data." << endl;
    }
}

// Handles user choice logic, mirrors _Z20ChangeCustomerChoicev
void ChangeCustomerChoice(int choice, int permissionLevel) {
    // SECURITY VULNERABILITY:
    // No permission check before processing potentially sensitive options.
    // FIX RECOMMENDATION: Add permission validation.
    if (permissionLevel != 2) {
        cout << "Access denied: insufficient permissions to modify data." << endl;
        return;
    }

    switch (choice) {
        case 1:
            cout << "Option 1 selected." << endl;
            break;
        case 2:
            cout << "Option 2 selected." << endl;
            break;
        case 3:
            cout << "Option 3 selected. Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
    }
}

int main() {
    cout << "Created by Buxton McCaslin - SNHU CS 410 Project One" << endl;

    int choice = 0;

    // Call permission check and capture access level
    int permissionLevel = CheckUserPermissionAccess();

    // SECURITY VULNERABILITY FIX:
    // Validate user input to avoid invalid or malicious inputs
    do {
        cout << "\nEnter a choice (1-3): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            continue;
        }

        ChangeCustomerChoice(choice, permissionLevel);

    } while (choice != 3);  // Exit on choice 3

    return 0;
}
