/*Se dă o listă de poziții ale unor pioni de aceeași culoare pe o tabla de șah de 8x8 numerotată pe axa x de la “a” la “h “ si pe axa y 
de la 1 la 8. Să se afle câți dintre acești pioni sunt “protejați”. Conform regulilor de șah, un pion ‘d4’ este considerat protejat 
dacă există alt pion ‘c3’ sau ‘e3’ .*/
#include<stdio.h>
int v[64], v1[64],ct=0,n,v2[64];
void citire(FILE* f)//pentru fiecare pereche(ex: "a5"), va exista un index, cifra va fi pastrata in v1, iar corespondentul literei, in v
{
	char c,i=0,j=0;
	while (1)
	{
		c = fgetc(f);//citeste caracter cu caracter
		if (c < 'i' && c >= 'a')//daca e litera
			v[++i] = c - 'a'+1;//pune in vectorul v, cifra care corespunde literei
		if (c < '9' && c >= '1')//daca e cifra
			v1[++j] = c - '0';//o pune in v1
		if (c == EOF)
			break;
	}
	n = i;
}
void verificare(int i)
{
	int j;
	for (j = 1; j <= n; j++)
		if ((v[i] == (v[j] - 1) && v1[i] == (v1[j] - 1)) || (v[i] == (v[j] + 1) && (v1[i] == v1[j] - 1))&& v2[j]==0)//verifica daca pionul este "protejat" si daca este, creste contorul
		{
			ct++;
			v2[j]++;//pentru a nu numara de 2 ori acelasi pion daca e protejat de catre 2 pioni, creste pozitia pionului in v2
		}
}

int main()
{
	FILE* f, * g;
	int i;
	f = fopen("in.txt", "r");
	g = fopen("out.txt", "w");
	citire(f);
	for (i = 0; i < 64; i++)
		v2[i] = 0;//in vectorul v2, se retine daca pionul cu indicele i este protejat pentru ca in cazul in care e protejat de 2 pioni, sa nu fie numarati amandoi
	for (i = 1; i <= n; i++)
		verificare(i);//se verifica pentru fiecare pion daca este sau nu protejat
	fprintf(g,"%d pioni sunt protejati", ct);//se fiseaza numarul pionilor protejati
	fclose(f);
	fclose(g);
	return 0;
}