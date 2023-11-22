/*****************************************************************************
 * FILE NAME    : TextDisplayWindow.h
 * DATE         : November 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _textdisplaywindow_h_
#define _textdisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "TextDisplayWindowScrollArea.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TEXT_DISPLAY_WINDOW_X           200
#define TEXT_DISPLAY_WINDOW_Y           200
#define TEXT_DISPLAY_WINDOW_WIDTH       200
#define TEXT_DISPLAY_WINDOW_HEIGHT      200

/*****************************************************************************!
 * Exported Class : TextDisplayWindow
 *****************************************************************************/
class TextDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TextDisplayWindow             ();

 //! Destructor
 public :
  ~TextDisplayWindow            ();

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
  TextDisplayWindowScrollArea*  scrollArea;

 //! Public Slots
 public slots :
  void                          SlotTextReceived        (QString InString);
  void                          SlotClearDisplay        (void);
  void                          SlotSaveData            (void);

 //! Public Signals
 signals :
  void                          SignalTextReceived      (QString InString);
  void                          SignalClearDisplay      (void);
  void                          SignalSaveData          (void);

 //! Public Actions
 public :

};

#endif /* _textdisplaywindow_h_*/
