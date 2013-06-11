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
	for(MaMap::Iterator it=m_mapVille.begin(); it != m_mapVille.end(); it++)
		if(x > it->getCoordonnees().x()-3 && x<it->getCoordonnees().x()+3)
			if(y > it->getCoordonnees().y()-3 && y < it->getCoordonnees().y()+3)
			{
				
			}
}