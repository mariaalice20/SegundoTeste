#ifndef SENSORINDUSTRIAL_H
#define SENSORINDUSTRIAL_H
#include <string>

#include "medicao.h"

using namespace std;

class SensorIndustrial
{
private:
    string id;
    string unidade;
    int numMed;
protected:
    Medicao* dados;
public:
    SensorIndustrial( const string&, const string&);
    ~SensorIndustrial();

    //funções set
    void setId(const string&);
    void setUnidade(const string&);
    virtual void lerDados(const Medicao*,const int&);
    virtual void limpaDados();

    // funções get
    string getId();
    string getUnidade();
    int getNumMed();
    int getDados(Medicao*);
    bool getDado(const string&, Medicao&);
    virtual void imprimeDados();
};

#endif
