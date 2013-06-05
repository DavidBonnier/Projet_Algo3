#pragma once
//#include "carte.h"
#include "Ville.h"
#include <qfiledialog.h>
#include <qtextstream.h>
#include <qmap.h>
#include <qvector.h>

typedef QVector<QVector<int>> Table;
typedef QMap<int, CVille> MaMap;

class CGestionnaire
{
private:

public:
	static void Chargement(QString nameFile, QString &image, MaMap &MapVille,Table &vector);
	static void Sauvegarde(QString nameFile, QString &image, MaMap &MapVille,Table &vector);
	CGestionnaire(void);
	~CGestionnaire(void);
};

