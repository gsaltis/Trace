/*****************************************************************************
 * FILE NAME    : trace_winnetqt.h
 * DATE         : November 29 2023
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _trace_winnetqt_h_
#define _trace_winnetqt_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "trace_winnet.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
//!
#define TRACE_FUNCTION_QSTRING(n)                                                                   \
  {                                                                                                 \
    TRACE_FUNCTION_INIT()                                                                           \
    sprintf(TraceOutputBuffer, "%02d:QSTRING:%s:%s:%04d:%s = \"%s\" \n",                            \
            TraceIndent, __FILE__, __FUNCTION__, __LINE__, #n, n.toStdString().c_str());            \
    TRACE_FUNCTION_SEND()                                                                           \
    TRACE_FUNCTION_FINISH()                                                                         \
  }                                                                                                 \

#define TRACE_FUNCTION_QPOINT(n)                                                                    \
  {                                                                                                 \
    TRACE_FUNCTION_INIT()                                                                           \
    sprintf(TraceOutputBuffer, "%02d:QPOINT:%s:%s:%04d:%s.x = %d  %s.y = %d \n",                    \
            TraceIndent, __FILE__, __FUNCTION__, __LINE__, #n, n.x(), #n, n.y());                   \
    TRACE_FUNCTION_SEND()                                                                           \
    TRACE_FUNCTION_FINISH()                                                                         \
  }                                                                                                 \

#define TRACE_FUNCTION_QSIZE(n)                                                                     \
  {                                                                                                 \
    TRACE_FUNCTION_INIT()                                                                           \
    sprintf(TraceOutputBuffer, "%02d:QSIZE:%s:%s:%04d:%s.width = %d  %s.height = %d \n",            \
            TraceIndent, __FILE__, __FUNCTION__, __LINE__, #n, n.width(), #n, n.height());          \
    TRACE_FUNCTION_SEND()                                                                           \
    TRACE_FUNCTION_FINISH()                                                                         \
  }                                                                                                 \

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/

#endif /* _trace_winnetqt_h_*/
