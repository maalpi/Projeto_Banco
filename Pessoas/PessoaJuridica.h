#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include <string>
using std::string;

#include <iostream>
using namespace std;

#include "Pessoa.h"

class PessoaJuridica: public Pessoa
{ 
public:

     ~PessoaJuridica()
  {}

  PessoaJuridica(string NOME = "", string RAZAO = "", string CNPJ = ""): Pessoa(NOME,CNPJ),RazaoSocial(RAZAO) { }

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

   virtual void setRazao(string RAZAO){
    RazaoSocial = RAZAO;
  }

  virtual string getRazao() const{
    return RazaoSocial;
  }
  
  virtual string getTipo() const{
    return "Juridica";
  }
  
protected:
  string RazaoSocial;
  
};

#endif