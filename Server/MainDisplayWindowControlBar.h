/*****************************************************************************
 * FILE NAME    : MainDisplayWindowControlBar.h
 * DATE         : November 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _maindisplaywindowcontrolbar_h_
#define _maindisplaywindowcontrolbar_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_DISPLAY_WINDOW_CONTROL_BAR_X 0
#define MAIN_DISPLAY_WINDOW_CONTROL_BAR_Y 0
#define MAIN_DISPLAY_WINDOW_CONTROL_BAR_WIDTH 200
#define MAIN_DISPLAY_WINDOW_CONTROL_BAR_HEIGHT 30

/*****************************************************************************!
 * Exported Class : MainDisplayWindowControlBar
 *****************************************************************************/
class MainDisplayWindowControlBar : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayWindowControlBar   ();

 //! Destructor
 public :
  ~MainDisplayWindowControlBar  ();

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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  QColor                        backgroundColor;
  QPushButton*                  ClearButton;

 //! Public Slots
 public slots :
  void                          SlotClearButtonPushed   (void);

 //! Public Signals
 signals :
  void                          SignalClearDisplay      (void);

 //! Public Actions
 public :
  QAction*                      ActionClearButtonPushed;

};

#endif /* _maindisplaywindowcontrolbar_h_*/
