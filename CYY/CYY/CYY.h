#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CYY.h"
#include "NetServer.h"



class CYY : public QMainWindow
{
	Q_OBJECT

public:
	CYY(QWidget *parent = Q_NULLPTR);

private:
	Ui::CYYClass ui;

	NetServer *pServer;
};
