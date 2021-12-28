//
// Created by 420 on 2021-10-08.
//

#include "Configurator.h"
#include "cstring"

JNIEXPORT jint JNICALL
do_Bootstrapping(const char *_s)
{
    if(_s == NULL)
    {
        return -1;
    }
    else
        return 0;
}

JNIEXPORT jint JNICALL
do_Authentication()
{
    return 0;
}

char *do_Scanning(const char *_qrInfo)
{
    char *qrInfo = NULL;
    qrInfo = (char *)_qrInfo;
    char *tempArr[10] = {
            NULL,
    };
    int i = 0, asn1len = 0;
    unsigned char keyasn1[1024] = {0};
    char *ptr = strtok(qrInfo, ";");
    char *ptr1 = {NULL};
    while (ptr != NULL)
    {
        tempArr[i] = ptr;
        i++;
        ptr = strtok(NULL, ";");
    }

    for (int i = 0; i < 4; i++)
    {
        if (tempArr[i] != NULL)
            ptr1 = strrchr(tempArr[i], ':');
        tempArr[i] = ptr1 + 1;
    }

    int enSize = strlen(tempArr[3]);


    return tempArr[3];
}



//JNIEXPORT jint JNICALL
//do_Configuration()
//{
//    return 0;
//}
//
//JNIEXPORT jint JNICALL
//do_WPA2()
//{
//    return 0;
//}

