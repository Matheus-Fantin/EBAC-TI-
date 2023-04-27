#include <stdio.h> //bibliotrca de comunica��o com o usu�rio;
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria;
#include <locale.h> //biblioteca de aloca��oes de texto por regi�o;
#include <string.h> //biblioteca respons�vel por cuidar da string
	
int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema 
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�vel/string
	printf("Digite o CPF a ser cadastrado: "); //coletano informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletano informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,nome); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletano informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,sobrenome); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletano informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,cargo); //salvo o valor da variavel
	fclose(file); //fecha o arquivo	
	
    system("pause");

}

int consultar() //Fun��o responsavel por fazer a consulta do usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
char cpf[40];
char conteudo[200];
	
printf("Digite o CPF a ser consultado: "); //coletano informa��o do usu�rio
scanf("%s",cpf); //%s refere-se a string
  	
FILE *file; //cria o arquivo
file = fopen(cpf,"r"); //cria o arquivo 
  	
if(file == NULL)
{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
}
	
while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");
	
	
}

int deletar() //Fun��o responsavel por deletar os usu�rios do sistema
{
	char cpf[40];
	
	printf("digite o CPF a ser deletado: ");
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsavel por limpar 
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");	
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu

		scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar 
	
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
		
			case 2:
			consultar();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel!\n");
			system("pause");
			break;	
		}//fim da sele��o	
	
	}	
	
}
