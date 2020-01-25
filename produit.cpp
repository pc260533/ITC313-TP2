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
    this->initialisertMapAttributsNomAttributs();
}

Produit::Produit(std::string titreProduit, std::string descriptionProduit, int quantiteDisponibleProduit, double prixUnitaire)
    : titreProduit(titreProduit), descriptionProduit(descriptionProduit), quantiteDisponibleProduit(quantiteDisponibleProduit), prixUnitaire(prixUnitaire) {
    this->initialisertMapAttributsNomAttributs();
}

Produit::~Produit() {

}

void Produit::initialisertMapAttributsNomAttributs() {
    this->ajouterEntreeMapAttributsNomAttributs("titreProduit", "titreProduit");
    this->ajouterEntreeMapAttributsNomAttributs("descriptionProduit", "descriptionProduit");
    this->ajouterEntreeMapAttributsNomAttributs("quantiteDisponibleProduit", "quantiteDisponibleProduit");
    this->ajouterEntreeMapAttributsNomAttributs("prixUnitaire", "prixUnitaire");
}

std::string Produit::serializerObjet() {
    ObjetSerialized objetSerialized;
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("titreProduit"), this->getTitreProduit());
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("descriptionProduit"), this->getDescriptionProduit());
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("quantiteDisponibleProduit"), std::to_string(this->getQuantiteDisponibleProduit()));
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("prixUnitaire"), std::to_string(this->getPrixUnitaire()));
    objetSerialized.serialiserLesAttributs();
    return objetSerialized.getObjetString();
}

void Produit::deserialiserObjet(ObjetSerialized objetSerialized) {
    objetSerialized.remplirMapNomAttributValeurAttribut();
    this->setTitreProduit(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("titreProduit")));
    this->setDescriptionProduit(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("descriptionProduit")));
    this->setQuantiteDisponibleProduit(std::stoi(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("quantiteDisponibleProduit"))));
    this->setPrixUnitaire(std::stod(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("prixUnitaire"))));
}
