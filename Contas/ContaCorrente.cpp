#include "ContaCorrente.h"

#include <iostream>
using namespace std;

#include <string>
using std::string;

#include<vector>
using namespace std;

#include <sstream>


ContaCorrente::ContaCorrente(int NUMEROCONTA,float SALDO,float LIMITE) : Conta(NUMEROCONTA,SALDO),Limite(LIMITE){
}


//deposito
void ContaCorrente::operator <<(float valor){
  int num;

  cout << "Digite 1 para confirmar o deposito de " << valor << "R$ ou digite 0 para cancelar a transacao na conta Corrente" << endl;
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

  cout << "Descricao do Deposito:" << endl;
  cin.ignore();
  std::getline( cin, DescricaoDeposito );
  

  Datas.push_back(DataDep);
  Valores.push_back(juncao);
  Descricao.push_back(DescricaoDeposito);
  cout << endl;
  }
  cout << endl;
}

//retirada
void ContaCorrente::operator >>(float valor){
    try {
      if (valor > Limite){
        throw limite_insuficiente_error();
      }

      if (valor > saldo){
        throw saldo_insuficiente_error();
      }

      int num;
      cout << "Digite 1 para confirmar a retirada de " << valor << "R$ ou digite 0 para cancelar a transacao na conta Corrente" << endl;
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
      std::getline( cin, DataRet );

      cout << "Descricao da Retirada:" << endl;
      cin.ignore();
      std::getline( cin, DescricaoRetirada);
  

    Datas.push_back(DataRet);
    Valores.push_back(juncao);
    Descricao.push_back(DescricaoRetirada);
    
    }
  }
    catch (saldo_insuficiente_error &e){
      cerr << "Erro na conta Corrente" << e.what() << endl;
      cout << endl;
    }
    catch (limite_insuficiente_error &e){
      cerr << "Erro na conta Corrente: " << e.what() << endl;
      cout << endl;
    }
    cout << endl;
}

void ContaCorrente::receberTransf(string DATA,float valor,string DESCRICAO){
  saldo = saldo + valor;

  std::stringstream sstream;
  sstream << valor;

  string num = sstream.str(), sinal = "+";
  string juncao = sinal+num;

  Datas.push_back(DATA);
  Valores.push_back(juncao);
  Descricao.push_back(DESCRICAO);
}


void ContaCorrente::transferir(float valor, Conta &CONTA_A_RECEBER){
  try {
    if (valor > Limite){
      throw limite_insuficiente_error();
    }

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
    cerr << "Erro na conta Corrente: " << e.what() << endl;
    cout << endl;
    }
  catch (limite_insuficiente_error &e){
    cerr << "Erro na conta Corrente: " << e.what() << endl;
    cout << endl;
    }
    
}


void ContaCorrente::impressaoExtrato() const{
    cout << "= DADOS =" << endl;
    cout << "Conta Corrente com Limite" << endl;
    cout << "Numero da conta: " << numeroConta << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Valor de Limite: " << Limite << endl;
    cout << "========TRANSACOES=======" << endl;
    for(int i = 0; i<Datas.size(); i++) {
      cout << "Dia: " << Datas[i] << endl;
      cout << "Valor: " << Valores[i] << endl;
      cout << "Descricao: " << Descricao[i] << endl;
      cout << endl;
   }
  
  cout << endl;
}
