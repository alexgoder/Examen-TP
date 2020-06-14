/*Începând din vârful triunghiului spre bază coborând doar pe elementele adiacente, să se
calculeze suma maximă care poate fi obținută.
Pentru exemplul
3
7 4
2 4 6
8 5 9 3
ruta care ne-ar oferii suma maximă ar fi: 3 7 4 9 (3 + 7 + 4 + 9 = 23).
Se dă un triunghi de forma celui de mai sus. Să se calculeze suma maximă obținută din vârful
triunghiului până la bază.*/
#include <stdio.h>
#include <stdlib.h>
int a[200][200], sum = 0, maxim = 0,n;
int suma(int i, int j,int a[200][200],int sum)
{
		sum =sum+a[i][j];//calculeaza suma
		if (sum > maxim)//daca suma este mai mare decat maximul
			maxim = sum;//maxim ia valoarea sumei
		if (i == n)//daca linia curenta este egala cu n(numarul total de linii)
		{
			return maxim;//afiseaza maximul obtinut si iese din functie
		}
		if (j > 0)//daca indicele coloanei e mai mare decat 0
			suma(i + 1, j - 1,a,sum);//apelam functia de linia urmatoare si coloana anterioara
		suma(i + 1, j,a,sum);//apelam functia de linia urmatoare si aceeasi coloana
		suma(i + 1, j + 1,a,sum);//apelam functia de linia urmatoare si coloana din dreapta
}
int citire(FILE*f)
{
	int i = 0, j = 0;
	while (!feof(f)) //cat timp nu este sfarsitul fisierului
	{
		fscanf(f, "%d", &a[i][j]);//se citeste elementul
		if (j == i) //daca coloana este egala cu linia se trece la linia urmatoare,pana se citesc toate elemnentele matriciei stiind ca 
			//elementele de sub diagonala principala au proprietatea j<=i
		{
			i++; //trecem la urmatoarea linie
			j = 0;//incepem din nou cu coloana 0
		}
		else
		j++;//daca indicele coloanei e mai mic decat al liniei, creste indicele coloanei
	}
	return i - 1;//returneaza numarul de linii(i-1 deoarece incepem de la 0)
}
int main()
{
	FILE* g, * f;
	f = fopen("in.txt", "r");
	g = fopen("out.txt", "w");
	n=citire(f);//in variabila n se retine numarul de linii
	maxim = suma(0, 0,a,sum);//se apeleaza functia de maxim incepand de la linia 0 si coloana 0
	fprintf(g,"Suma maxima este: %d ", maxim); //afisarea sumei maxime obtinute din varf pana la baza
	fclose(f);
	fclose(g);
	return 0;
}
