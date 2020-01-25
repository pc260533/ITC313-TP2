#ifndef EXCEPTIONSERIALIZATION_H
#define EXCEPTIONSERIALIZATION_H

#include <exception>



/**
 * @brief ExceptionSerialization est la classe représentant une exception correspondant à une erreur de sérialization.
 */
class ExceptionSerialization : public std::exception {

public:
    /**
     * @brief ExceptionSerialization : Constructeur sans paramètres.
     */
    ExceptionSerialization();
    /**
     * @brief ~ExceptionSerialization : Destructeur sans paramètres.
     */
    ~ExceptionSerialization() override;

    // exception interface
public:
    /**
     * @brief what : Retourne la chaine de caractères correspondant au message de l'exception.
     * @return La chaine de caractères correspondant au message de l'exception.
     */
    const char *what() const noexcept override;

};

#endif // EXCEPTIONSERIALIZATION_H
