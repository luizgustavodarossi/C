#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
typedef struct{
	
	int cod;
	char nome[40];
	char email[40];
	char telefone[14];
	
}USUARIO;


int menu(void){
	//declaração de variáveis do escopo
	int read;
	
	do
	{
		//leitura das opções do menu
		printf("	MENU PRINCIPAL\n");
		printf("[1]-Inserir um novo Cadastro\n");
		printf("[2]-Mostrar todos os Cadastros\n");
		printf("[3]-Ordenar cadastros\n");
		printf("[4]-Aumentar quantidade de clientes na agenda\n");
		printf("[0]-Encerrar\n");
			
		scanf("%d",&read);fflush(stdin);
		system("cls");
		if((read!=1)&&(read!=2)&&(read!=0)&&(read!=3)&&(read!=4)){
			printf("Erro: Opção inválida!\n",setlocale(LC_ALL,"portuguese"));
		}	
	}while((read!=1)&&(read!=2)&&(read!=0)&&(read!=3)&&(read!=4));
	
	return read;
}


int menuOrdenacao(void)
{
	int read;
	do
	{
		printf("[1]-Ordenar A-Z \n");
		printf("[2]-Ordenar Z-A\n");
		printf("[3]-Ordenar Primeiro-Último\n",setlocale(LC_ALL,"portuguese"));
		printf("[4]-Ordenar Último-Primeiro\n",setlocale(LC_ALL,"portuguese"));
		printf("[0]-Sair da operação\n",setlocale(LC_ALL,"portuguese"));
		
		scanf("%d",&read);fflush(stdin);
		system("cls");
		if((read!=1)&&(read!=2)&&(read!=0)&&(read!=3)&&(read!=4)){
			printf("Erro: Opção inválida!\n",setlocale(LC_ALL,"portuguese"));
		}	
	}while((read!=1)&&(read!=2)&&(read!=0)&&(read!=3)&&(read!=4));
	
	return read;
}


void ordena(USUARIO *CI,USUARIO *CJ, int op){
	
	USUARIO troca;
	if(op==1){
		if(strcmp(CI->nome,CJ->nome)>0)
		{
								
			troca.cod=CI->cod;
			strcpy(troca.nome,CI->nome);
			strcpy(troca.telefone,CI->telefone);
			strcpy(troca.email,CI->email);
								
			CI->cod=CJ->cod;
			strcpy(CI->nome,CJ->nome);
			strcpy(CI->telefone,CJ->telefone);
			strcpy(CI->email,CJ->email);
							
			CJ->cod=troca.cod;
			strcpy(CJ->nome,troca.nome);
			strcpy(CJ->telefone,troca.telefone);
			strcpy(CJ->email,troca.email);
		}	
	}
	else if(op==2){
		if(strcmp(CI->nome,CJ->nome)<0)
		{
								
			troca.cod=CI->cod;
			strcpy(troca.nome,CI->nome);
			strcpy(troca.telefone,CI->telefone);
			strcpy(troca.email,CI->email);
								
			CI->cod=CJ->cod;
			strcpy(CI->nome,CJ->nome);
			strcpy(CI->telefone,CJ->telefone);
			strcpy(CI->email,CJ->email);
							
			CJ->cod=troca.cod;
			strcpy(CJ->nome,troca.nome);
			strcpy(CJ->telefone,troca.telefone);
			strcpy(CJ->email,troca.email);
		}
	}else if(op==3){
		if(CI->cod>CJ->cod)
		{
								
			troca.cod=CI->cod;
			strcpy(troca.nome,CI->nome);
			strcpy(troca.telefone,CI->telefone);
			strcpy(troca.email,CI->email);
								
			CI->cod=CJ->cod;
			strcpy(CI->nome,CJ->nome);
			strcpy(CI->telefone,CJ->telefone);
			strcpy(CI->email,CJ->email);
							
			CJ->cod=troca.cod;
			strcpy(CJ->nome,troca.nome);
			strcpy(CJ->telefone,troca.telefone);
			strcpy(CJ->email,troca.email);
		}
	}else if(op==4){
		if(CI->cod<CJ->cod)
		{
								
			troca.cod=CI->cod;
			strcpy(troca.nome,CI->nome);
			strcpy(troca.telefone,CI->telefone);
			strcpy(troca.email,CI->email);
								
			CI->cod=CJ->cod;
			strcpy(CI->nome,CJ->nome);
			strcpy(CI->telefone,CJ->telefone);
			strcpy(CI->email,CJ->email);
							
			CJ->cod=troca.cod;
			strcpy(CJ->nome,troca.nome);
			strcpy(CJ->telefone,troca.telefone);
			strcpy(CJ->email,troca.email);
		}
	}	
}


void cadastrar(USUARIO *CadCliente,int *cont)
{
		
	CadCliente->cod=(100+(*cont));fflush(stdin); //Codigo dos clientes inicia em 100.
	
	printf("Informe seu nome completo: ");
	scanf("%40[^\n]s",strupr(CadCliente->nome));fflush(stdin);
	
	printf("\nInforme seu telefone no formato (DD)9XXXX-XXXX: ");
	scanf("%14[^\n]s",CadCliente->telefone);fflush(stdin);
	
	printf("\nInforme seu E-mail: ");
	scanf("%40s",CadCliente->email);fflush(stdin);
	
}


void imprimir(USUARIO impCliente)
{	
    FILE *Relatorio;
    Relatorio= fopen("Relatório Cliente Cadastrados.txt", "w+");   
	if (Relatorio == NULL)   
	{      
		printf ("O arquivo não foi aberto. Ocorreu um erro!\n");   
	}else
	{
		printf("-----------------------------------------------------------");
		printf("\nCódigo: %d",impCliente.cod,setlocale(LC_ALL,"portuguese"));
		printf("\nNome: %s",impCliente.nome,setlocale(LC_ALL,"Portuguese"));
		printf("\nTelefone: %s",impCliente.telefone,setlocale(LC_ALL,"portuguese"));	
		printf("\nE-mail: %s",impCliente.email,setlocale(LC_ALL,"portuguese"));
		printf("\n-----------------------------------------------------------\n");	
	}
	fclose(Relatorio);
	
}


int main(void){
	
	int cont={0},cad={1},op,ordem,achou;
	char pesquisa[40];
	int tamanho,aumTam;//variaveis relacionadas ao tamanho da agenda
	int i,j;//Incremento
	do
	{
		system("cls");
		printf("Determine a quantidade máxima de clientes a serem inseridos em sua agenda: ",setlocale(LC_ALL,"portuguese"));
		scanf("%d",&tamanho);//define tamanho da agenda	
		system("cls");
	}while(tamanho<=0);
	USUARIO cliente[tamanho];
	do
	{
		op=menu();	
		if(op==1)//Opção cadastrar
		{	
				while((cont<tamanho)&&(cad==1))
				{	
					cadastrar(&cliente[cont],&cont);//Chama função para cadastro de cliente
					cont++;
					do
					{
						system("cls");
						printf("Deseja cadastrar mais um cliente em sua agenda?\n[1]Sim\n[0]Não\n",setlocale(LC_ALL,"portuguese"));
						scanf("%d",&cad);fflush(stdin);
						system("cls");	
					}while((cad!=1)&&(cad!=0));
					
				}
				cad=1;
				if(cont==tamanho)
				{
					printf("	Agenda lotada!\n");
				}
				
				
		}else if(op==2)//Opção mostrar cadastros
		{
			if(cont==0)
			{
					printf("	Agenda vazia!\n");
			}else
			{
				for(i=0;i<cont;i++)
				{
					imprimir(cliente[i]);	
				}
					
			}
		}else if(op==3)//Opção Ordenar cadastros
		{
			if(cont<2)
			{
				printf("	Impossível ordenar!\n	Cadastre mais clientes\n",setlocale(LC_ALL,"portuguese"));
			}else
			
			{
				ordem=menuOrdenacao();
				if(ordem==1)//Ordena A-Z
				{
					
					for(i=0;i<cont;i++)
					{
						for(j=i+1;j<cont;j++)
						{
							ordena(&cliente[i],&cliente[j],ordem);
						}
					}
						
				}else if(ordem==2)//Ordena Z-A
				{
					
					for(i=0;i<cont;i++)
					{
						for(j=i+1;j<cont;j++)
						{
							ordena(&cliente[i],&cliente[j],ordem);
						}
					}
				}
				else if(ordem==3)//Ordena por ordem de cadastro
				{
					
					for(i=0;i<cont;i++)
					{
						for(j=i+1;j<cont;j++)
						{
							ordena(&cliente[i],&cliente[j],ordem);

						}
					}
				}else if(ordem==4)//Ordena do último ao primeiro
				{
					
					for(i=0;i<cont;i++)
					{
						for(j=i+1;j<cont;j++)
						{
							ordena(&cliente[i],&cliente[j],ordem);
						}
					}
				}	
			}							
		
		}else if(op==4)//Opção aumenta tamanho agenda
		{
			system("cls");
			do
			{
				printf("O Tamanho da sua agenda atual é de: %d cliente(s)\n",tamanho,setlocale(LC_ALL,"portuguese"));
				printf("Dígite 0(zero) para sair desse opção.\n",setlocale(LC_ALL,"portuguese"));
				printf("Dígite a quantidade a mais de clientes que deseja adicionar: ",setlocale(LC_ALL,"portuguese"));
				scanf("%d",&aumTam);fflush(stdin);
				system("cls");
				if(aumTam<0)
				{
					printf("	VALOR INVÁLIDO!\n",setlocale(LC_ALL,"portuguese"));
				}	
			}while((aumTam<0));
			
			tamanho+=aumTam;
			USUARIO cliente[tamanho];
		}
			
	}while(op!=0);
		
	return 0;
}
