#include "CYY.h"
#include "DataStruct.h"

CYY::CYY(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	pServer = new NetServer(this);
//	Basic_Data BasicData;
	
}
