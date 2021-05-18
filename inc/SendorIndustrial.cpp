#include "sensorindustrial.h"
#include <iostream>
#include <vector>

using namespace std;

SensorIndustrial::SensorIndustrial(const string& identificador, const string& un) : id(identificador), unidade(un), dados(nullptr),numMed(0)
{

}

SensorIndustrial::~SensorIndustrial()
{
    this->limpaDados();
    cout<<"Destrutor da calsse SensorIndustrial invocado ID: "<<this->id<<endl;

}

void SensorIndustrial::setId(const string& id)
{
    this->id = id;
}

void SensorIndustrial::setUnidade(const string& un)
{
    this->unidade = un;
}

void SensorIndustrial::lerDados(const Medicao* dadosNovos, const int& numdados)
{
    this->limpaDados();
    this->numMed = numdados;
    this->dados = new Medicao[this->numMed];

    for(int i = 0; i<this->numMed; i++)
    {
        this->dados[i] = dadosNovos[i];
    }
}

void SensorIndustrial::limpaDados()
{
    if(this->dados!=nullptr)
    {
        delete[] this->dados;
        this->dados = nullptr;
        this->numMed = 0;
    }
    else
    {
        cout<<"Não existe nenhum dado"<<endl;
    }
}

string SensorIndustrial::getId()
{
    return this->id;
}

string SensorIndustrial::getUnidade()
{
    return this->unidade;
}

int SensorIndustrial::getNumMed()
{
    return this->numMed;
}

int SensorIndustrial::getDados(Medicao* d)
{
    d = this->dados;
    return this->getNumMed();
}

bool SensorIndustrial::getDado(const string& h, Medicao& med)
{
    for(int i = 0; i<this->numMed; i++)
    {
        if(this->dados[i].horario == h)
        {
            med = this->dados[i];
            return true;
        }
    }
    return false;
}

void SensorIndustrial::imprimeDados()
{
    cout<<"Dados do Sensor "<<this->getId()<<" : "<<endl;
    for(int i = 0; i<this->numMed;i++)
    {
       cout<<"Horario: "<<this->dados[i].horario<<" h | valor: "<<this->dados[i].valor<<" "<<this->getUnidade()<<endl;
    }
}