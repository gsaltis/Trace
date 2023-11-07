/*****************************************************************************
 * FILE NAME    : trace_printf.h
 * DATE         : December 09 2021
 * COPYRIGHT    : Copyright (C) 2021 by Gregory R Saltis
 *****************************************************************************/
#ifndef _trace_printf_h_
#define _trace_printf_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#warning "Including printf version"
#define TRACE_FUNCTION_START()                  \
  {                                             \
    struct timeval tv;                          \
    struct tm* t2;                              \
    int i;                                      \
    for ( i = 0 ; i < TraceIndent-2 ; i += 2 ) {  \
      printf("%c ", '|');                      \
    }                                           \
    printf("/_");                               \
    gettimeofday(&tv, NULL);                    \
    t2 = localtime(&(tv.tv_sec));               \
    printf("Enter : %*s : %04d %02d:%02d:%02d.%06d\n", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, (int)t2->tm_hour, (int)t2->tm_min, (int)t2->tm_sec, (int)tv.tv_usec); \
    fflush(stdout);                             \
    TraceIndent += 2;                           \
  }                                             \

#define TRACE_FUNCTION_POINT()                  \
  {                                             \
    struct timeval tv;                          \
    struct tm* t2;                              \
    gettimeofday(&tv, NULL);                    \
    t2 = localtime(&(tv.tv_sec));               \
    printf("%*sPOINT : %*s : %04d %02d:%02d:%02d.%06d\n", TraceIndent, " ", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, (int)t2->tm_hour, (int)t2->tm_min, (int)t2->tm_sec, (int)tv.tv_usec); \
    fflush(stdout);                             \
  }                                             \

#define TRACE_FUNCTION_END()                    \
  {                                             \
    struct timeval tv;                          \
    struct tm* t2;                              \
    int i;                                      \
    for ( i = 0 ; i < TraceIndent-4 ; i += 2 ) {  \
      printf("| ");                             \
    }                                           \
    printf("\\_");                               \
    gettimeofday(&tv, NULL);                    \
    t2 = localtime(&(tv.tv_sec));               \
    TraceIndent -= 2;                           \
    printf("Exit  : %*s : %04d %02d:%02d:%02d.%06d\n", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, (int)t2->tm_hour, (int)t2->tm_min, (int)t2->tm_sec, (int)tv.tv_usec); \
    fflush(stdout);                             \
  }                                             \

#define TRACE_FUNCTION_END_VALUE_BOOL(b)        \
  {                                             \
    struct timeval tv;                          \
    struct tm* t2;                              \
    gettimeofday(&tv, NULL);                    \
    t2 = localtime(&(tv.tv_sec));               \
    TraceIndent -= 2;                           \
    printf("%*sExit  : %*s : %04d %02d:%02d:%02d.%06d -------- Return Value : %s\n", TraceIndent, " ", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, (int)t2->tm_min, (int)t2->tm_min, (int)t2->tm_sec, (int)tv.tv_usec, b ? "true" : "false"); \
    fflush(stdout);                             \
    return b;                                   \
  }                                             \

#define TRACE_FUNCTION_END_VALUE_INT(i)         \
  {                                             \
    struct timeval tv;                          \
    struct tm* t2;                              \
    gettimeofday(&tv, NULL);                    \
    t2 = localtime(&(tv.tv_sec));               \
    TraceIndent -= 2;                           \
    printf("%*sExit  : %*s : %04d %02d:%02d:%02d.%06d -------- Return Value : %d\n", TraceIndent, " ", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, (int)t2->tm_min, (int)t2->tm_min, (int)t2->tm_sec, (int)tv.tv_usec, i); \
    fflush(stdout);                             \
    return i;                                   \
  }                                             \

#define TRACE_FUNCTION_END_VALUE_HEX(i)         \
  {                                             \
    struct timeval tv;                          \
    struct tm* t2;                              \
    gettimeofday(&tv, NULL);                    \
    t2 = localtime(&(tv.tv_sec));               \
    TraceIndent -= 2;                           \
    printf("%*sExit  : %*s : %04d %02d:%02d:%02d.%06d -------- Return Value : %p\n", TraceIndent, " ", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, (int)t2->tm_min, (int)t2->tm_min, (int)t2->tm_sec, (int)tv.tv_usec, (void*)i); \
    fflush(stdout);                             \
    return i;                                   \
  }                                             \

#define TRACE_FUNCTION_INT(n)                   \
  {                                             \
    int i;                                      \
    for ( i = 0 ; i < TraceIndent-2 ; i += 2 ) {  \
      printf("| ");                             \
    }                                           \
    printf("  ");                               \
    printf("Value : %*s : %04d   %35s : %d\n", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, #n, n); \
  }

#define TRACE_FUNCTION_STRING(n)                   \
  {                                             \
    int i;                                      \
    for ( i = 0 ; i < TraceIndent-2 ; i += 2 ) {  \
      printf("| ");                             \
    }                                           \
    printf("  ");                               \
    printf("Value : %*s : %04d   %35s : \"%s\"\n", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, #n, n); \
  }

#define TRACE_FUNCTION_STRINGN(n, m)            \
  {                                             \
  string s;                                     \
    int i;                                      \
    s = StringNCopy(n, m);                      \
    for ( i = 0 ; i < TraceIndent-2 ; i += 2 ) {  \
      printf("| ");                             \
    }                                           \
    printf("  ");                               \
    printf("Value : %*s : %04d   %35s : \"%s\"\n", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, #n, s); \
    FreeMemory(s);                                                      \
  }

#define TRACE_FUNCTION_CALLS(n)                   \
  printf("%*sCALLS : %*s : %04d   %35s : %s()\n", TraceIndent, " ", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, #n, n);

#define TRACE_FUNCTION_HEX(n)                   \
  printf("%*sValue : %*s : %04d   %35s : %08x\n", TraceIndent, " ", TRACE_FUNCTION_NAME_LENGTH - TraceIndent, __FUNCTION__, __LINE__, #n, n);
#endif

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/

#endif /* _trace_printf_h_*/
