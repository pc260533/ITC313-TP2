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

public:
    Magasin();
    ~Magasin();
    void ajouterProduit(Produit *produit);
    void afficherListeProduits();
    void affcherProduitAvecNom(std::string nomProduit);
    void mettreAJourQuantiteDisponibleProduitAvecNom(std::string nomProduit, int nouvelleQauntiteDisponible);

};

#endif // MAGASIN_H
