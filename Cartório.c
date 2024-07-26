#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //cadastrar os usu�rios no sistema
{
    //in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
   	char cidade[200];
	char cargo[40];
    //final da cria��o de vari�veis/strings
    
    printf("Digite seu cpf: "); //coletar informa��es do usu�rio 
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //copiar os valores das strings
    
    FILE *file; //criar o arquivo
    file = fopen(arquivo, "w"); //"w" significa escrever
    fprintf(file, cpf); //salvar o valor da vari�vel
    fclose(file); //fechar o arquivo
    
    file = fopen(arquivo, "a"); //abrir o arquivo e "a" significa atualizar
    fprintf(file, ", "); //adicionar v�rgula para informa��es subsequentes
    fclose(file); //fechar o arquivo
    
    printf("Digite o seu nome: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);
    
    printf("Digite o seu sobrenome: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);
    
    printf("Digite a cidade/estado onde voc� mora: ");
    scanf("%s", cidade);
    
    file = fopen(arquivo, "a");
    fprintf(file, cidade);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);
	
	printf("Digite a sua ocupa��o: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

}

int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); //definir o idioma da interface
	   	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf que deseja consultar: "); 
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n\nEste cpf n�o consta no banco de dados\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
}

int deletar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf); //remover arquivo salvo
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Este CPF n�o consta no sistema\n");
		system("pause");
	}
	
	if(fgets(conteudo, 40, file) != NULL)
	{
		printf("\n\nO registro foi deletado com sucesso");
		system("pause");
	}	
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //limpar a tela
	
	setlocale(LC_ALL, "Portuguese");
	
	   printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu principal
	   printf("Escolha a op��o desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Op��o: "); //fim do menu principal
	
	   scanf("%d", &opcao); //armazenar a escolha do usu�rio
	
	   system("cls");
	   
	   switch(opcao) //in�cio sele��o menu principal
	   {
	   	case 1:
           registrar();
		   system("pause"); //chamar fun��es
		   break;
		   
		case 2:
		   consultar();
		   system("pause");
		   break;
		   
	    case 3:
	       deletar();
		   system("pause");
		   break;
		
	    default:
	       printf("Essa op��o n�o est� dispon�vel\n");
		   system("pause");
		   break;
	    	
	   }
    }
}
