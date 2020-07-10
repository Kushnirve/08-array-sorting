#include <iostream>
#include <random>
using namespace std;

long const records = 10;
long numbers[records], icq[records];
long long phones[records];

void generator(long size) {
	int codes[15] = { 67, 96, 97, 98, 68, 50, 95, 99, 66, 63, 93, 92, 91, 94, 39 };
	random_device rd;
	mt19937 gen1(rd()), gen2(rd());
	uniform_int_distribution <> distr1(10000, 999999999), distr2(0, 9999999);
	for (long i = 0; i < size; i++) {
		numbers[i] = i + 1;
		icq[i] = distr1(gen1);
		phones[i] = 380000000000 + codes[rand() % 15] * 10000000 + distr2(gen2);
	}
}

template <class T, class U, class V>
void listAll(T a[], U b[], V c[], long size) {
	for (long i = 0; i < size; i++) {
		cout << a[i] << " | " << b[i] << " | " << c[i] << endl;
	}
}

template <class T, class U, class V>
void insertsSort(T a[], U b[], V c[], long size) {
	T x;
	U y;
	V z;
	long i, j;
	for (i = 0; i < size; i++) {
		x = a[i];
		y = b[i];
		z = c[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--) {
			a[j + 1] = a[j];
			b[j + 1] = b[j];
			c[j + 1] = c[j];
		}
		a[j + 1] = x;
		b[j + 1] = y;
		c[j + 1] = z;
	}
	listAll(a, b, c, size);
}

template <class T>
void bubbleSortImproved(T a[], long size) {
	long i = 0, j;
	int n = 0;
	bool flag = true;
	T x;
	while (flag) {
		for (j = size - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;
				n++;
			}
		}
		if (n > 0) n = 0;
		else flag = false;
		i++;
	}
	for (int i = 0; i < size; i++) {
		cout << a[i] << endl;
	}
}


template <class T>
void Oladishaker(T a[], long size) {
	T x;
	long maxOlad, maxOladnomer, temp;
	for (long i = size - 1; i >= 0; i--) {
		maxOlad = a[i];
		maxOladnomer = i;
		for (int j = i; j >= 0; j--) {
			if (a[j] > maxOlad) {
				maxOlad = a[j];
				maxOladnomer = j;
			}
		}
		for (long swap = 0; swap <= maxOladnomer / 2; swap++) {
			if (maxOladnomer == 0) break;
			temp = a[swap];
			a[swap] = a[maxOladnomer - swap];
			a[maxOladnomer - swap] = temp;
		}
		for (long swap = 0; swap <= i / 2; swap++) {
			temp = a[swap];
			a[swap] = a[i - swap];
			a[i - swap] = temp;
		}
	}
	for (long i = 0; i < size; i++) {
		cout << "Oladushek " << i + 1 << " razmerom " << a[i] << endl;
	}
}

int main() {
	generator(records);
	int menu;
	while (true) {
		cout << "1: ICQ / 2: Phone / 3: User / 4: Exit / 5: bubbleSortImproved / 6: OladiShaker >> ";
		cin >> menu;
		switch (menu) {
		case 1:
			cout << "Sorted by ICQ UIN:" << endl;
			insertsSort(icq, phones, numbers, records);
			break;
		case 2:
			cout << "Sorted by Phone numbers:" << endl;
			insertsSort(phones, icq, numbers, records);
			break;
		case 3:
			cout << "Unsorted (generated) list:" << endl;
			insertsSort(numbers, phones, icq, records);
			break;
		case 4:
			exit(1);
		case 5:
			cout << "Sorted by bubbleSortImproved:" << endl;
			bubbleSortImproved(icq, records);
			break;
		case 6:
			Oladishaker(icq, records);
			break;
		}
		system("pause");
		cout << "\x1B[2J\x1B[H";
	}
}



