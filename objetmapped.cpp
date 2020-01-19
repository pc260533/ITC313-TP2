#include "objetmapped.h"

ObjetMapped::ObjetMapped() {

}

ObjetMapped::~ObjetMapped() {

}

std::map<std::string, std::string> ObjetMapped::getMapAttributsNomAttributs() {
    return this->mapAttributsNomAttributs;
}

void ObjetMapped::ajouterEntreeMapAttributsNomAttributs(std::string attribut, std::string nomAttribut) {
    this->mapAttributsNomAttributs.insert(std::pair<std::string, std::string>(attribut, nomAttribut));
}
