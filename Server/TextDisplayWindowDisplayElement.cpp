/*****************************************************************************
 * FILE NAME    : TextDisplayWindowDisplayElement.cpp
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
#include "TextDisplayWindowDisplayElement.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define DATE_TIME_WIDTH                 150
#define TYPE_LABEL_WIDTH                140
#define LINENUMBER_LABEL_WIDTH          40
#define FILENAME_LABEL_WIDTH            300

/*****************************************************************************!
 * Function : TextDisplayWindowDisplayElement
 *****************************************************************************/
TextDisplayWindowDisplayElement::TextDisplayWindowDisplayElement
(QString InString, QDateTime InDateTime, QWidget* InParent) : QWidget(InParent)
{
  QPalette pal;
  pal = palette();
  color = QColor(240, 240, 240);
  pal.setBrush(QPalette::Window, QBrush(color));
  setPalette(pal);
  setAutoFillBackground(true);

  dateTime = InDateTime;
  initialize();
  ParseText(InString);
}

/*****************************************************************************!
 * Function : ~TextDisplayWindowDisplayElement
 *****************************************************************************/
TextDisplayWindowDisplayElement::~TextDisplayWindowDisplayElement
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TextDisplayWindowDisplayElement::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TextDisplayWindowDisplayElement::CreateSubWindows()
{

  //! Create label  
  TextLabel = new QLabel();
  TextLabel->setParent(this);
  TextLabel->move(0, 0);
  TextLabel->resize(0, 0);
  TextLabel->setText(text);
  TextLabel->setAlignment(Qt::AlignLeft);
  TextLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));

  //! Create label
  DateTimeLabel = new QLabel();
  DateTimeLabel->setParent(this);
  DateTimeLabel->move(0, 0);
  DateTimeLabel->resize(0, 0);
  DateTimeLabel->setText(dateTime.toString("MM/dd/yyyy hh:mm:ss.zzz"));
  DateTimeLabel->setAlignment(Qt::AlignRight);
  DateTimeLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));

  TypeLabel = new ElementTypeLabel("", 0, color);
  TypeLabel->setParent(this);
  TypeLabel->move(0, 0);
  TypeLabel->resize(0, 0);
  TypeLabel->setText("");
  TypeLabel->setAlignment(Qt::AlignLeft);
  TypeLabel->setFont(QFont("Courier", 10, QFont::Normal));
  
  FilenameLabel = new QLabel();
  FilenameLabel->setParent(this);
  FilenameLabel->move(0, 0);
  FilenameLabel->resize(0, 0);
  FilenameLabel->setText("");
  FilenameLabel->setAlignment(Qt::AlignRight);
  FilenameLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
  
  LineNumberLabel = new QLabel();
  LineNumberLabel->setParent(this);
  LineNumberLabel->move(0, 0);
  LineNumberLabel->resize(0, 0);
  LineNumberLabel->setText("");
  LineNumberLabel->setAlignment(Qt::AlignLeft);
  LineNumberLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
  
  ValueLabel = new QLabel();
  ValueLabel->setParent(this);
  ValueLabel->move(0, 0);
  ValueLabel->resize(0, 0);
  ValueLabel->setText("");
  ValueLabel->setAlignment(Qt::AlignLeft);
  ValueLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TextDisplayWindowDisplayElement::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TextDisplayWindowDisplayElement::resizeEvent
(QResizeEvent* InEvent)
{
  QSize                                 size;  
  int                                   width;
  int                                   height;

  int                                   DateTimeLabelX;
  int                                   DateTimeLabelY;
  int                                   DateTimeLabelW;
  int                                   DateTimeLabelH;

  int                                   TypeLabelX;
  int                                   TypeLabelY;
  int                                   TypeLabelW;
  int                                   TypeLabelH;

  int                                   LineNumberLabelX;
  int                                   LineNumberLabelY;
  int                                   LineNumberLabelW;
  int                                   LineNumberLabelH;

  int                                   ValueLabelX;
  int                                   ValueLabelY;
  int                                   ValueLabelW;
  int                                   ValueLabelH;

  int                                   FilenameLabelX;
  int                                   FilenameLabelY;
  int                                   FilenameLabelW;
  int                                   FilenameLabelH;

  size = InEvent->size();
  width = size.width();
  height = size.height();

  DateTimeLabelX = 5;
  DateTimeLabelY = 1;
  DateTimeLabelW = DATE_TIME_WIDTH;
  DateTimeLabelH = height  - 2;

  TypeLabelX            = DateTimeLabelW + DateTimeLabelX + 5;
  TypeLabelY            = 0;
  TypeLabelW            = TYPE_LABEL_WIDTH;
  TypeLabelH            = height;;

  FilenameLabelX        = TypeLabelX + TypeLabelW + 5;
  FilenameLabelY        = 1;
  FilenameLabelW        = FILENAME_LABEL_WIDTH;
  FilenameLabelH        = height - 2;
  
  LineNumberLabelX      = FilenameLabelX + FilenameLabelW + 5;
  LineNumberLabelY      = 1;
  LineNumberLabelW      = LINENUMBER_LABEL_WIDTH;
  LineNumberLabelH      = height - 2;

  ValueLabelX           = LineNumberLabelX + LineNumberLabelW + 5;
  ValueLabelY           = 1;
  ValueLabelW           = width - ValueLabelX;
  ValueLabelH           = height - 2;

  
  DateTimeLabel->move(DateTimeLabelX, DateTimeLabelY);
  DateTimeLabel->resize(DateTimeLabelW, DateTimeLabelH);

  TypeLabel->move(TypeLabelX, TypeLabelY);
  TypeLabel->resize(TypeLabelW, TypeLabelH);

  FilenameLabel->move(FilenameLabelX, FilenameLabelY);
  FilenameLabel->resize(FilenameLabelW, FilenameLabelH);

  LineNumberLabel->move(LineNumberLabelX, LineNumberLabelY);
  LineNumberLabel->resize(LineNumberLabelW, LineNumberLabelH);

  ValueLabel->move(ValueLabelX, ValueLabelY);
  ValueLabel->resize(ValueLabelW, ValueLabelH);
}

/*****************************************************************************!
 * Function : ParseText
 *****************************************************************************/
void
TextDisplayWindowDisplayElement::ParseText
(QString InString)
{
  int                                   m;
  int                                   n;
  int                                   start;
  int                                   end;
  QString                               st;
  
  text = InString;

  n = text.length();

  //! Get Indent
  start = 0;
  for ( end = start ; text[end] != QChar(':') ; end++)
  {}

  m = end - start;
  st = text.sliced(start, m);
  indentLength = st.toInt();
  start = ++end;

  //! Get Type
  for ( end = start ; text[end] != QChar(':') ; end++)
  {}

  m = end - start;
  type = text.sliced(start, m);
  start = ++end;

  //!  Get file name
  for ( end = start ; text[end] != QChar(':') ; end++)
  {}

  m = end - start;
  fileName = text.sliced(start, m);
  start = ++end;

  //!  Get line number
  for ( end = start ; end < n && text[end] != QChar(':') ; end++)
  {}

  m = end - start;
  st = text.sliced(start, m);
  lineNumber = st.toInt();

  //! If at end, return
  if ( end < n ) {
    //! Get Value
    start = ++end;
    for ( end = start ; end < n ; end++)
    {}
    
    m = end - start;
    value = text.sliced(start, m);
  }

  TypeLabel->AddText(type, indentLength);
  FilenameLabel->setText(fileName);
  LineNumberLabel->setText(QString("%1").arg(lineNumber));
  ValueLabel->setText(value);
}
