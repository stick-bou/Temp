#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{

	int K = 0;
	int Q = 0;
	std::string tempstr;
	std::string resultstr = "";
	char tempchar;
	unsigned long long N = 0;
	unsigned long long n = 0;

	std::cin >> K;

	std::vector <unsigned long long> S(K, 0);

	int lpnum = 0;
	unsigned long long k = 0;
	int j = 0;
	int i = 0;

	for (; i < K; i++) {
		std::cin >> tempstr;

		lpnum = int(tempstr.length());

		for (k = 1, j = lpnum - 1; j >= 0; j--, k *= 26) {
			S[i] += k * (unsigned long long)((char)tempstr[j]);
		}

		tempstr.clear();
	}

	sort(S.begin(), S.end());

	std::cin >> Q;
	std::cin.ignore();
	getline(std::cin, tempstr);

	std::stringstream ss(tempstr);
	tempstr.clear();

	unsigned long long l = 0;

	for (i = 0; i < Q; i++) {
		ss >> tempstr;

		N = stoull(tempstr);

		for (l = 0; l < K; l++) {

			if (N + l < S[l]) {
				N += l;
				break;
			}

			if (l == K - 1) {
				N += l + 1;
			}
		}

		tempstr = "";

		while (true) {

			n = ((N - 1) % 26) + 1;
			N = (N - n) / 26;

			tempchar = int(n) + 96;

			tempstr.insert(0, 1, tempchar);

			if (N == 0) { break; }

		}

		resultstr += tempstr;

		if (i != Q - 1) {
			resultstr += " ";
		}

		tempstr.clear();

	}

	std::cout << resultstr << std::endl;

	return 1;

}