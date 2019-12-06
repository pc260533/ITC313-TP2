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
