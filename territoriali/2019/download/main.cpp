#include <fstream>

using namespace std;

int main() {
	int T;
	ifstream in("input.txt");
  	ofstream out("output.txt");
	in >> T;
	for (int t = 1; t <= T; t++) {
		int N, F, C;
		in >> N >> F >> C;
		int nFilmati, nCanzoni;
		nFilmati = N / F;
		N %= F;
		nCanzoni = N / C;
		out << "Case #" << t << ": " << nFilmati << ' ' << nCanzoni;
	}
}
