#include <iostream>
#include <string>
#include "Banco.h"
#include <cstring>
using namespace std;

struct DADOS_CARREGAR{
  string tipo_pes;
  string nome;
  string cpf;
  string razao;

  string tipo_conta;
  float limite;
  string aniv;
  int nume_conta;
  float saldo;
};

void Banco::iniciar_projeto(){
  iniciar_dados();
  cliente_ou_gerente();
}

int Banco::encontrar_correntista(string a){
  for(int i=0; i<num_pessoas;i++){
    if(a==listaPessoas[i]->getNome()){
      return i;
    }
  }
  return -1;
}

int Banco::encontrar_conta(int b){
    
  for(int i=0; i<num_conta;i++){
    if (b == listaContas[i].p_conta->getConta()){
      return i;
    }
    }  
  return -1;
}

bool Banco::iniciar_dados(){
  ifstream fin("dados.dat",ios::in);
  
  if (!fin){
    return false;
  }

  DADOS_CARREGAR c;

  cout << fixed << setprecision(1);
  
  while (fin >> c.tipo_pes >> c.nome >> c.cpf >> c.razao >> c.tipo_conta >> c.limite >> c.aniv >> c.nume_conta >> c.saldo)
  { 
    if (c.nume_conta != 0){
      
  
    if (c.tipo_pes == "Fisica"){
      
      if (encontrar_correntista(c.nome) == -1){
        
        listaPessoas[num_pessoas] = new PessoaFisica(c.nome,c.cpf);
        num_pessoas++;
      
        if (c.tipo_conta == "Comum"){
            
            listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaComum(c.nume_conta,c.saldo)};
            num_conta++;
        }
        else if(c.tipo_conta == "Corrente"){
            listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaCorrente(c.nume_conta,c.saldo,c.limite)};
          
            num_conta++;

        }
        else if (c.tipo_conta == "Poupanca"){
           listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaPoupanca(c.nume_conta,c.saldo,c.aniv)};
          
            num_conta++;
      }

      }else{
      if (c.tipo_conta == "Comum"){
  
          listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaComum(c.nume_conta,c.saldo)};
          num_conta++;
      }
      else if(c.tipo_conta == "Corrente"){
          listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaCorrente(c.nume_conta,c.saldo,c.limite)};
          
          num_conta++;

      }
      else if (c.tipo_conta == "Poupanca"){
         listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaPoupanca(c.nume_conta,c.saldo,c.aniv)};
          
          num_conta++;

      }
      }
    }else{

      if (encontrar_correntista(c.nome) == -1){

        listaPessoas[num_pessoas] = new PessoaJuridica(c.nome,c.cpf,c.razao);
        num_pessoas++;

        if (c.tipo_conta == "Comum"){
  
          listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaComum(c.nume_conta,c.saldo)};
          num_conta++;
      }
        else if(c.tipo_conta == "Corrente"){
          listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaCorrente(c.nume_conta,c.saldo,c.limite)};
          
          num_conta++;

      }
        else if (c.tipo_conta == "Poupanca"){
        listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaPoupanca(c.nume_conta,c.saldo,c.aniv)};
          
        num_conta++;
    }

      }else{
        if (c.tipo_conta == "Comum"){
  
          listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaComum(c.nume_conta,c.saldo)};
          num_conta++;
      }
        else if(c.tipo_conta == "Corrente"){
          listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaCorrente(c.nume_conta,c.saldo,c.limite)};
          
          num_conta++;

      }
        else if (c.tipo_conta == "Poupanca"){
        listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(c.nome)],new ContaPoupanca(c.nume_conta,c.saldo,c.aniv)};
          
        num_conta++;
    }
      }
    }
  }
  }

  fin.close(); 

  return true;

}

bool Banco::salvar_dados(DADOS_BANCO c[], int n){
  
  ofstream fout("dados.dat",ios::out);
  
  if (!fout)
    return false;
  
  int cont = 0;
  for (int i = 0 ; i < 100 ; i++){

  if (c[i].p_conta->getConta() != 0){  
      fout << c[i].p_pes->getTipo() << ' '  << c[i].p_pes->getNome() << ' ' << c[i].p_pes->getCpf_or_Cnpj() << ' ' << c[i].p_pes->getRazao() << ' ' << c[i].p_conta->getTipo() << ' ' << c[i].p_conta->getLimite() << ' '<< c[i].p_conta->getAniv() << ' ' << c[i].p_conta->getConta() << ' '<< c[i].p_conta->getSaldo() << ' ' << endl;

      cont++;
      
    }
    if (cont == num_conta){
    break;
    }
  }

  fout.close();
  return true;
}

void Banco::cliente_ou_gerente(){
    int escolha,op;
    cout<<"Bem vindo ao banco" << endl;
    cout << "Digite o numero equivalente ao que voce e:" << endl;
    cout << "1 - Cliente" << endl;
    cout << "2 - Gerente" << endl;
    cout << "Qualquer outro botão encerrara o programa." << endl;
    cin >> escolha;
    system("clear");
    if (escolha == 1 || escolha == 2){
      if (escolha == 2){
        while (op != -1){
        cout << endl;
        cout << "Escolha sua acao:" << endl;
        cout << "1 - Cadastrar nova conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - atualizar conta" << endl;
        cout << "4 - Fechar conta" << endl;
        cout << "5 - Consultar todas as contas" << endl;
        cout << "6 - consultar todas as contas de um correntista" << endl;
        cout << "-1 - voltar ao menu inicial" << endl;
        cin >> op;
        system("clear");
    
        switch(op){
          case 1:
            cadastrar_conta();
            break;
          case 2:{
            int num_cont;
            cout << "Digite o Numero da conta: "<<endl;
            cin >> num_cont;
            consultar_conta(num_cont);
            break;
          }
          case 3:{
            int num_cont = 0;
            cout << "Digite o Numero da conta para atualizarmos: " << endl;
            cin >> num_cont;
            att_conta(num_cont);
            break;
          }
          case 4:{
            int num_cont = 0;
            cout << "Digite o Numero da conta para deletar: " << endl;
            cin >> num_cont;
            remover_conta(num_cont);
            break;

          }
          case 5:{
            consultar_todas_contas();
            break;
          }
          case 6:{
            string nomes;
            cout << "Insira o nome do correntista:" << endl;
            cin.ignore();
            getline(cin,nomes);
            consultar_contas_correntista(nomes);
            break;
          }
          case -1:{
            cliente_ou_gerente();
            break;
          }
        }
        }
      }
      else if (escolha == 1){
        int numero_conta,op;
        cout << endl;
        cout << "Digite o numero de sua conta: "<< endl;
        cin >> numero_conta;
        cout << endl;
        
        int info;
        for (int i =0; i < num_conta;i++){
              if (numero_conta == listaContas[i].p_conta->getConta()){
                info+=1;
              }
        }
        if (info == 0){
          cout << "Numero de conta nao encontrada nos registro,porfavor crie um cadastro com nossos gerentes." << endl;
          cout << endl;
          cliente_ou_gerente();
        }else{

        
        while (op != -1){
        cout << "Escolha sua acao:" << endl;
        cout << "1 - Depositar" << endl;
        cout << "2 - Retirar" << endl;
        cout << "3 - Transferir" << endl;
        cout << "4 - Saldo e extrato" << endl;
        cout << "-1 - Menu Inicial" << endl;
        cin >> op;
        system("clear");
        switch(op){
          case 1:
            float valor;
            cout << "Quanto voce quer depositar?: " << endl;
            cin >> valor;
            for (int i =0; i < num_conta;i++){
              if (numero_conta == listaContas[i].p_conta->getConta()){
                *listaContas[i].p_conta << valor;
              }
              }
            break;
          case 2:{
            float valor;
            cout << "Quanto voce quer Retirar?: " << endl;
            cin >> valor;
            for (int i =0; i < num_conta;i++){
              if (numero_conta == listaContas[i].p_conta->getConta()){
                *listaContas[i].p_conta >> valor;
          }
        }
        break;
      }
      case 3:{
        int conta_t;
        float valor;
        cout << "Digite o numero da conta que vc quer transferir: " << endl;
        cin >> conta_t;
        
        cout << "Digite o valor: " << endl;
        cin >> valor;
        
        int pos = 0;
        int cont = 0;
        for (int i =0; i < num_conta;i++){
          if (conta_t == listaContas[i].p_conta->getConta()){
            pos = i;
            cont++;
          }
        }
        if (cont == 0){
          cout << "Nao foi encontrado nenhuma conta com esse digito." << endl;
          break;
        }

        for (int i =0; i < num_conta;i++){
          if (numero_conta == listaContas[i].p_conta->getConta()){
          listaContas[i].p_conta->transferir(valor,*listaContas[pos].p_conta);
            }
          }

        break;

      }
      case 4:{
        for (int i =0; i < num_conta;i++){
          if (numero_conta == listaContas[i].p_conta->getConta()){
          listaContas[i].p_conta->impressaoExtrato();
      }
      }
      break;

    }
    case -1:{
      cliente_ou_gerente();
      break;
    }
}
    }
        }
}
    }else{
      cout<< "Terminando o programa, obrigado por usar!!" << endl;
      salvar_dados(listaContas,num_conta);
      
    }
}

void Banco::consultar_conta(int numero){
  int cont = 0;
  cout << endl;
  for (int i =0; i < num_conta;i++){
    if (numero == listaContas[i].p_conta->getConta()){
      cont +=1;
      cout << "=========Dados sobre a conta: =========" << endl;
      cout << "Numero da conta: " << listaContas[i].p_conta->getConta() << endl;
      cout << "Nome do correntista: " << listaContas[i].p_pes->getNome() << endl;
      cout << "cpf ou cnpj do correntista: " << listaContas[i].p_pes->getCpf_or_Cnpj() << endl;
      if (listaContas[i].p_pes->getTipo() == "Juridica"){
        cout << "Razao: " << listaContas[i].p_pes->getRazao() << endl;
      }
      cout << "Saldo: " << listaContas[i].p_conta->getSaldo() << endl;
      if (listaContas[i].p_conta->getTipo() == "Corrente"){
        cout << "Limite: " << listaContas[i].p_conta->getLimite() << endl;
      }
      if (listaContas[i].p_conta->getTipo() == "Poupanca"){
        cout << "aniversario: " << listaContas[i].p_conta->getAniv() << endl;
      }
      cout << endl;
      break;
    }
  }
  if (cont == 0){
    cout << "Não foi encontrado a conta" << endl;
    cout << endl;
  }
}

void Banco::consultar_todas_contas(){
  int cont = 0;
  for (int i =0; i < num_conta;i++){
    if (listaContas[i].p_conta->getConta() != 0){
      
      cout << "=========Dados sobre a conta: =========" << endl;
      cout << "Numero da conta: " << listaContas[i].p_conta->getConta() << endl;
      cout << "Nome do correntista: " << listaContas[i].p_pes->getNome() << endl;
      cout << "cpf ou cnpj do correntista: " << listaContas[i].p_pes->getCpf_or_Cnpj() << endl;
      if (listaContas[i].p_pes->getTipo() == "Juridica"){
        cout << "Razao: " << listaContas[i].p_pes->getRazao() << endl;
      }
      cout << "Saldo: " << listaContas[i].p_conta->getSaldo() << endl;
      if (listaContas[i].p_conta->getTipo() == "Corrente"){
        cout << "Limite: " << listaContas[i].p_conta->getLimite() << endl;
      }
      if (listaContas[i].p_conta->getTipo() == "Poupanca"){
        cout << "aniversario: " << listaContas[i].p_conta->getAniv() << endl;
      }
      cout << endl;
      cont++;
    }
      if (cont == num_conta)
        break;
    }
}

void Banco::consultar_contas_correntista(string nome){
    int cont = 0;
    for (int i =0; i < num_conta;i++){
    if (listaContas[i].p_pes->getNome()== nome){
      
      cout << "=========Dados sobre a conta: =========" << endl;
      cout << "Numero da conta: " << listaContas[i].p_conta->getConta() << endl;
      cout << "Nome do correntista: " << listaContas[i].p_pes->getNome() << endl;
      cout << "cpf ou cnpj do correntista: " << listaContas[i].p_pes->getCpf_or_Cnpj() << endl;
      if (listaContas[i].p_pes->getTipo() == "Juridica"){
        cout <<"Razao: " << listaContas[i].p_pes->getRazao() << endl;
      }
      cout << "Saldo: " << listaContas[i].p_conta->getSaldo() << endl;
      if (listaContas[i].p_conta->getTipo() == "Corrente"){
        cout << "Limite: " << listaContas[i].p_conta->getLimite() << endl;
      }
      if (listaContas[i].p_conta->getTipo() == "Poupanca"){
        cout << "aniversario: " << listaContas[i].p_conta->getAniv() << endl;
      }
      cout << endl;
      cont++;
    }
      if (cont == num_conta)
        break;
    }

}

void Banco::att_conta(int numero){
  string novo_nome,razao;
  int novo_num_conta;
  string novo_cpf_cnpj,anive;
  float limite;
  
  for (int i =0; i < 100;i++){
     if (numero == listaContas[i].p_conta->getConta()){
       cout << "=========Atualizar Conta: =======" << endl;
       cout << "O nome é:" << listaContas[i].p_pes->getNome() <<" Digite um novo:" << endl;
      cin.ignore();
      std::getline(cin, novo_nome);
      listaContas[i].p_pes->setNome(novo_nome);
      cout << "O numero da conta é:" << listaContas[i].p_conta->getConta() << " Digite um novo:" << endl;
      cin >> novo_num_conta;
      listaContas[i].p_conta->setConta(novo_num_conta);
      cout << "O CPF/CNPJ da conta é: " << listaContas[i].p_pes->getCpf_or_Cnpj() << " Digite um novo: " << endl;
      cin.ignore();
      std::getline(cin,novo_cpf_cnpj);
      listaContas[i].p_pes->setCPF_OR_CNPJ(novo_cpf_cnpj);
      if (listaContas[i].p_pes->getTipo() =="Juridica"){
        cout << "A Razao Social é: " << listaContas[i].p_pes->getRazao() << " Digite uma nova: " << endl;
        cin.ignore();
        std::getline(cin, razao);
        listaContas[i].p_pes->setRazao(razao);

      }
      if (listaContas[i].p_conta->getTipo() == "Corrente"){
        cout << "O Limite da conta é: " << listaContas[i].p_conta->getLimite() << "Digite um novo: " << endl;
        cin >> limite;
        listaContas[i].p_conta->setLimite(limite);
      }

      if (listaContas[i].p_conta->getTipo() == "Poupanca"){
        cout << "Aniversario: " << listaContas[i].p_conta->getAniv() << "Digite um novo: " << endl;
        cin.ignore();
        std::getline(cin, anive);
        listaContas[i].p_conta->setAniv(anive);

      }
      break;
     }
}
}


void Banco::remover_conta(int numero){
  int cont = 0;
  cout << endl;
  DADOS_BANCO Test;
  for (int i =0; i < num_conta;i++){
    if (numero == listaContas[i].p_conta->getConta()){
      cont+=1;
      delete listaContas[i].p_conta;
      listaContas[i].p_conta = new ContaComum(0,0);
      listaContas[i].p_pes = new PessoaFisica("zero","00");
      
      cout << "Conta deletada com sucesso." << endl;
      break;
    }

  }
  if (cont == 0){
    cout << "Não foi encontrado a conta" << endl;
    cout << endl;
  }
}

void Banco::cadastar_cliente(){
  string nome;
  string cpf;
  cout << endl;
  cout << "======================" << endl;
  cout<<"Seja bem vindo ao cadastro de clientes."<<endl;
  cout<<"Para cadastro de pessoa fisica 1 para cadastro de pessoa Juridica 2: ";
  int op_p;
  cin>>op_p;

  if(op_p==1){
    cout<<"Digite o nome: " << endl;
    cin.ignore();
    std::getline( cin, nome );
     if (encontrar_correntista(nome) != -1){
      cout << "Ja existe uma conta com esse nome. Faca o cadastro de uma nova." << endl;
      cadastrar_conta();
    }else{
    cout<<"Digite o cpf: " << endl;
    //cin.ignore();
    std::getline(cin,cpf);

    listaPessoas[num_pessoas] = new PessoaFisica(nome,cpf);

    cout <<"O cadastro do(a) cliente "<<listaPessoas[num_pessoas]->getNome()<<" foi efetuado com Sucesso."<<endl;
    num_pessoas++;}
  }

    else{
    string RAZAO;
    string cnpj;
    cout<<"Digite o nome: " << endl;
    cin.ignore();
    std::getline(cin, nome );
    if (encontrar_correntista(nome) != -1){
      cout << "Ja existe uma conta com esse nome. Faca o cadastro de uma nova." << endl;
      cadastrar_conta();
    }else{
    
    cout<<"Digite o cnpj: " << endl;
    //cin.ignore();
    std::getline(cin, cnpj);

    cout<<"Digite a razão Social: " << endl;
    //cin.ignore();
    std::getline(cin, RAZAO);

    listaPessoas[num_pessoas] = new PessoaJuridica(nome,RAZAO,cnpj);
    cout<<"O cadastro do(a) cliente "<<listaPessoas[num_pessoas]->getNome()<<" foi efetuado com Sucesso."<<endl;
    num_pessoas++;
    
    }
  }
}

void Banco::cadastrar_conta(){
int conta,cont;
string nome; 
double saldo,limite;string anv; 
cout << "=====================" << endl;
    cout << "Cadastro de Conta." << endl;
    cout<<"A pessoa já poussui Cadastro? "<<endl;
    cout<<"Digite 1 para sim ou 2 para não."<<endl;
    int opp;
    cout<<"Resposta: ";
    cin>>opp;
    system("clear");
    if (opp==2){
      cadastar_cliente();
    }
    int op;
    cout << endl;
    
    while (op != -1){
    cout << "Certo, agora escolha o tipo de conta que voce quer criar:" << endl;
    cout << endl;
    cout << "Opções:" << endl;
    cout << "0 - Conta Comum" << endl;
    cout << "1 - Conta Limite" << endl;
    cout << "2 - Conta Poupança" << endl;
    cout << endl << "-1 - Sair" << endl;
    cout << "Op: ";
    cin >> op;
    system("clear");
    switch (op)
    {

      case 0:
      cout<<"Digite o nome do correntista: ";
      cin.ignore();
      std::getline( cin, nome );
      if (encontrar_correntista(nome) == -1){
        cout << "Erro, Nome nao encontrado nos cadastros,porfavor inicie um novo cadastro." << endl;
        cout << endl;
        break;
      };
      cout<<"Digite o numero da conta: ";
      cin>>conta;
      if (conta <= 0){
        cout << "O numero da conta nao pode conter somente digitos zeros ou ser menor que zero." << endl;
        cout << endl;
        break;
      }else{
      
      for (int i =0; i < num_conta;i++){
        if (conta == listaContas[i].p_conta->getConta()){
          cout << "Erro, Ja existe conta com esse numero, porfavor faca um novo cadastro." << endl;
        cout << endl;
        
        break;
        };
      };
      
      
      cout<<"Digite o saldo da conta: ";
      cin>>saldo;
      listaContas[num_conta]=DADOS_BANCO {listaPessoas[encontrar_correntista(nome)],new ContaComum(conta,saldo)};
      num_conta++;
      system("clear");
      break;}

      case 1:{
      cout<<"Digite o nome do correntista: ";
      cin.ignore();
      std::getline( cin, nome );
      if (encontrar_correntista(nome) == -1){
        cout << "Erro, Nome nao encontrado nos cadastros,porfavor inicie um novo cadastro." << endl;
        cout << endl;
        system("clear");
        break;
      };
      
      cout<<"Digite o numero da conta: ";
      cin >> conta;
      if (conta <= 0){
        cout << "O numero da conta nao pode conter somente digitos zeros ou ser menor que zero." << endl;
        cout << endl;
        break;
      }else{
      for (int i =0; i < num_conta;i++){
          if (conta == listaContas[i].p_conta->getConta()){
            cout << "Erro, Ja existe conta com esse numero, porfavor faca um novo cadastro." << endl;
          cout << endl;
          break;
          }
      }
      cout<<"Digite o saldo da conta: ";
      cin>>saldo;
      cout<<"Digite o limite da conta: ";
      cin>>limite;
      listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(nome)],new ContaCorrente(conta,saldo,limite)};
      num_conta++;
      system("clear");
        break;}}
      
      case 2:
        {
       cout<<"Digite o nome do correntista: ";
      cin.ignore();
      std::getline( cin, nome );
      if (encontrar_correntista(nome) == -1){
        cout << "Erro, Nome nao encontrado nos cadastros,porfavor inicie um novo cadastro." << endl;
        cout << endl;
        system("clear");
        break;
      };
      
      cout<<"Digite o numero da conta: ";
      cin>>conta;

      if (conta <= 0){
        cout << "O numero da conta nao pode conter somente digitos zeros ou ser menor que zero." << endl;
        cout << endl;
        break;
      }else{

      for (int i =0; i < num_conta;i++){
        if (conta == listaContas[i].p_conta->getConta()){
          cout << "Erro, Ja existe conta com esse numero, porfavor faca um novo cadastro." << endl;
          cout << endl;
      
        cont+=1;
        break;
      }
      }
       if (cont >0)
        break;
      

      cout<<"Digite o saldo da conta: ";
      cin>>saldo;
      cout<<"Digite a data de aniversario da conta: ";
      cin>>anv;
      listaContas[num_conta] =  DADOS_BANCO{listaPessoas[encontrar_correntista(nome)],new ContaPoupanca(conta,saldo,anv)};
      num_conta++;
        system("clear");
        break;
      }
        }

      case -1:
        system("clear");
        break;

    }
    }
}