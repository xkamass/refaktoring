//1.zadanie Kamas Samuel
#include<stdio.h>
#include <stdlib.h> 
#include <string.h>

FILE* v()                                              //V
{
	FILE* f;
	char c, b[100];
	if ((f = fopen("autobazar.txt", "r")) == NULL)
		printf("subor sa nepodarilo otvorit. \n");
	while ((c = getc(f)) != EOF)
	{
		printf("meno priezvisko: ");
		printf("%c%s", c, fgets(b, 100, f));
		printf("SPZ: ");
		printf("%s", fgets(b, 100, f));
		printf("typ auta: ");
		printf("%s", fgets(b, 100, f));
		printf("cena: ");
		printf("%s", fgets(b, 100, f));
		printf("datum: ");
		printf("%s", fgets(b, 100, f));
		printf("%s", fgets(b, 100, f));
	}

	return f;
}
read_line(char* arr, FILE* f) {                        //citanie riadkov
	int c = getc(f), i = 0;
	while (c != EOF && c != '\n') {
		arr[i] = c;
		i++;
		c = getc(f);
	}
	arr[i] = '\0';
}
void o(FILE* f)                                          //O
{
	rewind(f);
	char meno[30][100], spz[30][100], typ[10][10], datum[10][10], cena[10][10], c;
	int i, j, dnes;
	int datum2[10], cena2[10];
	float odmena = 0;
	scanf("%d", &dnes);
	i = 0;
	j = 0;
	while ((c = getc(f)) != EOF)
	{
		meno[i][0] = c;
		read_line(meno[i] + 1, f);
		read_line(spz[i], f);
		read_line(typ[i], f);
		read_line(cena[i], f);
		read_line(datum[i], f);

		i++;
	}
	for (int l = 0; l <= i - 1; l++) {
		datum2[l] = atoi(datum[l]);
		cena2[l] = atoi(cena[l]);
	}
	//		printf("%ld",cena2[5]);
	for (int k = 0; k <= i - 2; k++) {
		if ((dnes - 10000) > datum2[k]) {
			if (0 == (strcmp(typ[k], "0")))
				odmena = cena2[k] * 0.051;
			if (0 == (strcmp(typ[k], "1")))
				odmena = cena2[k] * 0.023;
			printf("%s %s %.2f", meno[k], spz[k], odmena);
		}
	}
	printf("\n");
}
char* n(FILE* f, int* pocet)                                          //N
{
	rewind(f);
	char c;
	char b[100];
	char* spz;
	int i = 0, x;
	while ((c = getc(f)) != EOF)
	{
		read_line(b, f);
		x = strcmp(b, "");
		if ((c == '0' || c == '1') && (x == 0)) {
			i++;
		}
	}
	spz = (char*)malloc((i * 7) * sizeof(char));
	rewind(f);
	while ((c = getc(f)) != EOF)
	{
		fgets(b, 100, f);
		fgets(b, 8, f);
		strcat(spz, b);
		fgets(b, 100, f);
		fgets(b, 100, f);
		fgets(b, 100, f);
		fgets(b, 100, f);
		fgets(b, 100, f);

	}
	*pocet = i;
	//	printf("\n");
	//	for (int pg = 0; pg <= i*7; pg++)
	//		printf("%c", spz[pg]);
	return spz;
}
void s(char* spz, int a) {                                        //S
	for (int i = 0; i <= a - 1; i++) {
		for (int j = 0; j <= 6; j++) {
			printf("%c", spz[(i * (a - 1)) + j]);
			if (j == 1 || j == 4)
				printf(" ");
		}
		printf("\n");
	}
}
void m(char* spz, int a) {                                  //M
	int x = 0, pismeno = 0, y = 0;
	for (int i = 65; i <= 90; i++) {
		for (int j = 0; j <= (a * 7); j++) {
			if (spz[j] == i)
				x++;
		}
		if (x >= y) {
			pismeno = i;
			y = x;
		}
		x = 0;
	}
	printf("%c %d\n", pismeno, y);
}
void p(char* spz, int a) {                                  //P
	for (int i = 0; i <= a - 1; i++) {
		if ((spz[(i * (a - 1))] == spz[(i * (a - 1)) + 6]) && (spz[(i * (a - 1)) + 1] == spz[(i * (a - 1)) + 5]) && (spz[(i * (a - 1)) + 2] == spz[(i * (a - 1)) + 4])) {
			printf("%c%c", spz[(i * (a - 1))], spz[(i * (a - 1)) + 1]);
			printf("\n");
		}
	}
}
void z(char* spz, int a) {                                  //z
	int x = 0, y = 0, b[8], c = 0;
	for (int i = 0; i <= a - 1; i++) {
		for (int j = 0; j <= a - 1; j++) {
			if ((spz[i * (a - 1)] == spz[((j + i) * (a - 1))]) && (spz[(i * (a - 1)) + 1] == spz[((j + i) * (a - 1) + 1)]))
				x++;
		}
		if (x > y)
			c = 0;
		if (x >= y) {
			b[c] = i;
			y = x;
			c++;
		}
		x = 0;
	}
	for (int k = 0; k <= c; k++)
		printf("%c%c %d\n", spz[b[k] * (a - 1)], spz[b[k] * (a - 1) + 1], y);

}
int main()                                                //MAIN
{
	FILE* f;
	char* spz;
	char x;
	int i = 0;
	while (x != 'k') {
		scanf("%c", &x);
		if (x == 'v')
			f = v();
		if ((x == 'o') && (f != NULL))
			o(f);
		if ((x == 'n') && (f != NULL))
			spz = n(f, &i);
		if ((x == 's') && (i != 0))
			s(spz, i);
		if ((x == 's') && (i == 0))
			printf("Pole nie je vytvorene \n");
		if ((x == 'm') && (i != 0))
			m(spz, i);
		if ((x == 'm') && (i == 0))
			printf("Pole nie je vytvorene \n");
		if ((x == 'p') && (i != 0))
			p(spz, i);
		if ((x == 'p') && (i == 0))
			printf("Pole nie je vytvorene \n");
		if ((x == 'z') && (i != 0))
			z(spz, i);
		if ((x == 'z') && (i == 0))
			printf("Pole nie je vytvorene \n");
	}
	if (fclose(f) == EOF)
		printf("Subor sa nepodarilo uzavriet.\n");

	return 0;
}