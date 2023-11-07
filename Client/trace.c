/*****************************************************************************
 * FILE NAME    : trace.c
 * DATE         : April 09 2021
 * COPYRIGHT    : Copyright (C) 2021 by Gregory R Saltis
 *****************************************************************************/

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
#include "trace.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
int
TraceIndent = 2;

char*
TraceFileName = NULL;

bool
TraceState = false;

char
TraceOutputBuffer[TRACE_OUTPUT_BUFFER_SIZE +1];

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/

/*****************************************************************************!
 * 
 *****************************************************************************/
void
TraceInitializeFile
(void)
{
  TraceIndent = 2;
}

/*****************************************************************************!
 * Function : TraceInitializeNetwork
 *****************************************************************************/
void
TraceInitializeNetwork
(void)
{

}

/*****************************************************************************!
 * 
 *****************************************************************************/
void
TraceOn
()
{
  TraceState = true;
}

/*****************************************************************************!
 * 
 *****************************************************************************/
void
TraceOff
()
{
  TraceState = false;
}

