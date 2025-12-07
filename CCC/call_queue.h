#ifndef CALL_QUEUE_H
#define CALL_QUEUE_H

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Call {
    int callerID;
    string status;
};

class CallQueue {
private:
    queue<Call> q;

public:
    void addCall(int id);
    bool hasCall();
    Call getNextCall();
    void showQueue();
};

#endif
