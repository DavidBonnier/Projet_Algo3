#include <qmessagebox.h>

#include "CarteView.h"


CCarteView::CCarteView()
{
	m_pdata=NULL;
}

CCarteView::CCarteView(CCarteData *donnerCarte)
	: m_pdata(donnerCarte)
{
}

CCarteView::CCarteView(QWidget *parent)
	: QLabel(parent)
{
}

CCarteView::~CCarteView(void)
{
}

QList<int> CCarteView::Recherche(QList<int> maFile, Table marque, int debut, int fin)
{
	bool trouver = false;
	maFile.push_back(debut);
	while(debut != fin)
	{
		for(int i=0; i<m_pdata->getTableRoutage().size(); i++)
		{
			if(marque[debut][i]==0)
				if(m_pdata->getTableRoutage()[debut][i]!=0)
				{
					marque[debut][i]=1;
					marque[i][debut]=1;

					debut = i;
					trouver=true;
					break;
				}
		}
		if (!trouver)
		{
			if(maFile.size() == 1)
			{
				maFile = QList<int> ();
				return maFile;
			}

			maFile.pop_back();
			debut = maFile.back();
		}
		else
			maFile.push_back(debut);

		trouver = false;
	}
	return maFile;
}

QList<int> CCarteView::RechercheC(int debut, int fin)
{
	//creation de la file
	QList<int> maFile;

	//Tableau pour marquer les noeuds deja traiter
	Table marque(m_pdata->getTableRoutage().size());
	//initialise le tableau marque à 0
	for(int i=0; i<marque.size(); i++)
		for(int j=0; j<marque.size(); j++)
			marque[i].insert(j,0);

	//Retourne un QList Si pas de solution =debut sinon =parcours
	Recherche(maFile, marque, debut, fin);

	//Pour diférentier debut == fin et un sans solution
	if(maFile.size() == 1 && debut!=fin)
		return QList <int> ();

	return maFile;
}

void CCarteView::setData(CCarteData *data)
{
	m_pdata = data;
	update();
}

void CCarteView::paintEvent(QPaintEvent * event)
{
	if(m_pdata==NULL)
	{
		//si pas de valeur de CarteData
		return;
	}

	//Ouverture de l'image
	QString nomImage = "./Resources/";
	nomImage.push_back(m_pdata->getNomImage());

	QImage image (nomImage);
	if (image.isNull())
	{
		//L'image pas charger (Exemple pas le bon nom image ou pas dans "Resources")
		return;
	}

	QPainter peintre (this);

	//Si image est pas null on affiche image
	QPixmap pixmap = QPixmap::fromImage(image);
	peintre.drawPixmap(0,0,pixmap);
	resize(pixmap.size());

	MaMap mapVille(m_pdata->getMapVille());
	if(mapVille.isEmpty())
	{
		//pas de Ville charger
		return;
	}

	//Je le save et le restore pour garder mon painter du départ
	peintre.save();

	//si la map est pas null on créer des ronds pour les villes et on met leurs noms
	for (auto it = mapVille.begin() ; it != mapVille.end() ; ++it)
	{
		peintre.save();
		peintre.setPen(Qt::red);
		peintre.setBrush(Qt::red);
		peintre.drawEllipse(it->getCoordonnees(),  3,3);
		peintre.restore();
		peintre.setPen(QColor(qRgb(0,0,255)));
		//Recupération du nom de la Ville
		QString nomVille = it->getNomVille();
		//Cetrage du nom de la ville au dessus du point
		//Diviser pas 3 car on a estimé que une lettre fesait 6 pixel et vu qu'on centre on divise en 2
		//Le -5 est pour qu'il soit un peu au desus du point
		peintre.drawText(it->getCoordonnees().x()-nomVille.size()*3,it->getCoordonnees().y()-5, nomVille);
	}
	peintre.restore();

	if(!m_pdata->getTableRoutage().isEmpty())
	{
		peintre.save();
		//Si la table de routage est pas nul on trace les routes
		peintre.setPen(QColor(qRgb(255,0,255)));
		for(int i=0; i<m_pdata->getTableRoutage().size(); i++)
		{
			for(int j=0; j<m_pdata->getTableRoutage().size(); j++)
				if(m_pdata->getTableRoutage()[i][j]!=0)
				{
					//si on a une distance, on trace la route
					peintre.drawLine(mapVille[i].getCoordonnees(),mapVille[j].getCoordonnees());
				}
		}
		peintre.restore();

		/*//Recherche le parcours entre 2 points
		QList<int> parcours =  m_pdata->getParcours();

		//On regarde  si on as un parcours
		if(parcours == QList<int>())
		{
			QMessageBox::warning(this, tr("Parcours"),
				tr("Aucun parcours entre ces villes."));
		}
		else
		{
			if (parcours != QList<int>())
			{
				QMessageBox::warning(this, tr("Parcours"),
					tr("Deux fois la même ville selectionner"));
			}
			else
			{
				//un parcours est trouvé
				for (auto it = parcours.begin() ; it != parcours.end()-1 ; ++it)
					peintre.drawLine(mapVille[it[0]].getCoordonnees(),mapVille[it[1]].getCoordonnees());
			}

		}*/
	}
}

void CCarteView::mousePressEvent(QMouseEvent *event)
{
	int x = event->x();
	int y = event->y();


}

/*MaMap mapVille(m_pdata->getMapVille());
if(!mapVille.isEmpty())
{
for (auto it = mapVille.begin() ; it != mapVille.end() ; ++it)
{
//Cration d'un QRect pour chaque ville
QRect rectangle(it->getCoordonnees().x()-3,it->getCoordonnees().y()-3,6,6);
if(rectangle.contains(x,y))
{

}
}

//Recherche le parcours entre 2 points
QList<int> parcours =  RechercheC(Point1,Point2);
}*/