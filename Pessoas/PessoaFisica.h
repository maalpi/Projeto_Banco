#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include <string>
using std::string;

#include <iostream>
using namespace std;

#include "Pessoa.h"

class PessoaFisica: public Pessoa
{ 
public:

   ~PessoaFisica()
  {}

  PessoaFisica(string NOME , string CPF) : Pessoa(NOME,CPF) {}

  virtual string getNome() const{
    return nome;
  }

  virtual void setNome(string NOME){
    nome = NOME;
  }

   virtual void setCPF_OR_CNPJ(string novo){
     cpf_or_cnpj = novo;
   }
  
  virtual string getCpf_or_Cnpj() const{
    return cpf_or_cnpj;
  }

  virtual string getTipo() const{
    return "Fisica";
  }

  virtual void setRazao(string RAZAO){
  }

  virtual string getRazao() const{
    return "Nothing";
  }
  
};

#endif