#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include "call_queue.h"
using namespace std;

class Agent {
public:
    string name;
    bool available;
    Call currentCall;

    Agent(string n);
    void assignCall(Call c);
    void finishCall();
    void showStatus();
};

#endif
