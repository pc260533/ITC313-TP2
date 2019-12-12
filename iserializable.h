#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include "objetserialized.h"

#include <string>
#include <map>



class ISerializable {

public:
    ISerializable();
    virtual ~ISerializable();
    virtual std::map<std::string, std::string> getMapAttributsNomAttributs() = 0;
    virtual void setValeurAttribut(std::string nomAttribut, std::string valeurAttribut) = 0;
    virtual std::string serializerObjet() = 0;
    virtual void deserialiserObjet(ObjetSerialized objetSerialized) = 0;

};

#endif // ISERIALIZABLE_H
