#ifndef MAGASIN_H
#define MAGASIN_H

#include "client.h"
#include "commande.h"
#include "produit.h"

#include <string>
#include <vector>
#include <iostream>



class Magasin : public ISerializable {

private:
    std::vector<Produit*> listeProduits;
    std::vector<Client*> listeClients;
    std::vector<Commande*> listeCommandes;
    int compteurClients;
    int compteurCommandes;

private:
    Produit* getProduitAvecNomProduit(std::string nomProduit);
    Client* getClientAvecNomClient(std::string nomClient);
    Commande* getCommandeAvecIdentifiantCommande(int identifiantCommande);

public:
    Magasin();
    ~Magasin();
    void ajouterProduit(Produit *produit);
    void afficherListeProduits();
    void afficherProduitAvecNom(std::string nomProduit);
    void mettreAJourQuantiteDisponibleProduitAvecNom(std::string nomProduit, int nouvelleQauntiteDisponible);

    void ajouterClient(std::string nomClient, std::string prenomClient);
    void afficherListeClients();
    void afficherClient(std::string nomClient);
    void afficherClient(int identifiantClient);

    void ajouterProduitDansPanierClient(std::string nomProduit, std::string nomClient);
    void supprimerProduitDansPanierClient(std::string nomProduit, std::string nomClient);
    void modifierQuantiteProduitDansPanierClient(std::string nomProduit, int nouvelleQuantiteProduit, std::string nomClient);

    void validerCommandeDUnClient(std::string nomClient);
    void mettreAJourStatutCommande(int identifiantCommande);
    void afficherListeCommandes();
    void afficherCommandeAvecNom(std::string nomClient);

    void initialiserPanierClient(Client *client);
    void initialiserClientEtListeProduitsCommandesCommande(Commande *commande);
    void initialiserCompteurClient();
    void initialiserCompteurCommande();

    // ISerializable interface
public:
    std::string serializerObjet() override;
    void deserialiserObjet(ObjetSerialized objetSerialized) override;

    // ObjetMapped interface
public:
    void initialisertMapAttributsNomAttributs() override;

};

#endif // MAGASIN_H
