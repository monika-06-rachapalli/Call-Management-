#ifndef SYSTEM_H
#define SYSTEM_H

#include "agent.h"
#include "call_queue.h"
#include <vector>
using namespace std;

class CallManagementSystem {
private:
    CallQueue queue;
    vector<Agent> agents;
    vector<Call> history;

public:
    CallManagementSystem();
    void generateCall();
    void routeCall();
    void showQueue();
    void showAgents();
    void finishAgentCall();
    void showHistory();
};

#endif
