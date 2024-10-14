#include <iostream>
using namespace std;

double power(double a, int n) {
	if (n == 0)
		return 1;

	if (n == 1)
		return a;

        if (n % 2 == 0)
        {
            double halfOfPower = power(a, n / 2);
            return halfOfPower * halfOfPower;
        }
        else
        {
            double halfOfPower = power(a, (n - 1) / 2);
            return halfOfPower * halfOfPower * a;
        }
}

int main() {
	double a;
	int n;

	cout << "Nhap so a: ";
	cin >> a;
	cout << "Nhap so nguyen n: ";
	cin >> n;

	double result = power(a, n);
	cout << a << "^" << n << " = " << result << endl;

	return 0;
}
