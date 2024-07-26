#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //cadastrar os usuários no sistema
{
    //início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
   	char cidade[200];
	char cargo[40];
    //final da criação de variáveis/strings
    
    printf("Digite seu cpf: "); //coletar informações do usuário 
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //copiar os valores das strings
    
    FILE *file; //criar o arquivo
    file = fopen(arquivo, "w"); //"w" significa escrever
    fprintf(file, cpf); //salvar o valor da variável
    fclose(file); //fechar o arquivo
    
    file = fopen(arquivo, "a"); //abrir o arquivo e "a" significa atualizar
    fprintf(file, ", "); //adicionar vírgula para informações subsequentes
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
    
    printf("Digite a cidade/estado onde você mora: ");
    scanf("%s", cidade);
    
    file = fopen(arquivo, "a");
    fprintf(file, cidade);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);
	
	printf("Digite a sua ocupação: ");
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
		printf("\n\nEste cpf não consta no banco de dados\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n\nEssas são as informações do usuário: ");
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
		printf("Este CPF não consta no sistema\n");
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
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //limpar a tela
	
	setlocale(LC_ALL, "Portuguese");
	
	   printf("### Cartório da EBAC ###\n\n"); //início do menu principal
	   printf("Escolha a opção desejada do menu:\n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n");
	   printf("Opção: "); //fim do menu principal
	
	   scanf("%d", &opcao); //armazenar a escolha do usuário
	
	   system("cls");
	   
	   switch(opcao) //início seleção menu principal
	   {
	   	case 1:
           registrar();
		   system("pause"); //chamar funções
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
	       printf("Essa opção não está disponível\n");
		   system("pause");
		   break;
	    	
	   }
    }
}
