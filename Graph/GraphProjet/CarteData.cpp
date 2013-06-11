#include "CarteData.h"

CCarteData::CCarteData()
{
}

CCarteData::CCarteData(Table routage, MaMap villes, QString fichier, QString image)
{
	m_nomFichier = fichier;
	m_nomImage = image;
	m_tableRoutage = routage;
	m_mapVille = villes;
}


CCarteData::~CCarteData(void)
{

}

void CCarteData::setNomFichier(QString string)
{
	m_nomFichier = string;
}

void CCarteData::setNomImage(QString img)
{
	m_nomImage = img;
}

void CCarteData::setTableRoutage(Table route)
{
	m_tableRoutage = route;
}

void CCarteData::setMapVille(MaMap cityMap)
{
	m_mapVille = cityMap;
}

void CCarteData::setParcours(QList<int> parcours)
{
	m_parcours = parcours;
}

void CCarteData::setBoolAddVille(bool modif)
{
	m_bAddVille = modif;
}

void CCarteData::setBoolSuppVille(bool modif)
{
	m_bSupprVille = modif;
}

void CCarteData::setBoolAddRoute(bool modif)
{
	m_bAddRoute = modif;
}

void CCarteData::setBoolSuppRoute(bool modif)
{
	m_bSupprRoute = modif;
}

void CCarteData::setBoolVilleDeb(bool modif)
{
	m_bvilleDeb = modif;
}

void CCarteData::setBoolVilleFin(bool modif)
{
	m_bvilleFin = modif;
}

void CCarteData::setVilleDeb(int modif)
{
	m_villeDebut = modif;
}

void CCarteData::setVilleFin(int modif)
{
	m_villeFin = modif;
}


void CCarteData::ajouterVille(int x, int y,QString str)
{
	//créé la structure de la nouvelle 
	CVille newVille(str,x,y);
	m_mapVille.insert(m_mapVille.size(),newVille);

	//ajoute une ligne
	m_tableRoutage.resize(m_tableRoutage.size()+1);
	//ajoute une colonne de a la derniere case de la ligne
	m_tableRoutage[m_tableRoutage.size()-1].resize(m_tableRoutage.size());
}




void CCarteData::ajouterRoute(CVille villeDeb, CVille villeFin)
{

}

//Retourne la position de la ville cliquer, si a l'extérieur = -1
int CCarteData::cliquerVille (int x, int y)
{
	if(!m_mapVille.isEmpty())
	{
		int i = 0;
		for (auto it = m_mapVille.begin() ; it != m_mapVille.end() ; ++it)
		{
			//Cration d'un QRect pour chaque ville
			QRect rectangle(it->getCoordonnees().x()-3,it->getCoordonnees().y()-3,6,6);
			//Si le rectangle contient x, y
			if(rectangle.contains(x,y)) 
				return i;
			i++;
		}
	}
	return -1;
}