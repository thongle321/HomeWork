#include <iostream>
#include <cmath>
using namespace std;
float TinhDoLonVector(float x);
float TinhDoLonVector(float x, float y);
float TinhDoLonVector(float x, float y, float z);
float TinhDoLonVector(float x)
{
	return abs(x);

}
float TinhDoLonVector(float x, float y)
{
	return sqrt(x * x + y * y);
}
float TinhDoLonVector(float x, float y, float z)
{
	return sqrt(x * x + y * y + z * z);
}
void main()
{
	float x, y, z;
	cin >> x >> y >> z;
	cout << TinhDoLonVector(x) << "\n";
	cout << TinhDoLonVector(x, y) << "\n";
	cout << TinhDoLonVector(x, y, z) << "\n";
}