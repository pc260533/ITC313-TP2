#include "produit.h"

std::string Produit::getTitreProduit() const {
    return this->titreProduit;
}

void Produit::setTitreProduit(std::string titreProduit) {
    this->titreProduit = titreProduit;
}

std::string Produit::getDescriptionProduit() const {
    return this->descriptionProduit;
}

void Produit::setDescriptionProduit(std::string descriptionProduit) {
    this->descriptionProduit = descriptionProduit;
}

int Produit::getQuantiteDisponibleProduit() const {
    return this->quantiteDisponibleProduit;
}

void Produit::setQuantiteDisponibleProduit(int quantiteDisponibleProduit) {
    this->quantiteDisponibleProduit = quantiteDisponibleProduit;
}

double Produit::getPrixUnitaire() const {
    return this->prixUnitaire;
}

void Produit::setPrixUnitaire(double prixUnitaire) {
    this->prixUnitaire = prixUnitaire;
}

Produit::Produit() : titreProduit(""), descriptionProduit(""), quantiteDisponibleProduit(0), prixUnitaire(0.0) {
    
}

Produit::Produit(std::string titreProduit, std::string descriptionProduit, int quantiteDisponibleProduit, double prixUnitaire)
    : titreProduit(titreProduit), descriptionProduit(descriptionProduit), quantiteDisponibleProduit(quantiteDisponibleProduit), prixUnitaire(prixUnitaire) {

}

std::map<std::string, std::string> Produit::getMapAttributsNomAttributs() {
    std::map<std::string, std::string> mapAttributsNomAttributs;
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("titreProduit", "titreProduit"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("descriptionProduit", "descriptionProduit"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("quantiteDisponibleProduit", "quantiteDisponibleProduit"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("prixUnitaire", "prixUnitaire"));
    return mapAttributsNomAttributs;
}

void Produit::setValeurAttribut(std::string nomAttribut, std::string valeurAttribut) {
    std::map<std::string, std::string> mapAttributsNomAttributs;
    mapAttributsNomAttributs = this->getMapAttributsNomAttributs();
    std::string nomAttibutMappe = "";
    for (auto &paireAttributAttributMappe : mapAttributsNomAttributs) {
        if (paireAttributAttributMappe.second == nomAttribut) {
            nomAttibutMappe = paireAttributAttributMappe.first;
        }
    }
    if (nomAttibutMappe == "titreProduit") {
        this->setTitreProduit(valeurAttribut);
    }
    else if (nomAttibutMappe == "descriptionProduit") {
        this->setDescriptionProduit(valeurAttribut);
    }
    else if (nomAttibutMappe == "quantiteDisponibleProduit") {
        this->setQuantiteDisponibleProduit(std::stoi(valeurAttribut));
    }
    else if (nomAttibutMappe == "prixUnitaire") {
        this->setPrixUnitaire(std::stod(valeurAttribut));
    }
}

std::string Produit::serializerObjet() {
    ObjetSerialized objetSerialized;
    objetSerialized.ajouterAttributString("titreProduit", this->getTitreProduit());
    objetSerialized.ajouterAttributString("descriptionProduit", this->getDescriptionProduit());
    objetSerialized.ajouterAttributString("quantiteDisponibleProduit", std::to_string(this->getQuantiteDisponibleProduit()));
    objetSerialized.ajouterAttributString("prixUnitaire", std::to_string(this->getPrixUnitaire()));
    objetSerialized.serialiserLesAttributs();
    return objetSerialized.getObjetString();
}

void Produit::deserialiserObjet(ObjetSerialized objetSerialized) {
    objetSerialized.remplirMapNomAttributValeurAttribut();
    std::map<std::string, std::string> mapAttributsNomAttributsProduit = objetSerialized.getMapNomAttributValeurAttribut();
    for (auto &paireNomAttributValeurAttributProduit : mapAttributsNomAttributsProduit) {
        this->setValeurAttribut(paireNomAttributValeurAttributProduit.first, paireNomAttributValeurAttributProduit.second);
    }
}
