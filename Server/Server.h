/*****************************************************************************
 * FILE NAME    : Server.h
 * DATE         : November 06 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Vertiv Company
 *****************************************************************************/
#ifndef _server_h_
#define _server_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QUdpSocket>
#include <QNetworkDatagram>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : Server
 *****************************************************************************/
class Server : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  Server                        (int InPort);

 //! Destructor
 public :
  ~Server                       ();

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
  void                          Init                    (void);
  void                          ProcessDataGram         (QNetworkDatagram InDataGram);
  
 //! Private Data
 private :
  QUdpSocket*                   socket;
  int                           port;

 //! Public Slots
 public slots :
  void                          SlotReadPendingDatagrams        ();
  
 //! Public Signals
 signals :
  void                          SignalTextReceived      (QString InText);

 //! Public Actions
 public :

};

#endif /* _server_h_*/
