#include "NetServer.h"
#include "QHostAddress"

NetServer::NetServer(QObject *parent)
	: QObject(parent)
{

	tcpServer = new QTcpServer(this);


	if (!tcpServer->listen(QHostAddress::LocalHost, 6666))
	{
		//监听本机6666端口。若出错，则输出错误信息，并关闭

		qDebug() << tcpServer->errorString();

	}

	//连接信号槽
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(server_New_Connect()));
	//	connect(this->m_temptcpServer, SIGNAL(newConnection()), this, SLOT(getNewConnection()))

}

NetServer::~NetServer()
{
	tcpServer->close();
//	tcpServer->deleteLater();
}


void NetServer::server_New_Connect()
{
	//获取客户端连接
	socket = tcpServer->nextPendingConnection();
	//连接QTcpSocket的信号槽，以读取新数据
	QObject::connect(socket, &QTcpSocket::readyRead, this, &NetServer::socket_Read_Data);
	QObject::connect(socket, &QTcpSocket::disconnected, this, &NetServer::socket_Disconnected);

	qDebug() << "A Client connect!";
}

void NetServer::socket_Read_Data()
{
	QByteArray buffer;
	//读取缓冲区数据
	buffer = socket->readAll();
	if (!buffer.isEmpty())
	{

	}
}

void NetServer::socket_Disconnected()
{

	qDebug() << "Disconnected!";
}
