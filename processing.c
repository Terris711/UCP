#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"
#include "linkedList.h"
#include "time.h"

void process(securityLog_t* SecurityLog, int index)
{
    int i;
    int loop, l;
    logEntry_t* delLog;

    printf("----------------------------------------\n");
    /*Display the date*/
    printf("Date: %s\n", SecurityLog[index - 1].date);

    loop = SecurityLog[index - 1].LogEntry -> count; 

    for (l = 0; l < loop; l++)

    {
            delLog = (logEntry_t*)removeFirst(SecurityLog[index - 1].LogEntry);

            /*printf("%f\n", delLog -> confidence_value)*/

            if (delLog -> confidence_value >= 60.0)
            {
                /*Display object name and object description*/
                 printf("Name: %s\n", delLog -> detected_obj.name);
                 printf("Description: %s\n", delLog -> detected_obj.description);

                /*Recording information in seconds*/
                 printf("Recording duration: %ds\n", delLog -> endTime - delLog -> startTime);

                 printf("\n");
            }
    }
    
}



