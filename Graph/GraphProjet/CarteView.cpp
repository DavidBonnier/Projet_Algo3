#include "CarteView.h"

CCarteView::CCarteView()
{
}

CCarteView::CCarteView(CCarteData * donnerCarte)
	: m_CarteDonner(donnerCarte)
{
}


CCarteView::~CCarteView(void)
{
}

void CCarteView::paintEvent(QPaintEvent * event)
{
	//Ouverture de l'image
	QImage image (m_CarteDonner->getNomImage());
	if (!image.isNull())
	{
		QPainter peintre (this);

		QPixmap pixmap = QPixmap::fromImage(image);
		peintre.drawPixmap(0,0,pixmap);
		resize(pixmap.size());

		for (auto it = m_CarteDonner->getMapVille().begin() ; 
					it != m_CarteDonner->getMapVille().end() ; ++it)
		{
			peintre.drawEllipse(it->getCoordonnees(),3,3);
		}
	}
}

//void CCarteView::mousePressEvent(QMouseEvent *event)
//{
//	int x = event->x();
//	int y = event->x();
//	for (auto it = m_CarteDonner->getMapVille().begin() ; 
//		it != m_CarteDonner->getMapVille().end() ; ++it)
//	{
//		//Cration d'un QRect pour chaque ville
//		QRect rectangle(it->getCoordonnees().x()-3,it->getCoordonnees().y()-3,6,6);
//		if(rectangle.contains(x,y))
//		{
//
//		}
//	}
//}