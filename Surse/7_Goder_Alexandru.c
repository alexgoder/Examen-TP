/*Se dau N numere naturale (0 < N ≤ 10). Să se afișeze câte subşiruri crescătoare formate din cel puţin doi termeni reprezintă o
progresie aritmetică și care sunt acestea. Subșirurile pot fi afișate în orice ordine, câte un subșir pe o linie. */
#include<stdio.h>

int n, ct = 0, v1[10];

void progr_artm(int i, int v[], FILE* g)
{
	int j, k, ctdif, prim, secund;
	j = i + 1;//j are valoarea indicelui urmator
	while (j < n)
	{
		ctdif = 0;
		prim = v[i];//salveaza primul termen al progresiei
		secund = v[j];//salveaza al doilea termen al progresiei
		v1[ctdif] = prim;//salveaza in vectorul v1 in care retine cel mai lung sir in progresie
		ctdif++;
		v1[ctdif] = secund;
		fprintf(g, "%d %d ", prim, secund);//afiseaza primii 2 termeni ai progresiei
		for (k = j + 1; k < n; k++)
			if (v[k] - secund == secund - prim)//practic, verifica daca secund=prim+v[k]/2
			{
				prim = secund;//primul termen devine secundul
				secund = v[k];//secundul devine termenul nou pentru a compara viitoare numere
				v1[++ctdif] = secund;//se salveaza intr-un vector sirul maxim care e in progresie 
				fprintf(g, "%d ", secund);//afiseaza termenii in progresie pe masura ce e parcurs vectorul
			}
		fprintf(g, "\n");
		while (ctdif > 1)
		{
			for (k = 0; k < ctdif; k++)
				fprintf(g, "%d ", v1[k]);//in cazul in care sunt mai mult de 2 termeni in progresia, 
			fprintf(g, "\n");//se afiseaza sirul din care se elimina mereu ultimul element pana ajunge ca sirul ramas sa fie de lungime 2
			ct++;
			ctdif--;//dupa fiecare afisare scade numarul termenilor
		}
		ct++;
		j++;
	}
}

int main()
{
	int i, j, v[10];
	FILE* f, * g;
	f = fopen("pra.in.txt", "r");
	g = fopen("pra.out.txt", "w");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(f, "%d", &v[i]);//introduce numerele in vector
	for (i = 0; i < n; i++)
		progr_artm(i, v, g);//afiseaza progresia incepand de la fiecare termen
	fprintf(g, "Exista %d perechi de termeni in progresie", ct);
	fclose(f);
	fclose(g);
	return 0;
}