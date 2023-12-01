/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : November 06 2023
 * PROJECT      : TraceServer
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
#include "MainDisplayWindow.h"

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
(int InPort) : QWidget()
{
  QPalette                              pal;

  port = InPort;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);

  Initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainDisplayWindow::Initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  server = new Server(port);

  CreateConnections();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  textWindow = NULL;  
  controlBar = NULL;
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  textWindow = new TextDisplayWindow();  
  textWindow->setParent(this);
  controlBar = new MainDisplayWindowControlBar();
  controlBar->setParent(this);
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;
  int                                   controlBarX;
  int                                   controlBarY;
  int                                   controlBarW;
  int                                   controlBarH;
  int                                   textWindowX;
  int                                   textWindowY;
  int                                   textWindowW;
  int                                   textWindowH;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;

  controlBarX = 0;
  controlBarY = 0;
  controlBarW = width;
  controlBarH = MAIN_DISPLAY_WINDOW_CONTROL_BAR_HEIGHT;

  textWindowX = 0;
  textWindowY = MAIN_DISPLAY_WINDOW_CONTROL_BAR_HEIGHT;
  textWindowW = width;
  textWindowH = height - (MAIN_DISPLAY_WINDOW_CONTROL_BAR_HEIGHT);
  
  if ( controlBar ) {
    controlBar->move(controlBarX, controlBarY);
    controlBar->resize(controlBarW, controlBarH);
  }
  if ( textWindow ) {
    textWindow->move(textWindowX, textWindowY);
    textWindow->resize(textWindowW, textWindowH);
  }
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainDisplayWindow::CreateConnections(void)
{
  connect(server,     SIGNAL(SignalTextReceived(QString)),
          this,       SLOT(SlotTextReceived(QString)));
  connect(this,       SIGNAL(SignalTextReceived(QString)),
          textWindow, SLOT(SlotTextReceived(QString)));
  connect(controlBar, SIGNAL(SignalClearDisplay()),
          this,       SLOT(SlotClearDisplay()));
  connect(this,       SIGNAL(SignalClearDisplay()),
          textWindow, SLOT(SlotClearDisplay()));
  connect(controlBar, SIGNAL(SignalSaveData()),
          this,       SLOT(SlotSaveData()));
  connect(this,       SIGNAL(SignalSaveData()),
          textWindow, SLOT(SlotSaveData()));
}

/*****************************************************************************!
 * Function : SlotTextReceived
 *****************************************************************************/
void
MainDisplayWindow::SlotTextReceived
(QString InString)
{
  if ( InString == "99:CLEAR \n" ) {
    emit SignalClearDisplay();
    return;
  }
  emit SignalTextReceived(InString);
}

/*****************************************************************************!
 * Function : SlotClearDisplay
 *****************************************************************************/
void
MainDisplayWindow::SlotClearDisplay(void)
{
  emit SignalClearDisplay();
}

/*****************************************************************************!
 * Function : SlotSaveData
 *****************************************************************************/
void
MainDisplayWindow::SlotSaveData(void)
{
  emit SignalSaveData();
}
