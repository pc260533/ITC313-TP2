#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <string>



class ISerializable {

public:
    ISerializable();
    virtual ~ISerializable();
    virtual void setValeurAttribut(std::string nomAttribut, std::string valeurAttribut) = 0;
    virtual std::string serializerObjet() = 0;
    virtual void deserialiserObjet(std::string objetString) = 0;

};

#endif // ISERIALIZABLE_H
