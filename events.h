#pragma once
#include <vector>
#include <functional>
#include <map> 
#include <queue>
#include <functional>
#include "tbt_thread.h"
#include "eventData.h"

using namespace std;
// class EventData;



#define ADD_LISTENER(eventType, callback) eventSystem.addListener(eventType, TO_CALLBACK(callback))


#define TO_CALLBACK(fn) [this](EventData *event){ return this->fn(event); }


class Events :public BaseThread {
   
typedef  function<bool(EventData*)> FN_CALLBACK;
typedef  vector<FN_CALLBACK> LIST_CALLBACK;
private:
    queue<EventData*> eventQueue;
    std::map<EventType,LIST_CALLBACK*> callbacks;
    bool processCallback();


public:
    Events();
    void execute() override;
    void addListener(EventType evt, FN_CALLBACK callback);
    // void dispatchMessage(EventType evt,EventData* data);
    void dispatchMessage(EventData *data);
  
    
    bool available();
};
extern Events eventSystem;