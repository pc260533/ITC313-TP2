#include "magasin.h"

Magasin::Magasin() : compteurClients(0) {

}

Magasin::~Magasin() {
    for (Produit *produit : this->listeProduits) {
        delete produit;
    }
    for (Client *client : this->listeClients) {
        delete client;
    }
    for (Commande *commande : this->listeCommandes) {
        delete commande;
    }
}

void Magasin::ajouterProduit(Produit *produit) {
    this->listeProduits.push_back(produit);
}

void Magasin::afficherListeProduits() {
    std::cout << "La liste des produits est :" << std::endl;
    for (Produit *produit : this->listeProduits) {
        std::cout << "Le produit est : " << *produit << std::endl;
    }
}

void Magasin::affcherProduitAvecNom(std::string nomProduit) {
    std::cout << "La produit " << nomProduit << " est :" << std::endl;
    for (Produit *produit : this->listeProduits) {
        if (produit->getTitreProduit() == nomProduit) {
            std::cout << "Le produit est : " << *produit << std::endl;
        }
    }
}

void Magasin::mettreAJourQuantiteDisponibleProduitAvecNom(std::string nomProduit, int nouvelleQauntiteDisponible) {
    for (Produit *produit : this->listeProduits) {
        if (produit->getTitreProduit() == nomProduit) {
            produit->setQuantiteDisponibleProduit(nouvelleQauntiteDisponible);
        }
    }
}
