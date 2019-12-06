#ifndef COMMANDE_H
#define COMMANDE_H

#include "client.h"
#include "produit.h"

#include <string>
#include <vector>



class Commande {

private:
    Client* clientCommande;
    std::vector<Produit*> listeProduitsCommandes;
    bool statutLivreeCommande;

public:
    Commande();
    Commande(Client* client, std::vector<Produit*> listeProduitsCommandes);
    ~Commande();
    Client* getClientCommande() const;
    void setClientCommande(Client *clientCommande);
    std::vector<Produit*> getListeProduitsCommandes() const;
    void setListeProduitsCommandes(std::vector<Produit*> listeProduitsCommandes);
    bool getStatutLivreeCommande() const;
    void setStatutLivreeCommande(bool statutLivreeCommande);

    friend std::ostream& operator<< (std::ostream& out, const Commande &commande){
        out << "Le client de la commande est : " << *commande.getClientCommande() << std::endl;
        out << "La liste des produits de la commande sont : " << std::endl;
        for (int i = 0; i < commande.getListeProduitsCommandes().size(); i++) {
            out << *commande.getListeProduitsCommandes().at(i);
        }
        return out;
    }

};

#endif // COMMANDE_H
