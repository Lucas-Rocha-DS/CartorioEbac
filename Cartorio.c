#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings


int registro () //fun��o para cadastrar os usu�rios no sistema
{
	//in�cio da cria��o das vari�veis/strings (conj de vari�veis) 
	char arquivo [40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //scanf Busca; %s refere-se a String; cpf � o que ser� buscado
	
	strcpy(arquivo, cpf); // Respos�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no B.D. ou computador
	file = fopen(arquivo, "w"); //w de escrever
	fprintf(file, cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //a de atualizar
	fprintf(file, ","); // v�rgula para deixar correta e com espa�o
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
			printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
		}
	
	while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
}

int deletar ()
{
	char cpf[40]; //vari�vel ou string, char tamb�m pode receber n�meros
	
	printf("Digite o CPF do usu�rio a ser deletado:"); // msg que vai aparecer para o usu�rio
	scanf("%s", cpf); //vai salvar tudo o que o usu�rio digitar e salvar onde a gente pedir
	
	
	FILE *file; // FILE � a biblioteca da fun��o, *file � puxar os arquivos
	file = fopen(cpf,"r"); //fopen � a fun��o de abrir, "r" de ler
	fclose(file);
	
	if(file == NULL) //se o arquivo for igual a null n�o existe
	{
		printf("Usu�rio n�o encontrado no sistema!\n\n");
		system("pause");
	}
	
	else
	{
		if(remove(cpf) == 0) //se o arquivo for encontrado, ent�o deletar
		{
			printf("Usu�rio deletado com sucesso!\n\n");
			system("pause");
		}
	}
	
}



int main ()
{
	int opcao=0; // Definindo as vari�veis
	int laco=1;
	setlocale(LC_ALL, "Portuguese");
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("Cart�rio da EBAC\n\n");
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
	
			printf("Cart�rio da EBAC\n\n"); // In�cio do Menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:"); // Fim do Menu
	
			scanf("%d", &opcao); // Armazenando a escolha do usu�rio
		
			system("cls");
	
			switch(opcao) //in�cio da sele��o do Menu
			{
				case 1:
				registro (); //chamada de fun��es
				break;
			
				case 2:
				consultar ();
				break;
			
				case 3:
				deletar ();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0; //quebra la�o, sai do sistema
				break;
						
				default:
				printf("Essa op��o n�o est� dispon�vel\n");
				system("pause");
				break;
			
			}	
		}
	}
	
	else
		printf("\n\nSenha incorreta!");
		
}
