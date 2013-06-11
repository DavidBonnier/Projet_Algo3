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
	m_data =new CCarteData();
	m_view->setData(m_data);

	initialisationBoolFaux();
	m_data->setBoolAddVille(true);

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
	connect (ui.radioButtonAddVilles,SIGNAL(clicked()),this,SLOT(AjouterVille()));
	connect (ui.radioButtonSuppVille,SIGNAL(clicked()),this,SLOT(changeBoolVille()));
	connect (ui.actionG_rer_les_routes,SIGNAL(triggered()),this,SLOT(Gerer_les_routes()));
	connect (ui.radioButtonSaisiRoute,SIGNAL(clicked()),this,SLOT(AjouterRoute()));
	connect (ui.radioButtonSuppRoute,SIGNAL(clicked()),this,SLOT(SuppRoute()));
	connect (ui.actionG_rer_les_parcours,SIGNAL(triggered()),this,SLOT(Gestion_des_parcours()));
	connect (ui.radioButtonVilleDep,SIGNAL(clicked()),this,SLOT(AjouteVilleDebut()));
	connect (ui.radioButtonVilleFin,SIGNAL(clicked()),this,SLOT(AjouteVilleFin()));

	ui.dockWidgetGestionRoutes->hide();
	ui.dockWidgetGestionParcours->hide();

	//Connection pour le menu Option
	connect (ui.actionChoix_r_pertoire,SIGNAL(triggered()),this,SLOT(Choix_repertoire()));
	connect (ui.actionRestaurer,SIGNAL(triggered()),this,SLOT(Restaurer()));

	//Connection pour le menu Aide
	connect (ui.actionAide,SIGNAL(triggered()),this,SLOT(Aide()));
	connect (ui.actionA_Propos,SIGNAL(triggered()),this,SLOT(A_propos()));

	if(!msg.IsOk())
	{
		QString titre = "Graphe";
		int rep = QMessageBox::critical(this, titre, "Travail impossible pas de fichier Message.mes", QMessageBox::Escape);
		exit(0);
	}

	m_nomRepetoire = "./Resources/";

	//change de valeur si le fichier GPH a �t� modifi�
	modif = false;

	setWindowTitle(msg.getMessage(1));
	ui.actionA_Propos->setStatusTip(msg.getMessage(51));
	ui.actionChoix_r_pertoire->setStatusTip(msg.getMessage(42));
	ui.actionFermer->setStatusTip(msg.getMessage(28));
	ui.actionG_rer_les_parcours->setStatusTip(msg.getMessage(53));
	ui.actionG_rer_les_routes->setStatusTip(msg.getMessage(46));
	ui.actionG_rer_les_villes->setStatusTip(msg.getMessage(44));
	ui.actionOuvrir->setStatusTip(msg.getMessage(22));
	ui.actionOuvrir_une_Image->setStatusTip(msg.getMessage(33));
	ui.actionQuitter->setStatusTip(msg.getMessage(30));
	ui.actionRestaurer->setStatusTip(msg.getMessage(48));
	ui.actionSauver->setStatusTip(msg.getMessage(24));
	ui.actionSauver_sous->setStatusTip(msg.getMessage(26));
	ui.radioButtonVilleDep->setStatusTip(msg.getMessage(69));
	ui.radioButtonVilleFin->setStatusTip(msg.getMessage(71));
	ui.radioButtonSaisiRoute->setStatusTip(msg.getMessage(65));
	ui.radioButtonAddVilles->setStatusTip(msg.getMessage(61));
	ui.radioButtonSuppRoute->setStatusTip(msg.getMessage(67));
	ui.radioButtonSuppVille->setStatusTip(msg.getMessage(63));
	ui.pushButtonClearParcours->setStatusTip(msg.getMessage(81));
	

}

Graph::~Graph()
{
}

void Graph::initialisationBoolFaux()
{
	m_data->setBoolAddVille(false);
	m_data->setBoolSuppVille(false);
	m_data->setBoolAddRoute(false);
	m_data->setBoolSuppRoute(false);
	m_data->setBoolVilleDeb(false);
	m_data->setBoolVilleFin(false);
}

void Graph::Ouvrir()
{
	QString nameFile;
	QString nameImg;
	Table vect;
	MaMap mappou;

	//Chargement du fichier .GPH
	nameFile = QFileDialog::getOpenFileName(this,msg.getMessage(2),m_nomRepetoire,msg.getMessage(3));
	
	int ouverture = CGestionnaire::Chargement(nameFile, nameImg, mappou, vect);
	//Traitement des erreurs lors de l'ouverture
	switch(ouverture)
	{
	case 1:

		return;
		break;
	case 2:
		QMessageBox::warning(this, msg.getMessage(2000),
				msg.getMessage(2021));
		return;
		break;
	case 3:
		QMessageBox::warning(this, msg.getMessage(2000),
				msg.getMessage(2023));
		return;
		break;
	case 4:
		QMessageBox::warning(this, msg.getMessage(2000),
				msg.getMessage(2024));
		break;
	case 5:
		QMessageBox::warning(this, msg.getMessage(2000),
			msg.getMessage(2025));
		break;
	}

	//M�J des attributs de la CCarteData m_data
	m_data->setTableRoutage(vect);
	m_data->setMapVille(mappou);
	m_data->setNomFichier(nameFile);
	m_data->setNomImage(nameImg);

	//M�J du nom de la fenetre
	setWindowTitle("Mon petit travail sur les graphes : "+m_data->getNomFichier()+" : "+ m_data->getNomImage());
	m_view->setData(m_data);
}

void Graph::Quitter()
{
	if(modif)
	{
		QMessageBox msgBox;
		msgBox.setText(msg.getMessage(0204));
		msgBox.setInformativeText(msg.getMessage(0203));
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
	if(m_data!= NULL)
		CGestionnaire::Sauvegarde(m_data->getNomFichier(), m_data->getNomImage(), m_data->getMapVille(), m_data->getTableRoutage());
}

void Graph::Sauver_sous()
{
	m_data->getNomFichier() = QFileDialog::getSaveFileName(this,msg.getMessage(5),m_nomRepetoire,msg.getMessage(3));
	Sauver();
}

void Graph::Fermer()
{
	if(modif)
	{
		QMessageBox msgBox;
		msgBox.setText(msg.getMessage(0204));
		msgBox.setInformativeText(msg.getMessage(0203));
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
	setWindowTitle(msg.getMessage(1));
	update();
}

void Graph::Ouvrir_une_Image()
{
	QString NomImage(QFileDialog::getOpenFileName(this,msg.getMessage(7),m_nomRepetoire,msg.getMessage(8)));

	if(NomImage != NULL)
	{
		m_data->setNomImage(NomImage);
		m_view->setData(m_data);
		update();
	}
}

void Graph::Gerer_les_villes()
{
	if(ui.actionG_rer_les_villes->isChecked())
	{
		ui.actionG_rer_les_parcours->setChecked(false);
		ui.dockWidgetGestionParcours->hide();
		ui.actionG_rer_les_routes->setChecked(false);
		ui.dockWidgetGestionRoutes->hide();
		ui.dockWidgetGestionVilles->show();

		initialisationBoolFaux();
		//Quand on afficher le dock on met un a vrai et l'autre a faux
		m_data->setBoolAddVille(true);
		ui.radioButtonAddVilles->setChecked(true);
		ui.radioButtonSuppVille->setChecked(false);
	}
	else
	{
		ui.dockWidgetGestionVilles->hide();
		initialisationBoolFaux();
	}
}

void Graph::Gerer_les_routes()
{
	if(ui.actionG_rer_les_routes->isChecked())
	{
		ui.actionG_rer_les_parcours->setChecked(false);
		ui.dockWidgetGestionParcours->hide();
		ui.actionG_rer_les_villes->setChecked(false);
		ui.dockWidgetGestionVilles->hide();
		ui.dockWidgetGestionRoutes->show();

		initialisationBoolFaux();
		//Quand on afficher le dock on met un a vrai et l'autre a faux
		m_data->setBoolAddRoute(true);
		ui.radioButtonSaisiRoute->setChecked(true);
		ui.radioButtonSuppRoute->setChecked(false);
	}
	else
	{
		ui.dockWidgetGestionRoutes->hide();
		initialisationBoolFaux();
	}
}

void Graph::Gestion_des_parcours()
{
	if(ui.actionG_rer_les_parcours->isChecked())
	{
		ui.actionG_rer_les_routes->setChecked(false);
		ui.dockWidgetGestionRoutes->hide();
		ui.actionG_rer_les_villes->setChecked(false);
		ui.dockWidgetGestionVilles->hide();
		ui.dockWidgetGestionParcours->show();

		initialisationBoolFaux();
		//Quand on afficher le dock on met un a vrai et l'autre a faux
		m_data->setBoolVilleDeb(true);
		ui.radioButtonVilleDep->setChecked(true);
		ui.radioButtonVilleFin->setChecked(false);
	}
	else
	{
		ui.dockWidgetGestionParcours->hide();
		initialisationBoolFaux();
	}
}

void Graph::Choix_repertoire()
{
	m_nomRepetoire = QFileDialog::getExistingDirectory(this,msg.getMessage(10),m_nomRepetoire);
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

void Graph::A_propos()
{
	QString title = msg.getMessage(1);
	QString texte = msg.getMessage(101)+msg.getMessage(102)+msg.getMessage(103)+msg.getMessage(104);

	QMessageBox::about(this,title, texte);
}

void Graph::AjouterVille()
{
	//Si on a pu cliquer c'est que le dockWidget est visible
	initialisationBoolFaux();
	//Quand on clique desus on met le bool comme le bouton
	m_data->setBoolAddVille(ui.radioButtonAddVilles->isChecked());
}

void Graph::SuppVille()
{
	//Si on a pu cliquer c'est que le dockWidget est visible
	initialisationBoolFaux();
	//Quand on clique desus on met le bool comme le bouton
	m_data->setBoolSuppVille(ui.radioButtonSuppVille->isChecked());
}

void Graph::AjouterRoute()
{
	//Si on a pu cliquer c'est que le dockWidget est visible
	initialisationBoolFaux();
	//Quand on clique desus on met le bool comme le bouton
	m_data->setBoolAddRoute(ui.radioButtonSaisiRoute->isChecked());
}

void Graph::SuppRoute()
{
	//Si on a pu cliquer c'est que le dockWidget est visible
	initialisationBoolFaux();
	//Quand on clique desus on met le bool comme le bouton
	m_data->setBoolSuppRoute(ui.radioButtonSuppRoute->isChecked());
}

void Graph::AjouteVilleDebut()
{
	//Si on a pu cliquer c'est que le dockWidget est visible
	initialisationBoolFaux();
	//Quand on clique desus on met le bool comme le bouton
	m_data->setBoolVilleDeb(ui.radioButtonVilleDep->isChecked());
}

void Graph::AjouteVilleFin()
{
	//Si on a pu cliquer c'est que le dockWidget est visible
	initialisationBoolFaux();
	//Quand on clique desus on met le bool comme le bouton
	m_data->setBoolVilleFin(ui.radioButtonVilleFin->isChecked());
}
