#include "client.h"

int Client::getIdentifiantClient() const {
    return this->identifiantClient;
}

void Client::setIdentifiantClient(int identifiant) {
    this->identifiantClient = identifiant;
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

std::vector<int> Client::getListeQuantitesProduitsSelectionnes() const {
    return this->listeQuantitesProduitsSelectionnes;
}

std::vector<std::string> Client::getListeNomProduitsSelectionnes() const {
    return this->listeNomProduitsSelectionnes;
}

Client::Client() : identifiantClient(0), prenomClient(""), nomClient(""), listeProduitsSelectionnes(std::vector<Produit*>()) {

}

Client::Client(int identifiantClient, std::string prenomClient, std::string nomClient)
    : identifiantClient(identifiantClient), prenomClient(prenomClient), nomClient(nomClient), listeProduitsSelectionnes(std::vector<Produit*>()) {

}

Client::~Client() {

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
    this->listeNomProduitsSelectionnes.clear();
}

void Client::validerLePanier() {
    this->listeProduitsSelectionnes.clear();
    this->listeQuantitesProduitsSelectionnes.clear();
    this->listeNomProduitsSelectionnes.clear();
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

void Client::initialiserListeProduitSelectionnes(std::vector<Produit *> listeProduitsSelectionnes) {
    this->listeProduitsSelectionnes = listeProduitsSelectionnes;
}

std::map<std::string, std::string> Client::getMapAttributsNomAttributs() {
    std::map<std::string, std::string> mapAttributsNomAttributs;
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("identifiantClient", "identifiantClient"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("nomClient", "nomClient"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("prenomClient", "prenomClient"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("listeNomProduitsSelectionnes", "listeProduitsSelectionnes"));
    mapAttributsNomAttributs.insert(std::pair<std::string, std::string>("listeQuantitesProduitsSelectionnes", "listeQuantitesProduitsSelectionnes"));
    return mapAttributsNomAttributs;
}

void Client::setValeurAttribut(std::string nomAttribut, std::string valeurAttribut) {
    std::map<std::string, std::string> mapAttributsNomAttributs;
    mapAttributsNomAttributs = this->getMapAttributsNomAttributs();
    std::string nomAttibutMappe = "";
    for (auto &paireAttributAttributMappe : mapAttributsNomAttributs) {
        if (paireAttributAttributMappe.second == nomAttribut) {
            nomAttibutMappe = paireAttributAttributMappe.first;
        }
    }
    if (nomAttibutMappe == "identifiantClient") {
        this->setIdentifiantClient(std::stoi(valeurAttribut));
    }
    else if (nomAttibutMappe == "prenomClient") {
        this->setPrenomClient(valeurAttribut);
    }
    else if (nomAttibutMappe == "nomClient") {
        this->setNomClient(valeurAttribut);
    }
    else if (nomAttibutMappe == "listeNomProduitsSelectionnes") {
        std::vector<std::string> listeNomProduitsSelectionnes;
        std::stringstream listeNomProduitsSelectionnesStringStream(valeurAttribut);
        std::string nomProduitSelectionne = "";
        while (std::getline(listeNomProduitsSelectionnesStringStream, nomProduitSelectionne, ',')) {
            listeNomProduitsSelectionnes.push_back(nomProduitSelectionne);
        }
        this->listeNomProduitsSelectionnes = listeNomProduitsSelectionnes;
    }
    else if (nomAttibutMappe == "listeQuantitesProduitsSelectionnes") {
        std::stringstream llisteQuantitesProduitsSelectionnesStringStream(valeurAttribut);
        std::string quantiteProduitSelectionne = "";
        while (std::getline(llisteQuantitesProduitsSelectionnesStringStream, quantiteProduitSelectionne, ',')) {
            this->listeQuantitesProduitsSelectionnes.push_back(std::stoi(quantiteProduitSelectionne));
        }
    }
}

std::string Client::serializerObjet() {
    ObjetSerialized objetSerialized;
    objetSerialized.ajouterAttributString("identifiantClient", std::to_string(this->getIdentifiantClient()));
    objetSerialized.ajouterAttributString("prenomClient", this->getPrenomClient());
    objetSerialized.ajouterAttributString("nomClient", this->getNomClient());
    std::string listeProduitsSelectionnesString = "";
    for (Produit *produitsSelectionnesString: this->listeProduitsSelectionnes) {
        listeProduitsSelectionnesString += produitsSelectionnesString->getTitreProduit() + ",";
    }
    if (listeProduitsSelectionnesString != "") {
        listeProduitsSelectionnesString.pop_back();
    }
    objetSerialized.ajouterAttributString("listeProduitsSelectionnes", listeProduitsSelectionnesString);
    std::string listeQuantitesProduitsSelectionnesString = "";
    for (int i = 0; i < this->listeQuantitesProduitsSelectionnes.size(); i++) {
        listeQuantitesProduitsSelectionnesString += std::to_string(this->listeQuantitesProduitsSelectionnes.at(i)) + ",";
    }
    if (listeQuantitesProduitsSelectionnesString != "") {
        listeQuantitesProduitsSelectionnesString.pop_back();
    }
    objetSerialized.ajouterAttributString("listeQuantitesProduitsSelectionnes", listeQuantitesProduitsSelectionnesString);
    objetSerialized.serialiserLesAttributs();
    return objetSerialized.getObjetString();
}

void Client::deserialiserObjet(ObjetSerialized objetSerialized) {
    objetSerialized.remplirMapNomAttributValeurAttribut();
    std::map<std::string, std::string> mapAttributsNomAttributsProduit = objetSerialized.getMapNomAttributValeurAttribut();
    for (auto &paireNomAttributValeurAttributProduit : mapAttributsNomAttributsProduit) {
        this->setValeurAttribut(paireNomAttributValeurAttributProduit.first, paireNomAttributValeurAttributProduit.second);
    }
}
