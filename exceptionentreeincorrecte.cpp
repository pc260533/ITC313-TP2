#include "exceptionentreeincorrecte.h"

ExceptionEntreeIncorrecte::ExceptionEntreeIncorrecte() {

}

ExceptionEntreeIncorrecte::~ExceptionEntreeIncorrecte() {

}

const char *ExceptionEntreeIncorrecte::what() const noexcept {
    return "Entree non correcte.";
}
