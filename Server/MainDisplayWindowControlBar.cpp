/*****************************************************************************
 * FILE NAME    : MainDisplayWindowControlBar.cpp
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
#include "MainDisplayWindowControlBar.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define BUTTON_WIDTH                    60

/*****************************************************************************!
 * Function : MainDisplayWindowControlBar
 *****************************************************************************/
MainDisplayWindowControlBar::MainDisplayWindowControlBar
() : QWidget()
{
  QPalette pal;
  pal = palette();
  backgroundColor = QColor(192, 192, 192);
  pal.setBrush(QPalette::Window, QBrush(backgroundColor));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindowControlBar
 *****************************************************************************/
MainDisplayWindowControlBar::~MainDisplayWindowControlBar
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainDisplayWindowControlBar::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  ActionClearButtonPushed = new QAction("ClearButtonPushed", this);
  connect(ActionClearButtonPushed, SIGNAL(triggered()), this, SLOT(SlotClearButtonPushed()));
  ActionSaveButtonPushed = new QAction("SaveButtonPushed", this);
  connect(ActionSaveButtonPushed, SIGNAL(triggered()), this, SLOT(SlotSaveButtonPushed()));
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindowControlBar::CreateSubWindows()
{
  //! Create the ClearButton button  
  ClearButton = new QPushButton(QIcon(":/Images/Delete.png"), "Clear", this);
  connect(ClearButton, SIGNAL(pressed()), this, SLOT(SlotClearButtonPushed()));

  //! Create the SaveButton button
  SaveButton = new QPushButton(QIcon(":/Images/SaveData.png"), "Save", this);
  connect(SaveButton, SIGNAL(pressed()), this, SLOT(SlotSaveButtonPushed()));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindowControlBar::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindowControlBar::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   height;
  int                                   ClearButtonX;
  int                                   ClearButtonY;
  int                                   ClearButtonW;
  int                                   ClearButtonH;

  int                                   SaveButtonX;
  int                                   SaveButtonY;
  int                                   SaveButtonW;
  int                                   SaveButtonH;
  
  size = InEvent->size();
  height = size.height();

  ClearButtonX = 3;
  ClearButtonY = 2;
  ClearButtonH = height - 4;
  ClearButtonW = BUTTON_WIDTH;

  SaveButtonX = ClearButtonX + ClearButtonW + 5;
  SaveButtonY = 2;
  SaveButtonH = height - 4;
  SaveButtonW = BUTTON_WIDTH;

  ClearButton->move(ClearButtonX, ClearButtonY);
  ClearButton->resize(ClearButtonW, ClearButtonH);

  SaveButton->move(SaveButtonX, SaveButtonY);
  SaveButton->resize(SaveButtonW, SaveButtonH);
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
MainDisplayWindowControlBar::paintEvent
(QPaintEvent* )
{
  QPainter                              painter(this);
  QSize                                 s = size();
  QColor                                c1, c2;
  QPen                                  p1, p2;
  int                                   x1, y1, x2, y2;


  c1 = backgroundColor.lighter(150);
  c2 = backgroundColor.darker(200);

  x1 = 0;
  y1 = 0;
  x2 = s.width();
  y2 = s.height();

  p1 = QPen(c1);
  p2 = QPen(c2);

  painter.setPen(p1);
  painter.drawLine(x1, y1, x2, y1);
  painter.drawLine(x1, y1, x1, y2);
  painter.drawLine(x1 + 1, y1 + 1, x2 - 1, y1 + 1);
  painter.drawLine(x1 + 1, y2 + 1, x1 + 1, y2 - 1);

  painter.setPen(p2);
  painter.drawLine(x2, y1, x2, y2);
  painter.drawLine(x1, y2, x2, y2);
  painter.drawLine(x2-1, y1 + 1, x2 - 1, y2 - 1);
  painter.drawLine(x2 - 2, y2 - 1, x1 + 1 , y2 - 1);
}

/*****************************************************************************!
 * Function : SlotClearButtonPushed
 *****************************************************************************/
void
MainDisplayWindowControlBar::SlotClearButtonPushed(void)
{
  emit SignalClearDisplay();
}

/*****************************************************************************!
 * Function : SlotSaveButtonPushed
 *****************************************************************************/
void
MainDisplayWindowControlBar::SlotSaveButtonPushed(void)
{
  emit SignalSaveData();
}
