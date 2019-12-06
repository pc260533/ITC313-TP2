#include "client.h"

int Client::getIdentifiantClient() const {
    return this->identifiantClient;
}

std::string Client::getPrenomClient() const {
    return this->prenomClient;
}

void Client::setPrenomClient(std::string prenomClient) {
    this->prenomClient = prenomClient;
}

std::string Client::getNomClient() const {
    return this->nomClient;
}

void Client::setNomClient(std::string nomClient) {
    this->nomClient = nomClient;
}

std::vector<Produit*> Client::getListeProduitsSelectionnes() const {
    return this->listeProduitsSelectionnes;
}

Client::Client() : identifiantClient(0), prenomClient(""), nomClient(""), listeProduitsSelectionnes(std::vector<Produit*>()) {

}

Client::Client(int identifiantClient, std::string prenomClient, std::string nomClient)
    : identifiantClient(identifiantClient), prenomClient(prenomClient), nomClient(nomClient), listeProduitsSelectionnes(std::vector<Produit*>()) {

}

Client::~Client() {
    // libérer les produits sélectionnés.
}

void Client::ajouterProduitAuPanier(Produit *produit) {
    this->listeProduitsSelectionnes.push_back(produit);
    this->listeQuantitesProduitsSelectionnes.push_back(1);
    produit->setQuantiteDisponibleProduit(produit->getQuantiteDisponibleProduit() - 1);
}

void Client::viderLePanier() {
    for (int i = 0; i < this->listeProduitsSelectionnes.size(); i++) {
        this->listeProduitsSelectionnes.at(i)->setQuantiteDisponibleProduit(this->listeProduitsSelectionnes.at(i)->getQuantiteDisponibleProduit() + this->listeQuantitesProduitsSelectionnes.at(i));
    }
    this->listeProduitsSelectionnes.clear();
    this->listeQuantitesProduitsSelectionnes.clear();
}

void Client::modifierQuantiteProduitSelectionne(std::string nomProduit, int nombreDeProduits) {
    if (nombreDeProduits > 0) {
        for (int i = 0; i < this->listeProduitsSelectionnes.size(); i++) {
            if (this->listeProduitsSelectionnes.at(i)->getTitreProduit() == nomProduit) {
                if (this->listeProduitsSelectionnes.at(i)->getQuantiteDisponibleProduit() != 0) {
                    if ((this->listeProduitsSelectionnes.at(i)->getQuantiteDisponibleProduit() < nombreDeProduits - this->listeQuantitesProduitsSelectionnes.at(i))) {
                        this->listeQuantitesProduitsSelectionnes.at(i) = this->listeProduitsSelectionnes.at(i)->getQuantiteDisponibleProduit() + this->listeQuantitesProduitsSelectionnes.at(i);
                    }
                    else {
                        this->listeProduitsSelectionnes.at(i)->setQuantiteDisponibleProduit(this->listeProduitsSelectionnes.at(i)->getQuantiteDisponibleProduit() - nombreDeProduits + this->listeQuantitesProduitsSelectionnes.at(i));
                        this->listeQuantitesProduitsSelectionnes.at(i) = nombreDeProduits;
                    }
                }
            }
        }
    }
}

void Client::supprimerProduit(std::string nomProduit) {
    for (int i = 0; i < this->listeProduitsSelectionnes.size(); i++) {
        if (this->listeProduitsSelectionnes.at(i)->getTitreProduit() == nomProduit) {
            this->listeProduitsSelectionnes.at(i)->setQuantiteDisponibleProduit(this->listeProduitsSelectionnes.at(i)->getQuantiteDisponibleProduit() + this->listeQuantitesProduitsSelectionnes.at(i));
            this->listeProduitsSelectionnes.erase(this->listeProduitsSelectionnes.begin() + i);
            this->listeQuantitesProduitsSelectionnes.erase(this->listeQuantitesProduitsSelectionnes.begin() + i);
        }
    }
}
