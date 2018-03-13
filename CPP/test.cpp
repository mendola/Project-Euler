#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
vector <int> vec;
vec.resize(10);
cout <<vec[0]<<endl;
vec[0] = 0;
int tmp = 4;

vec[4] = tmp;

cout <<vec[4]<<endl;
vec[12] = tmp;
vec.resize(15 + tmp);

return 0;
}
