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