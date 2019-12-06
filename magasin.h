#ifndef MAGASIN_H
#define MAGASIN_H

#include "client.h"
#include "commande.h"
#include "produit.h"

#include <string>
#include <vector>
#include <iostream>



class Magasin {

private:
    std::vector<Produit*> listeProduits;
    std::vector<Client*> listeClients;
    std::vector<Commande*> listeCommandes;
    int compteurClients;

private:
    Produit* getProduitAvecNomProduit(std::string nomProduit);
    Client* getClientAvecNomClient(std::string nomClient);

public:
    Magasin();
    ~Magasin();
    void ajouterProduit(Produit *produit);
    void afficherListeProduits();
    void affcherProduitAvecNom(std::string nomProduit);
    void mettreAJourQuantiteDisponibleProduitAvecNom(std::string nomProduit, int nouvelleQauntiteDisponible);

    void ajouterClient(std::string nomClient, std::string prenomClient);
    void afficherListeClients();
    void afficherClient(std::string nomClient);
    void afficherClient(int identifiantClient);

    void ajouterProduitDansPanierClient(std::string nomProduit, std::string nomClient);
    void supprimerProduitDansPanierClient(std::string nomProduit, std::string nomClient);
    void modifierQuantiteProduitDansPanierClient(std::string nomProduit, int nouvelleQuantiteProduit, std::string nomClient);
};

#endif // MAGASIN_H
