/*****************************************************************************
 * FILE NAME    : TextDisplayWindowScrollArea.cpp
 * DATE         : November 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "TextDisplayWindowScrollArea.h"

/*****************************************************************************!
 * Function : TextDisplayWindowScrollArea
 *****************************************************************************/
TextDisplayWindowScrollArea::TextDisplayWindowScrollArea
() : QScrollArea()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~TextDisplayWindowScrollArea
 *****************************************************************************/
TextDisplayWindowScrollArea::~TextDisplayWindowScrollArea
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TextDisplayWindowScrollArea::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TextDisplayWindowScrollArea::CreateSubWindows()
{
  displayArea = new TextDisplayWindowDisplayArea();  
  setWidget(displayArea);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TextDisplayWindowScrollArea::InitializeSubWindows()
{
  displayArea = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TextDisplayWindowScrollArea::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = displayArea->size().height();
  if ( displayArea ) {
    displayArea->resize(width, height);
    displayArea->move(0, 0);
  }
}

/*****************************************************************************!
 * Function : SlotTextReceived
 *****************************************************************************/
void
TextDisplayWindowScrollArea::SlotTextReceived
(QString InText)
{
  displayArea->SlotAddText(InText);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
TextDisplayWindowScrollArea::CreateConnections(void)
{
  connect(this,         SIGNAL(SignalClearDisplay()),
          displayArea,  SLOT(SlotClearDisplay()));
}

/*****************************************************************************!
 * Function : SlotClearDisplay
 *****************************************************************************/
void
TextDisplayWindowScrollArea::SlotClearDisplay(void)
{
  emit SignalClearDisplay();
}
