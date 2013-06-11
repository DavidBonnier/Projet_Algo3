#include <qmessagebox.h>

#include "CarteView.h"


CCarteView::CCarteView()
{
	m_pdata=NULL;

	m_bDwVille = true;
	m_bAddVille = true;
	m_bSupprVille = false;
}

CCarteView::CCarteView(CCarteData *donnerCarte)
	: m_pdata(donnerCarte)
{
}


void CCarteView::setAddVille(bool add)
{
	m_bAddVille = add;
}

void CCarteView::setSupprVille(bool suppr)
{
	m_bSupprVille =suppr;
}



CCarteView::CCarteView(QWidget *parent)
	: QLabel(parent)
{
}

CCarteView::~CCarteView(void)
{
}

QList<int> CCarteView::Recherche(int debut, int fin)
{
	//creation de la file, elle contient les noeuds du parcours. 
	QList<int> maFile;

	//Tableau pour marquer les noeuds deja traiter.
	Table marque(m_pdata->getTableRoutage().size());
	//initialise le tableau marque à 0.
	for(int i=0; i<marque.size(); i++)
		for(int j=0; j<marque.size(); j++)
			marque[i].insert(j,0);

	bool trouver = false;
	//On initialise la file avec le début
	maFile.push_back(debut);
	while(debut != fin)
	{	
		//trouve pour chaque villes les villes associees
		for(int i=0; i<m_pdata->getTableRoutage().size(); i++)
		{
			
			if(marque[debut][i]==0)
				if(m_pdata->getTableRoutage()[debut][i]!=0)
				{
					//on marque les noeuds deja parcouru
					marque[debut][i]=1;
					marque[i][debut]=1;

					//on trouve une route entre i et debut
					debut = i;
					trouver=true;
					break;
				}
		}
		if (!trouver)
		{
			if(maFile.size() == 1)
			{
				//Si on trouve pas et qu'on est au debut il le retourne car il a pas de solution.
				return maFile;
			}

			//On defile debut et on récupère la nouvelle valeur de debut.
			maFile.pop_back();
			debut = maFile.back();
		}
		else
		{
			//on a trouvé une route entre 2 villes on enfile debut.
			maFile.push_back(debut);
		}

		trouver = false;
	}

	//Pour diférencier debut == fin et un sans solution.
	if(maFile.size() == 1 && debut==fin)
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

		QList<int> parcours =  Recherche(0,4);

		peintre.save();
		//Recherche le parcours entre 2 points
		//QList<int> parcours =  m_pdata->getParcours();

		//On regarde  si on as un parcours
		if(!parcours.isEmpty())
		{
			peintre.setPen(QColor(0,255,0));
			//un parcours est trouvé
			for (auto it = parcours.begin() ; it != parcours.end()-1 ; ++it)
				peintre.drawLine(mapVille[it[0]].getCoordonnees(),mapVille[it[1]].getCoordonnees());
		}
		peintre.restore();
	}
}

CVille selectVille(int x, int y)
{

}

void CCarteView::mousePressEvent(QMouseEvent *event)
{

	
	//le dockWidgetVille est visible et le boutton ajouter ville est coché
	if(m_bDwVille && event->button() == Qt::MouseButton::RightButton && m_bAddVille==true)
	{
		bool ok;
		QString str = QInputDialog::getText(this,"blabla","toto",QLineEdit::Normal,"Nom de ville",&ok);          
		//la chaine n'est pas vide
		if(str != "")
			m_pdata->ajouterVille(event->x(), event->y(),str);
	}
	if(m_bDwRoute && event->button()==Qt::MouseButton::RightButton && m_bAddRoute==true)
	{
		

	}

}


