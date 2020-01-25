#ifndef EXCEPTIONFICHIERSAUVEGARDE_H
#define EXCEPTIONFICHIERSAUVEGARDE_H

#include <exception>



/**
 * @brief ExceptionEntreeIncorrecte est la classe représentant une exception correspondant à une erreur du fichier de sauvegarde.
 */
class ExceptionFichierSauvegarde : public std::exception {

public:
    /**
     * @brief ExceptionFichierSauvegarde : Constructeur sans paramètres.
     */
    ExceptionFichierSauvegarde();
    /**
     * @brief ~ExceptionFichierSauvegarde : Destructeur sans paramètres.
     */
    ~ExceptionFichierSauvegarde() override;

    // exception interface
public:
    /**
     * @brief what : Retourne la chaine de caractères correspondant au message de l'exception.
     * @return La chaine de caractères correspondant au message de l'exception.
     */
    const char *what() const noexcept override;

};

#endif // EXCEPTIONFICHIERSAUVEGARDE_H
