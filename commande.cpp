#include "commande.h"

int Commande::getIdentifiantCommande() const {
    return this->identifiantCommande;
}

Client* Commande::getClientCommande() const {
    return this->clientCommande;
}

void Commande::setClientCommande(Client* client) {
    this->clientCommande = client;
}

std::vector<Produit*> Commande::getListeProduitsCommandes() const {
    return this->listeProduitsCommandes;
}

void Commande::setListeProduitsCommandes(std::vector<Produit*> listeProduitsCommandes) {
    this->listeProduitsCommandes = listeProduitsCommandes;
}

std::vector<int> Commande::getListeQuantitesProduitsCommandes() const {
    return this->listeQuantitesProduitsCommandes;
}

bool Commande::getStatutLivreeCommande() const {
    return this->statutLivreeCommande;
}

void Commande::setStatutLivreeCommande(bool statutLivreeCommande) {
    this->statutLivreeCommande = statutLivreeCommande;
}

Commande::Commande() : identifiantCommande(0), clientCommande(nullptr), listeProduitsCommandes(std::vector<Produit*>()), listeQuantitesProduitsCommandes(std::vector<int>()), statutLivreeCommande(false) {

}

Commande::Commande(int identifiantCommande, Client *client, std::vector<Produit*> listeProduitsCommandes, std::vector<int> listeQuantitesProduitsCommandes)
    : identifiantCommande(identifiantCommande), clientCommande(client), listeProduitsCommandes(listeProduitsCommandes), listeQuantitesProduitsCommandes(listeQuantitesProduitsCommandes), statutLivreeCommande(false) {

}

Commande::~Commande() {

}
