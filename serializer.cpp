#include "serializer.h"

Serializer::Serializer() {

}

Serializer::~Serializer() {

}

std::string Serializer::serializeObjetISerializable(ISerializable *objetISerializable) {
    return objetISerializable->serializerObjet();
}

void Serializer::deserializeObjetISerializable(std::string objetISerilizableString, ISerializable *objetISerilizable) {
    objetISerilizable->deserialiserObjet(ObjetSerialized(objetISerilizableString));
}
