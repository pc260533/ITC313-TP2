#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "iserializable.h"
#include "exceptionserialization.h"

#include <string>



/**
 * @brief Serializer est la classe représentant un sériliser d'objet ISerializable.
 */
class Serializer {

public:
    /**
     * @brief Serializer : Constructeur sans paramètres.
     */
    Serializer();
    /**
     * @brief ~Serializer : Destructeur sans paramètres.
     */
    ~Serializer();
    /**
     * @brief serializeObjetISerializable : Sérialiser l'objet ISerializable.
     * @param objetISerializable : L'objet ISerializable.
     * @return L'objet ISerializable sérialisé au format string.
     */
    std::string serializeObjetISerializable(ISerializable *objetISerializable);
    /**
     * @brief deserializeObjetISerializable : Désérialiser l'objet ISerializable.
     * @param objetISerilizableString : L'objet ISerializable sérialisé au format string.
     * @param objetISerilizable : L'objet ISerilizable à initialiser avec la chaine de caractères.
     */
    void deserializeObjetISerializable(std::string objetISerilizableString, ISerializable *objetISerilizable);

};

#endif // SERIALIZER_H
