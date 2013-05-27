#include "Ville.h"


CVille::CVille(QString NomVille, int x, int y)
{
	m_NomVille = NomVille;
	m_Coordonnees.setX(x);
	m_Coordonnees.setY(y);
}

void CVille::setNomVille(QString NomVille)
{
	m_NomVille = NomVille;
}

void CVille::setCoordonnees(int x, int y)
{
	m_Coordonnees.setX(x);
	m_Coordonnees.setY(y);
}