#include "magasin.h"

Produit *Magasin::getProduitAvecNomProduit(std::string nomProduit) {
    Produit *res = nullptr;
    for (Produit *produit : this->listeProduits) {
        if (produit->getTitreProduit() == nomProduit) {
            res = produit;
        }
    }
    return res;
}

Client *Magasin::getClientAvecNomClient(std::string nomClient) {
    Client *res = nullptr;
    for (Client *client : this->listeClients) {
        if (client->getNomClient() == nomClient) {
            res = client;
        }
    }
    return res;
}

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
    std::cout << "Le produit " << nomProduit << " est :" << std::endl;
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

void Magasin::ajouterClient(std::string nomClient, std::string prenomClient) {
    this->listeClients.push_back(new Client(this->compteurClients, prenomClient, nomClient));
    this->compteurClients++;
}

void Magasin::afficherListeClients() {
    std::cout << "La liste des clients est :" << std::endl;
    for (Client *client : this->listeClients) {
        std::cout << "Le client est : " << *client << std::endl;
    }
}

void Magasin::afficherClient(std::string nomClient) {
    std::cout << "Les clients dont le nom est " << nomClient << " est :" << std::endl;
    for (Client *client : this->listeClients) {
        if (client->getNomClient() == nomClient) {
            std::cout << "Le client est : " << *client << std::endl;
        }
    }
}

void Magasin::afficherClient(int identifiantClient) {
    std::cout << "Les clients dont l'identifiant est " << std::to_string(identifiantClient) << " est :" << std::endl;
    for (Client *client : this->listeClients) {
        if (client->getIdentifiantClient() == identifiantClient) {
            std::cout << "Le client est : " << *client << std::endl;
        }
    }
}

void Magasin::ajouterProduitDansPanierClient(std::string nomProduit, std::string nomClient) {
    Client *client = this->getClientAvecNomClient(nomClient);
    if (client) {
        client->ajouterProduitAuPanier(this->getProduitAvecNomProduit(nomProduit));
    }
}

void Magasin::supprimerProduitDansPanierClient(std::string nomProduit, std::string nomClient) {
    Client *client = this->getClientAvecNomClient(nomClient);
    if (client) {
        client->supprimerProduit(nomProduit);
    }
}

void Magasin::modifierQuantiteProduitDansPanierClient(std::string nomProduit, int nouvelleQuantiteProduit, std::string nomClient) {
    Client *client = this->getClientAvecNomClient(nomClient);
    if (client) {
        client->modifierQuantiteProduitSelectionne(nomProduit, nouvelleQuantiteProduit);
    }
}
