#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include "objetmapped.h"
#include "objetserialized.h"

#include <string>
#include <map>



class ISerializable : public ObjetMapped {

public:
    ISerializable();
    virtual ~ISerializable();
    virtual std::string serializerObjet() = 0;
    virtual void deserialiserObjet(ObjetSerialized objetSerialized) = 0;

};

#endif // ISERIALIZABLE_H
