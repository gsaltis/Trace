/*****************************************************************************
 * FILE NAME    : ElementTypeLabel.cpp
 * DATE         : November 07 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
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
#include "ElementTypeLabel.h"

QString LevelColorNames[] = {
  QString("#b71c1c"),
  QString("#CC0000"),
  QString("#004400"),
  QString("#0000AA"),
  QString("#880088"),
  QString("#008888"),
  QString("#884400"),
  QString("#884422"),
  QString("#8000C0"),
  QString("#008800"),
  QString("#008888"),
  QString("#FF1c1c"),
  QString("#b71c1c"),
  QString("#4A148C"),
  QString("#1A237E"),
  QString("#01579B"),
  QString("#006064"),
  QString("#1B5E20"),
  QString("#33691E"),
  QString("#F57F17"),
  QString("#E65100"),
  QString("#3E2723"),
  QString("#880E4F"),
  QString("#311B92"),
  QString("#0D47A1"),
  QString("#004D40"),
  QString("#FF6F00"),
  QString("#BF360C"),
  QString("#CCFF00"),
  QString("#CC9900"),
  QString("#CC3300"),
  QString("#03A9F4"),
  QString("#FF5722"),
  QString("#000000")
};
  
/*****************************************************************************!
 * Function : ElementTypeLabel
 *****************************************************************************/
ElementTypeLabel::ElementTypeLabel
(QString InText, int InIndent, QColor InColor) : QLabel()
{
  int                                   k;
  int                                   j;
  
  text = InText;
  indent = InIndent;
  color = InColor;

  k = indent;
  j = sizeof(LevelColorNames) / sizeof(LevelColorNames[0]);
  if ( k >= j ) {
    k = j - 1;
  }
  textColor = QColor(LevelColorNames[k]);
  
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(color));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ElementTypeLabel
 *****************************************************************************/
ElementTypeLabel::~ElementTypeLabel
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ElementTypeLabel::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ElementTypeLabel::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ElementTypeLabel::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ElementTypeLabel::resizeEvent
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
}

/*****************************************************************************!
 * Function : AddText
 *****************************************************************************/
void
ElementTypeLabel::AddText
(QString InText, int InIndent)
{
  QString                               st;
  QString                               st2;
  
  text = InText;
  indent = InIndent;

  st.fill(QChar(0x258F), indent);
  st2 = st + text;
  setText(st2);
}

/*****************************************************************************!
 * Function : paintEvent
 *****************************************************************************/
void
ElementTypeLabel::paintEvent
(QPaintEvent*)
{
  QPainter                              painter(this);
  QFont                                 f = font();
  QPen                                  pen;
  QBrush                                brush;
  int                                   x1, x2, y1, y2;
  int                                   i;
  QFontMetrics                          fm(f);
  int                                   m;
  int                                   textHeight;
  int                                   elementHeight;
  QString                               s;
  
  elementHeight = size().height();

  //!
  pen.setWidth(4);

  //!
  x1 = 5;
  x2 = 5;
  y1 = 0;
  y2 = elementHeight;

  textHeight = fm.size(0, text).height();

  //!
  for ( i = 1 ; i <= indent-1 ; i++ ) {
    pen.setColor(QColor(LevelColorNames[i]));
    brush.setColor(QColor(LevelColorNames[i]));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawLine(x1, 0, x2, elementHeight);
    x1 += 15;
    x2 += 15;
  }

  //!
  textColor = LevelColorNames[indent];
  pen.setColor(textColor);
  painter.setPen(pen);
  brush.setColor(textColor);
  painter.setBrush(brush);

  //!
  if ( text == "ENTER" ) {
    y1 = elementHeight / 2;
    painter.drawLine(x1, y1, x1 + 8, y1);
  } else if ( text == "EXIT" ) {
    y2 = elementHeight / 2;
    painter.drawLine(x1, y2, x1 + 8, y2);
  }
  painter.drawLine(x1, y1, x2, y2);
  x1 += 15;
  m = (elementHeight - textHeight) / 2;

  f.setWeight(QFont::Bold);
  painter.setFont(f);
  s = QString("%1").arg(text);
              
  painter.drawText(QPoint(x1, elementHeight - (m + textHeight / 4)), s);
}

/*****************************************************************************!
 * Function : GetTextColor
 *****************************************************************************/
QColor
ElementTypeLabel::GetTextColor
()
{
  return textColor;
}
