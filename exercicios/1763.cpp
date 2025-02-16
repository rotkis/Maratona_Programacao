#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <set>
#include <cstdlib>
#include <list>
#include <map>
using namespace std;
// and = &&
// or ||

int main() {
	map<string, string>paises;
	paises["brasil"] = "Feliz Natal!";
	paises["alemanha"] = "Frohliche Weihnachten!";
	paises["austria"] = "Frohe Weihnacht!";
	paises["coreia"] = "Chuk Sung Tan!";
	paises["espanha"] = "Feliz Navidad!";
	paises["grecia"] = "Kala Christougena!";
	paises["estados-unidos"] = "Merry Christmas!";
	paises["inglaterra"] = "Merry Christmas!";
	paises["australia"] = "Merry Christmas!";
	paises["portugal"] = "Feliz Natal!";
	paises["suecia"] = "God Jul!";
	paises["turquia"] = "Mutlu Noeller";
	paises["argentina"] = "Feliz Navidad!";
	paises["chile"] = "Feliz Navidad!";
	paises["mexico"] = "Feliz Navidad!";
	paises["antardida"] = "Merry Christmas!";
	paises["canada"] = "Merry Christmas!";
	paises["irlanda"] = "Nollaig Shona Dhuit!";
	paises["belgica"] = "Zalig Kerstfeest!";
	paises["italia"] = "Buon Natale!";
	paises["libia"] = "Buon Natale!";
	paises["siria"] = "Milad Mubarak!";
	paises["marrocos"] = "Milad Mubarak!";
	paises["japao"] = "Merii Kurisumasu!";
	string a;
	while (cin >> a) {
		if (paises.count(a) > 0) {
			cout << paises[a] << endl;
		}
		else
		{
			cout << "--- NOT FOUND ---" << endl;
		}
	}

	}


	
	

