#pragma once
#include <qmap.h>
#include <qvector.h>
#include <qstring.h>
#include "Ville.h"

typedef QVector<QVector<int>> Table;
typedef QMap<int, CVille> MaMap;


class CCarteData
{
private:
	QString m_nomFichier;
	QString m_nomImage;
	Table m_tableRoutage;
	MaMap m_mapVille;

public:	
	CCarteData();
	CCarteData(Table routage, MaMap villes, QString fichier, QString image);
	~CCarteData(void);

	//Methodes
	QString getNomFichier(){return m_nomFichier;}
	QString getNomImage(){return m_nomImage;}
	Table getTableRoutage(){ return m_tableRoutage;}
	MaMap getMapVille(){return m_mapVille;}

	void setNomFichier(QString string);
	void setNomImage(QString img);
	void setTableRoutage(Table route);
	void setMapVille(MaMap cityMap);

};

