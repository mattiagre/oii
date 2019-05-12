#include <fstream>
#include <limits>
#include <array>
#include <queue>

using namespace std;

constexpr auto MAX = numeric_limits<int>::max();

struct Punto_t {
	int x; 
	int y;
	int altitudine;
	int pericolo = MAX;
};

array<array<Punto_t, 100>, 100> punti;

int esplora(int H, int W) {
	auto compare = [](const Punto_t& a, const Punto_t& b) {
		return a.pericolo > b.pericolo;
	};
	priority_queue<Punto_t, vector<Punto_t>, decltype(compare)> coda(compare);
	punti[0][0].pericolo = 0;
	coda.push(punti[0][0]);
	
	while(!coda.empty()) {
		auto top = coda.top();
		coda.pop();
		if (top.x > 0) 
		{
			int diff = punti[top.x - 1][top.y].altitudine - top.altitudine;
			int pericoloAttuale = top.pericolo > diff ? top.pericolo : diff;
			if (punti[top.x - 1][top.y].pericolo > pericoloAttuale) {
				punti[top.x - 1][top.y].pericolo = pericoloAttuale;
				coda.push(punti[top.x - 1][top.y]);
			}
		}
		if (top.y > 0) 
		{
			int diff = punti[top.x][top.y - 1].altitudine - top.altitudine;
			int pericoloAttuale = top.pericolo > diff ? top.pericolo : diff;
			if (punti[top.x][top.y - 1].pericolo > pericoloAttuale) {
				punti[top.x][top.y - 1].pericolo = pericoloAttuale;
				coda.push(punti[top.x][top.y - 1]);
			}
		}
		if (top.x < H) 
		{
			int diff = punti[top.x + 1][top.y].altitudine - top.altitudine;
			int pericoloAttuale = top.pericolo > diff ? top.pericolo : diff;
			if (punti[top.x + 1][top.y].pericolo > pericoloAttuale) {
				punti[top.x + 1][top.y].pericolo = pericoloAttuale;
				coda.push(punti[top.x + 1][top.y]);
			}
		}
		if (top.y < W) 
		{
			int diff = punti[top.x][top.y + 1].altitudine - top.altitudine;
			int pericoloAttuale = top.pericolo > diff ? top.pericolo : diff;
			if (punti[top.x][top.y + 1].pericolo > pericoloAttuale) {
				punti[top.x][top.y + 1].pericolo = pericoloAttuale;
				coda.push(punti[top.x][top.y + 1]);
			}
		}
	}
	
	return punti[H - 1][W - 1].pericolo;
}

int main() {
	int T;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	for (int t = 1; t <= T; t++) {
		int H, W;
		in >> H >> W;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				in >> punti[i][j].altitudine;
				punti[i][j].x = i;
				punti[i][j].y = j;
			}
		out << "Case #" << t << " : " << esplora(H, W) << ‘\n’;
	}
}
