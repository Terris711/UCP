#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"
#include "linkedList.h"

int SlogCount(char filename[])
{
    FILE* fileobj;
    int count;
    char singleline[150];

    count = 1;

    fileobj = fopen(filename, "r");

    while(fgets(singleline, 150, fileobj) != NULL)
    {
        if(*singleline == '\n')
        {
            count ++;
        }
    }

    fclose(fileobj);
    return count;
}


securityLog_t* read(char filename[])
{
    securityLog_t* SecurityLogs;
    securityLog_t* SecArray[3];
    
    logEntry_t* newLog;
    logEntry_t* LogEntry;
    logEntry_t* delLog;

    object_t* detected_obj;
    
    FILE* fileobj;
    char singleline[150];
    int loop, i;
        
    SecurityLogs = calloc(1, sizeof(securityLog_t));  
    LogEntry = calloc(1, sizeof(logEntry_t));
    detected_obj = calloc(1, sizeof(logEntry_t));          
        
    fileobj = fopen((char*)filename,"r");
    
    if(fileobj == NULL)
    {
        return NULL;
    }
    else
    {
        loop = SlogCount(filename);


        /*Read each of SecurityLogs in the file*/
        for(i = 0; i < loop; i++)
        {
            SecurityLogs[i].LogEntry = createLinkedList();
            
            fgets(singleline, 150, fileobj);
            sscanf(singleline, "%12s", SecurityLogs[i].date);
            /*printf("Date: %12s\n", SecurityLogs[i].date);*/

            while(fgets(singleline, 150, fileobj) != NULL && *singleline != '\n')
            {
                newLog = calloc(1, sizeof(securityLog_t));

                sscanf(singleline, "%d$%d", &newLog -> startTime, &newLog -> endTime);
                /*printf("Start time: %d, End time: %d\n", newLog -> startTime, newLog -> endTime);*/
                
                fgets(singleline, 150, fileobj);
                sscanf(singleline, "%c", &newLog -> camera);
                /*printf("Camera: %c\n", newLog -> camera);*/
                
                fgets(singleline, 150, fileobj);
                sscanf(singleline, "%f", &newLog -> confidence_value);
                /*printf("Confidence val: %f\n", newLog -> confidence_value);*/

                fgets(singleline, 150, fileobj);
                sscanf(singleline, "%d$%127[^$]$%255[^\n]", &newLog -> detected_obj.id, 
                                                        newLog -> detected_obj.name, 
                                                        newLog -> detected_obj.description);
                /*printf("Id: %d\nName: %s\nDescription: %s\n", newLog -> detected_obj.id, 
                                                              newLog -> detected_obj.name,
                                                              newLog -> detected_obj.description);
                printf("\n");*/

                insertLast(SecurityLogs[i].LogEntry, newLog);
                
                
                /*delLog = (logEntry_t*)removeFirst(SecurityLogs[i].LogEntry);*/
                /*printf("Description: %s\n", delLog -> detected_obj.description);*/


            }
            
        }
        
    }


    fclose(fileobj);

    return SecurityLogs;

}



