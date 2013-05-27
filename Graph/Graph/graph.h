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
	QImage m_Image;
	QPixmap m_pixmap;
	QPoint m_Dim;
	QString m_nomImage;
	QString m_nomRepetoire;
	QString m_programmeGPH;
	//Affiche le QImage à l'aide du QPixmap
	void paintEvent(QPaintEvent * evt);

public slots:
	//ouvre un fichier .gph qui est le programme qui contient tout
	void Ouvrir();
	//save le fichier .gph
	void Sauver();
	//save le fichier .gph sous un autre nom
	void Sauver_sous();
	//ferme le fichier .gph
	void Fermer();
	//ouvre une image .jpg
	void Ouvrir_une_Image();
	//Montre ou cache les dockWidget de gauche
	void Gerer_les_villes();
	void Gerer_les_routes();
	//Choisit un repertoire courant ou sera stocker les .gph et .jpg
	void Choix_repertoire();
	//Remet la fenetre dans l'état initial
	void Restaurer();

	void Aide();
	//Donne le nom du programme et des personne du groupes
	void A_propos();
};

#endif // GRAPH_H
