#ifndef PRODUIT_H
#define PRODUIT_H

#include "iserializable.h"

#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>



/**
 * @brief Produit est le classe représentant un produit.
 * Elle implémente les fonctionnalités de ISerializable et ObjetMapped.
 */
class Produit : public ISerializable {

private:
    /**
     * @brief titreProduit : Le titre du produit.
     */
    std::string titreProduit;
    /**
     * @brief descriptionProduit : La description du produit.
     */
    std::string descriptionProduit;
    /**
     * @brief quantiteDisponibleProduit : La quantité disponible du produit.
     */
    int quantiteDisponibleProduit;
    /**
     * @brief prixUnitaire : Le prix unitaire du produit.
     */
    double prixUnitaire;

public:
    /**
     * @brief Produit : Constructeur sans paramètres.
     */
    Produit();
    /**
     * @brief Produit : Constructeur prenant en paramètre le titre, la description, la quantité disponible et le prix unitaire du produit.
     * @param titreProduit : Le titre du produit.
     * @param descriptionProduit : La description du produit.
     * @param quantiteDisponibleProduit : La quantité dispoible du produit.
     * @param prixUnitaire : Le prix unitaire du produit.
     */
    Produit(std::string titreProduit, std::string descriptionProduit, int quantiteDisponibleProduit, double prixUnitaire);
    /**
     * @brief ~Produit : Destructeur sans paramètres.
     */
    ~Produit() override;
    /**
     * @brief getTitreProduit : Retourner le titre du produit.
     * @return Le titre du produit.
     */
    std::string getTitreProduit() const;
    /**
     * @brief setTitreProduit : Retourner le titre du produit.
     * @param titreProduit : Le nouveau titre du produit.
     */
    void setTitreProduit(std::string titreProduit);
    /**
     * @brief getDescriptionProduit : Retourner la description du produit.
     * @return La description du produit.
     */
    std::string getDescriptionProduit() const;
    /**
     * @brief setDescriptionProduit : Modifier la description du produit.
     * @param descriptionProduit : La nouvelle description du produit.
     */
    void setDescriptionProduit(std::string descriptionProduit);
    /**
     * @brief getQuantiteDisponibleProduit : Retourner la quantité disponible du produit.
     * @return La quantité disponible du produit.
     */
    int getQuantiteDisponibleProduit() const;
    /**
     * @brief setQuantiteDisponibleProduit : Modifier la quantité disponible du produit.
     * @param quantiteDisponibleProduit : La nouvelle quantité disponible du produit.
     */
    void setQuantiteDisponibleProduit(int quantiteDisponibleProduit);
    /**
     * @brief getPrixUnitaire : Retourner le prix unitaire du produit.
     * @return Le prix unitaire du produit.
     */
    double getPrixUnitaire() const;
    /**
     * @brief setPrixUnitaire : Modifier le prix unitaire du produit.
     * @param prixUnitaire : le nouveau prix unitaire du produit.
     */
    void setPrixUnitaire(double prixUnitaire);

    /**
     * @brief operator << : Surcharge de l'opérateur de flux de sortie.
     * @param out : Le flux de sortie.
     * @param commande : La produit à afficher.
     * @return Le nouveau flux de sortie.
     */
    friend std::ostream& operator<< (std::ostream& out, const Produit &produit){
        out << "Nom produit : " << produit.getTitreProduit() << " Quantite disponible : " << std::to_string(produit.getQuantiteDisponibleProduit()) << " Prix unitaire : " << std::to_string(produit.getPrixUnitaire()) << std::endl;
        return out;
    }

    // ISerializable interface
public:
    /**
     * @brief serializerObjet : Sérialiser le produit.
     * @return Le produit sérialiser au format string.
     */
    virtual std::string serializerObjet() override;
    /**
     * @brief deserialiserObjet : Désérialiser le produit.
     * @param objetSerialized : Le objectSerialized représente le produit désérialisé.
     */
    virtual void deserialiserObjet(ObjetSerialized objetSerialized) override;

    // ObjetMapped interface
public:
    /**
     * @brief initialisertMapAttributsNomAttributs :  Initialiser la map qui fait la correspondance entre les noms des attributs et les noms des attributs sérialisés.
     */
    virtual void initialisertMapAttributsNomAttributs() override;

};

#endif // PRODUIT_H
