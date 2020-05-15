#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Cliente{
	int idade;
	string cpf;
	int sexo;
	int gravida;
	struct Cliente *prox;
};

Cliente *criarCliente() {

	Cliente *novo = new Cliente;
	return novo;

}

Cliente *inserirInicio(Cliente *fila, int idade, string cpf, int sexo, int gravida) {

	Cliente *novoCliente = criarCliente();
	novoCliente->idade = idade;
	novoCliente->cpf = cpf;
	novoCliente->sexo = sexo;
	novoCliente->gravida = gravida;

	if (fila == NULL) {
		fila = novoCliente;
		novoCliente->prox = NULL;
	}
	else
	{
		novoCliente->prox = fila;
		fila = novoCliente;
	}
	return fila;
}

Cliente *inserirFim(Cliente *fila, int idade, string cpf, int sexo, int gravida) {
	Cliente *novoCliente = criarCliente();
	novoCliente->idade = idade;
	novoCliente->cpf = cpf;
	novoCliente->sexo = sexo;
	novoCliente->gravida = gravida;

	if (fila == NULL) {
		novoCliente->prox = NULL;
		fila = novoCliente;
	} else {
		Cliente *aux = fila;
		while (aux->prox!=NULL) {
			aux=aux->prox;
		}
		novoCliente->prox=NULL;
		aux->prox=novoCliente;
	}
	return fila;
}

Cliente *inserirMeio(Cliente *fila, int idade, string cpf, int sexo, int gravida, int posicao) {

	Cliente *novoCliente = criarCliente();
	novoCliente->idade = idade;
	novoCliente->cpf = cpf;
	novoCliente->sexo = sexo;
	novoCliente->gravida = gravida;

	Cliente *aux = fila;

	for(int i;i<posicao;i++) {
		aux++;
	}
	novoCliente->prox=aux->prox;
	aux->prox=novoCliente;

	return fila;
}

void imprimirFila(Cliente *fila) {

	Cliente *aux = fila;
	
	cout << "Ordem da fila" << endl;
	while (aux != NULL) {
		cout << aux->cpf << endl;
		aux = aux->prox;
	}

}

Cliente cadCliente(Cliente pessoa) {
	cout << "--Digite a idade--" << endl;
	cin >> (pessoa.idade);
	system("CLS");
	cout << "--Digite o cpf--" << endl;
	cin >> (pessoa.cpf);
	system("CLS");
	cout << "--Digite o sexo (1 - Feminino | 2 - Masculino)--" << endl;
	cin >> (pessoa.sexo);
	system("CLS");
	if (pessoa.sexo == 1) {
		cout << "--A cliente esta gravida? (1 - sim | 2 - nao)--" << endl;
		cin >> (pessoa.gravida);
		system("CLS");
	}
	return (pessoa);
}

Cliente *opt1(Cliente pessoa, Cliente *fila) {
	string entrou = "s";
	int contPrioridade = 0;

	while (entrou != "n" && entrou == "s") {
	cout << "Alguem entrou na fila? (s/n)\n";
	cin >> (entrou);
	if (entrou == "s") {
		pessoa = cadCliente(pessoa);

		if (pessoa.idade >= 65 || pessoa.gravida == 1){
			if (contPrioridade > 0) {
				fila=inserirMeio(fila, pessoa.idade, pessoa.cpf, pessoa.sexo, pessoa.gravida, contPrioridade);
			} else {
				fila=inserirInicio(fila, pessoa.idade, pessoa.cpf, pessoa.sexo, pessoa.gravida);
			}
			contPrioridade++;
		}
		else {
			fila=inserirFim(fila, pessoa.idade, pessoa.cpf, pessoa.sexo, pessoa.gravida);
		}
	}
	}
	system("CLS");
	return fila;
}

Cliente *proximoCliente(Cliente *fila) {
	cout << "Chamando o cliente: ";
	cout << fila->cpf << endl;
	fila = fila->prox;
	return fila;
}

int main()
{
	Cliente *fila=NULL;
	Cliente pessoa;
	int opt;

	while (opt != 0) {

		cout << "Fila de atendimento bancario" << endl;
		cout << "Digite 1 para registrar um novo cliente" << endl;
		cout << "Digite 2 para chamar o proximo cliente" << endl;
		cout << "Digite 3 para mostrar os clientes na fila" << endl;
		cout << "Digite 0 para sair do programa" << endl;

		cout << "Digite a opcao: ";
		cin>>opt;

		switch (opt) {
			case 1:
				system("CLS");
				fila = opt1(pessoa, fila);
				break;
			case 2:
				system("CLS");
				if (fila != NULL){
					fila = proximoCliente(fila);
				} else {
					cout << "Nao existe fila no momento, por favor registre algum cliente!" << endl;
					cout << "Pressione ENTER para voltar ao menu." << endl;
					system("PAUSE");
					system("CLS");
				}
				break;
			case 3:
				system("CLS");
				if (fila != NULL){
					imprimirFila(fila);
				} else {
					cout << "Nao existe fila no momento, por favor registre algum cliente!" << endl;
					cout << "Pressione ENTER para voltar ao menu." << endl;
					system("PAUSE");
					system("CLS");
				}
				break;
		}
	}

	
	return 0;
}
