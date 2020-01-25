#ifndef MAGASIN_H
#define MAGASIN_H

#include "client.h"
#include "commande.h"
#include "produit.h"

#include <string>
#include <vector>
#include <iostream>



/**
 * @brief Magasin est la classe représentant un magasin.
 * Elle implémente les fonctionnalités de ISerializable.
 */
class Magasin : public ISerializable {

private:
    /**
     * @brief listeProduits : La liste des produits du magasin.
     */
    std::vector<Produit*> listeProduits;
    /**
     * @brief listeClients : La liste des clients du magasin.
     */
    std::vector<Client*> listeClients;
    /**
     * @brief listeCommandes : La liste des commandes du magasin.
     */
    std::vector<Commande*> listeCommandes;
    /**
     * @brief compteurClients : Le compteur de clients du magasin.
     */
    int compteurClients;
    /**
     * @brief compteurCommandes : Le compteur de commandes du magasin.
     */
    int compteurCommandes;

private:
    /**
     * @brief getProduitAvecNomProduit : Retourner le produit avec le nom du produit.
     * @param nomProduit : Le nom du produit.
     * @return Le produit.
     */
    Produit* getProduitAvecNomProduit(std::string nomProduit);
    /**
     * @brief getClientAvecNomClient : Retourner le client avec le nom du client.
     * @param nomClient : Le nom du client.
     * @return Le client.
     */
    Client* getClientAvecNomClient(std::string nomClient);
    /**
     * @brief getCommandeAvecIdentifiantCommande : Retourner la commande avec l'identifiant de commande.
     * @param identifiantCommande : L'identifiant de commande.
     * @return La commande.
     */
    Commande* getCommandeAvecIdentifiantCommande(int identifiantCommande);

public:
    /**
     * @brief Magasin : Constructeur sans paramètres.
     */
    Magasin();
    /**
     * @brief ~Magasin : Destructeur sans paramètres.
     */
    ~Magasin() override;
    /**
     * @brief ajouterProduit : Ajouter le produit au magasin.
     * @param titreProduit : Le titre du produit.
     * @param descriptionProduit : La description du produit.
     * @param quantiteDisponibleProduit : La quantité disponible du produit.
     * @param prixUnitaireProduit : Le prix unitaire du produit.
     */
    void ajouterProduit(std::string titreProduit, std::string descriptionProduit, int quantiteDisponibleProduit, double prixUnitaireProduit);
    /**
     * @brief afficherListeProduits : Afficher la liste de tous les produits.
     */
    void afficherListeProduits();
    /**
     * @brief afficherProduitAvecNom : Afficher le produit avec le nom du produit.
     * @param nomProduit : Le nom du produit.
     */
    void afficherProduitAvecNom(std::string nomProduit);
    /**
     * @brief mettreAJourQuantiteDisponibleProduitAvecNom : Mettre à jour la quantité disponible du produit avec le nom du produit.
     * @param nomProduit Le nom du produit.
     * @param nouvelleQuantiteDisponible : La nouvelle quantité disponible du produit.
     */
    void mettreAJourQuantiteDisponibleProduitAvecNom(std::string nomProduit, int nouvelleQuantiteDisponible);

    /**
     * @brief ajouterClient : Ajouter un client au magasin.
     * @param nomClient Le nom du client.
     * @param prenomClient Le prénom du client.
     */
    void ajouterClient(std::string nomClient, std::string prenomClient);
    /**
     * @brief afficherListeClients : Afficher la liste de tous les clients.
     */
    void afficherListeClients();
    /**
     * @brief afficherClient : Afficher le client avec le nom du client.
     * @param nomClient Le nom du client.
     */
    void afficherClient(std::string nomClient);
    /**
     * @brief afficherClient : Affciher le client avec l'ifentifiant du client.
     * @param identifiantClient : L'identifiant du client.
     */
    void afficherClient(int identifiantClient);

    /**
     * @brief ajouterProduitDansPanierClient : Ajouter le produit dans le panier du client avec le nom du produit et le nom du client.
     * @param nomProduit : Le nom du produit.
     * @param nomClient : Le nom du client.
     */
    void ajouterProduitDansPanierClient(std::string nomProduit, std::string nomClient);
    /**
     * @brief supprimerProduitDansPanierClient : Supprimer le produit dans le panier du client avec le nom du produit et le nom du client.
     * @param nomProduit : Le nom du produit.
     * @param nomClient : Le nom du client.
     */
    void supprimerProduitDansPanierClient(std::string nomProduit, std::string nomClient);
    /**
     * @brief modifierQuantiteProduitDansPanierClient : Modifier la quantité d'un produit du panier du client avec le nom du produit et le nom du client.
     * @param nomProduit : Le nom du produit.
     * @param nouvelleQuantiteProduit : La nouvelle quantité du produit dans le panier du client.
     * @param nomClient : Le nom du client.
     */
    void modifierQuantiteProduitDansPanierClient(std::string nomProduit, int nouvelleQuantiteProduit, std::string nomClient);

    /**
     * @brief validerCommandeDUnClient : Valider la commande d'un client avec le nom du client.
     * @param nomClient : Le nom du client.
     */
    void validerCommandeDUnClient(std::string nomClient);
    /**
     * @brief mettreAJourStatutCommande : Mettre à jour le statut d'une commande avec l'identifiant de la commande.
     * @param identifiantCommande L'identifiant de la commande.
     */
    void mettreAJourStatutCommande(int identifiantCommande);
    /**
     * @brief afficherListeCommandes : Affciher la liste de toutes les commandes.
     */
    void afficherListeCommandes();
    /**
     * @brief afficherCommandeAvecNom : Affciher les commandes d'un client avec le nom du client.
     * @param nomClient : Le nom du client.
     */
    void afficherCommandeAvecNom(std::string nomClient);

    /**
     * @brief initialiserPanierClient : Initialiser le panier d'un client pour la désérialisation d'un client.
     * @param client : Le client.
     */
    void initialiserPanierClient(Client *client);
    /**
     * @brief initialiserClientEtListeProduitsCommandesCommande : Initiliser le client et la liste des produits commandés pour la désérialisation d'une commande.
     * @param commande : La commande.
     */
    void initialiserClientEtListeProduitsCommandesCommande(Commande *commande);
    /**
     * @brief initialiserCompteurClient : Initialiser le compteur de clients.
     */
    void initialiserCompteurClient();
    /**
     * @brief initialiserCompteurCommande : Initialiser le compteur de commandes.
     */
    void initialiserCompteurCommande();

    // ISerializable interface
public:
    /**
     * @brief serializerObjet : Sérialiser le magasin.
     * @return Le magasin sérialiser au format string.
     */
    std::string serializerObjet() override;
    /**
     * @brief deserialiserObjet : Désérialiser le magasin.
     * @param objetSerialized : Le objectSerialized représente le magasin désérialisé.
     */
    void deserialiserObjet(ObjetSerialized objetSerialized) override;

    // ObjetMapped interface
public:
    /**
     * @brief initialisertMapAttributsNomAttributs :  Initialiser la map qui fait la correspondance entre les noms des attributs et les noms des attributs sérialisés.
     */
    virtual void initialisertMapAttributsNomAttributs() override;

};

#endif // MAGASIN_H
