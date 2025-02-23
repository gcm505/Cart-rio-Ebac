#include <stdio.h>  //biblioteca de comunicação 
#include <stdlib.h> //biblioteca de alocação de espaçoem memoria
#include <locale.h> //biblioteca de alocaçãode texto por região
#include <string.h> //biblioteca de string

int registro () //funcao de cadastro de usuarios
{
	//inicio das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final das variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de valores
	scanf("%s", cpf);//%s = string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
	
}
 
 int consulta () //funcao de consulta de usuarios cadastrados no sistema
 {
 	setlocale(LC_ALL, "Portuguese");  //define a linguagem
	 
	 
	//inicio das variaveis
	char cpf[40];
 	char conteudo[200];
 	//fim das variaveis
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");
	 
	 if (file == NULL)
	 {
	 	printf("CPF não encontrado.\n");
	
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\nEssas são as informações do usuario: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 	
	 }
	 
	 system("pause");
	 
	 
	 
	 
 }

int deletar () //funcao de deletar usuarios cadastrados
{
	//inicio das variaveis
	char cpf[40];
	//fim das variaveis
	
	printf("Digite o cpf a ser excluida: ");
	scanf("%s",cpf);
	
	remove(cpf); //deleta o numero digitado
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (cpf == NULL) //comfirmacao se o cpf digitado existe no sistema
	{
		printf("Esse usuario não existe.\n");
		system("pause");
		
	}
	else 
	{
		printf("O usuario foi deletado.\n");
		system("pause");
	}	
	
}

int main ()
{
	//inicio das variaveis
	int opcao=0; 
	int repeticao =1;
	char senhadigitada[10]="a";
	int comparacao;
	//fim das variaveis
	
	printf("=====Cartório da EBAC===== \n\n");
	printf("Login de administrador\n\nDigite a senha:\n");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); // "strcmp" == Comparação de strings
	
	if (comparacao == 0) 
	{
		system("cls"); //limpa a tela
		
		for(repeticao=1;repeticao=1;)
		{

	
			setlocale(LC_ALL, "Portuguese"); //define a linguagem
	
			system("cls");
	
			printf("=====Cartório da EBAC===== \n\n" ); //menu
			printf("escolha a opção desejada:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair\n\n");
			printf("Opção: ");
	
	
			scanf("%d", &opcao); //ler a opcao escolhida pelo usuario
	
			system("cls");
	
	
			switch(opcao) //chama as funcoes
			{
		 		case 1:
			  		registro();
				break;
	 
 				case 2:
	 				consulta();
	 			break;
	 
	 			case 3:
	 				deletar();	
	 			break;
	 
	 			case 4:
	 				printf("Obrigado por usar o sistema\n");
	 			return 0;
	 			break;
	 
				default:
	 				printf("Esssa opção não existe\n");
	 				system("pause");
	 			break;
			}
		}
 	}
 	else
 		printf("Senha incorreta!!");
	
}
