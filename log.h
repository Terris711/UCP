#ifndef LOG_H
#define LOG_H

#include "linkedList.h"

typedef struct SecurityLog
{
    char date[12];
    LinkedList* LogEntry;
} securityLog_t;



typedef struct Object
{
    int id;
    char name[128];
    char description[256];
} object_t;



typedef struct LogEntry
{
    int startTime;
    int endTime;
    char camera;
    object_t detected_obj;
    float confidence_value;
} logEntry_t;

int SlogCount(char filename[]);
securityLog_t* read(char filename[]);



#endif
