#include "commande.h"

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

bool Commande::getStatutLivreeCommande() const {
    return this->statutLivreeCommande;
}

void Commande::setStatutLivreeCommande(bool statutLivreeCommande) {
    this->statutLivreeCommande = statutLivreeCommande;
}

Commande::Commande() : clientCommande(nullptr), listeProduitsCommandes(std::vector<Produit*>()), statutLivreeCommande(false) {

}

Commande::Commande(Client *client, std::vector<Produit*> listeProduitsCommandes) : clientCommande(client), listeProduitsCommandes(listeProduitsCommandes), statutLivreeCommande(false) {

}

Commande::~Commande() {

}
