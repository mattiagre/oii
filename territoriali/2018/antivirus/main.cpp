#include <fstream>
#include <array>
#include <string>

using namespace std;

array<string, 4> stringhe;

bool check(const string& virus)
{
	return stringhe[2].find(virus) != string::npos && stringhe[3].find(virus) != string::npos;
}

string trovaVirus(int m)
{
	const string& str0 = stringhe[0], str1 = stringhe[1];

	for (int i = 0; i <= str0.size(); i++)
	{
		int tempI = i;
		for (int j = 0; j <= str1.size(); j++)
		{
			if (i - tempI == m && check(string(&str0[tempI], &str0[i])))
				return string(&str0[tempI], &str0[i]);

			if (str0[i] == str1[j])
				++i;
			else
				i = tempI;
		}
	}

	return "NONDOVREBBEACCADERE";
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int casi;
	in >> casi;
	for (int k = 1; k <= casi; k++)
	{
		int discard, M;
		for (int i = 0; i < 4; i++)
			in >> discard;
		in >> M;

		for (auto& s : stringhe)
			in >> s;

		string virus = trovaVirus(M);

		out << "Case #" << k << ": ";
		for (auto& s : stringhe)
			out << s.find(virus) << ' ';
		out << ' ';
	}
}
