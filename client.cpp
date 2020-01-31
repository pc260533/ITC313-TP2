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
    this->initialisertMapAttributsNomAttributs();
}

Client::Client(int identifiantClient, std::string prenomClient, std::string nomClient)
    : identifiantClient(identifiantClient), prenomClient(prenomClient), nomClient(nomClient), listeProduitsSelectionnes(std::vector<Produit*>()) {
    this->initialisertMapAttributsNomAttributs();
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

std::string Client::affichageCourt() const {
    return "Identifiant Client : " + std::to_string(this->getIdentifiantClient()) + " Prenom : " + this->getPrenomClient() + " Nom : " + this->getNomClient();
}

void Client::initialisertMapAttributsNomAttributs() {
    this->ajouterEntreeMapAttributsNomAttributs("identifiantClient", "identifiantClient");
    this->ajouterEntreeMapAttributsNomAttributs("nomClient", "nomClient");
    this->ajouterEntreeMapAttributsNomAttributs("prenomClient", "prenomClient");
    this->ajouterEntreeMapAttributsNomAttributs("listeNomProduitsSelectionnes", "listeProduitsSelectionnes");
    this->ajouterEntreeMapAttributsNomAttributs("listeQuantitesProduitsSelectionnes", "listeQuantitesProduitsSelectionnes");
}

std::string Client::serializerObjet() {
    ObjetSerialized objetSerialized;
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("identifiantClient"), std::to_string(this->getIdentifiantClient()));
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("nomClient"), this->getPrenomClient());
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("prenomClient"), this->getNomClient());
    std::string listeProduitsSelectionnesString = "";
    for (Produit *produitsSelectionnesString: this->listeProduitsSelectionnes) {
        listeProduitsSelectionnesString += produitsSelectionnesString->getTitreProduit() + ",";
    }
    if (listeProduitsSelectionnesString != "") {
        listeProduitsSelectionnesString.pop_back();
    }
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("listeNomProduitsSelectionnes"), listeProduitsSelectionnesString);
    std::string listeQuantitesProduitsSelectionnesString = "";
    for (int i = 0; i < this->listeQuantitesProduitsSelectionnes.size(); i++) {
        listeQuantitesProduitsSelectionnesString += std::to_string(this->listeQuantitesProduitsSelectionnes.at(i)) + ",";
    }
    if (listeQuantitesProduitsSelectionnesString != "") {
        listeQuantitesProduitsSelectionnesString.pop_back();
    }
    objetSerialized.ajouterAttributString(this->getMapAttributsNomAttributs().at("listeQuantitesProduitsSelectionnes"), listeQuantitesProduitsSelectionnesString);
    objetSerialized.serialiserLesAttributs();
    return objetSerialized.getObjetString();
}

void Client::deserialiserObjet(ObjetSerialized objetSerialized) {
    objetSerialized.remplirMapNomAttributValeurAttribut();
    this->setIdentifiantClient(std::stoi(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("identifiantClient"))));
    this->setPrenomClient(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("prenomClient")));
    this->setNomClient(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("nomClient")));

    std::vector<std::string> listeNomProduitsSelectionnes;
    std::stringstream listeNomProduitsSelectionnesStringStream(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("listeNomProduitsSelectionnes")));
    std::string nomProduitSelectionne = "";
    while (std::getline(listeNomProduitsSelectionnesStringStream, nomProduitSelectionne, ',')) {
        listeNomProduitsSelectionnes.push_back(nomProduitSelectionne);
    }
    this->listeNomProduitsSelectionnes = listeNomProduitsSelectionnes;

    std::stringstream llisteQuantitesProduitsSelectionnesStringStream(objetSerialized.getValeurAttribut(this->getMapAttributsNomAttributs().at("listeQuantitesProduitsSelectionnes")));
    std::string quantiteProduitSelectionne = "";
    while (std::getline(llisteQuantitesProduitsSelectionnesStringStream, quantiteProduitSelectionne, ',')) {
        this->listeQuantitesProduitsSelectionnes.push_back(std::stoi(quantiteProduitSelectionne));
    }
}
