#include "ausgaben.h"

/**
 * Diese Funktion gibt einen Studenten aus,
 * dessen Anfangsadresse uebergeben wird.
 * Das Format der Ausgabe entspricht genau
 * demjenigen, das die Funktion
 * "drucke_studenten_kurz_by_val()"
 * verwendet; z.B.: Lang, Olga;
 * Parameter:
 *	student_ptr - Adresse des auszugebenden
 *		Studenten
 * Rueckgabewert:
 *	Keiner!
 */
 // Aufgabe 1.8 (1/2)
 // ... drucke_studenten_kurz_by_ref(... student_ptr)
 // {
 //    ... Ihr Quelltext!!! ...
 // } // drucke_studenten_kurz_by_ref
void drucke_studenten_kurz_by_ref(struct studenten_typ* student_ptr)
{
	printf("%s, %s;  ",
		student_ptr->name.nachname_ptr,
		student_ptr->name.vorname_ptr);
}


/**
 * Diese Funktion gibt den Nach- und Vornamen
 * einen Studenten aus, der mittels Call-by-value
 * uebergeben wird.
 * Beispiel fuer das Format: Lang, Olga;
 * Parameter:
 *	student - Vollstaendige Kopie des auszugebenden
 *		Studenten.
 * Rueckgabewert:
 *	Keiner!
 */
void drucke_studenten_kurz_by_val(struct studenten_typ student)
{
	printf("%s, %s;  ",
		student.name.nachname_ptr,
		student.name.vorname_ptr);
} // drucke_studenten_kurz_by_val

/**
 * Diese Funktion gibt in 1 Zeile alle Daten
 * eines Studenten aus, der mittels Call-by-value
 * uebergeben wird.
 * Parameter:
 *	student - Vollstaendige Kopie des auszugebenden
 *		Studenten.
 * Rueckgabewert:
 *	Keiner!
 */
void drucke_studenten_lang_by_val(struct studenten_typ student)
{
	// Linksbuendig (Minuszeichen!) spaltenweise formatiert
	//  ausgeben
	printf("%5d  %-10s %-10s %-10s\n",
		student.matrikel_nr,
		student.name.vorname_ptr,
		student.name.nachname_ptr,
		student.kurs);
} // drucke_studenten_lang_by_val