#include <iostream>
#include <fstream>
using namespace std;

int UpperBound(int x, int* A, int n) {
	int q = 0, r = n - 1,k;
	while (q < r) {
		k = (q + r) / 2;
		if (x < A[k])
			r = k;
		else
			q = k + 1;
	}
	return q;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, length = 0;
	fin >> n;
	//cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> A[i];
		//cin >> A[i];
	}

	//if (A[0] < A[1]) length++;
	int a;
	for (int i = 1; i < n; i++) {
		if (A[length] < A[i]) {
			length++;
			A[length] = A[i];
		}
		else {
			a = UpperBound(A[i], A, length + 1);
			if (A[a - 1] != A[i])
				A[a] = A[i];
		}
	}
	fout << length << endl;

}