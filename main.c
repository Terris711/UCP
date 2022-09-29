#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"
#include "linkedList.h"
#include "processing.h"
#include <time.h>

#define RAND_ELEMENT(index, len) ( (index)[ rand() % (len) ] )

int main(int argc, char* argv[])
{   
    securityLog_t* cameraList;

    void* index[3];
    int randidx[] = {1,2,3};
    int len = 3;
    int a, selected;

    FILE* camera;
    int i, loop;
    
    
   
    /*Deal with the file*/
    if (argc != 2)
    {
        printf("Error: Incorrect number of parameters. \n");
        return 1;
    }

    camera = fopen(argv[1], "r");
    if (camera == NULL)
    {
        perror("Error in reading the file.\n");
        return 1;
    }
    
    fclose(camera);

    /*printf("Number of Security Logs  = %d\n", SlogCount(argv[1]));*/

    
    /*Processing data*/
    cameraList = read(argv[1]);

    /*printf("%s", cameraList[0].date);*/
    
    /*Choose random index of cameraList*/ 
    srand (time(NULL));

    for (a = 0; a < len; a++)
    {
        /*Set fields of ramdomArr = &cameraList*/
        index[a] = (void*)&randidx[a];
    }

    selected = *(int*)RAND_ELEMENT(index, len);

    printf("Choose random index of SecurityLog from the list (0-2): %d\n", selected);

    /*printf("%s", cameraList[selected - 1].date);*/
    
    /*Display selected securityLogs*/
    process(cameraList, selected);


    /*Free memory*/ 
    loop = SlogCount(argv[1]);

    for (i = 0; i < loop; i++)
    {
        freeList(cameraList[i].LogEntry);
    }
   
    free(cameraList);

    return 0;
}

