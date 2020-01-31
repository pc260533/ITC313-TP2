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

Client *Magasin::getClientAvecNomPrenomClient(std::string nomClient, std::string prenomClient) {
    Client *res = nullptr;
    for (Client *client : this->listeClients) {
        if ((client->getNomClient() == nomClient) && (client->getPrenomClient() == prenomClient)) {
            res = client;
        }
    }
    return res;
}

Commande *Magasin::getCommandeAvecIdentifiantCommande(int identifiantCommande) {
    Commande *res = nullptr;
    for (Commande *commande : this->listeCommandes) {
        if (commande->getIdentifiantCommande() == identifiantCommande) {
            res = commande;
        }
    }
    return res;
}

Magasin::Magasin()
    : listeProduits(std::vector<Produit*>()), listeClients(std::vector<Client*>()), listeCommandes(std::vector<Commande*>()), compteurClients(0), compteurCommandes(0) {
    this->initialisertMapAttributsNomAttributs();
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

void Magasin::ajouterProduit(std::string titreProduit, std::string descriptionProduit, int quantiteDisponibleProduit, double prixUnitaireProduit) {
    this->listeProduits.push_back(new Produit(titreProduit, descriptionProduit, quantiteDisponibleProduit, prixUnitaireProduit));
}

void Magasin::afficherListeProduits() {
    std::cout << "La liste des produits est :" << std::endl;
    for (Produit *produit : this->listeProduits) {
        std::cout << "Le produit est : " << std::endl << *produit << std::endl;
    }
}

void Magasin::afficherProduitAvecNom(std::string nomProduit) {
    std::cout << "Le produit " << nomProduit << " est :" << std::endl;
    for (Produit *produit : this->listeProduits) {
        if (produit->getTitreProduit() == nomProduit) {
            std::cout << "Le produit est : " << std::endl << *produit << std::endl;
        }
    }
}

void Magasin::mettreAJourQuantiteDisponibleProduitAvecNom(std::string nomProduit, int nouvelleQuantiteDisponible) {
    for (Produit *produit : this->listeProduits) {
        if (produit->getTitreProduit() == nomProduit) {
            produit->setQuantiteDisponibleProduit(nouvelleQuantiteDisponible);
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
        std::cout << "Le client est : " << std::endl << *client << std::endl;
    }
}

void Magasin::afficherClient(std::string nomClient, std::string prenomClient) {
    std::cout << "Les clients dont le nom est " << nomClient << " est :" << std::endl;
    for (Client *client : this->listeClients) {
        if ((client->getNomClient() == nomClient) && (client->getPrenomClient() == prenomClient)) {
            std::cout << "Le client est : " << std::endl << *client << std::endl;
        }
    }
}

void Magasin::afficherClient(int identifiantClient) {
    std::cout << "Les clients dont l'identifiant est " << std::to_string(identifiantClient) << " est :" << std::endl;
    for (Client *client : this->listeClients) {
        if (client->getIdentifiantClient() == identifiantClient) {
            std::cout << "Le client est : " << std::endl << *client << std::endl;
        }
    }
}

void Magasin::ajouterProduitDansPanierClient(std::string nomProduit, std::string nomClient, std::string prenomClient) {
    Client *client = this->getClientAvecNomPrenomClient(nomClient, prenomClient);
    if (client) {
        client->ajouterProduitAuPanier(this->getProduitAvecNomProduit(nomProduit));
    }
}

void Magasin::supprimerProduitDansPanierClient(std::string nomProduit, std::string nomClient, std::string prenomClient) {
    Client *client = this->getClientAvecNomPrenomClient(nomClient, prenomClient);
    if (client) {
        client->supprimerProduit(nomProduit);
    }
}

void Magasin::modifierQuantiteProduitDansPanierClient(std::string nomProduit, int nouvelleQuantiteProduit, std::string nomClient, std::string prenomClient) {
    Client *client = this->getClientAvecNomPrenomClient(nomClient, prenomClient);
    if (client) {
        client->modifierQuantiteProduitSelectionne(nomProduit, nouvelleQuantiteProduit);
    }
}

void Magasin::validerCommandeDUnClient(std::string nomClient, std::string prenomClient) {
    Client *client = this->getClientAvecNomPrenomClient(nomClient, prenomClient);
    if (client) {
        if (!client->getListeProduitsSelectionnes().empty()) {
            this->listeCommandes.push_back(new Commande(this->compteurCommandes, client, client->getListeProduitsSelectionnes(), client->getListeQuantitesProduitsSelectionnes()));
            client->validerLePanier();
            this->compteurCommandes++;
        }
    }
}

void Magasin::mettreAJourStatutCommande(int identifiantCommande) {
    Commande* commande = this->getCommandeAvecIdentifiantCommande(identifiantCommande);
    if (commande) {
        commande->setStatutLivreeCommande(true);
    }
}

void Magasin::afficherListeCommandes() {
    std::cout << "La liste des commandes est :" << std::endl;
    for (Commande *commande : this->listeCommandes) {
        std::cout << "La commande est : " << std::endl << *commande << std::endl;
    }
}

void Magasin::afficherCommandeAvecNom(std::string nomClient, std::string prenomClient) {
    std::cout << "La liste des commandes dont le nom du client est " << nomClient << " est :" << std::endl;
    for (Commande *commande : this->listeCommandes) {
        if (commande->getClientCommande()->getNomClient() == nomClient) {
            std::cout << "La commande est : " << std::endl << *commande << std::endl;
        }
    }
}

void Magasin::initialiserPanierClient(Client *client) {
    std::vector<Produit*> listeProduitsSelectionnesParLeClient;
    for (int i = 0; i < client->getListeNomProduitsSelectionnes().size(); i++) {
        Produit *produit = this->getProduitAvecNomProduit(client->getListeNomProduitsSelectionnes().at(i));
        if (produit) {
            listeProduitsSelectionnesParLeClient.push_back(produit);
        }
        client->initialiserListeProduitSelectionnes(listeProduitsSelectionnesParLeClient);
    }
}

void Magasin::initialiserClientEtListeProduitsCommandesCommande(Commande *commande) {
    Client *clientCommande = this->getClientAvecNomPrenomClient(commande->getNomClient(), commande->getPrenomClient());
    std::vector<Produit*> listeProduitsCommandesParLeClient;
    if (clientCommande) {
        commande->initialiserClient(clientCommande);
    }
    for (int i = 0; i < commande->getListeNomProduitsCommandes().size(); i++) {
        Produit *produit = this->getProduitAvecNomProduit(commande->getListeNomProduitsCommandes().at(i));
        if (produit) {
            listeProduitsCommandesParLeClient.push_back(produit);
        }
        commande->initialiserListeProduitsCommandes(listeProduitsCommandesParLeClient);
    }
}

void Magasin::initialiserCompteurClient() {
    int maximumIdentifiantClient = 0;
    for (Client *client : this->listeClients) {
        if (maximumIdentifiantClient < client->getIdentifiantClient()) {
            maximumIdentifiantClient = client->getIdentifiantClient();
        }
    }
    this->compteurClients = maximumIdentifiantClient + 1;
}

void Magasin::initialiserCompteurCommande() {
    int maximumIdentifiantCommande = 0;
    for (Commande *commande : this->listeCommandes) {
        if (maximumIdentifiantCommande < commande->getIdentifiantCommande()) {
            maximumIdentifiantCommande = commande->getIdentifiantCommande();
        }
    }
    this->compteurCommandes = maximumIdentifiantCommande + 1;
}

void Magasin::initialisertMapAttributsNomAttributs() {

}

std::string Magasin::serializerObjet() {
    std::string res = "";
    for (Produit *produit : this->listeProduits) {
        res += "produit\n" + produit->serializerObjet() + "_produit\n";
    }
    for (Client *client : this->listeClients) {
        res += "client\n" + client->serializerObjet() + "_client\n";
    }
    for (Commande *commande : this->listeCommandes) {
        res += "commande\n" + commande->serializerObjet() + "_commande\n";
    }
    return res;
}

void Magasin::deserialiserObjet(ObjetSerialized objetSerialized) {
    std::vector<std::string> listeProduitsSerialisesString = objetSerialized.getObjetStringEncapsule("produit");
    for (int i = 0; i < listeProduitsSerialisesString.size(); i++) {
        Produit *produit = new Produit();
        produit->deserialiserObjet(ObjetSerialized(listeProduitsSerialisesString.at(i)));
        this->listeProduits.push_back(produit);
    }
    std::vector<std::string> listeClientsSerialisesString = objetSerialized.getObjetStringEncapsule("client");
    for (int i = 0; i < listeClientsSerialisesString.size(); i++) {
        Client *client = new Client();
        client->deserialiserObjet(ObjetSerialized(listeClientsSerialisesString.at(i)));
        this->listeClients.push_back(client);
        this->initialiserPanierClient(client);
    }
    this->initialiserCompteurClient();
    std::vector<std::string> listeCommandesSerialisesString = objetSerialized.getObjetStringEncapsule("commande");
    for (int i = 0; i < listeCommandesSerialisesString.size(); i++) {
        Commande *commande = new Commande();
        commande->deserialiserObjet(ObjetSerialized(listeCommandesSerialisesString.at(i)));
        this->listeCommandes.push_back(commande);
        this->initialiserClientEtListeProduitsCommandesCommande(commande);
    }
    this->initialiserCompteurCommande();
}
