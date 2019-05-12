#include <fstream>
#include <vector>

using namespace std;

vector<int> zone;

int analizza(int from, int to) {
	bool finito = true;
	for (int i = from; i < to; i++)
		if (zone[i] != 0)
			finito = false;
	if (finito)
		return 0;
	int i = from;
	for ( ; i < to; i++)
		if (zone[i] == 0)
			break;
	for (int j = from; j < i; j++)
		--zone[j];
	if (i == from)
		return analizza(i + 1, to);
	else if (i == to)
		return 1 + analizza(from, to);
	else return 1 + analizza(from, i) + analizza(i + 1, to);
}

int main() {
	int T;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	
	for (int t = 1; t <= T; t++) {
		int N;
		in >> N;
		zone.resize(N);
		for (auto& z : zone)
			in >> z;
		out << "Case #" << t << ": " << analizza(0, N) << endl;
	}
	
}
