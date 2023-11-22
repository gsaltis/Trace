/*****************************************************************************
 * FILE NAME    : TextDisplayWindow.cpp
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
#include "TextDisplayWindow.h"

/*****************************************************************************!
 * Function : TextDisplayWindow
 *****************************************************************************/
TextDisplayWindow::TextDisplayWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~TextDisplayWindow
 *****************************************************************************/
TextDisplayWindow::~TextDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TextDisplayWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TextDisplayWindow::CreateSubWindows()
{
  scrollArea = new TextDisplayWindowScrollArea();  
  scrollArea->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TextDisplayWindow::InitializeSubWindows()
{
  scrollArea = NULL;  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TextDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
  if ( scrollArea ) {
    scrollArea->move(0, 0);
    scrollArea->resize(width, height);
  }
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
TextDisplayWindow::CreateConnections(void)
{
  connect(this,
          SIGNAL(SignalTextReceived(QString)),
          scrollArea,
          SLOT(SlotTextReceived(QString)));
  connect(this,         SIGNAL(SignalClearDisplay()),
          scrollArea,   SLOT(SlotClearDisplay()));
  connect(this,         SIGNAL(SignalSaveData()),
          scrollArea,   SLOT(SlotSaveData()));
}

/*****************************************************************************!
 * Function : SlotTextReceived
 *****************************************************************************/
void
TextDisplayWindow::SlotTextReceived
(QString InString)
{
  emit SignalTextReceived(InString);
}

/*****************************************************************************!
 * Function : SlotClearDisplay
 *****************************************************************************/
void
TextDisplayWindow::SlotClearDisplay(void)
{
  emit SignalClearDisplay();
}

/*****************************************************************************!
 * Function : SlotSaveData
 *****************************************************************************/
void
TextDisplayWindow::SlotSaveData(void)
{
  emit SignalSaveData();
}
