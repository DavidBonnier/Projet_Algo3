#pragma once
#include <qlabel.h>
#include <qpainter.h>
 #include <QMouseEvent>

#include "CarteData.h"

typedef QMap<int, CVille> MaMap;

class CCarteView : public QLabel
{
private:

public:
	CCarteView();
	CCarteView(CCarteData * donnerCarte);
	~CCarteView(void);

private:
	CCarteData *m_CarteDonner;

private:
	void paintEvent(QPaintEvent *event);
	//void mousePressEvent(QMouseEvent *event);
};

