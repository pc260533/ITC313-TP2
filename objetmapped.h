#ifndef OBJETMAPPED_H
#define OBJETMAPPED_H

#include <string>
#include <map>



class ObjetMapped {

private:
    std::map<std::string, std::string> mapAttributsNomAttributs;

public:
    ObjetMapped();
    virtual ~ObjetMapped();

    std::map<std::string, std::string> getMapAttributsNomAttributs();
    void ajouterEntreeMapAttributsNomAttributs(std::string attribut, std::string nomAttribut);
    virtual void initialisertMapAttributsNomAttributs() = 0;

};

#endif // OBJETMAPPED_H
