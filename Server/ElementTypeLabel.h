/*****************************************************************************
 * FILE NAME    : ElementTypeLabel.h
 * DATE         : November 07 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _elementtypelabel_h_
#define _elementtypelabel_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define ELEMENT_TYPE_LABEL_X            200
#define ELEMENT_TYPE_LABEL_Y            200
#define ELEMENT_TYPE_LABEL_WIDTH        200
#define ELEMENT_TYPE_LABEL_HEIGHT       200

/*****************************************************************************!
 * Exported Class : ElementTypeLabel
 *****************************************************************************/
class ElementTypeLabel : public QLabel
{
  Q_OBJECT;

 //! Constructors
 public :
  ElementTypeLabel              (QString InText, int InIndent, QColor InColor);

 //! Destructor
 public :
  ~ElementTypeLabel             ();

 //! Public Methods
 public :
  void                          AddText                 (QString InText, int InIndent);
  
 //! Public Data
 public :

 //! Protected Methods
 protected :
  void                          paintEvent              (QPaintEvent* InEvent);
  
 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);

 //! Private Data
 private :
  QString                       text;
  int                           indent;
  QColor                        color;
  
 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _elementtypelabel_h_*/
