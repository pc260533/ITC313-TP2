#include "serializer.h"

Serializer::Serializer() {

}

Serializer::~Serializer() {

}

std::string Serializer::serializeObjetISerializable(ISerializable *objetISerializable) {
    std::string objetISerializableSerialize = "";
    try {
        objetISerializableSerialize = objetISerializable->serializerObjet();
    }
    catch (std::exception &exception) {
        throw ExceptionSerialization();
    }
    return objetISerializableSerialize;
}

void Serializer::deserializeObjetISerializable(std::string objetISerilizableString, ISerializable *objetISerilizable) {
    try {
        objetISerilizable->deserialiserObjet(ObjetSerialized(objetISerilizableString));
    }
    catch (std::exception &exception) {
        throw ExceptionSerialization();
    }
}
