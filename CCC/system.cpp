#include "system.h"
#include <cstdlib>

CallManagementSystem::CallManagementSystem() {
    agents.push_back(Agent("Agent A"));
    agents.push_back(Agent("Agent B"));
    agents.push_back(Agent("Agent C"));
}

void CallManagementSystem::generateCall() {
    int id = rand() % 900000 + 100000;
    queue.addCall(id);
    routeCall();
}

void CallManagementSystem::routeCall() {
    for (auto &agent : agents) {
        if (agent.available && queue.hasCall()) {
            Call c = queue.getNextCall();
            agent.assignCall(c);
            history.push_back(c);
        }
    }
}

void CallManagementSystem::showQueue() {
    queue.showQueue();
}

void CallManagementSystem::showAgents() {
    cout << "\n👨‍💼 Agent Status:\n";
    for (auto &agent : agents)
        agent.showStatus();
}

void CallManagementSystem::finishAgentCall() {
    cout << "\nSelect agent to finish call:\n";
    for (int i = 0; i < agents.size(); i++) {
        cout << i + 1 << ". " << agents[i].name << endl;
    }

    int ch;
    cin >> ch;

    if (ch >= 1 && ch <= agents.size()) {
        agents[ch - 1].finishCall();
        routeCall();
    } else {
        cout << "Invalid option.\n";
    }
}

void CallManagementSystem::showHistory() {
    cout << "\n📜 Call History:\n";
    if (history.empty()) {
        cout << "No call handled.\n";
        return;
    }

    for (auto &h : history) {
        cout << "Caller " << h.callerID 
             << " | Status: " << h.status << endl;
    }
}
