#include <iostream>
#include <random>
#include <time.h>
#include <vector>

using namespace std;

//Экспонента числа n
double my_exp(int n);

//Машинный эпсилон
double EMach();

int main(){
	const int x = 50;
	for (int i = -x; i < 50 + 1; i += 10) {
		double ESis = exp(i), EMy = my_exp(i);
		double OD = abs(EMy - ESis) / ESis;
		cout << i << '\t' << ESis << '\t' << EMy << '\t' << OD << endl;
	}
	return 0;
}

double my_exp(int n) {
	//Экспонента числа n
	double d = EMach();
	double e0 = 1, e1 = 1, tmp = 1;
	double k = 1;
	if (n < 0) {
		do {
			e0 = e1;
			tmp = tmp * (double)(-n) / k;
			e1 += tmp;
			k++;
		} while (abs(e0 - e1) > d);
		return 1 / e0;
	}
	else {
		do {
			e0 = e1;
			tmp = tmp * (double)(n) / k;
			e1 += tmp;
			k++;
		} while (abs(e0 - e1) > d);
		return e0;
	}
}

double EMach() {
	//Машинный эпсилон
	double x = 1, y = 0, me;
	do {
		me = x;
		x = x / 2;
		y = 1 + x;
	} while (y != 1);
	return me;
}
