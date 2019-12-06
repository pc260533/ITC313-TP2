#ifndef CLIENT_H
#define CLIENT_H

#include "produit.h"

#include <string>
#include <vector>



class Client {

private:
    int identifiantClient;
    std::string prenomClient;
    std::string nomClient;
    std::vector<Produit*> listeProduitsSelectionnes;
    std::vector<int> listeQuantitesProduitsSelectionnes;

public:
    Client();
    Client(int identifiantClient, std::string prenomClient, std::string nomClient);
    ~Client();
    int getIdentifiantClient() const;
    std::string getPrenomClient() const;
    void setPrenomClient(std::string prenomClient);
    std::string getNomClient() const;
    void setNomClient(std::string prenomClient);
    void ajouterProduitAuPanier(Produit *produit);
    void viderLePanier();
    void modifierQuantiteProduitSelectionne(std::string nomProduit, int nombreDeProduits);
    void supprimerProduit(std::string nomProduit);

    friend std::ostream& operator<< (std::ostream& out, const Client &client){
        out << std::to_string(client.getIdentifiantClient()) << " " << client.getPrenomClient() << " " << client.getNomClient() << std::endl;
        out << "La liste des produits du panier sont : " << std::endl;
        for (int i = 0; i < client.listeProduitsSelectionnes.size(); i++) {
            out << "Quantite : " << client.listeQuantitesProduitsSelectionnes.at(i) << " " << *client.listeProduitsSelectionnes.at(i);
        }
        return out;
    }

};

#endif // CLIENT_H
