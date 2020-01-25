#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include "objetmapped.h"
#include "objetserialized.h"

#include <string>
#include <map>



/**
 * @brief ISerializable est une interface représentant les fonctionnalités d'un objet sérialisable.
 * Elle hérite de ObjetMapped.
 */
class ISerializable : public ObjetMapped {

public:
    /**
     * @brief ISerializable : Constructeur sans paramètres.
     */
    ISerializable();
    /**
     * @brief ~ISerializable : Destructeur sans paramètres.
     */
    virtual ~ISerializable();
    /**
     * @brief serializerObjet : Sérialiser le ISerializable.
     * @return Le ISerializable sérialiser au format string.
     */
    virtual std::string serializerObjet() = 0;
    /**
     * @brief deserialiserObjet : Désérialiser le ISerializable.
     * @param objetSerialized : Le objectSerialized représente le ISerializable désérialisé.
     */
    virtual void deserialiserObjet(ObjetSerialized objetSerialized) = 0;

};

#endif // ISERIALIZABLE_H
