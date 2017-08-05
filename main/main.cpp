// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <cctype>
#include <algorithm>
#include <vector>
#include <sstream>

class conversion {

};

enum Quadrant
{
	N = -90,
	NE = -90,
	E = +90,
	SE = +90,
	S = +90,
	SW = +90,
	W = +90,
	NW = +270
} quadrant;


struct usNorm
{
	double dip;
	double dipDir = 0;
};

struct euNorm
{
	double az;
	double dip;
	std::string dipAz;
};
int main()
{
	/*double az, dip;
	double DipDir = 0;
	std::string dipAz;*/

	std::vector<euNorm> inputData;
	std::ifstream fichier("B1.txt");
	if (fichier)
	{
		std::string ligne;
		while (getline(fichier, ligne))
		{
			std::stringstream stream(ligne);
			euNorm data;
			stream >> data.az >> data.dip >> data.dipAz;
			std::cout << data.az << " " << data.dip << " " << data.dipAz << std::endl;
			inputData.push_back(data);

		}

	}
	else
	{
		std::cout << "erreur" << std::endl;
	}



	//quadrant = Quadrant(N);
	std::vector<usNorm> outputData;

	std::cout << "les fichiers convertis: " << std::endl;
	for (auto data : inputData)
	{

		if (data.dipAz == "N" && data.az > 90) quadrant = Quadrant(N);
		else if (data.dipAz == "N" && data.az < 90) quadrant = Quadrant(NW);
		else if (data.dipAz == "NE") quadrant = Quadrant(NE);
		else if (data.dipAz == "E") quadrant = Quadrant(E);
		else if (data.dipAz == "SE") quadrant = Quadrant(SE);
		else if (data.dipAz == "S") quadrant = Quadrant(S);
		else if (data.dipAz == "SW") quadrant = Quadrant(SW);
		else if (data.dipAz == "W") quadrant = Quadrant(W);
		else if (data.dipAz == "NW") quadrant = Quadrant(NW);
		usNorm outData;
		outData.dipDir = data.az + quadrant;
		outData.dip = data.dip;
		outputData.push_back(outData);
		std::cout << outData.dip << " " << outData.dipDir << std::endl;
	}




	/*switch (quadrant)
	{
	case 0:
	if (az >= 0 && az <= 90)
	{
	DipDir = az + 270;
	}
	break;
	case 1:
	if (az > 90 && az <= 180)
	{
	DipDir = az - 90;
	}
	break;
	case 2:
	if (az >= 0 && az <= 90)
	{
	DipDir = az + 90;
	}
	else if (az > 90 && az <= 180)
	{
	DipDir = az - 90;
	}
	break;
	case 3:
	if (az >= 0 && az <= 90)
	{
	DipDir = az + 90;
	}
	break;
	case 4:
	if (az >= 0 && az <= 90)
	{
	DipDir = az + 90;
	}
	else if (az > 90 && az <= 180)
	{
	DipDir = az + 90;
	}
	break;
	case 5:
	if (az > 90 && az <= 180)
	{
	DipDir = az + 90;
	}
	break;
	case 6:
	if (az >= 0 && az <= 90)
	{
	DipDir = az + 270;
	}
	else if (az > 90 && az <= 180)
	{
	DipDir = az + 90;
	}
	break;
	case 7:
	if (az >= 0 && az <= 90)
	{
	DipDir = az + 270;
	}
	break;
	default:
	std::cout << "erreur de valeurs" << std::endl;
	}*/

	//std::cout << dip << " " << DipDir << std::endl;
}
