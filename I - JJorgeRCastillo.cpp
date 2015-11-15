//=====================================================
// Name			: I.cpp
// Author		: EmptyString
// Version		: v.1.0
// Copyright	: Desarrollado por EmptyString
// Description  : Porblema I de Regional 2015 LATAM
//=====================================================

#include <iostream>

using namespace std;

int main(){
	int n, a, b, c, d, e;
	int cont;
	while(cin >> n){
		cont = 0;
		cin >> a >> b >> c >> d >> e;
		if(n == a) cont++;
		if(n == b) cont++;
		if(n == c) cont++;
		if(n == d) cont++;
		if(n == e) cont++;
		cout << cont << "\n";
	}
	return 0;
}
