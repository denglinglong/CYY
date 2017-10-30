#include "NetServer.h"
#include "QHostAddress"

NetServer::NetServer(QObject *parent)
	: QObject(parent)
{

	tcpServer = new QTcpServer(this);


	if (!tcpServer->listen(QHostAddress::LocalHost, 6666))
	{
		//��������6666�˿ڡ������������������Ϣ�����ر�

		qDebug() << tcpServer->errorString();

	}

	//�����źŲ�
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
	//��ȡ�ͻ�������
	socket = tcpServer->nextPendingConnection();
	//����QTcpSocket���źŲۣ��Զ�ȡ������
	QObject::connect(socket, &QTcpSocket::readyRead, this, &NetServer::socket_Read_Data);
	QObject::connect(socket, &QTcpSocket::disconnected, this, &NetServer::socket_Disconnected);

	qDebug() << "A Client connect!";
}

void NetServer::socket_Read_Data()
{
	QByteArray buffer;
	//��ȡ����������
	buffer = socket->readAll();
	if (!buffer.isEmpty())
	{

	}
}

void NetServer::socket_Disconnected()
{

	qDebug() << "Disconnected!";
}
