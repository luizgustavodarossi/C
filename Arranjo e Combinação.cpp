#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <windows.h>

void header()
{
	system("cls");//limpando ambiente
	printf("\n\t\tARRANJO E COMBINA��O\n\tDesenvolvido por:Luiz Gustavo Retka Darossi\n",setlocale(LC_ALL,"portuguese"));	
}

int operacao()
{
	int opcao;
	do{
		header();
		printf("\n\tSelecione a Opera��o desejada\n\t[1]-Arranjo Simples\n\t[2]-Arranjo com Repeti��o\n\t[3]Combina��o Simples\n\t[4]Combina��o com Repeti��o\n\t:",setlocale(LC_ALL,"portuguese"));
		scanf("%d",&opcao);	
	}while((opcao!=1)&&(opcao!=2)&&(opcao!=3)&&(opcao!=4));	
	return opcao;
}

double fatorial(int x)
{
	if(x==0){
		return 1;
	}else{
		return (x*fatorial(x-1));
	}
}

void arranjo_simples(int n,int p)
{
	double print={0};
	print=(fatorial(n)/(fatorial(n-p)));
	header();
	printf("\n\tN=Total de elementos do conjunto\n\tP=Quantidade de elementos por agrupamento\n\n\tO resultado do Arranjo simples de N=%d e P=%d � de : %.0f",n,p,print);	
}

void arranjo_repeticao(int n,int p)
{
	double print={0};
	print=pow(n,p);
	header();
	printf("\n\tN=Total de elementos do conjunto\n\tP=Quantidade de elementos por agrupamento\n\n\tO resultado do Arranjo com repeti��o de N=%d e P=%d � de : %.0f",n,p,print,setlocale(LC_ALL,"portuguese"));	
}

void combinacao_simples(int n,int p)
{
	double print={0};
	print=(fatorial(n)/(fatorial(p)*fatorial(n-p)));
	header();
	printf("\n\tN=Total de elementos do conjunto\n\tP=Quantidade de elementos por agrupamento\n\n\tO resultado do Combina��o simples de N=%d e P=%d � de : %.0f",n,p,print,setlocale(LC_ALL,"portuguese"));
}
void combinacao_repeticao(int n,int p)
{
	double print={0};
	print=(fatorial(n+p-1)/(fatorial(p)*fatorial(n-1)));
	header();
	printf("\n\tN=Total de elementos do conjunto\n\tP=Quantidade de elementos por agrupamento\n\n\tO resultado do Combina��o com repeti��o de N=%d e P=%d � de : %.0f",n,p,print,setlocale(LC_ALL,"portuguese"));
}

void principal(void)
{
	//Declara��o das variaveis do escopo
	int n={0},p={0};
	int repete={0},tipo;
	//Entrada de valor para opera��o
	do{
		do{
			do{
				header();
				printf("\n\tInforme n�mero de elementos do conjunto: ",setlocale(LC_ALL,"portuguese"));
				scanf("%d",&n);fflush(stdin);	
			}while(n<=0);
			
			do{
				header();
				printf("\n\tInforme n�mero de elementos do conjunto: %d",n,setlocale(LC_ALL,"portuguese"));
					
				printf("\n\tInforme a quantidade de elementos por agrupamento: ");
				scanf("%d",&p);fflush(stdin);
			
			}while((n<p)||(p<0)||(p==0));
			printf("\tDeseja reiniciar opera��o?\n\t[1]-Sim\n\t[0]-N�o\n\t: ",setlocale(LC_ALL,"portuguese"));//Caso o usu�rio tenha d�gitado dados errados ele ter� a op��o de repetir o procedimento
			scanf("%d",&repete);fflush(stdin);		
		}while(repete==1);
		
		tipo = operacao();//Determina a opera��o
			
		switch(tipo){
			case 1:
				arranjo_simples(n,p);
				break;
			case 2:
				arranjo_repeticao(n,p);
				break;
			case 3:
				combinacao_simples(n,p);
				break;
			case 4:
				combinacao_repeticao(n,p);
				break;
		}	
		printf("\n\t[1]-Continuar calculando\n\t[0]-Sair do programa\n\t:");
		scanf("%d",&repete);fflush(stdin);
	}while(repete==1);	
}


int main(void)
{	/* //Caso queira deixar fullscreen
	keybd_event ( VK_MENU, 0x36, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
	*/
	system("title Arranjo e Combina��o");//Definindo t�tulo
	system("color 02");	//Cor do console
	
	principal();
	return 0;
}
