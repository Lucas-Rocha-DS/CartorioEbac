#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings


int registro () //função para cadastrar os usuários no sistema
{
	//início da criação das variáveis/strings (conj de variáveis) 
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //scanf Busca; %s refere-se a String; cpf é o que será buscado
	
	strcpy(arquivo, cpf); // Resposável por copiar os valores das strings
	
	FILE *file; // cria o arquivo no B.D. ou computador
	file = fopen(arquivo, "w"); //w de escrever
	fprintf(file, cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //a de atualizar
	fprintf(file, ","); // vírgula para deixar correta e com espaço
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
		
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //a de atualizar
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

	
}
int consultar ()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
		{
			printf("Não foi possível abrir o arquivo, não localizado!.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
}

int deletar ()
{
	char cpf[40]; //variável ou string, char também pode receber números
	
	printf("Digite o CPF do usuário a ser deletado:"); // msg que vai aparecer para o usuário
	scanf("%s", cpf); //vai salvar tudo o que o usuário digitar e salvar onde a gente pedir
	
	
	FILE *file; // FILE é a biblioteca da função, *file é puxar os arquivos
	file = fopen(cpf,"r"); //fopen é a função de abrir, "r" de ler
	fclose(file);
	
	if(file == NULL) //se o arquivo for igual a null não existe
	{
		printf("Usuário não encontrado no sistema!\n\n");
		system("pause");
	}
	
	else
	{
		if(remove(cpf) == 0) //se o arquivo for encontrado, então deletar
		{
			printf("Usuário deletado com sucesso!\n\n");
			system("pause");
		}
	}
	
}



int main ()
{
	int opcao=0; // Definindo as variáveis
	int laco=1;
	setlocale(LC_ALL, "Portuguese");
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("Cartório da EBAC\n\n");
	printf("Login de Administrador\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");	
		for (laco=1; laco=1;)	
		{
	
			system ("cls"); //limpar a tela do menu e mostrar item escolhido
		
			setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
			printf("Cartório da EBAC\n\n"); // Início do Menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção:"); // Fim do Menu
	
			scanf("%d", &opcao); // Armazenando a escolha do usuário
		
			system("cls");
	
			switch(opcao) //início da seleção do Menu
			{
				case 1:
				registro (); //chamada de funções
				break;
			
				case 2:
				consultar ();
				break;
			
				case 3:
				deletar ();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0; //quebra laço, sai do sistema
				break;
						
				default:
				printf("Essa opção não está disponível\n");
				system("pause");
				break;
			
			}	
		}
	}
	
	else
		printf("\n\nSenha incorreta!");
		
}
