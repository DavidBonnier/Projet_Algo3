#pragma once
#include <qlabel.h>
#include <qpainter.h>
#include <QList.h>
#include <qmouseevent>
#include <QList.h>

#include "CarteData.h"

class CCarteView : public QLabel
{
public:
	CCarteView();
	CCarteView(CCarteData *donnerCarte);
	CCarteView(QWidget * parent);
	~CCarteView(void);

private:
	CCarteData *m_pdata;
	int Recherche(int debut, int fin);
	QList<int> RechercheC(int debut, int fin);
	QList<int> Recherche(QList<int> maFile, Table marque, int debut, int fin);

public:
	void setData(CCarteData *data);
	//Methodes
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
};

