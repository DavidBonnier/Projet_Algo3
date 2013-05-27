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
	QImage Image;
	QPixmap *pixmap;
	QPoint Dim;
	QString Fichier;
	void paintEvent(QPaintEvent * evt);

public slots:
	void Ouvrir();
	void Sauvegarder();
	void Sauver_sous();
	void Fermer();
	void Quitter();
	void Ouvrir_une_Image();
	void Gerer_les_villes();
	void Gerer_les_routes();
	void Choix_repertoire();
	void Restaurer();
	void Aide();
	void A_propos();
};

#endif // GRAPH_H
