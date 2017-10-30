#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class NetServer : public QObject
{
	Q_OBJECT
		QTcpServer *tcpServer;
public:
	NetServer(QObject *parent);
	~NetServer();
	
	QTcpSocket *socket;

private slots:
	void server_New_Connect();
	void socket_Read_Data();
	void socket_Disconnected();

};
