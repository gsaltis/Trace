/*****************************************************************************
 * FILE NAME    : TextDisplayWindowDisplayElement.h
 * DATE         : November 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _textdisplaywindowdisplayelement_h_
#define _textdisplaywindowdisplayelement_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ElementTypeLabel.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_X 200
#define TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_Y 200
#define TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_WIDTH 200
#define TEXT_DISPLAY_WINDOW_DISPLAY_ELEMENT_HEIGHT 20

/*****************************************************************************!
 * Exported Class : TextDisplayWindowDisplayElement
 *****************************************************************************/
class TextDisplayWindowDisplayElement : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TextDisplayWindowDisplayElement (QString InString, QDateTime InDateTime,
                                   QColor InColor, QWidget* InParent);

 //! Destructor
 public :
  ~TextDisplayWindowDisplayElement ();

 //! Public Methods
 public :
  void                          Save                    (QFile* InFile);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          ParseText               (QString InString);

 //! Private Data
 private :
  QString                       text;
  QDateTime                     dateTime;
  QColor                        color;
  QLabel*                       TextLabel;
  QLabel*                       DateTimeLabel;
  ElementTypeLabel*             TypeLabel;
  QLabel*                       FileNameLabel;
  QLabel*                       FunctionNameLabel;
  QLabel*                       LineNumberLabel;
  QLabel*                       ValueLabel;

  int                           indentLength;
  int                           lineNumber;
  QString                       type;
  QString                       fileName;
  QString                       functionName;
  QString                       value;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _textdisplaywindowdisplayelement_h_*/
