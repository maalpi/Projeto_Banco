#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

#include <iostream>
using namespace std;

class Pessoa
{ 
  
public:
  
  virtual ~Pessoa(){};

  Pessoa(string Nome,string CPF_OR_CNPJ) : nome(Nome),cpf_or_cnpj(CPF_OR_CNPJ) { }

  virtual string getCpf_or_Cnpj() const = 0;
  virtual string getNome() const = 0;
  virtual void setNome(string) = 0;
  virtual void setCPF_OR_CNPJ(string) = 0;
  virtual string getTipo() const = 0;
  virtual string getRazao() const = 0;
  virtual void setRazao(string RAZAO) = 0;

protected:

  string cpf_or_cnpj;
  string nome;
  

};

#endif