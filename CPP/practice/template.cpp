#include <iostream>

using namespace std;

template <class T>
T GetMax(T a, T b) {

	T result;
	result = (a>b) ? a : b;
	return result;
}

int main()

{
	int i=5, j = 8, k;
	char a = 'a', b='b', rslt;

	k = GetMax(i,j);
	rslt = GetMax(a,b);

	cout<< k<<endl;
	cout<<rslt<<endl;
	return 0;
}