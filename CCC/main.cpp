#include <iostream> 
#include "system.h"
using namespace std;

int main() {
    CallManagementSystem cms;
    int choice;

    while (true) {
        cout << "\n===== CALL MANAGEMENT SYSTEM =====";
        cout << "\n1. Generate Incoming Call";
        cout << "\n2. Show Call Queue";
        cout << "\n3. Show Agent Status";
        cout << "\n4. Finish Agent Call";
        cout << "\n5. Show Call History";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
       

if (!cin) {                    // extraction failed
    cin.clear();               // clear error flags
    cin.ignore(10000, '\n');   // discard bad input
    cout << "Invalid input. Please enter a number between 1 and 6.\n";
    continue;                  // go to next loop iteration
}


        switch (choice) {
            case 1: cms.generateCall(); break;
            case 2: cms.showQueue(); break;
            case 3: cms.showAgents(); break;
            case 4: cms.finishAgentCall(); break;
            case 5: cms.showHistory(); break;
            case 6: return 0;
            default: cout << "Invalid choice.";    
        }
    }
}
