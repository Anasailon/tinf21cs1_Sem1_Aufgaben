/**
 * Angelehnt an das Beispielprogramm "quicksrt.c" von
 * Goll S.490 (7.Aufl.).
 * 1. Semester
 * 
 * Meine Matrikelnummer: 
 * Mein Name:
 *
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>

// Prototypen
void zerlege(int teil_feld[], int startLinks, int startRechts);
void quickSort(int feld[], int n);

/**
 * Hauptprogramm
 */
int main(int argc, char*argv[])
{
	// Feld mit zu sortierenden Ganzzahlen
	int feld[] = { 7, 3, 8, 6, 9, 1, 2, 4 };
	// Anzahl der Feldelemente
	int feld_n = sizeof(feld)/sizeof(feld[0]);
	// Laufvariable
	int index;

	// Zu sortierendes Array ausgeben 
	printf("Das gegebene, unsortierte Feld:\n");
	for (index=0; index < feld_n; index++)
		printf("%i ", feld[index]);
	printf("\n\n");
	
	// Aufsteigend sortieren
	printf("Das Feld sortieren ...\n");
	quickSort(feld, feld_n);
	printf("\n");
	
	// Sortiertes Feld ausgeben 
	printf("Das sortierte Feld:\n");
	for(index = 0; index < feld_n; index++)
		printf("%i ", feld[index]);
	printf("\n");

	return EXIT_SUCCESS;
} // main


/**
 * Wrapper-Funktion von Goll.
 */
void quickSort (int feld[], int n)
{
	zerlege (feld, 0, n-1);
} // quickSort


/**
 * Rekursive Funktion von Goll.
 */
void zerlege(int teil_feld [], int startLinks, int startRechts)
{
	int i;
	int laufLinks = startLinks;
	int laufRechts = startRechts;
	int vergleichselementIndex =
		(startLinks + startRechts) / 2; /*(1)*/
	int vergleichselement = teil_feld[vergleichselementIndex];

	do /*(2)*/
	{ /* Schleife, bis laufLinks und laufRechts zusammentreffen */
		/* Suche von links groessere Elemente als */
		/* Vergleichselement (2.1)*/
		while (teil_feld[laufLinks] < vergleichselement)
			laufLinks++;
		/* Suche von rechts kleinere Elemente als */
		/* Vergleichselement (2.2)*/
		while (teil_feld[laufRechts] > vergleichselement)
			laufRechts-- ;
		if (laufLinks <= laufRechts) /* Vertauschen (2.3)*/
		{
			int zwischen = teil_feld[laufLinks];
			teil_feld[laufLinks] = teil_feld[laufRechts];
			teil_feld[laufRechts] = zwischen;
			laufLinks++; laufRechts--;
		}
	} while (laufLinks <= laufRechts); /*(2.4)*/

	/* Vorsortiertes Feld ausgeben */
	for (i = 0; i < startLinks; i++)
		printf(" ");
	for (i=startLinks; i <= startRechts; i++)
		printf("%i ", teil_feld[i]);
	printf("\n");
	/* Jetzt beide Teilfelder rekursiv gleich behandeln (3)*/
	if (startLinks < laufRechts)
		zerlege(teil_feld, startLinks, laufRechts);
	if (laufLinks < startRechts)
		zerlege(teil_feld, laufLinks, startRechts);
} // zerlege

