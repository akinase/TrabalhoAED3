#include <iostream>
#include <string>
//#include "Dicionario.h"
#include "ABB.h"
using namespace std;

class Pessoa
{
public:
	string nome;
	int idade;
        Dicionario<int, Pessoa> * arvoreDeAmigos;
	Pessoa();
	Pessoa(string n, int i);	
	void Imprime();
};

Pessoa::Pessoa()
{
	nome = "vazio";
	idade = 0;
        arvoreDeAmigos = new Dicionario<int, Pessoa>();
}

Pessoa::Pessoa(string n, int i)
{
	nome = n;
	idade = i;
        arvoreDeAmigos = new Dicionario<int, Pessoa>();
}

void Pessoa::Imprime()
{
	cout << nome << "-" << idade << endl;
}

int main()
{
	string opcao;
	cin >> opcao;

	Dicionario<int, Pessoa> arvorePrincipalPessoas;

	while(opcao != "SAIR")
	{
		if(opcao == "INSERIR")
		{
			string nome, lixo;
			int chave;
			int idade;
			cin >> chave;
			getline(cin, lixo);
			getline(cin, nome);
			cin >> idade;	
				
			Pessoa p(nome, idade);
		
			arvorePrincipalPessoas.Inserir(chave, p);
		}
                else if(opcao == "INSERIRAMIGO")
		{
 
                        int chaveRaiz;
                        cout << "DIGITE O ID do amigo RAIZ"<< endl;
                        cin >> chaveRaiz;                      
			int chavemigs;
			cout << "DIGITE O ID DO AMIGO A SER INSERIDO"<< endl;
			cin >> chavemigs;
                        
                        cout << "#########LIsta de Amigos#########"<< endl;
                        Pessoa raiz = arvorePrincipalPessoas.Buscar(chaveRaiz);                       
                        Pessoa amigo = arvorePrincipalPessoas.Buscar(chavemigs);
                        
                        raiz.arvoreDeAmigos->Inserir(chavemigs, amigo);
                        amigo.arvoreDeAmigos->Inserir(chaveRaiz, raiz);  
                        
                        //IMPRINDO A SUBARVORE DO NÓ
                        raiz.arvoreDeAmigos->Imprime();
            
		}
		else if(opcao ==  "BUSCAR")
		{
			int chave;
			cin >> chave;
			Pessoa p = arvorePrincipalPessoas.Buscar(chave);
			p.Imprime();
		}
                else if (opcao == "CAMINHO")
                {
                        int chave1, chave2, soma;
                        cout << "Digite o id de um dos amigos"<< endl;
                        cin >> chave1;
                        cout << "Digite o id do segundo amigo"<< endl;
                        cin >> chave2;

                        Pessoa origem = arvorePrincipalPessoas.Buscar(chave1); 

                        arvorePrincipalPessoas.ImprimeCaminho(chave1, chave2);
       
                }
                
		else if(opcao == "REMOVER")
		{
			int chave;
			cin >> chave;
                        //não precisa atribuir a uma pessoa para remover
			//Pessoa p = arvorePrincipalPessoas.Remover(chave);
                        arvorePrincipalPessoas.Remover(chave);
		}
                
                else if (opcao == "REMOVERAMIZADE")
                {
                        int chaveRaiz;
                        cout << "DIGITE O ID do amigo RAIZ"<< endl;
                        cin >> chaveRaiz;                      
			int chavemigs;
			cout << "DIGITE O ID do amigo à ser REMOVIDO"<< endl;
			cin >> chavemigs;
                        
                        cout << "#########LIsta de Amigos atualizado#########"<< endl;
                        Pessoa raiz = arvorePrincipalPessoas.Buscar(chaveRaiz);                       
                        Pessoa amigo = arvorePrincipalPessoas.Buscar(chavemigs);
                        
                        amigo.arvoreDeAmigos->Remover(chaveRaiz);
                        raiz.arvoreDeAmigos->Remover(chavemigs);
                        
                }
		else if(opcao == "IMPRIMIR")
		{
			arvorePrincipalPessoas.Imprime();
		}
                else if  (opcao == "IMPRIMIRAMIZADE")
                {
                        int chaveRaiz;
                        cout << "Digite o ID da pessoa que queira ver a(s) amizade(s)"<< endl;
                        cin >> chaveRaiz;  
                    
                        Pessoa raiz = arvorePrincipalPessoas.Buscar(chaveRaiz);
                    
                        raiz.arvoreDeAmigos->Imprime();                    
                }
                
                                
		cin >> opcao;
	}
}
