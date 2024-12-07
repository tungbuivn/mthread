#pragma once

#include <string>

enum EventType {
    NONE,
    
    TEMPERATURE_UPDATED,
    BUTTON_PRESSED,
    TEMPERATURE_BUTTON
   
   
};

class EventData {

public:
    EventType type;
    union
    {
        int pwm;
        int temperature;
      
        int gear;
        int page;
      
        long long data=0;
        double doubleValue;
        
    };
    EventData(EventType atype,long long adata) { type=atype;data=adata;}
    EventData(EventType atype,double adata) { type=atype;doubleValue=adata;}
    // EventData(EventData *aobj) {type=aobj->type;data=aobj->data;}
    virtual ~EventData();
    
};

