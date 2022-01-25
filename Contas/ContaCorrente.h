#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H 

#include "Conta.h"

#include<vector>

#include <iostream>
using namespace std;

#include <string>
using std::string;

class ContaCorrente : public Conta
{
public:
  ContaCorrente(int NUMEROCONTA = 0 ,float SALDO = 0.0,float Limite = 0.0);

  virtual ~ContaCorrente()
  {
    cout << "Destruindo Conta Corrente" << endl;
  }
  
  virtual void setConta(int novo){
    numeroConta = novo;
  }

  //deposito
  virtual void operator <<(float valor);
  
  //retirada
  virtual void operator >>(float valor);

  //transferencia
  virtual void transferir(float valor, Conta &);
  virtual void receberTransf(string DATA,float valor,string DESCRICAO);

  virtual string getTipo(){
    return "Corrente";
  }

  int getConta(){
    return numeroConta;
  };

  virtual float getLimite(){
    return Limite;
  }

  virtual void setLimite(float limit){
    Limite = limit;
  }

  virtual string getAniv(){
    return "Nothing";
  }
  virtual void setAniv(string anv){}

  float getSaldo(){
    return saldo;
  };

  void impressaoExtrato() const;

private:
  float Limite;
  vector<string> Datas;
  vector<string> Valores;
  vector<string> Descricao;

};

#endif