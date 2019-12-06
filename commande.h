#ifndef COMMANDE_H
#define COMMANDE_H

#include "client.h"
#include "produit.h"

#include <string>
#include <vector>



class Commande {

private:
    Client clientCommande;
    std::vector<Produit*> listeProduitsCommandes;
    bool statutLivreeCommande;

public:
    Commande();

};

#endif // COMMANDE_H
