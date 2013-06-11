#include "Message.h"


CMessage::CMessage()
{
	
	Chargement();
}


void CMessage::Chargement()
{
	QString NomFichier = "Message.mes" ;
	QFile fichier(NomFichier);
	if(!fichier.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		Ok = false;
		return;
	}
	QTextStream in(&fichier);
	
	QString texte;
	QString num;
	QString ligne;
	bool commentaire = false;
	//lis chaque ligne tant qu'on est pas � la fin
	while(!in.atEnd())
	{
		//lis jusqu'au point virgule
		ligne = in.readLine();
		int i=0;
		commentaire = false;
		num.clear();
		texte.clear();
		while(ligne[i]!=NULL && ligne[i]!=';')
		{
			//lis le num�ro de la ligne
			num+=ligne[i];
			i++;
		}
		//Si la ligne est un commentaire, on passe � la ligne suivante
		if(num == "//")
			commentaire = true;
		while(ligne[i] != NULL && !commentaire)
		{
			if(ligne[i] != NULL)
			{
				texte += ligne[i+1];
			}
			i++;
		}

		//Remplissage de la QMap
		if(!commentaire)
			RemplirMessage(num, texte);
	}
	// indicateur permettant de savoir si un fichier Message.mes a �t� lue est mis � true
	Ok=true;
	fichier.close();
}

void CMessage::RemplirMessage(QString A, QString B)
{
	Mess[A.toInt()]=B;
}

QString CMessage::getMessage(int Numero)
{
	return Mess[Numero];
}

