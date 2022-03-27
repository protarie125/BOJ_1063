#include <iostream>
#include <map>
#include <string>

using namespace std;

using pii = pair<int, int>;
using msii = map<string, pii>;

bool isRange(const pii& pos, int x, int y) {
	return (0 <= pos.first + x) && (pos.first + x < 8) &&
		(0 <= pos.second + y) && (pos.second + y < 8);
}

void doMove(pii& pos, int x, int y) {
	pos.first += x;
	pos.second += y;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto moves = msii{
		{ "R", {1, 0}},
		{ "L", {-1, 0}},
		{ "B", {0, -1}},
		{ "T", {0, 1}},
		{ "RT", {1, 1}},
		{ "LT", {-1, 1}},
		{ "RB", {1, -1}},
		{ "LB", {-1, -1}}
	};

	string k, p;
	int n;
	cin >> k >> p >> n;

	auto posK = pii{};
	posK.first = k[0] - 'A';
	posK.second = k[1] - '1';

	auto posP = pii{};
	posP.first = p[0] - 'A';
	posP.second = p[1] - '1';

	while (0 < (n--)) {
		string m;
		cin >> m;

		const auto& [x, y] = moves[m];
		if (isRange(posK, x, y)) {
			if (posK.first + x == posP.first && posK.second + y == posP.second) {
				if (isRange(posP, x, y)) {
					doMove(posP, x, y);
					doMove(posK, x, y);
				}
			}
			else {
				doMove(posK, x, y);
			}
		}
	}

	cout << static_cast<char>(posK.first + 'A') << posK.second + 1 << '\n'
		<< static_cast<char>(posP.first + 'A') << posP.second + 1;

	return 0;
}