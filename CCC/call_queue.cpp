#include "call_queue.h"

void CallQueue::addCall(int id) {
    Call c;
    c.callerID = id;
    c.status = "Waiting";
    q.push(c);
    cout << "\n📞 New incoming call from: " << id << endl;
}

bool CallQueue::hasCall() {
    return !q.empty();
}

Call CallQueue::getNextCall() {
    Call c = q.front();
    q.pop();
    return c;
}

void CallQueue::showQueue() {
    if (q.empty()) {
        cout << "\nNo calls in waiting queue.\n";
        return;
    }

    cout << "\n📌 Waiting Calls:\n";
    queue<Call> temp = q;

    while (!temp.empty()) {
        Call c = temp.front();
        temp.pop();
        cout << "Caller ID: " << c.callerID << " | Status: " << c.status << endl;
    }
}
