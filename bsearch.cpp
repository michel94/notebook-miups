
#include <iostream>
#include <algorithm>
#include <vector>

int main () {
	int myints[] = {10,20,30,30,20,10,10,20};
	std::vector<int> v(myints,myints+8);

	std::sort (v.begin(), v.end());

	std::vector<int>::iterator low,up;
	low = std::lower_bound (v.begin(), v.end(), 20);
	up = std::upper_bound (v.begin(), v.end(), 20);

	std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
	std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

	return 0;
}