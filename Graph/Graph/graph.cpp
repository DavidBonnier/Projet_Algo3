#include "graph.h"
#include "QFileDialog"

Graph::Graph(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	//Connection pour le menu Fichier
	connect (ui.actionOuvrir,SIGNAL(triggered()),this,SLOT(Ouvrir()));
	connect (ui.actionSauver,SIGNAL(triggered()),this,SLOT(Sauvegarder()));
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
}

Graph::~Graph()
{

}


void Graph::Ouvrir()
{

}

void Graph::Sauvegarder()
{

}

void Graph::Sauver_sous()
{

}

void Graph::Fermer()
{

}

void Graph::Quitter()
{
	close();
}

void Graph::Ouvrir_une_Image()
{
	Fichier = QFileDialog::getOpenFileName(this,tr("Fichier a ouvrir"),"",tr("(*.png)"));
	if(Fichier != NULL)
		Image = QImage(Fichier);
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

}

void Graph::Restaurer()
{

}

void Graph::Aide()
{

}

void Graph::A_propos()
{

}

void Graph::paintEvent(QPaintEvent * evt)
{
	if (!Image.isNull())
	{
		*pixmap = QPixmap::fromImage(Image) ;
		int h = pixmap->height() ;
		int w = pixmap->width() ;
		Dim.setX(w);
		Dim.setY(h) ;
		ui.imageLabel ->setGeometry(0,0,Dim.x(),Dim.y()) ;
		ui.imageLabel->setPixmap(*pixmap) ;
	}
}