/*****************************************************************************
 * FILE NAME    : TextDisplayWindowScrollArea.h
 * DATE         : November 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _textdisplaywindowscrollarea_h_
#define _textdisplaywindowscrollarea_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QScrollArea>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "TextDisplayWindowDisplayArea.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TEXT_DISPLAY_WINDOW_SCROLL_AREA_X 200
#define TEXT_DISPLAY_WINDOW_SCROLL_AREA_Y 200
#define TEXT_DISPLAY_WINDOW_SCROLL_AREA_WIDTH 200
#define TEXT_DISPLAY_WINDOW_SCROLL_AREA_HEIGHT 200

/*****************************************************************************!
 * Exported Class : TextDisplayWindowScrollArea
 *****************************************************************************/
class TextDisplayWindowScrollArea : public QScrollArea
{
  Q_OBJECT;

 //! Constructors
 public :
  TextDisplayWindowScrollArea   ();

 //! Destructor
 public :
  ~TextDisplayWindowScrollArea  ();

 //! Public Methods
 public :

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
  void                          CreateConnections       (void);

 //! Private Data
 private :
  TextDisplayWindowDisplayArea* displayArea;

 //! Public Slots
 public slots :
  void                          SlotTextReceived        (QString InText);
  void                          SlotClearDisplay        (void);

 //! Public Signals
 signals :
  void                          SignalTextReceived      (QString InText);
  void                          SignalClearDisplay      (void);

 //! Public Actions
 public :

};

#endif /* _textdisplaywindowscrollarea_h_*/
