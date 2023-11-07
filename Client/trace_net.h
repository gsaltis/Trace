/*****************************************************************************
 * FILE NAME    : trace_net.h
 * DATE         : December 09 2021
 * COPYRIGHT    : Copyright (C) 2021 by Gregory R Saltis
 *****************************************************************************/
#ifndef _trace_net_h_
#define _trace_net_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define TRACE_NET_ADDRESS                               "192.168.100.3"
#define TRACE_NET_PORT                                  8080

#define TRACE_OUTPUT_BUFFER_SIZE                2048
#define TRACE_FUNCTION_NAME_LENGTH              60

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/
extern int
TraceIndent;

extern char
TraceOutputBuffer[TRACE_OUTPUT_BUFFER_SIZE +1];

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#warning "Including NET version"
#define TRACE_FUNCTION_START()                                                                      \
  do                                                                                                \
  {                                                                                                 \
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);                                                    \
    struct sockaddr_in                  servaddr;                                                   \
    struct timeval                      tv;                                                         \
    struct tm*                          t2;                                                         \
    int                                 i;                                                          \
    char*                               s;                                                          \
    if ( sockfd < 0 ) {                                                                             \
      break;                                                                                        \
    }                                                                                               \
    memset(&servaddr, 0, sizeof(servaddr));                                                         \
    servaddr.sin_family = AF_INET;                                                                  \
    servaddr.sin_port = htons(TRACE_NET_PORT);                                                      \
    servaddr.sin_addr.s_addr = inet_addr(TRACE_NET_ADDRESS);                                        \
    sprintf(TraceOutputBuffer, "%02d:ENTER:%s:%04d \n", TraceIndent, __FUNCTION__, __LINE__);       \
    sendto(sockfd, (const char *)TraceOutputBuffer, strlen(TraceOutputBuffer),                      \
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,                                        \
           sizeof(servaddr));                                                                       \
    TraceIndent++;                                                                                  \
    close(sockfd);                                                                                  \
    } while (false);

#define TRACE_FUNCTION_END()                                                                        \
  do                                                                                                \
  {                                                                                                 \
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);                                                    \
    struct sockaddr_in                  servaddr;                                                   \
    struct timeval                      tv;                                                         \
    struct tm*                          t2;                                                         \
    int                                 i;                                                          \
    char*                               s;                                                          \
    if ( sockfd < 0 ) {                                                                             \
      break;                                                                                        \
    }                                                                                               \
    TraceIndent--;                                                                                  \
    memset(&servaddr, 0, sizeof(servaddr));                                                         \
    servaddr.sin_family = AF_INET;                                                                  \
    servaddr.sin_port = htons(TRACE_NET_PORT);                                                      \
    servaddr.sin_addr.s_addr = inet_addr(TRACE_NET_ADDRESS);                                        \
    sprintf(TraceOutputBuffer, "%02d:EXIT:%s:%04d \n", TraceIndent, __FUNCTION__, __LINE__);        \
    sendto(sockfd, (const char *)TraceOutputBuffer, strlen(TraceOutputBuffer),                      \
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,                                        \
           sizeof(servaddr));                                                                       \
    close(sockfd);                                                                                  \
  } while (false);

#define TRACE_FUNCTION_LOCATION()                                                                   \
  do                                                                                                \
  {                                                                                                 \
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);                                                    \
    struct sockaddr_in                  servaddr;                                                   \
    struct timeval                      tv;                                                         \
    struct tm*                          t2;                                                         \
    int                                 i;                                                          \
    char*                               s;                                                          \
    if ( sockfd < 0 ) {                                                                             \
      break;                                                                                        \
    }                                                                                               \
    memset(&servaddr, 0, sizeof(servaddr));                                                         \
    servaddr.sin_family = AF_INET;                                                                  \
    servaddr.sin_port = htons(TRACE_NET_PORT);                                                      \
    servaddr.sin_addr.s_addr = inet_addr(TRACE_NET_ADDRESS);                                        \
    sprintf(TraceOutputBuffer, "%02d:LOCATION:%s:%04d \n", TraceIndent, __FUNCTION__, __LINE__);    \
    sendto(sockfd, (const char *)TraceOutputBuffer, strlen(TraceOutputBuffer),                      \
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,                                        \
           sizeof(servaddr));                                                                       \
    close(sockfd);                                                                                  \
  } while (false);

#define TRACE_FUNCTION_BOOL(n)                                                                      \
  do                                                                                                \
  {                                                                                                 \
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);                                                    \
    struct sockaddr_in                  servaddr;                                                   \
    struct timeval                      tv;                                                         \
    struct tm*                          t2;                                                         \
    int                                 i;                                                          \
    char*                               s;                                                          \
    if ( sockfd < 0 ) {                                                                             \
      break;                                                                                        \
    }                                                                                               \
    memset(&servaddr, 0, sizeof(servaddr));                                                         \
    servaddr.sin_family = AF_INET;                                                                  \
    servaddr.sin_port = htons(TRACE_NET_PORT);                                                      \
    servaddr.sin_addr.s_addr = inet_addr(TRACE_NET_ADDRESS);                                        \
    sprintf(TraceOutputBuffer, "%02d:BOOL:%s:%04d:%s = %s \n",                                      \
            TraceIndent, __FUNCTION__, __LINE__, #n, n ? "TRUE" : "FALSE");                         \
    sendto(sockfd, (const char *)TraceOutputBuffer, strlen(TraceOutputBuffer),                      \
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,                                        \
           sizeof(servaddr));                                                                       \
    close(sockfd);                                                                                  \
  } while (false);

#define TRACE_FUNCTION_INT(n)                                                                       \
  do                                                                                                \
  {                                                                                                 \
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);                                                    \
    struct sockaddr_in                  servaddr;                                                   \
    struct timeval                      tv;                                                         \
    struct tm*                          t2;                                                         \
    int                                 i;                                                          \
    char*                               s;                                                          \
    if ( sockfd < 0 ) {                                                                             \
      break;                                                                                        \
    }                                                                                               \
    memset(&servaddr, 0, sizeof(servaddr));                                                         \
    servaddr.sin_family = AF_INET;                                                                  \
    servaddr.sin_port = htons(TRACE_NET_PORT);                                                      \
    servaddr.sin_addr.s_addr = inet_addr(TRACE_NET_ADDRESS);                                        \
    sprintf(TraceOutputBuffer, "%02d:INT:%s:%04d:%s = %d \n",                                       \
            TraceIndent, __FUNCTION__, __LINE__, #n, n);                                            \
    sendto(sockfd, (const char *)TraceOutputBuffer, strlen(TraceOutputBuffer),                      \
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,                                        \
           sizeof(servaddr));                                                                       \
    close(sockfd);                                                                                  \
  } while (false);


#define TRACE_FUNCTION_STRING(n)                                                                    \
  do                                                                                                \
  {                                                                                                 \
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);                                                    \
    struct sockaddr_in                  servaddr;                                                   \
    struct timeval                      tv;                                                         \
    struct tm*                          t2;                                                         \
    int                                 i;                                                          \
    char*                               s;                                                          \
    if ( sockfd < 0 ) {                                                                             \
      break;                                                                                        \
    }                                                                                               \
    memset(&servaddr, 0, sizeof(servaddr));                                                         \
    servaddr.sin_family = AF_INET;                                                                  \
    servaddr.sin_port = htons(TRACE_NET_PORT);                                                      \
    servaddr.sin_addr.s_addr = inet_addr(TRACE_NET_ADDRESS);                                        \
    sprintf(TraceOutputBuffer, "%02d:INT:%s:%04d:%s = \"%s\" \n",                                   \
            TraceIndent, __FUNCTION__, __LINE__, #n, n);                                            \
    sendto(sockfd, (const char *)TraceOutputBuffer, strlen(TraceOutputBuffer),                      \
           MSG_CONFIRM, (const struct sockaddr *) &servaddr,                                        \
           sizeof(servaddr));                                                                       \
    close(sockfd);                                                                                  \
  } while (false);

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/

#endif /* _trace_net_h_*/
