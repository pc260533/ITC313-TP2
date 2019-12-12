#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "iserializable.h"

#include <string>



class Serializer {

public:
    Serializer();
    ~Serializer();
    std::string serializeObjetISerializable(ISerializable *objetISerializable);
    void deserializeObjetISerializable(std::string objetISerilizableString, ISerializable *objetISerilizable);

};

#endif // SERIALIZER_H
