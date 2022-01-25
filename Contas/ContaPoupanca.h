#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H 

#include "Conta.h"

#include<vector>

#include <iostream>
using namespace std;

#include <string>
using std::string;

class ContaPoupanca : public Conta
{
public:
  ContaPoupanca(int NUMEROCONTA = 0 ,float SALDO = 0.0, string Aniversario = "");

  virtual ~ContaPoupanca()
  {
    cout << "Destruindo Conta Poupanca" << endl;
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
    return "Poupanca";
  }

  int getConta(){
    return numeroConta;
  };

  float getSaldo(){
    return saldo;
  };

  virtual float getLimite(){
    return 0;
  }
  virtual void setLimite(float limit){}

  virtual string getAniv(){
    return Aniversario;
  }

  virtual void setAniv(string anv){
    Aniversario = anv;
  }

  void impressaoExtrato() const;

private:
  string Aniversario;
  vector<string> Datas;
  vector<string> Valores;
  vector<string> Descricao;

};

#endif