#ifndef GRAPH_H
#define GRAPH_H

#include <QtGui/QMainWindow>
#include "ui_graph.h"
#include "Gestionnaire.h"
#include "CarteView.h"
#include "CarteData.h"
#include "Message.h"
#include <qscrollarea.h>


class Graph : public QMainWindow
{
	Q_OBJECT

public:
	Graph(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Graph();

private:
	Ui::GraphClass ui;

	bool modif;
	CMessage msg;

	QPoint m_Dim;
	QString m_nomRepetoire;
	CCarteData *m_data;
	CCarteView *m_view;
	QScrollArea *scrollArea;

	void initialisationBoolFaux();

public slots:
	//ouvre un fichier .gph qui est le programme qui contient tout
	void Ouvrir();
	//quitte l'application
	void Quitter();
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
	void Gestion_des_parcours();
	//Choisit un repertoire courant ou sera stocker les .gph et .jpg
	void Choix_repertoire();
	//Remet la fenetre dans l'état initial
	void Restaurer();
	//Donne le nom du programme et des personne du groupes
	void A_propos();

	//slot des radioBoutons
	void AjouterVille();
	void SuppVille();
	void AjouterRoute();
	void SuppRoute();
	void AjouteVilleDebut();
	void AjouteVilleFin();
};

#endif // GRAPH_H
