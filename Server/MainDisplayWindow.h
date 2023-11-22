/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.h
 * DATE         : November 06 2023
 * PROJECT      : TraceServer
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _maindisplaywindow_h_
#define _maindisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Server.h"
#include "TextDisplayWindow.h"
#include "MainDisplayWindowControlBar.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MainDisplayWindow
 *****************************************************************************/
class MainDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayWindow             (int InPort);

 //! Destructor
 public :
  ~MainDisplayWindow            ();

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
  void                          Initialize              ();
  void                          InitializeSubWindows    ();
  void                          CreateSubWindows        ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          CreateConnections       (void);

 //! Private Data
 private :
  Server*                       server;
  int                           port;
  
  TextDisplayWindow*            textWindow;
  MainDisplayWindowControlBar*  controlBar;

 //! Public Slots
 public slots :
  void                          SlotTextReceived        (QString InString);
  void                          SlotClearDisplay        (void);
  void                          SlotSaveData            (void);

 //! Public Signals
 signals :
  void                          SignalTextReceived      (QString InString);
  void                          SignalClearDisplay      ();
  void                          SignalSaveData          (void);
  
 //! Public Actions
 public :

};

#endif /* _maindisplaywindow_h_*/
