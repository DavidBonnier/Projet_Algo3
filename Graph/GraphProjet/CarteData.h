#pragma once
#include <qmap.h>
#include <qvector.h>
#include <qstring.h>
#include <qobject.h>
#include <qlist.h>
#include <qpoint.h>
#include <qinputdialog.h>

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
	QList <int> m_parcours;
	QList<QPoint> m_pointClique;

public:	
	CCarteData();
	CCarteData(Table routage, MaMap villes, QString fichier, QString image);
	~CCarteData(void);

	//Methodes get puis set
	QList<QPoint> getPointClique(){return m_pointClique;}
	QList<int> getParcours() {return m_parcours;}

	QString getNomFichier(){return m_nomFichier;}
	QString getNomImage(){return m_nomImage;}
	Table getTableRoutage(){ return m_tableRoutage;}
	MaMap getMapVille(){return m_mapVille;}

	void setNomFichier(QString string);
	void setNomImage(QString img);
	void setTableRoutage(Table route);
	void setMapVille(MaMap cityMap);
	void setParcours(QList<int> parcours);

	//gestion des villes
	void ajouterVille(int x, int y,QString str);

	void ajouterRoute(CVille villeDeb, CVille villeFin);

};

