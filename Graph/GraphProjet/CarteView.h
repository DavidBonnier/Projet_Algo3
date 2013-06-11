#pragma once
#include <qlabel.h>
#include <qpainter.h>
#include <QList.h>
#include <qmouseevent>
#include <QList.h>
#include <qinputdialog.h>
#include <qmessagebox.h>

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
	QList<int> Recherche(int debut, int fin);

	int m_villeDebut;
	int m_villeFin;

	bool m_bDwVille;
	bool m_bAddVille;
	bool m_bSupprVille;

	bool m_bDwRoute;
	bool m_bAddRoute;
	bool m_bSupprRoute;

public:
	void setData(CCarteData *data);
	//Methodes
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);

	void setAddVille(bool add);
	void setSupprVille(bool suppr);

	bool getAddVille(){return m_bAddVille;}
	bool getSupprVille(){return m_bSupprVille;}

	CVille selectVille(int x, int y);

};
