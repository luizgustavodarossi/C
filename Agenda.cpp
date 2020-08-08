#include <stdio.h>
#include <stdlib.h>
/*Criando uma agenda telefonica*/
/*Todos os system("cls") s�o apenas para a est�tica do programa, deixar bonito*/

/*Cria��o do registro para a agenda*/
typedef struct {
	int cod;
	char nome[30];
	char telefone[14];
}Usuario_Agenda;//nome do registro

/*Menu inicial*/
int menu(void){
	int aux;
	printf("\tAGENDA TELEFONICA\n1-Cadastrar\n2-Mostrar\n0-Sair\n:");
	scanf("%d",&aux);fflush(stdin);
	return aux;
}

void cadastrar(Usuario_Agenda *cad){//Passagem de parametro por referencia
	
	printf("Informe o codigo: ");
	scanf("%d",&cad->cod);fflush(stdin);//Observe a sintaxe para ler um vetor por referencia (->)
	printf("Informe seu nome: ");
	scanf("%30[^\n]s",cad->nome);fflush(stdin);
	printf("Infore seu telefone: ");
	scanf("%14s",cad->telefone);fflush(stdin);
	system("cls");
}

void mostrar(Usuario_Agenda imprime){//passagem de parametro por valor
	printf("CODIGO:%d\nNOME: %s\nTELEFONE: %s\n\n",imprime.cod,imprime.nome,imprime.telefone);//Sintaxe do parametro por valor usamos (.)	
}
int main(void){
	#define TAM 3//define o tamanho da agenda
	/*Declarando variaveis do escopo*/
	int opcao,i,cont={0};
	Usuario_Agenda cad_usuario[TAM];
	
	do{
		opcao = menu();//Chama a fun��o menu()
		switch(opcao){
			case 1:
				if(cont<TAM){
					system("cls");
					for(i=0;i<TAM;i++){
						cadastrar(&cad_usuario[i]);//Chama fun��o para cadastrar, passagem parametros por refer�ncia
						cont++;	
					}
						
				}else{
					system("cls");
					printf("Agenda Lotada!!\n");
				}
				
				break;
				
			case 2:
				system("cls");
				if(cont!=0){
					for(i=0;i<TAM;i++){
						mostrar(cad_usuario[i]);//Chama fun��o para exibi��o, passagem de parametro por valor	
					}	
				}else{
					system("cls");
					printf("Agenda Vazia!\n");
				}
				
				break;
		}
	}while(opcao != 0);//Ao d�gita 0 o programa finaliza
}
