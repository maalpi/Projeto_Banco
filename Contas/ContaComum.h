#ifndef CONTACOMUM_H
#define CONTACOMUM_H 

#include "Conta.h"

#include<vector>

#include <iostream>
using namespace std;

#include <string>
using std::string;

class ContaComum : public Conta
{
public:
  ContaComum(int NUMEROCONTA = 0 ,float SALDO = 0.0);

  virtual ~ContaComum()
  {
    cout << "Destruindo Conta Comum" << endl;
  }

  virtual void setConta(int novo){
    numeroConta = novo;
  }

  //deposito
  virtual void operator <<( float valor);

  //retirada
  virtual void operator >>(float valor);

  //transferencia
  virtual void transferir(float valor, Conta &);
  virtual void receberTransf(string DATA,float valor,string DESCRICAO);
  
  int getConta(){
    return numeroConta;
  };

  virtual string getTipo(){
    return "Comum";
  }
  float getSaldo(){
    return saldo;
  };

  virtual float getLimite(){
    return 0;
  }
    
  virtual string getAniv(){
    return "Nothing";
  }
  virtual void setAniv(string anv){}

  virtual void setLimite(float limit){}
  void impressaoExtrato() const;

private:
  vector<string> Datas;
  vector<string> Valores;
  vector<string> Descricao;

};

#endif