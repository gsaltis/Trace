/*****************************************************************************
 * FILE NAME    : Server.cpp
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
#include "Server.h"

/*****************************************************************************!
 * Function : Server
 *****************************************************************************/
Server::Server
(int InPort) : QWidget()
{
  port = InPort;
  Init();
  
}

/*****************************************************************************!
 * Function : ~Server
 *****************************************************************************/
Server::~Server
()
{
}

/*****************************************************************************!
 * Function : Init
 *****************************************************************************/
void
Server::Init(void)
{
  socket = new QUdpSocket(this);
  socket->bind(QHostAddress::AnyIPv4, port);
  connect(socket,
          SIGNAL(readyRead()),
          this,
          SLOT(SlotReadPendingDatagrams()));
}

/*****************************************************************************!
 * Function : SlotReadPendingDatagrams
 *****************************************************************************/
void
Server::SlotReadPendingDatagrams
()
{

  while (socket->hasPendingDatagrams()) {
         QNetworkDatagram datagram = socket->receiveDatagram();
         ProcessDataGram(datagram);
  }
}

/*****************************************************************************!
 * Function : ProcessDataGram
 *****************************************************************************/
void
Server::ProcessDataGram
(QNetworkDatagram InDatagram)
{
  QString                               text;

  text = QString(InDatagram.data());
  emit SignalTextReceived(text);
}
