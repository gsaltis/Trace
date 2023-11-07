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
  width = size.width();

  n = elements.size();
  for ( i = 0 ; i < n ; i++ ) {
    element = elements[i];
    element->resize(width, element->size().height());
  }

}

/*****************************************************************************!
 * Function : SlotAddText
 *****************************************************************************/
void
TextDisplayWindowDisplayArea::SlotAddText
(QString InString)
{
  TextDisplayWindowDisplayElement*      element;
  element = new TextDisplayWindowDisplayElement(InString, QDateTime::currentDateTime(), this);
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
  int                                   width;
  int                                   y;
  
  if ( NULL == InElement ) {
    return;
  }
  width = size().width();
  
  y = GetNextY();
  InElement->move(0, y);
  InElement->resize(width, TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_HEIGHT);

  elements << InElement;

  height = y + TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_HEIGHT;
  resize(width, height);
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
