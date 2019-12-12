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

}

Commande::Commande(int identifiantCommande, Client *client, std::vector<Produit*> listeProduitsCommandes, std::vector<int> listeQuantitesProduitsCommandes)
    : identifiantCommande(identifiantCommande), clientCommande(client), listeProduitsCommandes(listeProduitsCommandes), listeQuantitesProduitsCommandes(listeQuantitesProduitsCommandes), statutLivreeCommande(false) {

}

Commande::~Commande() {

}

void Commande::initialiserClient(Client *clientCommande) {
    this->clientCommande = clientCommande;
}

void Commande::initialiserListeProduitsCommandes(std::vector<Produit *> listeProduitsCommandes) {
    this->listeProduitsCommandes = listeProduitsCommandes;
}


std::map<std::string, std::string> Commande::getMapAttributsNomAttributs() {
    std::map<std::string, std::string> mapAttributsNomAttributs;
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("identifiantCommande", "identifiantCommande"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("nomClient", "clientCommande"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("listeNomProduitsCommandes", "listeProduitsCommandes"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("listeQuantitesProduitsCommandes", "listeQuantitesProduitsCommandes"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("statutLivreeCommande", "statutLivreeCommande"));
    return mapAttributsNomAttributs;
}

void Commande::setValeurAttribut(std::string nomAttribut, std::string valeurAttribut) {
    std::map<std::string, std::string> mapAttributsNomAttributs;
    mapAttributsNomAttributs = this->getMapAttributsNomAttributs();
    std::string nomAttibutMappe = "";
    for (auto &paireAttributAttributMappe : mapAttributsNomAttributs) {
        if (paireAttributAttributMappe.second == nomAttribut) {
            nomAttibutMappe = paireAttributAttributMappe.first;
        }
    }
    if (nomAttibutMappe == "identifiantCommande") {
        this->setIdentifiantCommande(std::stoi(valeurAttribut));
    }
    else if (nomAttibutMappe == "nomClient") {
        this->nomClient = valeurAttribut;
    }
    else if (nomAttibutMappe == "listeNomProduitsCommandes") {
        std::vector<std::string> listeNomProduitsCommandes;
        std::stringstream listeNomProduitsCommandestringStream(valeurAttribut);
        std::string nomProduitCommande = "";
        while (std::getline(listeNomProduitsCommandestringStream, nomProduitCommande, ',')) {
            listeNomProduitsCommandes.push_back(nomProduitCommande);
        }
        this->listeNomProduitsCommandes = listeNomProduitsCommandes;
    }
    else if (nomAttibutMappe == "listeQuantitesProduitsCommandes") {
        std::stringstream listeQuantitesProduitsCommandesStringStream(valeurAttribut);
        std::string quantiteProduitCommande = "";
        while (std::getline(listeQuantitesProduitsCommandesStringStream, quantiteProduitCommande, ',')) {
            this->listeQuantitesProduitsCommandes.push_back(std::stoi(quantiteProduitCommande));
        }
    }
    else if (nomAttibutMappe == "statutLivreeCommande") {
        if (valeurAttribut == "true") {
            this->setStatutLivreeCommande(true);
        }
        else if (valeurAttribut == "false") {
            this->setStatutLivreeCommande(false);
        }
    }
}

std::string Commande::serializerObjet() {
    ObjetSerialized objetSerialized;
    objetSerialized.ajouterAttributString("identifiantCommande", std::to_string(this->getIdentifiantCommande()));
    objetSerialized.ajouterAttributString("clientCommande", this->getClientCommande()->getNomClient());
    std::string listeProduitsCommandesString = "";
    for (Produit *produitsSelectionnesString: this->listeProduitsCommandes) {
        listeProduitsCommandesString += produitsSelectionnesString->getTitreProduit() + ",";
    }
    if (listeProduitsCommandesString != "") {
        listeProduitsCommandesString.pop_back();
    }
    objetSerialized.ajouterAttributString("listeProduitsCommandes", listeProduitsCommandesString);
    std::string listeQuantitesProduitsCommandesString = "";
    for (int i = 0; i < this->listeQuantitesProduitsCommandes.size(); i++) {
        listeQuantitesProduitsCommandesString += std::to_string(this->listeQuantitesProduitsCommandes.at(i)) + ",";
    }
    if (listeQuantitesProduitsCommandesString != "") {
        listeQuantitesProduitsCommandesString.pop_back();
    }
    objetSerialized.ajouterAttributString("listeQuantitesProduitsCommandes", listeQuantitesProduitsCommandesString);
    std::string statutLivreeCommandeString = "false";
    if (this->statutLivreeCommande) {
        statutLivreeCommandeString = "true";
    }
    objetSerialized.ajouterAttributString("statutLivreeCommande", statutLivreeCommandeString);
    objetSerialized.serialiserLesAttributs();
    return objetSerialized.getObjetString();
}

void Commande::deserialiserObjet(ObjetSerialized objetSerialized) {
    objetSerialized.remplirMapNomAttributValeurAttribut();
    std::map<std::string, std::string> mapAttributsNomAttributsProduit = objetSerialized.getMapNomAttributValeurAttribut();
    for (auto &paireNomAttributValeurAttributProduit : mapAttributsNomAttributsProduit) {
        this->setValeurAttribut(paireNomAttributValeurAttributProduit.first, paireNomAttributValeurAttributProduit.second);
    }
}
