/**
 * TINF21CS1, Programmieraufgabe
 * 1. Semester
 * 
 * Meine Matrikelnummer: 
 * Mein Name:
 *
 */
// System-Header-Dateien
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Eigene Header-Dateien
#include "datentypen.h"
#include "ausgaben.h"

// Prototypen

int vgl_fkt_kurs_nachname_vorname(
	const void*v1_ptr, const void*v2_ptr);
void studenten_feld_ausgeben(struct studenten_typ* feld, int feld_n, void (*ausgaben_fkt_ptr) (struct studenten_typ student));
struct studenten_typ* kopiere_studenten_auf_heap(struct studenten_typ);
int vgl_fkt_zeiger_matrikel_nr(
	const void*v1_ptr, const void*v2_ptr);
void die_Befreiungsarmee_des_Friedhofs(struct studenten_typ **studenten_array,int anzahl_der_Datenleichen);


/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	// Initialisierungsliste mit Testdaten
	struct studenten_typ studenten_feld[] = {
			{ 1000, { "Eva",	"Meier"		}, "TINF21CS1" },
			{ 1001, { "Eva",	"Meier"		}, "TINF21CS1" },
			{ 1002, { "Karla",	"Schulze"	}, "TINF21CS1" },
			{ 1003, { "Eva",	"Schlau"	}, "TINF21CS1" },
			{ 1004, { "Berta",	"Meier"		}, "TINF21CS1" },
			{ 1005, { "Tom",	"Schmitt"	}, "TINF21CS1" },
			{ 1006, { "Peter",	"Weise"		}, "TINF21CS1" },
			{ 1007, { "Max",	"Weise"		}, "TINF21CS1" },
			{ 1008, { "Anton",	"Meyer"		}, "TINF21CS1" },
			{ 1009, { "Eva",	"Meier"		}, "TINF20CS2" },
	};
	// Aufgabe 1.2
	// Anzahl der Beispieldatensaetze in "studenten_feld"
	size_t studenten_feld_n = sizeof(studenten_feld)/sizeof(studenten_feld[0]);
	// Zeiger fuer die Indizierung mit 1..n
	struct studenten_typ* studenten_feld_1_bis_n_ptr = (&(studenten_feld[-1]));
	// Zeigerfeld, das auf die im Heap liegenden Studenten-Objekte verweist
	struct studenten_typ **studenten_feld_2ptr = NULL;
	// Laufvariable
	size_t i;

	printf("Das urspruengliche Feld mit den Studenten (kurze Ausgabe):\n");
	// Aufgabe 1.7 (1/2)
	if(0)
	{
		for(i = 0; i < studenten_feld_n; i++)
			drucke_studenten_kurz_by_val(studenten_feld[i]);
		printf("\n");
	}
	else
	{
		// Aufgabe 1.7 (1/2)
		// ... studenten_feld_ausgeben(...);
		studenten_feld_ausgeben(studenten_feld, drucke_studenten_kurz_by_val, studenten_feld_n);
	}
	
	printf("Sortieren des Feldes nach dem Kurs, dem Nachnamen und dem Vornamen ...\n");
	qsort(studenten_feld, studenten_feld_n, sizeof(studenten_feld[0]),
		vgl_fkt_kurs_nachname_vorname);

	printf("Das sortierte Feld mit den Studenten (lange Ausgabe):\n");
	// Aufgabe 1.7 (2/2)
	if(0)
	{
		for(i = 0; i < studenten_feld_n; i++)
			drucke_studenten_lang_by_val(studenten_feld[i]);
		printf("\n");
	}
	else
	{
		// Aufgabe 1.7 (2/2)
		// ... studenten_feld_ausgeben(...);
		studenten_feld_ausgeben(studenten_feld, drucke_studenten_lang_by_val, studenten_feld_n);
	}
	

	printf("Nach Eva Meier (TINF21CS1) suchen...\n");
	{
		// Aufgabe 1.4
		struct studenten_typ student;
		struct studenten_typ *ergebnis_ptr = NULL;

		// Studenten-Variable mit 0 fuellen, damit keine
		//  Warnung erscheint, auch wenn Sie die Aufgabe 1.4
		//  noch nicht bearbeitet haben
		memset(&student, 0, sizeof(student));


		// student initialisieren
		//    ... Ihr Quelltext!!! ...
		strcpy(student.kurs, "TINF21CS1");

		student.matrikel_nr = 1000;

		struct namens_typ *studenten_name = (struct namens_typ*) malloc(sizeof(struct namens_typ));

		studenten_name->vorname_ptr = strdup("Eva");
		studenten_name->nachname_ptr = strdup("Meier");

		student.name = *studenten_name;

		

		
		// bsearch() aufrufen
		//    ... Ihr Quelltext!!! ...
		
		ergebnis_ptr = bsearch(&student,studenten_feld,studenten_feld_n, sizeof(studenten_feld[0]), vgl_fkt_kurs_nachname_vorname);

		
		free(studenten_name->vorname_ptr);
		free(studenten_name->nachname_ptr);
		free(studenten_name);
		// Suchergebnis auswerten
		// Aufgabe 1.5

		/*
			Es gibt offensichlicherweise 2 Personen mit dem Name Eva Meier
			Anstatt einens Pointers könnte man die Ergebnisse in einer Aufzählung speichern,
			ich würde bei diesem Beispiel eine Liste nehmen, da wir nicht die Anzahl der in bsearch
			gefundenen Ergebnisse wissen, sollten wir unsere Studenten erweitern.						(Listen sind unendlich Arrays nicht)
			Und dann kann man die Liste ausgeben.
			Bsearch sollte man deswegen hiier egtl. nicht verwenden, stattdessen sollte 
			man etwas kluegeres verwenden, da bsearch laut Manpage irgendein Element zurückgibt auf welches die Suchparameter passen.
			Dadurch dass qsort vorher verwendet wurde, kann man einfach das Array nach weiteren Einträgen dursuchen (womit auch immer)
			und die weiteren gefunden Einträge in die Ergebnissliste eintragen.
		*/


		if(ergebnis_ptr != NULL)
			printf("Die Studentin gibt es; Matrikelnummer = %d\n",
				ergebnis_ptr->matrikel_nr);
		else
			printf("Die gesuchte Studentin wurde nicht gefunden.\n");
	}
	
	printf("Das Feld in Kurzform; Ausgabefunktion erhaelt die Speicheradresse:\n");
	for(i = 0; i < studenten_feld_n; i++)
	{
		// Aufgabe 1.8 (2/2)
		// ... drucke_studenten_kurz_by_ref(...);
		drucke_studenten_kurz_by_ref(&(studenten_feld[i]));

	}
	printf("\n");

	// Aufgabe 1.9
	printf("Das Feld mit der Indizierung 1..n durchlaufen:\n");
	// studenten_feld_1_bis_n_ptr ....
	
	for(i = 1; i <= studenten_feld_n; i++)
	{
		 drucke_studenten_kurz_by_val(studenten_feld_1_bis_n_ptr[i]);
	}
	printf("\n");

	printf("Ein Feld mit Zeigern auf die Studenten-Objekte\n"
		"auf dem Heap einrichten...\n");
	studenten_feld_2ptr = (struct studenten_typ**)calloc(studenten_feld_n, sizeof(*studenten_feld_2ptr));
	if(studenten_feld_2ptr == NULL)
	{
		fprintf(stderr, "Heap voll! Datei %s, Zeile %d, Version %s %s\n",
			__FILE__, __LINE__, __DATE__, __TIME__);
		exit(EXIT_FAILURE);
	}
	
	// Aufgabe 1.10 (2/2)
	if(1)
	{
		printf("Die Studenten auf den Heap kopieren...\n");
		for(i = 0; i < studenten_feld_n; i++)
			studenten_feld_2ptr[i] = kopiere_studenten_auf_heap(studenten_feld[i]);
 

		printf("Das Feld mit den Zeigern auf die Studenten ausgeben:\n");
		for(i = 0; i < studenten_feld_n; i++)
			drucke_studenten_lang_by_val(*studenten_feld_2ptr[i]);

		// Aufgabe 1.11 (2/2)
		if(1)
		{
			printf("Das Zeigerfeld entsprechend den Matrikelnummern sortieren...\n");
			qsort(studenten_feld_2ptr, studenten_feld_n, sizeof(*studenten_feld_2ptr),
				vgl_fkt_zeiger_matrikel_nr);

			printf("Das sortierte Zeigerfeld ausgeben:\n");
			for(i = 0; i < studenten_feld_n; i++)
				drucke_studenten_lang_by_val(*studenten_feld_2ptr[i]);
		}
		die_Befreiungsarmee_des_Friedhofs(studenten_feld_2ptr,studenten_feld_n);
		free(studenten_feld_2ptr);
	}
	
	return EXIT_SUCCESS;
} // main











/**
 * Diese Vergleichsfunktion dient zum Vergleichen
 * von 2 Studentenobjekten, wobei die Adressen der
 * beiden Studenten als Parameter erwartet werden.
 * Als Vergleichskriterien dienen der Kurs, der Nachname
 * und der Vorname.
 * Parameter:
 *	v1_ptr - Adresse des 1. Studenten-Objektes.
 *	v2_ptr - Adresse des 2. Studenten-Objektes.
 * Rueckgabewert:
 *	neg. Wert --> 1. Student vor 2. Student einzusortieren.
 *	0 --> beide Studenten gleich.
 *	pos. Wert --> 1. Student nach 2. Student einzusortieren.
 */
int vgl_fkt_kurs_nachname_vorname(
	const void*v1_ptr, const void*v2_ptr)
{
	// Aufgabe 1.3
	//    ... Ihr Quelltext!!! ...
	if (v1_ptr == NULL || v2_ptr == NULL) 
	{
		exit(EXIT_FAILURE);
	}

	struct studenten_typ* studenten1_ptr = (struct studenten_typ*)v1_ptr;
	struct studenten_typ* studenten2_ptr = (struct studenten_typ*)v2_ptr;

	int compare_kurs = strcmp(studenten1_ptr->kurs, studenten2_ptr->kurs);

	if (compare_kurs != 0) 
	{
		return compare_kurs;
	}

	int compare_nachname = strcmp(studenten1_ptr->name.nachname_ptr, studenten2_ptr->name.nachname_ptr);

	if (compare_nachname != 0) {
		return compare_nachname;
	}

	return strcmp(studenten1_ptr->name.vorname_ptr,studenten2_ptr->name.vorname_ptr);
} // vgl_fkt_kurs_nachname_vorname


/**
 * Diese Funktion gibt ein Feld mit Studenten aus,
 * wobei die Ausgabe nicht direkt erfolgt, sondern
 * mittels einer Callback-Funktion. Diese ermoeglicht
 * es, die Form der Ausgabe weitgehend frei einstellen
 * zu koennen.
 * Parameter:
 *	feld - Anfangsadresse des Feldes mit den Studenten.
 *	feld_n - Anzahl der Feldelemente.
 *	ausgabe_fkt_ptr - Einsprungadresse der aktuell
 *		gewuenschten Callback-Funktion fuer die
 *		Ausgabe eines Studenten.
 * Rueckgabewert:
 *	Keiner!
 */
// Aufgabe 1.6
// ... studenten_feld_ausgeben(... feld, ... feld_n, 
//						...ausgabe_fkt_ptr...)
// {
//  
// } // studenten_feld_ausgeben
void studenten_feld_ausgeben(struct studenten_typ *feld,  void (*ausgaben_fkt_ptr) (struct studenten_typ student), int feld_n)
{
	if (feld == NULL || feld_n < 0 || ausgaben_fkt_ptr == NULL) 
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < feld_n; i++)
	{
		ausgaben_fkt_ptr(feld[i]);
	}
}// studenten feld ausgeben


/**
 * Aufgabe 1.10 (1/2)
 *
 * Diese Funktion kopiert einen Studentendatensatz,
 * der mittels call-by-value uebergeben wird, auf 
 * den Heap, wobei auch der Vor- und Nachname als
 * neue Objekte angelegt werden.
 * Parameter:
 *  student - Auf den Heap zu kopierender Student; wird
 *		mittels call-by-value uebergeben.
 * Rueckgabewert:
 *	Adresse des Studenten-Objektes auf dem Heap.
 */
struct studenten_typ* kopiere_studenten_auf_heap(struct studenten_typ student)
{
	struct studenten_typ *student_auf_heap = (struct student_typ*) malloc(sizeof(student));
	struct namens_typ namen_auf_heap;
	

	if (student_auf_heap == NULL) {
		fprintf(stderr, "Heap voll! Datei %s, Zeile %d, Version %s %s\n",
			__FILE__, __LINE__, __DATE__, __TIME__);
		exit(EXIT_FAILURE);
	}

	student_auf_heap->matrikel_nr = student.matrikel_nr;
	strcpy(student_auf_heap->kurs, student.kurs);
	namen_auf_heap.nachname_ptr = strdup(student.name.nachname_ptr);
	namen_auf_heap.vorname_ptr = strdup(student.name.vorname_ptr);
	
	student_auf_heap->name = namen_auf_heap;

	return student_auf_heap;
} // kopiere_studenten_auf_heap


/**
 * Diese Vergleichsfunktion dient zum Vergleichen
 * von 2 Studentenobjekten, wobei die Adressen der
 * Adressen der beiden Studenten als Parameter
 * erwartet werden.
 * Als Vergleichskriterium dient die Matrikelnummer.
 * Parameter:
 *	v1_ptr - Adresse der Adresse des 1. Studenten-Objektes.
 *	v2_ptr - Adresse der Adresse des 2. Studenten-Objektes.
 * Rueckgabewert:
 *	neg. Wert --> 1. Student vor 2. Student einzusortieren.
 *	0 --> beide Studenten gleich.
 *	pos. Wert --> 1. Student nach 2. Student einzusortieren.
 */
int vgl_fkt_zeiger_matrikel_nr(const void*v1_ptr, const void*v2_ptr)
{
	// Aufgabe 1.11 (1/2)
	//    ... Ihr Quelltext!!! ...
	if (v1_ptr == NULL || v2_ptr == NULL) {
		exit(EXIT_FAILURE);
	}

	struct studenten_typ* studenten1_ptr = *(struct studententyp**)v1_ptr;
	struct studenten_typ* studenten2_ptr = *(struct studententyp**)v2_ptr;

	int matrikel_Nummer1 = studenten1_ptr->matrikel_nr;
	int matrikel_Nummer2 = studenten2_ptr->matrikel_nr;
	

	return matrikel_Nummer1 - matrikel_Nummer2;
} // vgl_fkt_zeiger_matrikel_nr

void die_Befreiungsarmee_des_Friedhofs(struct studenten_typ **studenten_array, int anzahl_der_Datenleichen) 
{
	while (anzahl_der_Datenleichen != 0) 
	{
		for (int i = 0; i < anzahl_der_Datenleichen; i++)
		{
			struct studenten_typ *student = studenten_array[i];
			free(student->name.vorname_ptr);
			free(student->name.nachname_ptr);
			free(student);
		}



		anzahl_der_Datenleichen = 0;
	}
}

