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
#define FUNCTIONNAME_LABEL_WIDTH        300

/*****************************************************************************!
 * Function : TextDisplayWindowDisplayElement
 *****************************************************************************/
TextDisplayWindowDisplayElement::TextDisplayWindowDisplayElement
(QString InString, QDateTime InDateTime, QColor InColor, QWidget* InParent) : QWidget(InParent)
{
  QPalette pal;
  pal = palette();
  color = InColor;
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
  
  FileNameLabel = new QLabel();
  FileNameLabel->setParent(this);
  FileNameLabel->move(0, 0);
  FileNameLabel->resize(0, 0);
  FileNameLabel->setText("");
  FileNameLabel->setAlignment(Qt::AlignRight);
  FileNameLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
  
  FunctionNameLabel = new QLabel();
  FunctionNameLabel->setParent(this);
  FunctionNameLabel->move(0, 0);
  FunctionNameLabel->resize(0, 0);
  FunctionNameLabel->setText("");
  FunctionNameLabel->setAlignment(Qt::AlignRight);
  FunctionNameLabel->setFont(QFont("Segoe UI", 10, QFont::Normal));
  
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

  int                                   FileNameLabelX;
  int                                   FileNameLabelY;
  int                                   FileNameLabelW;
  int                                   FileNameLabelH;

  int                                   FunctionNameLabelX;
  int                                   FunctionNameLabelY;
  int                                   FunctionNameLabelW;
  int                                   FunctionNameLabelH;

  //!
  size = InEvent->size();
  width = size.width();
  height = size.height();

  DateTimeLabelX = 5;
  DateTimeLabelY = 1;
  DateTimeLabelW = DATE_TIME_WIDTH;
  DateTimeLabelH = height  - 2;

  //!
  TypeLabelX            = DateTimeLabelW + DateTimeLabelX + 5;
  TypeLabelY            = 0;
  TypeLabelW            = TYPE_LABEL_WIDTH;
  TypeLabelH            = height;;

  FileNameLabelX        = TypeLabelX + TypeLabelW + 5;
  FileNameLabelY        = 1;
  FileNameLabelW        = FILENAME_LABEL_WIDTH;
  FileNameLabelH        = height - 2;

  FunctionNameLabelX    = FileNameLabelX + FileNameLabelW + 5;
  FunctionNameLabelY    = 1;
  FunctionNameLabelW    = FUNCTIONNAME_LABEL_WIDTH;
  FunctionNameLabelH    = height - 2;
  
  LineNumberLabelX      = FunctionNameLabelX + FunctionNameLabelW + 5;
  LineNumberLabelY      = 1;
  LineNumberLabelW      = LINENUMBER_LABEL_WIDTH;
  LineNumberLabelH      = height - 2;

  ValueLabelX           = LineNumberLabelX + LineNumberLabelW + 5;
  ValueLabelY           = 1;
  ValueLabelW           = width - ValueLabelX;
  ValueLabelH           = height - 2;

  //!
  DateTimeLabel->move(DateTimeLabelX, DateTimeLabelY);
  DateTimeLabel->resize(DateTimeLabelW, DateTimeLabelH);

  TypeLabel->move(TypeLabelX, TypeLabelY);
  TypeLabel->resize(TypeLabelW, TypeLabelH);

  FileNameLabel->move(FileNameLabelX, FileNameLabelY);
  FileNameLabel->resize(FileNameLabelW, FileNameLabelH);

  FunctionNameLabel->move(FunctionNameLabelX, FunctionNameLabelY);
  FunctionNameLabel->resize(FunctionNameLabelW, FunctionNameLabelH);

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

  //!  Get function name
  for ( end = start ; text[end] != QChar(':') ; end++)
  {}

  m = end - start;
  functionName = text.sliced(start, m);
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
  FileNameLabel->setText(fileName);
  FunctionNameLabel->setText(functionName);
  LineNumberLabel->setText(QString("%1").arg(lineNumber));
  ValueLabel->setText(value);
}
