#include <fstream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

const int RMax = 100, CMax = 100;
char matrice[RMax][CMax];
string parola;

string trovaPercorso(int x = 0, int y = 0, int pos = 0, string percorso = "")
{
	if(pos == parola.size())
		return percorso.substr(0, percorso.size() - 1);
	if (matrice[x][y] != parola[pos])
		return "ASSENTE";
		
	string B, D;
	B = trovaPercorso(x + 1, y, pos + 1, percorso + 'B');
	D = trovaPercorso(x, y + 1, pos + 1, percorso + 'D');
	if (B != "ASSENTE")
		return B;
	else if(D != "ASSENTE")
		return D;
	else 
		return "ASSENTE";
}

int main()
{
	ifstream in("input.txt");
	int R, C;
	in >> R >> C;
	
	in >> parola;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			in >> matrice[i][j];
	in.close();	
	
	ofstream out("output.txt");	
	out << trovaPercorso();	
	out.close();
}
