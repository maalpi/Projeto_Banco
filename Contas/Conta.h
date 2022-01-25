#ifndef CONTA_H
#define CONTA_H 

#include <iostream>
using namespace std;

#include <string>
using std::string;

//excecoes
#include <stdexcept>

class saldo_insuficiente_error : public std::out_of_range 
{
public:
  saldo_insuficiente_error(const char *e="Saldo Insuficiente") : std::out_of_range(e) {}
};

class limite_insuficiente_error : public std::out_of_range 
{
public:
  limite_insuficiente_error(const char *e="Limite Insuficiente") : std::out_of_range(e) {}
};

class Conta
{
public:
  Conta(int NUMEROCONTA = 0,float SALDO = 0.0) : numeroConta(NUMEROCONTA),saldo(SALDO){ }
  
  //métodos virtuais puros

   virtual ~Conta(){}
  
  //DEPOSITO
  virtual void operator <<(float valor) = 0;

  //RETIRADA
  virtual void operator >>(float valor) = 0;
  
  virtual float getSaldo() = 0;
  virtual int getConta() = 0;

  //TRANSFERENCIA
  virtual void transferir(float valor, Conta &) = 0;
  virtual void receberTransf(string DATA,float valor,string DESCRICAO) = 0;

  virtual void setConta(int novo) = 0;

  virtual void impressaoExtrato() const = 0;

  virtual string getTipo() = 0;

  virtual float getLimite() = 0;
  virtual void setLimite(float limit) = 0;

  virtual string getAniv() = 0;
  virtual void setAniv(string anive) = 0;

protected:
  int numeroConta;
  float saldo;
  string tipo;

};

#endif