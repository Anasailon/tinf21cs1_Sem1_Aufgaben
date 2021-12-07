#pragma once
#include <stdio.h>

#include "datentypen.h"

void drucke_studenten_lang_by_val(struct studenten_typ student);
void drucke_studenten_kurz_by_val(struct studenten_typ student);
void drucke_studenten_kurz_by_ref(struct studenten_typ* student_ptr);