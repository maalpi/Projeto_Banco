#ifndef BANCO_H
#define BANCO_H 

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "../Pessoas/Pessoa.h"
#include "../Pessoas/PessoaFisica.h"
#include "../Pessoas/PessoaJuridica.h"
#include "../Contas/ContaComum.h"
#include "../Contas/ContaPoupanca.h"
#include "../Contas/ContaCorrente.h"

class Banco : public PessoaJuridica
{
  struct DADOS_BANCO {
  Pessoa *p_pes; // ptr
  Conta *p_conta; //ptr_conta
  };

public:
  Banco() {}
  
  void iniciar_projeto();//okay
  bool salvar_dados(DADOS_BANCO c[], int n); //okay
  bool iniciar_dados();//okay
  
  void cliente_ou_gerente(); //OKAY
  
  void consultar_conta(int numero);//OKAY
  void consultar_todas_contas();//OKAY
  void consultar_contas_correntista(string nome);//okay

  void cadastrar_conta(); //OKAY
  void remover_conta(int num_conta);
  void att_conta(int num_conta);//Okay
  void cadastar_cliente(); //OKAY
  int encontrar_correntista(string); //OKAY
  int encontrar_conta(int);//okay

  
  protected:
  int escolha;
  Pessoa *listaPessoas[100];
  DADOS_BANCO listaContas[100];
  int num_conta=0;
  int num_pessoas=0;
  
};

#endif