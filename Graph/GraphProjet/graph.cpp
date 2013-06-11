#include "graph.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QPaintEvent"

Graph::Graph(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	m_view = new CCarteView ();
	setCentralWidget(m_view);

	//Initialisation des scrollBar quand image est trop grand
	scrollArea = new QScrollArea;
	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setWidget(m_view);
	setCentralWidget(scrollArea);

	//Connection pour le menu Fichier
	connect (ui.actionOuvrir,SIGNAL(triggered()),this,SLOT(Ouvrir()));
	connect (ui.actionSauver,SIGNAL(triggered()),this,SLOT(Sauver()));
	connect (ui.actionSauver_sous,SIGNAL(triggered()),this,SLOT(Sauver_sous()));
	connect (ui.actionFermer,SIGNAL(triggered()),this,SLOT(Fermer()));
	connect (ui.actionQuitter,SIGNAL(triggered()),this,SLOT(Quitter()));

	//Connection pour le menu Outils
	connect (ui.actionOuvrir_une_Image,SIGNAL(triggered()),this,SLOT(Ouvrir_une_Image()));
	connect (ui.actionG_rer_les_villes,SIGNAL(triggered()),this,SLOT(Gerer_les_villes()));
	connect (ui.actionG_rer_les_routes,SIGNAL(triggered()),this,SLOT(Gerer_les_routes()));
	ui.dockWidgetGestionRoutes->hide();

	//Connection pour le menu Option
	connect (ui.actionChoix_r_pertoire,SIGNAL(triggered()),this,SLOT(Choix_repertoire()));
	connect (ui.actionRestaurer,SIGNAL(triggered()),this,SLOT(Restaurer()));

	//Connection pour le menu Aide
	connect (ui.actionAide,SIGNAL(triggered()),this,SLOT(Aide()));
	connect (ui.actionA_propos,SIGNAL(triggered()),this,SLOT(A_propos()));

	m_nomRepetoire = "../";

	modif = false;

	setWindowTitle("Mon petit ravail sur les graphes : nofichier : noImage");
}

Graph::~Graph()
{
}

void Graph::Ouvrir()
{
	QString nameFile;
	QString nameImg;
	Table vect;
	MaMap mappou;

	//Chargement du fichier .GPH
	nameFile = QFileDialog::getOpenFileName(this,tr("Fichier a ouvrir"),m_nomRepetoire,tr("(*.gph)"));
	
	int ouverture = CGestionnaire::Chargement(nameFile, nameImg, mappou, vect);
	//Traitement des erreurs lors de l'ouverture
	switch(ouverture)
	{
	case 1:
		QMessageBox::warning(this, tr("Ouverture Fichier"),
				tr("Fichier pas ouvert."));
		break;
	case 2:
		QMessageBox::warning(this, tr("Ouverture Fichier"),
				tr("Ce n'est pas un fichier '.gph'."));
		break;
	case 3:
		QMessageBox::warning(this, tr("Ouverture Fichier"),
				tr("Image pas ouverte."));
		break;
	case 4:
		QMessageBox::warning(this, tr("Ouverture Fichier"),
				tr("Pas de ville a charger."));
		break;
	case 5:
		QMessageBox::warning(this, tr("Ouverture Fichier"),
				tr("Pas de Distance."));
		break;
	}

	//MàJ des attributs de la CCarteData m_data
	m_data =new CCarteData(vect, mappou, nameFile, nameImg);

	//MàJ du nom de la fenetre
	setWindowTitle("Mon petit travail sur les graphes : "+m_data->getNomFichier()+" : "+ m_data->getNomImage());

	m_view->setData(m_data);
}

void Graph::Quitter()
{
	if(modif)
	{
		QMessageBox msgBox;
		msgBox.setText("Le document a été modifié");
		msgBox.setInformativeText("Voulez vous sauvegarder vos changements?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Save);
		int ret = msgBox.exec();

		switch (ret) 
		{
		case QMessageBox::Save:
			Sauver();
			break;

		case QMessageBox::Cancel:
			return;
			break;
		}
	}

	close();
}

void Graph::Sauver()
{
	if(!(m_data->getNomFichier().isEmpty()))
		CGestionnaire::Sauvegarde(m_data->getNomFichier(), m_data->getNomImage(), m_data->getMapVille(), m_data->getTableRoutage());
}

void Graph::Sauver_sous()
{
	m_data->getNomFichier() = QFileDialog::getSaveFileName(this,tr("Sauvgarder Fichier"),m_nomRepetoire,tr("(*.gph)"));
	Sauver();
}

void Graph::Fermer()
{
	if(modif)
	{
		QMessageBox msgBox;
		msgBox.setText("Le document a été modifié");
		msgBox.setInformativeText("Voulez vous sauvegarder vos changements?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Save);
		int ret = msgBox.exec();

		switch (ret) 
		{
		case QMessageBox::Save:
			Sauver();
			break;

		case QMessageBox::Cancel:
			return;
			break;
		}
	}
	setWindowTitle("Mon petit ravail sur les graphes : nofichier : noImage");
	update();
}

void Graph::Ouvrir_une_Image()
{
	m_data->setNomImage(QFileDialog::getOpenFileName(this,tr("Fichier a ouvrir"),m_nomRepetoire,tr("(*.jpg)")));
	m_view->setData(m_data);

	if(m_data->getNomImage() != NULL)
	{
		update();
	}
}

void Graph::Gerer_les_villes()
{
	if (ui.actionG_rer_les_villes->isChecked())
	{
		ui.actionG_rer_les_villes->setChecked(true);
		ui.actionG_rer_les_routes->setChecked(false);
		ui.dockWidgetGestionVilles->show();
		ui.dockWidgetGestionRoutes->hide();
	}
	else
		ui.actionG_rer_les_villes->setChecked(true);
}

void Graph::Gerer_les_routes()
{
	if (ui.actionG_rer_les_routes->isChecked())
	{
		ui.actionG_rer_les_routes->setChecked(true);
		ui.actionG_rer_les_villes->setChecked(false);
		ui.dockWidgetGestionRoutes->show();
		ui.dockWidgetGestionVilles->hide();
	}
	else
		ui.actionG_rer_les_routes->setChecked(true);
}

void Graph::Choix_repertoire()
{
	m_nomRepetoire = QFileDialog::getExistingDirectory(this,tr("Choix du répertoire de stockage des fichier *.gph et image *.jpg"),m_nomRepetoire);
}

void Graph::Restaurer()
{
	Fermer();
	m_nomRepetoire = "../";
	ui.actionG_rer_les_villes->setChecked(true);
	ui.actionG_rer_les_routes->setChecked(false);
	ui.dockWidgetGestionVilles->show();
	ui.dockWidgetGestionRoutes->hide();
}

void Graph::Aide()
{

}

void Graph::A_propos()
{
	QMessageBox::about(this,"Mon petit travail sur les graphes",
		"---------------- Ma petite gestion des routes ---------------"
		"<p> Version 1.0.1 </p>"
		"<p> .................. Jonas Lamy, Jéremy Prime, David Bonnier</p>");
}

