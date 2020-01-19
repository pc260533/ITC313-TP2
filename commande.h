#ifndef COMMANDE_H
#define COMMANDE_H

#include "client.h"
#include "produit.h"

#include <string>
#include <vector>



class Commande : public ISerializable {

private:
    int identifiantCommande;
    Client *clientCommande;
    std::vector<Produit*> listeProduitsCommandes;
    std::vector<int> listeQuantitesProduitsCommandes;
    bool statutLivreeCommande;

    std::string nomClient;
    std::vector<std::string> listeNomProduitsCommandes;

public:
    Commande();
    Commande(int identifiantCommande, Client* client, std::vector<Produit*> listeProduitsCommandes, std::vector<int> listeQuantitesProduitsCommandes);
    ~Commande();
    int getIdentifiantCommande() const;
    void setIdentifiantCommande(int identifiantCommande);
    Client* getClientCommande() const;
    void setClientCommande(Client *clientCommande);
    std::vector<Produit*> getListeProduitsCommandes() const;
    std::vector<int> getListeQuantitesProduitsCommandes() const;
    void setListeProduitsCommandes(std::vector<Produit*> listeProduitsCommandes);
    bool getStatutLivreeCommande() const;
    void setStatutLivreeCommande(bool statutLivreeCommande);
    std::vector<std::string> getListeNomProduitsCommandes() const;
    std::string getNomClient() const;

    void initialiserClient(Client *clientCommande);
    void initialiserListeProduitsCommandes(std::vector<Produit*> listeProduitsCommandes);

    friend std::ostream& operator<< (std::ostream& out, const Commande &commande){
        out << "Le client de la commande est : " << *commande.getClientCommande() << std::endl;
        std::string statutLivreeCommande = "non livree";
        if (commande.getStatutLivreeCommande()) {
            statutLivreeCommande = "livree";
        }
        out << "La statut de la commande est : " << statutLivreeCommande << "." << std::endl;
        out << "La liste des produits de la commande sont : " << std::endl;
        for (int i = 0; i < commande.getListeProduitsCommandes().size(); i++) {
            out << "Quantite : " << commande.getListeQuantitesProduitsCommandes().at(i) << " " << *commande.getListeProduitsCommandes().at(i);
        }
        return out;
    }

    // ISerializable interface
public:
    virtual std::string serializerObjet() override;
    virtual void deserialiserObjet(ObjetSerialized objetSerialized) override;


    // ObjetMapped interface
public:
    virtual void initialisertMapAttributsNomAttributs() override;

};

#endif // COMMANDE_H
