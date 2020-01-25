#include "exceptionfichiersauvegarde.h"

ExceptionFichierSauvegarde::ExceptionFichierSauvegarde() {

}

ExceptionFichierSauvegarde::~ExceptionFichierSauvegarde() {

}

const char *ExceptionFichierSauvegarde::what() const noexcept {
    return "Fichier de sauvegarde inaccessible ou inexistant.";
}
