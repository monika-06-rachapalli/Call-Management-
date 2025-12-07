#include "agent.h"

Agent::Agent(string n) {
    name = n;
    available = true;
}

void Agent::assignCall(Call c) {
    available = false;
    currentCall = c;
    currentCall.status = "In Call";
    cout << "\nAgent " << name 
         << " is now handling call from " << currentCall.callerID << endl;
}

void Agent::finishCall() {
    if (available) {
        cout << name << " has no active call.\n";
        return;
    }

    cout << "\nAgent " << name 
         << " completed call from " << currentCall.callerID << endl;

    available = true;
}

void Agent::showStatus() {
    cout << name << ": ";
    if (available)
        cout << "Available\n";
    else
        cout << "Busy with " << currentCall.callerID << endl;
}
