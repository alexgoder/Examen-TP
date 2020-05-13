#include<stdio.h>
int n, cuv[5000], lung = 0,maxim;

void citire(FILE* f)
{
	int i = 0;
	fscanf(f, "%d", &n);//citeste numarul de cuvinte
	while (i<n)
	{
		fscanf(f, "%d", &cuv[i]);
		lung = lung + cuv[i];//dupa citirea fiecarui cuvant, il adauga la lung, reprezentand lungimea maxima
		if (cuv[i] > maxim)//verifica daca valoarea citita este mai mare decat cea existenta pana in acel moment, iar daca e, maxim se modifica
			maxim = cuv[i];
		i++;
	}
}

int verif_prim(int n)
{
	int d,ct=0;
	for (d = 2; d < n / 2; d++)//genereaza numere
		if (n % d == 0)//verifica daca are divizori
			ct++;//daca are divizori, ii numara
	return ct;//returneaza numarul de divizori
}

int verificare(int rand,FILE *g)
{
	int i, sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = sum + cuv[i];//calculeaza suma 
		if (sum == rand)
			sum = 0;//daca suma este egala cu divizorul, atunci reseteaza suma la 0
		if (sum > rand)//daca suma este mai mare decat divizorul, creste divizorul, suma este 0 si reincepe verificarea
		{ 
			rand++;
			i = -1;//dupa ce va face i++, i va deveni 0 si se va repeta operatiunea de la inceput
			sum = 0;//suma este resetata la 0
		}
	}
	if (sum == 0 && rand <= lung)//daca dupa ce e parcurs vectorul, ultima suma e 0 si divizorul e mai mic decat lungimea sirului
		fprintf(g, "Numarul maxim de cuvinte ce se pot pune pe un rand este: %d", rand);
	else
		fprintf(g, "Nu se pot aranja cuvintele pe randuri de lungimi egale");
}


int main()
{
	FILE* f, * g;
	f = fopen("cuv.in.txt", "r");
	g = fopen("cuv.out.txt", "w");
	citire(f);
	if (verif_prim(n))//verifica daca numarul divizorilor e 0, insemna ca lungimea totala e prima
	fprintf(g, "Numarul total de litere este prim, deci nu se pot aranja cuvintele pe randuri de lungimi egale");
	else
	verificare(maxim,g);//verifica daca se pot scrie cuvintele pe randuri de lungime egala, cea mai mica lungime verificata fiind lungimea maxima
	fclose(f);
	fclose(g);
	return 0;
}
