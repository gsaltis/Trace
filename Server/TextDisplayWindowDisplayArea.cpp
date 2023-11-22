/*****************************************************************************
 * FILE NAME    : TextDisplayWindowDisplayArea.cpp
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
#include <QMessageBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "TextDisplayWindowDisplayArea.h"
#include "TextDisplayWindowDisplayElement.h"

/*****************************************************************************!
 * Function : TextDisplayWindowDisplayArea
 *****************************************************************************/
TextDisplayWindowDisplayArea::TextDisplayWindowDisplayArea
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(240, 240, 240)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
  windowWidth = 8000;
}

/*****************************************************************************!
 * Function : ~TextDisplayWindowDisplayArea
 *****************************************************************************/
TextDisplayWindowDisplayArea::~TextDisplayWindowDisplayArea
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::InitializeSubWindows()
{
  
}

#if 0
/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   i;
  int                                   n;
  QSize                                 size;  
  int                                   width;
  TextDisplayWindowDisplayElement*      element;
  
  size = InEvent->size();
  width = windowWidth;

  n = elements.size();
  for ( i = 0 ; i < n ; i++ ) {
    element = elements[i];
    element->resize(width, element->size().height());
  }
}

#endif
/*****************************************************************************!
 * Function : SlotAddText
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::SlotAddText
(QString InString)
{
  int                                   n;
  QColor                                color;
  
  TextDisplayWindowDisplayElement*      element;
  n = elements.size();
  color = QColor(255, 255, 255);
  if ( n % 2 == 0 ) {
    color = QColor(224, 224, 224);
  }
  element = new TextDisplayWindowDisplayElement(InString, QDateTime::currentDateTime(), color, this);
  element->show();
  AddElement(element);
}

/*****************************************************************************!
 * Function : AddElement
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::AddElement
(TextDisplayWindowDisplayElement* InElement)
{
  int                                   height;
  int                                   y;
  
  if ( NULL == InElement ) {
    return;
  }
  y = GetNextY();
  InElement->move(0, y);
  InElement->resize(windowWidth, TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_HEIGHT);

  elements << InElement;

  height = y + TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_HEIGHT;
  resize(windowWidth, height);
}

/*****************************************************************************!
 * Function : GetNextY
 *****************************************************************************/
int
TextDisplayWindowDisplayArea::GetNextY(void)
{
  int                                   returnY;
  int                                   y;
  QPoint                                p;
  int                                   i;
  int                                   n;

  n = elements.size();
  returnY = 0;
  
  for ( i = 0 ; i < n ; i++ ) {
    auto element = elements[i];

    p = element->pos();
    y = p.y() + element->size().height();
    if ( y > returnY ) {
      returnY = y;
    }
  }
  return returnY;
}


/*****************************************************************************!
 * Function : SlotClearDisplay
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::SlotClearDisplay(void)
{
  while ( QWidget* w = findChild<QWidget*>() )
    delete w;
  
  elements.clear();
}

/*****************************************************************************!
 * Function : SlotSaveData
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::SlotSaveData(void)
{
  bool                                  haveItem;
  QString                               filename = "Trace.json";
  QFile                                 file(filename);
  QString                               st = "[\n";

  if ( !file.open(QIODevice::ReadWrite | QIODevice::Truncate) ) {
    QMessageBox mb = QMessageBox(QMessageBox::Warning, "Could not open file", QString("Could not open \"%1\"").arg(filename));
    mb.exec();
    return;
  }

  file.write(st.toLatin1());
  haveItem = false;
  for ( auto element : elements ) {
    if ( haveItem ) {
      st = ",\n";
      file.write(st.toLatin1());
    }
    element->Save(&file);
    haveItem = true;
  }

  st = "\n]\n";
  file.write(st.toLatin1());
  file.close();
  QMessageBox mb = QMessageBox(QMessageBox::Information, QString("File Saved"), QString("\"%1\" saved\n").arg(filename));
  mb.exec();
}
