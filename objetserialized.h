#ifndef OBJETSERIALIZED_H
#define OBJETSERIALIZED_H

#include <string>
#include <vector>
#include <map>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>


class ObjetSerialized {

private:
    std::string objetString;
    std::map<std::string, std::string> mapNomAttributValeurAttribut;

public:
    ObjetSerialized();
    ObjetSerialized(std::string objetString);
    ~ObjetSerialized();
    std::string getObjetString() const;
    void setObjetString(std::string objetString);
    std::map<std::string, std::string> getMapNomAttributValeurAttribut();
    void remplirMapNomAttributValeurAttribut();
    std::string getValeurAttribut(std::string nomAttribut);

    void ajouterAttributString(std::string nomAttribut, std::string valeurAttribut);
    void serialiserLesAttributs();

    std::vector<std::string> getObjetStringEncapsule(std::string nomEncapsulation);

};

#endif // OBJETSERIALIZED_H
