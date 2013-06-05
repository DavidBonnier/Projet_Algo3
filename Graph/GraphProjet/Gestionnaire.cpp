#include "Gestionnaire.h"


CGestionnaire::CGestionnaire(void)
{
}


CGestionnaire::~CGestionnaire(void)
{
}

void CGestionnaire::Chargement(QString nameFile, QString &nameImage, MaMap &MapVille, Table &vector)
{
	QFile file(nameFile);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	
	QTextStream in(&file);
	QString buffer;
	QString NombreVille;
	int NbVille;

	//Gestion signature
	in>>buffer;
	if(buffer=="GPH")
	{
		//Gestion de l'image
		in>>buffer;
		if(buffer == "Image=")
			in>>nameImage;
		else
		{
			//message erreur, pas d'image
		}

		//Gestion du nombre de ville
		in>>NombreVille;
		if(NombreVille == "Ville=")
		{
			in>>NombreVille;
			NbVille = NombreVille.toInt();
		
			for(int i = 0; i<NbVille; i++)
			{
				QString nameCity;
				QString xCity;
				QString yCity;

				in>>buffer; //lis la clé
				in>>nameCity;
				in>>xCity;
				in>>yCity;

				//remplissage de la map
				MapVille[i] = CVille(nameCity,xCity.toInt(),yCity.toInt());
			}
		}
		else
		{
			//message erreur pas de ville
		}

		//gestion du vecteur distance
		in>>buffer;
		if(buffer == "Distance=")
		{
			//met le vcteur à la bonne taille
			vector.resize(NbVille);
			for(QVector<QVector<int>>::iterator it=vector.begin();it != vector.end(); it++)
			{
				it->resize(NbVille);
			}

			//bufferVille
			QString bufferVille;
			//bufferDistance
			QString bufferDistance;

			//remplissage de la table  routage
			while(!in.atEnd())
			{
				in>>buffer;
				in>>bufferVille;
				in>>bufferDistance;

				vector[buffer.toInt()][bufferVille.toInt()] = bufferDistance.toInt();

			}
		}
		else
		{
			//message erreur pas de distance
		}
	}
	else
	{
		//message d'erreur, le fichier n'est pas un *.gph
	}
	

}

void CGestionnaire::Sauvegarde(QString nameFile, QString &image, MaMap &MapVille,Table &vector)
{
	//creation du fichier
	QFile  writingFile(nameFile);
	if(!(writingFile.open(QIODevice::WriteOnly| QIODevice::Text)))
		return;
	QTextStream out(&writingFile);
	//ecriture de la signature
	out<<"GPH "<<endl;
	//ecriture du Label image
	out<<"Image= "<<image<<endl;
	//ecriture du Label Ville
	out<<"Ville= "<<MapVille.count()<<endl;

	for(int i = 0; i < vector.size(); i++)
	{
		out<<i<<" "<<MapVille[i].getNomVille()<<" "<<MapVille[i].getCoordonnees().x()<<" "<<MapVille[i].getCoordonnees().y()<<endl;
	}
	out<<"Distance= "<<endl;


	for(int i=0; i<vector.size(); i++)
		for(int j=0; j<vector.size(); j++)
		{
			if(vector[i][j] != 0)
				out<<i<<" "<<j<<" "<<vector[i][j]<<endl;

		}
}