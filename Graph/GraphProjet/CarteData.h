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

	int m_villeDebut;
	int m_villeFin;

	bool m_bAddVille;
	bool m_bSupprVille;
	bool m_bAddRoute;
	bool m_bSupprRoute;
	bool m_bvilleDeb;
	bool m_bvilleFin;

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

	bool getBoolAddVille(){return m_bAddVille;}
	bool getBoolSupprVille(){return m_bSupprVille;}
	bool getBoolAddRoute(){return m_bAddRoute;}
	bool getBoolSuppRoute(){return m_bSupprRoute;}
	bool getBoolVilleDeb(){return m_bvilleDeb;}
	bool getBoolVilleFin(){return m_bvilleFin;}
	int getVilleDeb(){return m_villeDebut;}
	int getVilleFin(){return m_villeFin;}


	void setNomFichier(QString string);
	void setNomImage(QString img);
	void setTableRoutage(Table route);
	void setMapVille(MaMap cityMap);
	void setParcours(QList<int> parcours);

	void setBoolAddVille(bool modif);
	void setBoolSuppVille(bool modif);
	void setBoolAddRoute(bool modif);
	void setBoolSuppRoute(bool modif);
	void setBoolVilleDeb(bool modif);
	void setBoolVilleFin(bool modif);

	void setVilleDeb(int modif);
	void setVilleFin(int modif);

	//gestion des villes
	void ajouterVille(int x, int y,QString str);

	void ajouterRoute(CVille villeDeb, CVille villeFin);

	int cliquerVille (int x, int y);

};

