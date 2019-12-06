#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>



class Produit {

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
        out << produit.getTitreProduit() << " " << std::to_string(produit.getQuantiteDisponibleProduit()) << " " << std::to_string(produit.getPrixUnitaire()) << std::endl;
        return out;
    }
};

#endif // PRODUIT_H
