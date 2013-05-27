#include "graph.h"
#include "QFileDialog"
#include "QMessageBox"

Graph::Graph(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	//Connection pour le menu Fichier
	connect (ui.actionOuvrir,SIGNAL(triggered()),this,SLOT(Ouvrir()));
	connect (ui.actionSauver,SIGNAL(triggered()),this,SLOT(Sauver()));
	connect (ui.actionSauver_sous,SIGNAL(triggered()),this,SLOT(Sauver_sous()));
	connect (ui.actionFermer,SIGNAL(triggered()),this,SLOT(Fermer()));
	connect (ui.actionQuitter,SIGNAL(triggered()),this,SLOT(close()));

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
}

Graph::~Graph()
{
}

void Graph::Ouvrir()
{
	m_programmeGPH = QFileDialog::getOpenFileName(this,tr("Fichier a ouvrir"),m_nomRepetoire,tr("(*.gph)"));
}

void Graph::Sauver()
{
	if(m_programmeGPH.isEmpty())
		Sauver_sous();
}

void Graph::Sauver_sous()
{
	if(!m_programmeGPH.isEmpty())
		m_programmeGPH = QFileDialog::getSaveFileName(this,tr("Sauvgarder Fichier"),m_programmeGPH,tr("(*.gph)"));
}

void Graph::Fermer()
{
	m_Image=QImage("");
	update();
}

void Graph::Ouvrir_une_Image()
{
	m_nomImage = QFileDialog::getOpenFileName(this,tr("Fichier a ouvrir"),m_nomRepetoire,tr("(*.jpg)"));
	if(m_nomImage != NULL)
	{
		m_Image = QImage(m_nomImage);
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

void Graph::paintEvent(QPaintEvent * evt)
{
	if (!m_Image.isNull()||!m_pixmap.isNull())
	{
		m_pixmap = QPixmap::fromImage(m_Image) ;
		int h = m_pixmap.height() ;
		int w = m_pixmap.width() ;
		m_Dim.setX(w);
		m_Dim.setY(h) ;
		ui.imageLabel ->setGeometry(0,0,m_Dim.x(),m_Dim.y()) ;
		ui.imageLabel->setPixmap(m_pixmap) ;
	}
}