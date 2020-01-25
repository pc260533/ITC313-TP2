#ifndef EXCEPTIONENTREEINCORRECTE_H
#define EXCEPTIONENTREEINCORRECTE_H

#include <exception>



/**
 * @brief ExceptionEntreeIncorrecte est la classe représentant une exception correspondant à une entrée incorrecte de l'utilisateur.
 */
class ExceptionEntreeIncorrecte : public std::exception {

public:
    /**
     * @brief ExceptionEntreeIncorrecte : Constructeur sans paramètres.
     */
    ExceptionEntreeIncorrecte();
    /**
     * @brief ~ExceptionEntreeIncorrecte : Destructeur sans paramètres.
     */
    ~ExceptionEntreeIncorrecte() override;

    // exception interface
public:
    /**
     * @brief what : Retourne la chaine de caractères correspondant au message de l'exception.
     * @return La chaine de caractères correspondant au message de l'exception.
     */
    const char *what() const noexcept override;

};

#endif // EXCEPTIONENTREEINCORRECTE_H
