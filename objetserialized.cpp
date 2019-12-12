#include "objetserialized.h"

std::string ObjetSerialized::getObjetString() const {
    return this->objetString;
}

void ObjetSerialized::setObjetString(std::string objetString) {
    this->objetString = objetString;
}

std::map<std::string, std::string> ObjetSerialized::getMapNomAttributValeurAttribut() {
    return this->mapNomAttributValeurAttribut;
}

ObjetSerialized::ObjetSerialized() : objetString(""), mapNomAttributValeurAttribut(std::map<std::string, std::string>()) {

}

ObjetSerialized::ObjetSerialized(std::string objetString) : objetString(objetString), mapNomAttributValeurAttribut(std::map<std::string, std::string>()) {

}

ObjetSerialized::~ObjetSerialized() {

}

void ObjetSerialized::remplirMapNomAttributValeurAttribut() {
    std::vector<std::string> listeAttributsValeurs;
    std::stringstream objetStringStream(objetString);
    std::string attributValeur = "";
    while (std::getline(objetStringStream, attributValeur, '\n')) {
        listeAttributsValeurs.push_back(attributValeur);
    }
    for (int i = 0; i < listeAttributsValeurs.size(); i++) {
        int positionCaractereDeuxPoints = listeAttributsValeurs.at(i).find_first_of(":");
        std::string nomAttribut = listeAttributsValeurs.at(i).substr(0, positionCaractereDeuxPoints);
        std::string valeurAttribut = listeAttributsValeurs.at(i).substr(positionCaractereDeuxPoints + 1);
        this->mapNomAttributValeurAttribut.insert(std::pair<std::string, std::string>(nomAttribut, valeurAttribut));
    }
}

std::string ObjetSerialized::getValeurAttribut(std::string nomAttribut) {
    return this->mapNomAttributValeurAttribut.at(nomAttribut);
}

void ObjetSerialized::ajouterAttributString(std::string nomAttribut, std::string valeurAttribut) {
    this->mapNomAttributValeurAttribut.insert(std::pair<std::string, std::string>(nomAttribut, valeurAttribut));
}

void ObjetSerialized::serialiserLesAttributs() {
    for (auto &paireNomAttributValeurAttribut : this->mapNomAttributValeurAttribut) {
        this->objetString += paireNomAttributValeurAttribut.first + ":" + paireNomAttributValeurAttribut.second + "\n";
    }
}

std::vector<std::string> ObjetSerialized::getObjetStringEncapsule(std::string nomEncapsulation) {
    std::vector<std::string> listeObjetsStringEncapsule;
    std::stringstream objetStringStream(objetString);
    std::string objetStringLigne = "";
    bool quit = false;
    bool objetDuBonType = false;
    std::string sousObjetString = "";
    while (!quit) {
        if (!std::getline(objetStringStream, objetStringLigne, '\n')) {
            quit = true;
        }
        else {
            if (objetStringLigne == "_" + nomEncapsulation) {
                objetDuBonType = false;
                sousObjetString.pop_back();
                listeObjetsStringEncapsule.push_back(sousObjetString);
                sousObjetString = "";
            }
            if (objetDuBonType) {
                sousObjetString += objetStringLigne + "\n";
            }
            if (objetStringLigne == nomEncapsulation) {
                objetDuBonType = true;
            }

        }
    }
    return listeObjetsStringEncapsule;
}
