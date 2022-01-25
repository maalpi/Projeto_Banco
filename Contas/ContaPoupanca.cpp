#include "ContaPoupanca.h"

#include <iostream>
using namespace std;

#include <string>
using std::string;

#include<vector>
using namespace std;

#include <sstream>


ContaPoupanca::ContaPoupanca(int NUMEROCONTA,float SALDO,string Aniversario) : Conta(NUMEROCONTA,SALDO),Aniversario(Aniversario){
}

//deposito
void ContaPoupanca::operator <<(float valor){
  int num;

  cout << "Digite 1 para confirmar o deposito de " << valor << "R$ ou digite 0 para cancelar a transacao na conta Poupanca" << endl;
  cin >> num;

  if (num == 1){  
  
  saldo = saldo + valor;

  std::stringstream sstream;
  sstream << valor;
  
  string num = sstream.str(), sinal = "+";
  string juncao = sinal+num;

  string DescricaoDeposito;
  string DataDep;

  cout << "Digite a data do Deposito:" << endl;
  cin.ignore();
  std::getline( cin, DataDep );

  if (DataDep == Aniversario){
    cout << endl;
    cout << "Como hoje eh seu aniversario, foi acrescentado um juros ao seu saldo!!" << endl;

    float juros = (saldo*0.05);
    saldo = saldo + juros;
    
  }

  cout << "Descricao do Deposito:" << endl;
  cin.ignore();
  std::getline( cin, DescricaoDeposito);
  

  Datas.push_back(DataDep);
  Valores.push_back(juncao);
  Descricao.push_back(DescricaoDeposito);
  cout << endl;
  }
  cout << endl;
}

//retirada
void ContaPoupanca::operator >>(float valor){
    try{
    if (valor > saldo){
      throw saldo_insuficiente_error();
    }

    int num;

    cout << "Digite 1 para confirmar a retirada de " << valor << "R$ ou digite 0 para cancelar a transacao na conta Poupanca" << endl;
    cin >> num;
    
    if (num == 1){  
    saldo = saldo - valor;

    std::stringstream sstream;
    sstream << valor;

    string num = sstream.str(), sinal = "-";
    string juncao = sinal+num;

    string DescricaoRetirada;
    string DataRet;

    cout << "Digite a data da Retirada:" << endl;
    cin.ignore();
    std::getline(cin, DataRet);

    cout << "Descricao da Retirada:" << endl;
    cin.ignore();
    std::getline( cin, DescricaoRetirada);  

    Datas.push_back(DataRet);
    Valores.push_back(juncao);
    Descricao.push_back(DescricaoRetirada);
    cout << endl;
    }
    cout << endl;
  }
  catch (saldo_insuficiente_error &e){
    cerr << "Erro na conta Poupanca: " << e.what() << endl;
    cout << endl;
    }
}

void ContaPoupanca::receberTransf(string DATA,float valor,string DESCRICAO){
  saldo = saldo + valor;

  std::stringstream sstream;
  sstream << valor;

  string num = sstream.str(), sinal = "+";
  string juncao = sinal+num;

  Datas.push_back(DATA);
  Valores.push_back(juncao);
  Descricao.push_back(DESCRICAO);
}

void ContaPoupanca::transferir(float valor, Conta &CONTA_A_RECEBER){
   try {
    if (valor > saldo){
      throw saldo_insuficiente_error();
    }

    string DescricaoTrans;
    string DataTrans;

    std::stringstream sstream;
    sstream << valor;

    string num = sstream.str(), sinal = "-";
    string juncao = sinal+num;

    cout << "Digite a data da Tranferencia:" << endl;
    cin.ignore();
    std::getline( cin, DataTrans );

    cout << "Descricao Transferencia:" << endl;
    cin.ignore();
    std::getline( cin, DescricaoTrans);

    Datas.push_back(DataTrans);
    Valores.push_back(juncao);
    Descricao.push_back(DescricaoTrans);

    saldo = saldo - valor;
    CONTA_A_RECEBER.receberTransf(DataTrans,valor,DescricaoTrans);
  }
  catch (saldo_insuficiente_error &e){
    cerr << "Erro na conta Poupanca: " << e.what() << endl;
    cout << endl;
    }
    
}

void ContaPoupanca::impressaoExtrato() const{
    cout << "= DADOS =" << endl;
    cout << "Conta Poupanca" << endl;
    cout << "Numero da conta: " << numeroConta << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Data de Aniversario: " << Aniversario << endl;
    cout << "========TRANSACOES=======" << endl;
    for(int i = 0; i<Datas.size(); i++) {
      cout << "Dia: " << Datas[i] << endl;
      cout << "Valor: " << Valores[i] << endl;
      cout << "Descricao: " << Descricao[i] << endl;
      cout << endl;
   }
  
  cout << endl;
}


