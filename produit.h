#ifndef PRODUIT_H
#define PRODUIT_H

#include "iserializable.h"

#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>



class Produit : public ISerializable {

private:
    std::string titreProduit;
    std::string descriptionProduit;
    int quantiteDisponibleProduit;
    double prixUnitaire;

public:
    Produit();
    Produit(std::string titreProduit, std::string descriptionProduit, int quantiteDisponibleProduit, double prixUnitaire);
    std::string getTitreProduit() const;
    void setTitreProduit(std::string titreProduit);
    std::string getDescriptionProduit() const;
    void setDescriptionProduit(std::string descriptionProduit);
    int getQuantiteDisponibleProduit() const;
    void setQuantiteDisponibleProduit(int quantiteDisponibleProduit);
    double getPrixUnitaire() const;
    void setPrixUnitaire(double prixUnitaire);

    friend std::ostream& operator<< (std::ostream& out, const Produit &produit){
        out << "Nom produit : " << produit.getTitreProduit() << " Quantite disponible : " << std::to_string(produit.getQuantiteDisponibleProduit()) << " Prix unitaire : " << std::to_string(produit.getPrixUnitaire()) << std::endl;
        return out;
    }

    // ISerializable interface
public:
    std::map<std::string, std::string> getMapAttributsNomAttributs() override;
    void setValeurAttribut(std::string nomAttribut, std::string valeurAttribut) override;
    std::string serializerObjet() override;
    void deserialiserObjet(ObjetSerialized objetSerialized) override;

};

#endif // PRODUIT_H
