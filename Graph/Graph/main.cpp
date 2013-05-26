#include "graph.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Graph w;
	w.show();
	return a.exec();
}
