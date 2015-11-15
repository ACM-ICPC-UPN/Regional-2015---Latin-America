//=====================================================
// Name			: D.cpp
// Author		: EmptyString
// Version		: v.1.0
// Copyright	: Desarrollado por EmptyString
// Description  : Porblema D de Regional 2015 LATAM
//=====================================================
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int N, M, budget;
	int arr[200];
	int den[5] = {1, 10, 100, 1000, 10000};
	while(cin >> N >> M){
		int ganado = 0;
		int posible = 0;
		int sum = 0;
		while(M--){
			cin >> budget;
			sum = 0;
			for(int i = 0; i < N; i++){
				cin >> arr[i];
				sum += arr[i];
			}
			if(sum <= budget) {
				ganado += arr[0];
			}
			for(int i = 4; i >= 0 ; i--){
				if((sum - arr[0] + den[i]) <= budget){
					posible += den[i];
					break;
				}
			}
		}
		cout << fabs(ganado-posible) << "\n";
	}
	return 0;
}
