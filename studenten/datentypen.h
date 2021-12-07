#pragma once
// Aufgabe 1.1
// Eigene Datentypen
#define KURS_LEN 10

/**
 * Datentyp fuer die Namen.
 */
struct namens_typ {
	char* vorname_ptr;
	char* nachname_ptr;
};

/**
 * Datentyp fuer die Studenten.
 */
struct studenten_typ {
	int matrikel_nr;
	struct namens_typ name;
	char kurs[KURS_LEN];
};

