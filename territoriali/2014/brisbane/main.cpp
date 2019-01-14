#include <fstream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

struct Fermata {
	int n;
	bool visitata = false;
	bool attrazione = false;
};

struct Strada {
	enum Tipo {
		Gratuito = 0b1,
		Bus = 0b10,
		Traghetto = 0b100
	} tipo;
	
	int fermataA;
	int fermataB;
};

using Tipo = Strada::Tipo;

int attrazioniVisitabili(vector<Fermata>& f, vector<Strada>& s, int t)
{
	int conta = 0;
	stack<Fermata*> daVisitare;
	daVisitare.push(&f[0]);
	
	while (!daVisitare.empty())
	{
		Fermata* fermata = daVisitare.top();
		if (fermata->attrazione && !fermata->visitata) 
			++conta;
		fermata->visitata = true;
		daVisitare.pop();
		for (auto& strada : s)
		{
			if((strada.tipo & t) && strada.fermataA == fermata->n && !f[strada.fermataB].visitata)
				daVisitare.push(&f[strada.fermataB]);
			else if((strada.tipo & t) && strada.fermataB == fermata->n && !f[strada.fermataA].visitata)
				daVisitare.push(&f[strada.fermataA]);
		}
	}
	
	for (auto& fermata : f)
		fermata.visitata = false;
	return conta;
}
	
int main()
{
	ifstream in("input.txt");
	int N, A, Mg, Mb, Mt;
	in >> N >> A >> Mg >> Mb >> Mt;
	
	vector<Fermata> fermate(N);
	vector<Strada> strade(Mg + Mb + Mt);
	
	for (int i = 0; i < N; i++) 
		fermate[i].n = i;
	for (int i = 0; i < A; i++)
	{
		int pos;
		in >> pos;
		fermate[pos].attrazione = true;
	}
	
	for (int i = 0; i < Mg; i++)
	{
		strade[i].tipo = Tipo::Gratuito;
		in >> strade[i].fermataA >> strade[i].fermataB;
	}	
	for (int i = Mg; i < Mg + Mb; i++)
	{	
		strade[i].tipo = Tipo::Bus;
		in >> strade[i].fermataA >> strade[i].fermataB;
	}
	for (int i = Mg + Mb; i < Mg + Mb + Mt; i++)
	{
		strade[i].tipo = Tipo::Traghetto;
		in >> strade[i].fermataA >> strade[i].fermataB;
	}
in.close();
	
	ofstream out("output.txt");
	out << attrazioniVisitabili(fermate, strade, Tipo::Gratuito) << '\n' 
		<< attrazioniVisitabili(fermate, strade, Tipo::Gratuito | Tipo::Bus) << '\n'
		<< attrazioniVisitabili(fermate, strade, Tipo::Gratuito | Tipo::Traghetto) << '\n'
		<< attrazioniVisitabili(fermate, strade, Tipo::Gratuito | Tipo::Bus | Tipo::Traghetto) << '\n';
	out.close();
	
	return 0;
}
