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
	ui.radioButtonAddVilles->setChecked(true);
	ui.radioButtonSuppVille->setChecked(false);

	m_data = NULL;

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
	bool test =connect (ui.radioButtonAddVilles,SIGNAL(clicked()),this,SLOT(changeBoolVille()));
	test =connect (ui.radioButtonSuppVille,SIGNAL(clicked()),this,SLOT(changeBoolVille()));

	connect (ui.actionG_rer_les_routes,SIGNAL(triggered()),this,SLOT(Gerer_les_routes()));
	connect (ui.actionG_rer_les_parcours,SIGNAL(triggered()),this,SLOT(Gestion_des_parcours()));

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

	//change de valeur si le fichier GPH a été modifié
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

	//MàJ des attributs de la CCarteData m_data
	m_data =new CCarteData(vect, mappou, nameFile, nameImg);

	//MàJ du nom de la fenetre

	
	setWindowTitle(m_data->getNomImage());

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
	}
	else
	{
		ui.dockWidgetGestionVilles->hide();
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
	}
	else
	{
		ui.dockWidgetGestionRoutes->hide();
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
	}
	else
	{
		ui.dockWidgetGestionParcours->hide();
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

void Graph::changeBoolVille()
{
	m_view->setAddVille(!m_view->getAddVille());
	m_view->setSupprVille(!m_view->getSupprVille());
}
