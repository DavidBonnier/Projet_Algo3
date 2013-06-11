#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <QObject>
#include <qstring.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qmap.h> 
#include <qmessagebox.h>
#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

class CMessage 
{

public:
	// constructeur
	// Il chargera les messages dans la QMap Mess
	CMessage();
	// accesseur au texte d'un message Numero
	QString getMessage(int Numero);
	// accesseur à Ok variable de validité des messages
	bool IsOk(void){return Ok;}
	

private:
	// QMap de stockage des messages
	QMap<int, QString> Mess;
	// méthodes privée lisant le fichier Message.mes
	void Chargement();
	// Methode privée permettant de stocker le message n° A et texte B
	// dans la QMap Mess
	void RemplirMessage ( QString A, QString B) ;
	// indicateur permettant de savoir si un fichier Message.mes a
	// été lue ou pas
	bool Ok;

	
};

#endif // CMESSAGE_H