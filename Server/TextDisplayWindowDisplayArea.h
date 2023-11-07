/*****************************************************************************
 * FILE NAME    : TextDisplayWindowDisplayArea.h
 * DATE         : November 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _textdisplaywindowdisplayarea_h_
#define _textdisplaywindowdisplayarea_h_

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
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : TextDisplayWindowDisplayArea
 *****************************************************************************/
class TextDisplayWindowDisplayArea : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TextDisplayWindowDisplayArea  ();

 //! Destructor
 public :
  ~TextDisplayWindowDisplayArea ();

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
  void                          AddElement              (TextDisplayWindowDisplayElement* InElement);
  int                           GetNextY                (void);

 //! Private Data
 private :
  QList<TextDisplayWindowDisplayElement*>       elements;
  
 //! Public Slots
 public slots :
  void                          SlotAddText             (QString InString);
  void                          SlotClearDisplay        (void);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _textdisplaywindowdisplayarea_h_*/
