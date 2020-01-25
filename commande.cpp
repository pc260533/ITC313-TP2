#include "commande.h"

int Commande::getIdentifiantCommande() const {
    return this->identifiantCommande;
}

void Commande::setIdentifiantCommande(int identifiantCommande) {
    this->identifiantCommande = identifiantCommande;
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

std::string Commande::getNomClient() const {
    return this->nomClient;
}

std::vector<std::string> Commande::getListeNomProduitsCommandes() const {
    return this->listeNomProduitsCommandes;
}

Commande::Commande() : identifiantCommande(0), clientCommande(nullptr), listeProduitsCommandes(std::vector<Produit*>()), listeQuantitesProduitsCommandes(std::vector<int>()), statutLivreeCommande(false) {
    this->initialisertMapAttributsNomAttributs();
}

Commande::Commande(int identifiantCommande, Client *client, std::vector<Produit*> listeProduitsCommandes, std::vector<int> listeQuantitesProduitsCommandes)
    : identifiantCommande(identifiantCommande), clientCommande(client), listeProduitsCommandes(listeProduitsCommandes), listeQuantitesProduitsCommandes(listeQuantitesProduitsCommandes), statutLivreeCommande(false) {
    this->initialisertMapAttributsNomAttributs();
}

Commande::~Commande() {

}

void Commande::initialiserClient(Client *clientCommande) {
    this->clientCommande = clientCommande;
}

void Commande::initialiserListeProduitsCommandes(std::vector<Produit *> listeProduitsCommandes) {
    this->listeProduitsCommandes = listeProduitsCommandes;
}

void Commande::initialisertMapAttributsNomAttributs() {
    this->ajouterEntreeMapAttributsNomAttributs("identifiantCommande", "identifiantCommande");
    this->ajouterEntreeMapAttributsNomAttributs("nomClient", "clientCommande");
    this->ajouterEntreeMapAttributsNomAttributs("listeNomProduitsCommandes", "listeProduitsCommandes");
    this->ajouterEntreeMapAttributsNomAttributs("listeQuantitesProduitsCommandes", "listeQuantitesProduitsCommandes");
    this->ajouterEntreeMapAttributsNomAttributs("statutLivreeCommande", "statutLivreeCommande");
}

std::string Commande::serializerObjet() {
    ObjetSerialized objetSerialized;
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("identifiantCommande"), std::to_string(this->getIdentifiantCommande()));
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("nomClient"), this->getClientCommande()->getNomClient());
    std::string listeProduitsCommandesString = "";
    for (Produit *produitsSelectionnesString: this->listeProduitsCommandes) {
        listeProduitsCommandesString += produitsSelectionnesString->getTitreProduit() + ",";
    }
    if (listeProduitsCommandesString != "") {
        listeProduitsCommandesString.pop_back();
    }
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("listeNomProduitsCommandes"), listeProduitsCommandesString);
    std::string listeQuantitesProduitsCommandesString = "";
    for (int i = 0; i < this->listeQuantitesProduitsCommandes.size(); i++) {
        listeQuantitesProduitsCommandesString += std::to_string(this->listeQuantitesProduitsCommandes.at(i)) + ",";
    }
    if (listeQuantitesProduitsCommandesString != "") {
        listeQuantitesProduitsCommandesString.pop_back();
    }
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("listeQuantitesProduitsCommandes"), listeQuantitesProduitsCommandesString);
    std::string statutLivreeCommandeString = "false";
    if (this->statutLivreeCommande) {
        statutLivreeCommandeString = "true";
    }
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("statutLivreeCommande"), statutLivreeCommandeString);
    objetSerialized.serialiserLesAttributs();
    return objetSerialized.getObjetString();
}

void Commande::deserialiserObjet(ObjetSerialized objetSerialized) {
    objetSerialized.remplirMapNomAttributValeurAttribut();
    this->setIdentifiantCommande(std::stoi(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("identifiantCommande"))));
    this->nomClient = objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("nomClient"));

    std::vector<std::string> listeNomProduitsCommandes;
    std::stringstream listeNomProduitsCommandestringStream(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("listeNomProduitsCommandes")));
    std::string nomProduitCommande = "";
    while (std::getline(listeNomProduitsCommandestringStream, nomProduitCommande, ',')) {
        listeNomProduitsCommandes.push_back(nomProduitCommande);
    }
    this->listeNomProduitsCommandes = listeNomProduitsCommandes;

    std::stringstream listeQuantitesProduitsCommandesStringStream(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("listeQuantitesProduitsCommandes")));
    std::string quantiteProduitCommande = "";
    while (std::getline(listeQuantitesProduitsCommandesStringStream, quantiteProduitCommande, ',')) {
        this->listeQuantitesProduitsCommandes.push_back(std::stoi(quantiteProduitCommande));
    }

    std::string statutLivreeCommande = objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("statutLivreeCommande"));
    if (statutLivreeCommande == "true") {
        this->setStatutLivreeCommande(true);
    }
    else if (statutLivreeCommande == "false") {
        this->setStatutLivreeCommande(false);
    }
}
