#include <fstream>

using namespace std;

int festa_canina(ifstream& fin)
{
	int amici, bellezza = 0;
	fin >> amici;

	for (int j = 0; j < amici; j++)
	{
		int temp;
		fin >> temp;
		if (temp >= 0)
			bellezza += temp;
	}

	return bellezza;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int casi;

	in >> casi;

	for (int i = 1; i <= casi; i++)
		out << "Case #" << i << ": " << festa_canina(in) << endl;
}
