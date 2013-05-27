#pragma once
#include <qstring.h>
#include <qpoint.h>

class CVille
{
private:

	QString m_NomVille;
	QPoint m_Coordonnees;

public:
	CVille(QString NomVille, int x, int y);

	QString getNomVille(){return m_NomVille;}
	QPoint getCoordonnees(){return m_Coordonnees;}

	void setNomVille(QString NomVille);
	void setCoordonnees(int x, int y);

};
