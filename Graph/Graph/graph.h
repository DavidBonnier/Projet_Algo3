#ifndef GRAPH_H
#define GRAPH_H

#include <QtGui/QMainWindow>
#include "ui_graph.h"

class Graph : public QMainWindow
{
	Q_OBJECT

public:
	Graph(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Graph();

private:
	Ui::GraphClass ui;
};

#endif // GRAPH_H
