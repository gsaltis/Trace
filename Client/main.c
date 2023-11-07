/*****************************************************************************
 * FILE NAME    : main.c
 * DATE         : November 06 2023
 * PROJECT      : Bay Simulator
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
WSADATA
MainWinsockData;

int
SERVER_PORT = 8080;

const char*
SERVER_ADDRESS = "192.168.100.3";

const char*
MainMessage = "2:ENTER:main.c:40:n = 3";

int
MainMessageLen;

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main(int argc, char**argv)
{
  int                                   serverAddrLen;
  SOCKET                                sock;
  int                                   r;
  sockaddr_in                           serverAddr;
  int                                   bytesSent;
  
  MainMessageLen = strlen(MainMessage);
  r = WSAStartup(MAKEWORD(2, 2), &MainWinsockData);

  if ( NO_ERROR != r ) {
    printf("WSAStartup error : %d\n", r);
    return EXIT_FAILURE;
  }

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if ( INVALID_SOCKET == sock ) {
    printf("Could not create socket\n");
    return EXIT_FAILURE;
  }


  serverAddrLen = sizeof(serverAddr);
  
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
  serverAddr.sin_port = htons(SERVER_PORT);

  bytesSent = sendto(sock,
                     MainMessage,
                     MainMessageLen,
                     0,
                     (struct sockaddr*)&serverAddr,
                     serverAddrLen);
  printf("%d\n", bytesSent);
  WSACleanup();
  return EXIT_SUCCESS;
}
