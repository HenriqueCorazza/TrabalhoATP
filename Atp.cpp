#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>

#define TF 100

struct tpData
{
	int d,m,a;
};

struct tpProdutos
{
	int CodProd,Estoque,CodForn;
	float Preco;
	tpData DtValidade;
	char Descr[30];
};
					  
struct tpFornecedores
{
	int CodForn;
	char NomeForn[30], Cidade[30];
};

struct tpClientes
{
	int QtdeCompras;
	float ValorTotComp;
	char cpf[11], NomeC[30];
};

struct tpVendas
{
	int CodVenda;
	char cpf[11];
	tpData DtVenda;
	float TotVenda;
};

struct tpVendas_Prod
{
	int Qtde, CodVenda, CodProd;
	float ValorUni;
};

void Moldura(int CI,int LI,int CF,int LF,int CorT,int CorF)
{
	int i;
	
	textcolor(5);
	textbackground(15);
	
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
	
	textcolor(0);
}

void Preenche(void)
{
	int i,j;
	textbackground(15);
	for (i=1;i<81;i++)
		for(j=1;j<26;j++)
		{
			gotoxy(i,j);
			printf("%c",255);
		}
}

void LimpaEntrada(void)
{
	int i;
	for(i=38;i<78;i++)
	{
		gotoxy(i,19);
		printf("%c",255);
	}
	gotoxy(39,19);
}

void LimpaTela(void)
{
	int i,j;
	
	for(i=29;i<79;i++)
		for(j=6;j<18;j++)
		{
			gotoxy(i,j);
			printf("%c",255);
		}
}

void InicioTela(int &C, int &L)
{
	LimpaTela();
	C=31;
	L=7;
	gotoxy(C,L);
}

void LimpaMenu(void)
{
	int i,j;
	for(i=3;i<27;i++)
		for(j=6;j<21;j++)
		{
			gotoxy(i,j);
			printf("%c",255);
		}
}

void LimpaMsg(void)
{
	int i;
	
	for(i=13;i<79;i++)
	{
		gotoxy(i,23);
		printf("%c",255);
	}
}

void EscrMsg(void)
{
	LimpaMsg();
	gotoxy(14,23);
}

void MenuFornecedor(void)
{
	Moldura(1,1,80,25,1,15);
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	LimpaEntrada();
	gotoxy(3,7);
	printf("Fornecedores: ");
	gotoxy(3,9);
	printf("[A] Cadastro:");
	gotoxy(3,10);
	printf("[B] Consulta:");
	gotoxy(3,11);
	printf("[C] Exclusao");
	gotoxy(3,12);
	printf("[D] Alteracao");
	gotoxy(3,13);
	printf("[E] Relatorio");
	gotoxy(3,14);
	printf("[F] Aumento de Precos");
	gotoxy(3,19);
	printf("[R] Voltar");
	gotoxy(31,7);
	printf("Selecione Uma Operacao:");
	gotoxy(39,19);
}

void MenuCliente(void)
{
	Moldura(1,1,80,25,1,15);
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	gotoxy(3,7);
	printf("Clientes: ");
	gotoxy(3,9);
	printf("[A] Cadastro:");
	gotoxy(3,10);
	printf("[B] Consulta:");
	gotoxy(3,11);
	printf("[C] Exclusao");
	gotoxy(3,12);
	printf("[D] Alteracao");
	gotoxy(3,13);
	printf("[E] Relatorio");
	gotoxy(3,19);
	printf("[R] Voltar");
	gotoxy(31,7);
	printf("Selecione Uma Operacao:");
	gotoxy(39,19);
}

void MenuProduto(void)
{
	Moldura(1,1,80,25,1,15);
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	gotoxy(3,7);
	printf("Produtos: ");
	gotoxy(3,9);
	printf("[A] Cadastro:");
	gotoxy(3,10);
	printf("[B] Consulta:");
	gotoxy(3,11);
	printf("[C] Exclusao");
	gotoxy(3,12);
	printf("[D] Alteracao");
	gotoxy(3,13);
	printf("[E] Relatorio");
	gotoxy(3,19);
	printf("[R] Voltar");
	gotoxy(31,7);
	printf("Selecione Uma Operacao:");
	gotoxy(39,19);
}

void MenuVendas(void)
{
	Moldura(1,1,80,25,1,15);
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	LimpaEntrada();
	gotoxy(3,7);
	printf("Vendas: ");
	gotoxy(3,9);
	printf("[A] Realizar Venda:");
	gotoxy(3,10);
	printf("[B] Vendas/Produto:");
	gotoxy(3,11);
	printf("[C] Vendas/Cliente");
	gotoxy(3,12);
	printf("[D] Relatorio de Vendas");
	gotoxy(3,13);
	printf("[E] Excluir Vendas");
	gotoxy(3,14);
	printf("[F] Consultar Cupom");
	gotoxy(3,19);
	printf("[R] Voltar");
	gotoxy(31,7);
	printf("Selecione Uma Operacao:");
	gotoxy(39,19);
} 

void MenuPrincipal(void)
{
	Moldura(1,1,80,25,1,15);
	LimpaMenu();
	LimpaMsg();
	LimpaTela();
	gotoxy(3,7);
	printf("# #  M E N U  # #");
	gotoxy(3,9);
	printf("[P] Produtos");
	gotoxy(3,10);
	printf("[F] Fornecedores");
	gotoxy(3,11);
	printf("[C] Clientes");
	gotoxy(3,12);
	printf("[V] Vendas");
	gotoxy(3,13);
	printf("[I] Inserir Dados");
	gotoxy(3,19);
	printf("[Esc] Sair");
	gotoxy(31,7);
	printf("Selecione Uma Operacao:");
	LimpaEntrada();
}

char Menu(void)
{
	char op;
	
	Preenche();
	Moldura(1,1,80,25,1,15);
	gotoxy(24,3);
	printf("# # #  T R A B A L H O   A T P  # # #");
	Moldura(2,2,79,4,1,15);
	Moldura(2,5,27,21,1,15);
	Moldura(2,22,79,24,1,15);
	gotoxy(4,23);
	printf("Mensagem:");
	Moldura(28,5,79,21,1,15);
	Moldura(29,18,78,20,1,15);
	gotoxy(30,19);
	printf("Entrada:");
	MenuPrincipal();
	
	LimpaEntrada();
	return toupper(getch());
}

void InserirDados(tpProdutos TabProd[TF],int &TLP,tpClientes TabCli[TF],int &TLC,tpFornecedores TabForn[TF],int &TLF,tpVendas TabVendas[TF],int &TLV,tpVendas_Prod TabVP[TF],int &TLVP)
{
	TabProd[TLP].CodProd=7000;
	strcpy(TabProd[TLP].Descr,"Lasanha");
	TabProd[TLP].Estoque=52;
	TabProd[TLP].Preco=9.98;
	TabProd[TLP].DtValidade.d=10;
	TabProd[TLP].DtValidade.m=9;
	TabProd[TLP].DtValidade.a=2024;
	TabProd[TLP].CodForn=200;
	TLP++;
	
	TabProd[TLP].CodProd=1000;
	strcpy(TabProd[TLP].Descr,"Suco");
	TabProd[TLP].Estoque=188;
	TabProd[TLP].Preco=1.62;
	TabProd[TLP].DtValidade.d=15;
	TabProd[TLP].DtValidade.m=5;
	TabProd[TLP].DtValidade.a=2025;
	TabProd[TLP].CodForn=500;
	TLP++;
	
	TabProd[TLP].CodProd=4000;
	strcpy(TabProd[TLP].Descr,"Biscoito");
	TabProd[TLP].Estoque=63;
	TabProd[TLP].Preco=4.56;
	TabProd[TLP].DtValidade.d=22;
	TabProd[TLP].DtValidade.m=11;
	TabProd[TLP].DtValidade.a=2024;
	TabProd[TLP].CodForn=300;
	TLP++;
	
	TabForn[TLF].CodForn=200;
	strcpy(TabForn[TLF].NomeForn,"Fabrica Matao");
	strcpy(TabForn[TLF].Cidade,"Matao");
	TLF++;
	
	TabForn[TLF].CodForn=500;
	strcpy(TabForn[TLF].NomeForn,"Sapore S.A");
	strcpy(TabForn[TLF].Cidade,"Campinas");
	TLF++;
	
	TabForn[TLF].CodForn=300;
	strcpy(TabForn[TLF].NomeForn,"Basteck");
	strcpy(TabForn[TLF].Cidade,"Guarapuava");
	TLF++;
	
	strcpy(TabCli[TLC].cpf,"48070830077");
	strcpy(TabCli[TLC].NomeC,"Windislaisson");
	TabCli[TLC].QtdeCompras=5;
	TabCli[TLC].ValorTotComp=2841.63;
	TLC++;
	
	strcpy(TabCli[TLC].cpf,"64065512069");
	strcpy(TabCli[TLC].NomeC,"Astolfo");
	TabCli[TLC].QtdeCompras=2;
	TabCli[TLC].ValorTotComp=1450.25;
	TLC++;
	
	strcpy(TabCli[TLC].cpf,"50388983000");
	strcpy(TabCli[TLC].NomeC,"Armelinda");
	TabCli[TLC].QtdeCompras=11;
	TabCli[TLC].ValorTotComp=1982.54;
	TLC++;
	
	TabVendas[TLV].CodVenda=TLV+1;
	strcpy(TabVendas[TLV].cpf,"64065512069");
	TabVendas[TLV].DtVenda.d=10;
	TabVendas[TLV].DtVenda.m=8;
	TabVendas[TLV].DtVenda.a=2023;
	TabVendas[TLV].TotVenda=451.90;
	TLV++;
	
	TabVendas[TLV].CodVenda=TLV+1;
	strcpy(TabVendas[TLV].cpf,"48070830077");
	TabVendas[TLV].DtVenda.d=15;
	TabVendas[TLV].DtVenda.m=7;
	TabVendas[TLV].DtVenda.a=2023;
	TabVendas[TLV].TotVenda=45.60;
	TLV++;
	
	TabVendas[TLV].CodVenda=TLV+1;
	strcpy(TabVendas[TLV].cpf,"50388983000");
	TabVendas[TLV].DtVenda.d=6;
	TabVendas[TLV].DtVenda.m=4;
	TabVendas[TLV].DtVenda.a=2023;
	TabVendas[TLV].TotVenda=9.98;
	TLV++;
	
	TabVP[TLVP].CodVenda=1;
	TabVP[TLVP].CodProd=1000;
	TabVP[TLVP].Qtde=10;
	TabVP[TLVP].ValorUni=1.62;
	TLVP++;
	
	TabVP[TLVP].CodVenda=1;
	TabVP[TLVP].CodProd=7000;
	TabVP[TLVP].Qtde=20;
	TabVP[TLVP].ValorUni=9.98;
	TLVP++;
	
	TabVP[TLVP].CodVenda=1;
	TabVP[TLVP].CodProd=4000;
	TabVP[TLVP].Qtde=53;
	TabVP[TLVP].ValorUni=4.56;
	TLVP++;
	
	TabVP[TLVP].CodVenda=2;
	TabVP[TLVP].CodProd=4000;
	TabVP[TLVP].Qtde=10;
	TabVP[TLVP].ValorUni=4.56;
	TLVP++;
	
	TabVP[TLVP].CodVenda=3;
	TabVP[TLVP].CodProd=7000;
	TabVP[TLVP].Qtde=1;
	TabVP[TLVP].ValorUni=9.98;
	TLVP++;
	
	EscrMsg();
	printf("Dados Inseridos Com Sucesso");
	getch();
}

void ValidaData(int &d, int &m, int &a)
{
	int valida=0;
	
	do
	{
		LimpaMsg();
		LimpaEntrada();
		scanf("%d",&d);
		LimpaEntrada();
		scanf("%d",&m);
		LimpaEntrada();
		scanf("%d",&a);
		if(a>=2023 && a<2030)
		{
			if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12))
				valida=1;
			else
				if((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11))
					valida=1;
				else
					if((d>=1 && d<=28) && m==2)
						valida=1;
					else
						if(d==29 && m==2 && ((a%400==0 || (a%4==0 && a%100!=0))))
							valida=1;
						else
						{
							EscrMsg();
							printf("Data Invalida");
							getch();
						}
		}
		else
		{
			EscrMsg();
			printf("Data Invalida");
			getch();
		}
	}while(valida!=1);
}

int ValidaCPF(char CPF[11])
{
	int i,mult,Dig[11],soma=0,resto,dig1,dig2;
	
	if(strlen(CPF)!=11)
		return 0;
	else
		if((strcmp(CPF,"00000000000")==0) || (strcmp(CPF,"11111111111")==0) || (strcmp(CPF,"22222222222")==0) || (strcmp(CPF,"33333333333")==0) || (strcmp(CPF,"44444444444")==0) || (strcmp(CPF,"55555555555")==0) || (strcmp(CPF,"66666666666")==0) || (strcmp(CPF,"77777777777")==0) || (strcmp(CPF,"88888888888")==0) || (strcmp(CPF,"99999999999")==0))
			return 0;
	else
	{
		for(i=0,mult=10;i<9;i++,mult--)
			soma+=(mult*(CPF[i]-48));
		resto=soma%11;
		dig1=11-resto;
		if(dig1==10 || dig1==11)
			dig1=0;
		if(dig1!=(CPF[9]-48))
			return 0;
		else
		{
			soma=0;
			for(i=0,mult=11;i<10;i++,mult--)
				soma+=(mult*(CPF[i]-48));
			resto=soma%11;
			dig2=11-resto;
			if(dig2==10 || dig2==11)
				dig2=0;
			if(dig2!=(CPF[10]-48))
				return 0;
		}
	}
	return 1;
}

void EntInv(void)
{
	EscrMsg();
	printf("Entrada Invalida");
	getch();
	LimpaMsg();
	LimpaEntrada();
}

char *ValidaString(void)
{
	int i;
	char StrAux[30];
	
	do
	{
		LimpaEntrada();
		fflush(stdin);
		gets(StrAux);
		if(strlen(StrAux)==0)
			EntInv();
		else
			return StrAux;
			
	}while(StrAux[0]!='/0');
}

int ConfirmaAlt(void)
{
	EscrMsg();
	printf("Confirma Alteracao (S/N)?");
	LimpaEntrada();
	if(toupper(getche())=='S')
		return 1;
	else
		return 0;
}

int BuscaCPF(tpClientes TabCli[TF], int TLC, char CPF[11])
{
	int /*pos*/i,j,igual;
	
	for(i=0;i<TLC;i++)
	{
		igual=0;
		for(j=0;j<11;j++)
		{
			if(CPF[j]==TabCli[i].cpf[j])
				igual=1;
			else
			{
				j=11;
				igual=0;
			}
		}
		if(igual==1)
			return i;
	}
	return -1;
	
	/*pos=0;
	
	if(pos<TLC && strcmp(CPF,TabCli[pos].cpf)!=0)
	{
		pos++;
	}
	if(pos<TLC)
		return pos;
	else
		return -1;*/
}

int BuscaCodForn(tpFornecedores Tab[TF], int TLF, int Cod)
{
	int pos=0;
	
	while(pos<TLF && Cod!=Tab[pos].CodForn)
		pos++;
	if(pos<TLF)
		return pos;
	else
		return -1;
}

int BuscaCupom(tpVendas TabVenda[TF],int TLV,int Cod)
{
	int pos=0;
	while(pos<TLV && Cod!=TabVenda[pos].CodVenda)
		pos++;
	if(pos<TLV)
		return pos;
	else
		return -1;
}

int BuscaCodProd(tpProdutos TabProd[TF],int TLP,int Cod)
{
	int pos=0;
	while(pos<TLP && Cod!=TabProd[pos].CodProd)
		pos++;
	if(pos<TLP)
		return pos;
	else
		return -1;
}

int BuscaProdVenda(tpVendas_Prod TabVP[TF],int TLVP,int Cod)
{
	int pos=0;
	while(pos<TLVP && Cod!=TabVP[pos].CodProd)
		pos++;
	if(pos<TLVP)
		return pos;
	else
		return -1;
}

int BuscaVenda(tpVendas_Prod TabVP[TF],int TLVP,int CodVenda)
{
	int pos=0;
	while(pos<TLVP && CodVenda!=TabVP[pos].CodVenda)
		pos++;
	if(pos<TLVP)
		return pos;
	else
		return -1;
}

int BuscaVendaSeq(tpVendas TabVendas[TF], int TLV, int CodVenda)
{
	int pos=0;
	while(pos<TLV && CodVenda!=TabVendas[pos].CodVenda)
		pos++;
	if(pos<TLV)
		return pos;
	else
		return -1;
}

int BuscaFornProd(tpProdutos TabProd[TF],int TLP,int Cod)
{
	int pos=0;
	while(pos<TLP && Cod!=TabProd[pos].CodForn)
		pos++;
	if(pos<TLP)
		return pos;
	else
		return -1;
}

void ValidaInt(int &IntAux)
{
	int valido=0;
	while(valido!=1)
	{
		if(scanf("%d",&IntAux)==1)
			valido=1;
		else
		{
			EscrMsg();
			printf("A Entrada Deve Ser Um Numero Inteiro");
			getch();
			fflush(stdin);
			LimpaMsg();
			LimpaEntrada();
		}
	}
}

void ValidaFloat(float &FloatAux)
{
	int valido=0;
	while(valido!=1)
	{
		if(scanf("%f",&FloatAux)==1)
			valido=1;
		else
		{
			EscrMsg();
			printf("A Entrada Deve Ser Um Numero");
			getch();
			LimpaMsg();
			LimpaEntrada();
		}
		fflush(stdin);
	}
}

void CadForn(tpFornecedores TabForn[TF],int &TLF)
{
	int Cod,pos,C,L;
	char op;
	
	if(TLF==TF)
	{
		EscrMsg();
		printf("Nao Ha Espaco Para Cadastro");
		getch();
	}
	else
	{
		textcolor(9);
		gotoxy(3,9);
		printf("[A] Cadastro:");
		textcolor(0);
		InicioTela(C,L);
		printf("Cadastro de Fornecedores");
		gotoxy(31,9);
		printf("Codigo do Fornecedor: ");
		LimpaEntrada();
		ValidaInt(Cod);
		while(TLF<TF && Cod!=0)
		{
			pos=BuscaCodForn(TabForn,TLF,Cod);
			if(pos==-1)
			{
				TabForn[TLF].CodForn = Cod;
				gotoxy(31,10);
				printf("Nome Fantasia do Fornecedor: ");
				LimpaEntrada();
				strcpy(TabForn[TLF].NomeForn,ValidaString());
				if(strcmp(TabForn[TLF].NomeForn,"0")==0)
				{
					Cod=0;
					EscrMsg();
					printf("Cadastro Cancelado");
					getch();
				}
				else
				{
					gotoxy(31,11);
					printf("Cidade do Fornecedor: ");
					LimpaEntrada();
					strcpy(TabForn[TLF].Cidade,ValidaString());
					if(strcmp(TabForn[TLF].Cidade,"0")==0)
					{
						Cod=0;
						EscrMsg();
						printf("Cadastro Cancelado");
						getch();
					}
					else
					{
						TLF++;
						EscrMsg();
						printf("Fornecedor Cadastrado com Sucesso!");
						getch();
					}	
				}
			}
			else
			{
				EscrMsg();
				printf("Fornecedor Ja Cadastrado!");
				getch();
			}
			EscrMsg();
			printf("Realizar Novo Cadastro (S/N)?");
			LimpaEntrada();
			if(toupper(getche())=='S')
			{
				if(TLF < TF)
				{
					LimpaMsg();
					InicioTela(C,L);
					printf("Cadastro de Fornecedores");
					gotoxy(31,9);
					printf("Codigo do Fornecedor: ");
					LimpaEntrada();
					ValidaInt(Cod);
				}
				else
				{
					LimpaTela();
					EscrMsg();
					printf("Nao Ha Espaco Para Cadastro");
					LimpaEntrada();
					getch();
				}
			}
			else
			{
				EscrMsg();
				printf("Menu de Cadastro Encerrado!");
				LimpaEntrada();
				getch();
				Cod=0;
			}
		}
		LimpaTela();
		MenuFornecedor();
		LimpaEntrada();
	}
}

void CadCli(tpClientes TabCli[TF],int &TLC)
{
	int i,pos,C,L,VCPF;
	char CPF[11],op;
	
	if(TLC==TF)
	{
		EscrMsg();
		printf("Nao Ha Espaco Para Cadastro");
		getch();
	}
	else
	{
		textcolor(9);
		gotoxy(3,9);
		printf("[A] Cadastro:");
		textcolor(0);
		InicioTela(C,L);
		printf("Cadastro de Clientes");
		L+=2;
		gotoxy(C,L);
		printf("CPF do Cliente:");
		L++;
		LimpaEntrada();
		fflush(stdin);
		strcpy(CPF,ValidaString());
		while(TLC<TF && strcmp(CPF,"0"))
		{
			VCPF = ValidaCPF(CPF);
			if(VCPF==0)
			{
				EscrMsg();
				printf("CPF Invalido");
				getch();
			}
			else
			{
				pos=BuscaCPF(TabCli,TLC,CPF);
				if(pos==-1)
				{
					strcpy(TabCli[TLC].cpf,CPF);
					gotoxy(31,11);
					printf("Nome do Cliente: ");
					L++;
					LimpaEntrada();
					strcpy(TabCli[TLC].NomeC,ValidaString());
					if(strcmp(TabCli[TLC].NomeC,"0")==0)
					{
						EscrMsg();
						printf("Cadastro Cancelado");
						getch();
					}
					else
					{
						TabCli[TLC].QtdeCompras=0;
						TabCli[TLC].ValorTotComp=0;
						TLC++;
						EscrMsg();
						printf("Cliente Cadastrado com Sucesso!");
						LimpaEntrada();
						getch();
					}
				}
				else
				{
					EscrMsg();
					printf("CPF Ja Cadastrado");
					getch();
				}
			}
			EscrMsg();
			printf("Realizar Novo Cadastro (S/N)?");
			LimpaEntrada();
			if(toupper(getche())=='S')
			{
				if(TLC<TF)
				{
					InicioTela(C,L);
					printf("Cadastro de Clientes");
					gotoxy(C,L);
					L+=2;
					gotoxy(C,L);
					printf("CPF do Cliente: ");
					L++;
					LimpaMsg();
					LimpaEntrada();
					fflush(stdin);
					gets(CPF);
				}
				else
				{
					LimpaTela();
					EscrMsg();
					printf("Nao Ha Espaco Para Cadastro");
					LimpaEntrada();
					getch();
					LimpaMsg();
				}
			}
			else
			{
				EscrMsg();
				printf("Menu de Cadastro Encerrado!");
				LimpaEntrada();
				getch();
				strcpy(CPF,"0");
			}
		}
		LimpaTela();
		MenuCliente();
		LimpaEntrada();
	}
}

void CadProd(tpProdutos TabProd[TF],int &TLP,tpFornecedores TabForn[TF],int TLF)
{
	int Cod,CodForn,posForn,pos,C,L;
	char op;
	
	if(TLP==TF)
	{
		EscrMsg();
		printf("Nao Ha Espaco Para Cadastro");
		getch();
	}
	else
		if(TLF==0)
		{
			EscrMsg();
			printf("Nao Existem Fornecedores Cadastrados");
			getch();
		}
		else
		{
			textcolor(9);
			gotoxy(3,9);
			printf("[A] Cadastro:");
			textcolor(0);
			InicioTela(C,L);
			printf("Cadastro de Produtos");
			L+=2;
			gotoxy(C,L);
			printf("Codigo do Produto:");
			L++;
			LimpaEntrada();
			ValidaInt(Cod);
			while(TLP<TF && Cod!=0)
			{
				pos=BuscaCodProd(TabProd,TLP,Cod);
				if(pos==-1)
				{
					TabProd[TLP].CodProd = Cod;
					gotoxy(C,L);
					printf("Codigo do Fornecedor:");
					L++;
					do
					{
						LimpaMsg();
						LimpaEntrada();
						ValidaInt(CodForn);
						posForn=BuscaCodForn(TabForn,TLF,CodForn);
						if(posForn==-1)
						{
							EscrMsg();
							printf("Fornecedor Nao Encontrado");
							LimpaEntrada();
							getch();
							EscrMsg();
						}
						else
						{
							EscrMsg();
							printf("Confirma Fornecedor (S/N): %s",TabForn[posForn].NomeForn);
							LimpaEntrada();
							fflush(stdin);
							if(toupper(getch())=='S')
							{
								TabProd[TLP].CodForn = TabForn[posForn].CodForn;
								op='S';
							}
							LimpaMsg();
						}
					}while(op!='S');
					gotoxy(C,L);
					printf("Descricao do Produto: ");
					L++;
					LimpaEntrada();
					strcpy(TabProd[TLP].Descr,ValidaString());
					if(strcmp(TabProd[TLP].Descr,"0")==0)
					{
						EscrMsg();
						printf("Cadastro Cancelado");
						getch();
					}
					else
					{
						gotoxy(C,L);
						printf("Quantidade em Estoque:");
						L++;
						LimpaEntrada();
						ValidaInt(TabProd[TLP].Estoque);
						gotoxy(C,L);
						printf("Preco:");
						L++;
						LimpaEntrada();
						ValidaFloat(TabProd[TLP].Preco);
						if(TabProd[TLP].Preco==0)
						{
							EscrMsg();
							printf("Cadastro Cancelado");
							getch();
						}
						else
						{
							gotoxy(C,L);
							printf("Data de Validade:");
							L++;
							LimpaEntrada();
							ValidaData(TabProd[TLP].DtValidade.d,TabProd[TLP].DtValidade.m,TabProd[TLP].DtValidade.a);
							if((TabProd[TLP].DtValidade.d==0) && (TabProd[TLP].DtValidade.m==0) && (TabProd[TLP].DtValidade.a==0))
							{
								EscrMsg();
								printf("Cadastro Cancelado");
								getch();
							}
							else
							{
								TLP++;
								EscrMsg();
								printf("Produto Cadastrado com Sucesso!");
								LimpaEntrada();
								getch();
							}
						}	
					}
				}
				else
				{
					EscrMsg();
					printf("Produto Ja Cadastrado!");
					getch();
					LimpaMsg();
				}
				EscrMsg();
				printf("Realizar Novo Cadastro (S/N)?");
				LimpaEntrada();
				if(toupper(getche())=='S')
				{
					if(TLP<TF)
					{
						InicioTela(C,L);
						printf("Cadastro de Produtos");
						gotoxy(C,L);
						L+=2;
						gotoxy(C,L);
						printf("Codigo do Produto: ");
						L++;
						LimpaMsg();
						LimpaEntrada();
						ValidaInt(Cod);
					}
					else
					{
						LimpaTela();
						EscrMsg();
						printf("Nao Ha Espaco Para Cadastro");
						LimpaEntrada();
						getch();
						LimpaMsg();
					}
				}
				else
				{
					EscrMsg();
					printf("Menu de Cadastro Encerrado!");
						LimpaEntrada();
					Cod=0;
				}
			}
			LimpaTela();
			MenuProduto();
			LimpaEntrada();
		}
}

void ConsultaCli(tpClientes TabCli[TF], int TLC)
{
	int i,C,L,pos;
	char CPF[11];
	
	if(TLC==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados!");
		getch();
	}
	else
	{
		textcolor(9);
		gotoxy(3,10);
		printf("[B] Consulta:");
		textcolor(0);
		InicioTela(C,L);
		printf("Consulta de Clientes");
		gotoxy(31,9);
		printf("CPF do Cliente: ");
		LimpaEntrada();
		strcpy(CPF,ValidaString());
		while(TLC<TF && strcmp(CPF,"0"))
		{
			pos=BuscaCPF(TabCli,TLC,CPF);
			if(pos==-1)
			{
				EscrMsg();
				printf("Cliente Nao Encontrado");
				getch();
			}
			else
			{
				InicioTela(C,L);
				gotoxy(C,L);
				printf("CPF: ");
				for(i=0;i<11;i++)
				{
					printf("%c",TabCli[pos].cpf[i]);
					if((i!=8) && (i+1)%3==0)
						printf(".");
					if(i==8)
						printf("-");
				}
				L++;
				gotoxy(C,L);
				printf("Nome: %s",TabCli[pos].NomeC);
				L++;
				gotoxy(C,L);
				printf("Quantidade de Compras: %d",TabCli[pos].QtdeCompras);
				L++;
				gotoxy(C,L);
				printf("Valor Total Comprado: R$ %.2f",TabCli[pos].ValorTotComp);
				L+=2;
				getch();
			}
			InicioTela(C,L);
			printf("Consulta de Clientes");
			gotoxy(31,9);
			printf("CPF do Cliente: ");
			LimpaEntrada();
			strcpy(CPF,ValidaString());
		}
	}
	LimpaEntrada();
}

void ConsultaForn(tpFornecedores Tab[TF], int TLF)
{
	int i,C,L,Cod,pos;
	
	if(TLF==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados!");
		getch();
	}
	else
	{
		textcolor(9);
		gotoxy(3,10);
		printf("[B] Consulta:");
		textcolor(0);
		InicioTela(C,L);
		printf("Consulta de Fornecedores");
		gotoxy(31,9);
		printf("Codigo do Fornecedor: ");
		LimpaEntrada();
		ValidaInt(Cod);
		while(TLF<TF && Cod!=0)
		{
			pos=BuscaCodForn(Tab,TLF,Cod);
			LimpaEntrada();
			if(pos==-1)
			{
				EscrMsg();
				printf("Fornecedor Nao Encontrado");
				getch();
			}
			else
			{
				InicioTela(C,L);
				gotoxy(C,L);
				printf("Codigo: %d",Tab[pos].CodForn);
				L++;
				gotoxy(C,L);
				printf("Nome: %s",Tab[pos].NomeForn);
				L++;
				gotoxy(C,L);
				printf("Cidade: %s",Tab[pos].Cidade);
				L+=2;
				getch();
			}
			InicioTela(C,L);
			printf("Consulta de Fornecedores");
			gotoxy(31,9);
			printf("Codigo do Fornecedor: ");
			LimpaEntrada();
			ValidaInt(Cod);
		}
	}
	LimpaEntrada();
}

void ConsultaProd(tpProdutos TabProd[TF], int TLP,tpFornecedores TabForn[TF],int TLF)
{
	int i,C,L,Cod,pos,posForn;
	
	if(TLP==0)
	{
		EscrMsg();
		printf("Nao Existem Produtos Cadastrados!");
		getch();
	}
	else
	{
		textcolor(9);
		gotoxy(3,10);
		printf("[B] Consulta:");
		textcolor(0);
		InicioTela(C,L);
		printf("Consulta de Produtos");
		gotoxy(31,9);
		printf("Codigo do Produto: ");
		LimpaEntrada();
		ValidaInt(Cod);
		while(TLP<TF && Cod!=0)
		{
			pos=BuscaCodProd(TabProd,TLP,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Produto Nao Encontrado");
				LimpaEntrada();
				getch();
			}
			else
			{
				InicioTela(C,L);
				
				gotoxy(C,L);
				printf("Codigo: %d",TabProd[pos].CodProd);
				L++;
				gotoxy(C,L);
				printf("Descricao: %s",TabProd[pos].Descr);
				L++;
				gotoxy(C,L);
				pos=BuscaCodForn(TabForn,TLF,TabProd[pos].CodForn);
				printf("Fornecedor [%d] - %s",TabProd[pos].CodForn,TabForn[pos].NomeForn);
				L++;
				gotoxy(C,L);
				printf("Estoque: %d   -   ",TabProd[pos].Estoque);
				printf("Preco: R$ %.2f",TabProd[pos].Preco);
				L++;
				gotoxy(C,L);
				printf("Validade: %d/%d/%d",TabProd[pos].DtValidade.d,TabProd[pos].DtValidade.m,TabProd[pos].DtValidade.a);
				L+=2;
				getch();
			}
			InicioTela(C,L);
			printf("Consulta de Produtos");
			gotoxy(31,9);
			printf("Codigo do Produto: ");
			LimpaEntrada();
			ValidaInt(Cod);
		}
	}
	LimpaEntrada();
}

void RelatorioForn(tpFornecedores Tab[TF], int TL)
{
	int i,l=7,c=31,pg=1;
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados!");
		getch();
	}
	else
	{
		LimpaTela();
		textcolor(9);
		gotoxy(3,13);
		printf("[E] Relatorio");
		textcolor(0);
		gotoxy(41,6);
		printf("Relatorio de Fornecedores (%d)",TL);
		for(i=0;i<TL;i++)
		{
				gotoxy(c,l);
				printf("Codigo: %d",Tab[i].CodForn);
				l++;
				gotoxy(c,l);
				printf("Nome: %s",Tab[i].NomeForn);
				l++;
				gotoxy(c,l);
				printf("Cidade: %s",Tab[i].Cidade);
				l+=2;
				if((i+1)%3==0)
				{
					
					gotoxy(68,17);
					printf("Pagina: %d",pg);
					getch();
					pg++;
					LimpaTela();
					gotoxy(41,6);
					printf("Relatorio de Fornecedores (%d)",TL);
					l=7;
				}
		}
		if(i%3!=0)
		{
			gotoxy(68,17);
			printf("Pagina: %d",pg);
			getch();
		}
		LimpaEntrada();
		MenuFornecedor();
	}
}

void RelatorioProd(tpProdutos TabProd[TF],int TLP,tpFornecedores TabForn[TF],int TLF)
{
	int i,l=7,c=31,pg=1,pos;
	
	if(TLP==0)
	{
		EscrMsg();
		printf("Nao Existem Produtos Cadastrados!");
		getch();
	}
	else
	{
		textcolor(9);
		gotoxy(3,13);
		printf("[E] Relatorio");
		textcolor(0);
		LimpaTela();
		gotoxy(43,6);
		printf("Relatorio de Produtos (%d)",TLP);
		for(i=0;i<TLP;i++)
		{
				gotoxy(c,l);
				printf("Codigo: %d",TabProd[i].CodProd);
				l++;
				gotoxy(c,l);
				printf("Descricao: %s",TabProd[i].Descr);
				l++;
				gotoxy(c,l);
				pos=BuscaCodForn(TabForn,TLF,TabProd[i].CodForn);
				printf("Fornecedor [%d] - %s",TabProd[i].CodForn,TabForn[pos].NomeForn);
				l++;
				gotoxy(c,l);
				printf("Estoque: %d   -   ",TabProd[i].Estoque);
				printf("Preco: R$ %.2f",TabProd[i].Preco);
				l++;
				gotoxy(c,l);
				printf("Validade: %d/%d/%d",TabProd[i].DtValidade.d,TabProd[i].DtValidade.m,TabProd[i].DtValidade.a);
				l+=2;
				if((i+1)%2==0)
				{
					
					gotoxy(68,17);
					printf("Pagina: %d",pg);
					getch();
					pg++;
					LimpaTela();
					gotoxy(43,6);
					printf("Relatorio de Produtos (%d)",TLP);
					l=7;
				}
		}
		if(i%2!=0)
		{
			gotoxy(68,17);
			printf("Pagina: %d",pg);
			getch();
		}
		LimpaEntrada();
		MenuProduto();
	}
}

void RelatorioVC(tpVendas TabV[TF],int TLV,tpClientes TabCli[TF],int TLC)
{
	int i,j,c,l,posCPF,pg=1;
	
	if(TLV==0)
	{
		EscrMsg();
		printf("Nao Existem Vendas Registradas");
		getch();
	}
	else
	{
		LimpaMsg();
		LimpaEntrada();
		textcolor(9);
		gotoxy(3,11);
		printf("[C] Vendas/Cliente:");
		textcolor(0);
		InicioTela(c,l);
		gotoxy(39,6);
		printf("Relatorio de Vendas/Clientes (%d)",TLV);
		l++;
		for(i=0;i<TLV;i++)
		{
				gotoxy(c,l);
				printf("Codigo da Venda: %d",TabV[i].CodVenda);
				l++;
				gotoxy(c,l);
				posCPF=BuscaCPF(TabCli,TLC,TabV[i].cpf);
				printf("Cliente [");
				for(j=0;j<11;j++)
				{
					printf("%c",TabV[i].cpf[j]);
					if((j!=8) && (j+1)%3==0)
						printf(".");
					if(j==8)
						printf("-");
				}
				printf("] - %s",TabCli[posCPF].NomeC);
				l++;
				gotoxy(c,l);
				printf("Data da Venda: %d/%d/%d",TabV[i].DtVenda.d,TabV[i].DtVenda.m,TabV[i].DtVenda.a);
				l++;
				gotoxy(c,l);
				printf("Valor Total: R$ %.2f",TabV[i].TotVenda);
				l+=2;
				if((i+1)%2==0)
				{
					
					gotoxy(68,17);
					printf("Pagina: %d",pg);
					getch();
					pg++;
					LimpaTela();
					gotoxy(39,6);
					printf("Relatorio de Vendas/Clientes (%d)",TLV);
					l=8;
				}
		}
		if(i%2!=0)
		{
			gotoxy(68,17);
			printf("Pagina: %d",pg);
			getch();
		}
		LimpaEntrada();
		MenuProduto();
	}
}

void RelatorioVP(tpVendas_Prod TabVP[TF*10],int TLVP,tpClientes TabCli[TF],int TLC,tpProdutos TabProd[TF],int TLP)
{
	int i,j,l=7,c=31,pg=1,pos,posProd;
	
	if(TLC==0)
	{
		EscrMsg();
		printf("Nao Existem Vendas Registradas!");
		getch();
	}
	else
	{
		InicioTela(c,l);
		textcolor(9);
		gotoxy(3,10);
		printf("[B] Vendas/Produto:");
		textcolor(0);
		LimpaTela();
		gotoxy(38,6);
		printf("Relatorio de Vendas/Produtos (%d)",TLVP);
		l=8;
		for(i=0;i<TLVP;i++)
		{
				gotoxy(c,l);
				printf("Codigo da Venda: %d",TabVP[i].CodVenda);
				l++;
				gotoxy(c,l);
				posProd=BuscaCodProd(TabProd,TLP,TabVP[i].CodProd);
				printf("Produto [%d] - %s",TabVP[i].CodProd,TabProd[posProd].Descr);
				l++;
				gotoxy(c,l);
				printf("Quantidade: %d",TabVP[i].Qtde);
				l++;
				gotoxy(c,l);
				printf("Valor Unitario: R$ %.2f",TabVP[i].ValorUni);
				l+=2;
				if((i+1)%2==0)
				{
					
					gotoxy(68,17);
					printf("Pagina: %d",pg);
					getch();
					pg++;
					LimpaTela();
					gotoxy(38,6);
					printf("Relatorio de Vendas/Produtos (%d)",TLVP);
					l=8;
				}
		}
		if(i%2!=0)
		{
			gotoxy(68,17);
			printf("Pagina: %d",pg);
			getch();
		}
		LimpaEntrada();
		MenuProduto();
	}
}

void RelatorioVendas(tpVendas TabV[TF],int TLV,tpVendas_Prod TabVP[TF],int TLVP,tpProdutos TabP[TF],int TLP,tpFornecedores TabF[TF],int TLF)
{
	int i,j,c,l,posProd,posVenda,posForn,pg=1;
	
	if(TabV==0)
	{
		EscrMsg();
		printf("Nao Existem Vendas Registradas");
		getch();
	}
	else
	{
		InicioTela(c,l);
		textcolor(9);
		gotoxy(3,12);
		printf("[D] Relatorio de Vendas");
		textcolor(0);
		LimpaTela();
		gotoxy(42,6);
		printf("Relatorio de Vendas (%d)",TLV);
		l=8;
		for(i=0;i<TLV;i++)
		{
			posVenda=BuscaVenda(TabVP,TLVP,TabV[i].CodVenda);
			gotoxy(c,l);
			printf("Codigo da Venda: %d",TabV[i].CodVenda);
			l++;
			gotoxy(c,l);
			printf("Produtos:");
			for(j=0;j<TLVP;j++)
			{
				if(TabVP[j].CodVenda==TabV[i].CodVenda)
				{
					l++;
					posProd=BuscaCodProd(TabP,TLP,TabVP[j].CodProd);
					posForn=BuscaCodForn(TabF,TLF,TabP[posProd].CodForn);
					gotoxy(c,l);
					printf("[%d] - %s",TabVP[j].CodProd,TabP[posProd].Descr);
					gotoxy(50,l);
					printf("%d",TabVP[j].Qtde);
					gotoxy(54,l);
					printf("R$ %.2f",TabVP[j].Qtde*TabVP[j].ValorUni);
					gotoxy(64,l);
					printf("%s",TabF[posForn].NomeForn);
				}
				if(l%17==0)
				{
					fflush(stdin);
					getch();
					InicioTela(c,l);
				}
			}
			l++;
			if(l>=17)
				InicioTela(c,l);
			gotoxy(c,l);
			printf("Total: R$ %.2f",TabV[i].TotVenda);
			gotoxy(68,17);
			printf("Pagina: %d",pg);
			if(i<TLV)
			{
				getch();
				LimpaTela();
				pg++;
				gotoxy(42,6);
				printf("Relatorio de Vendas (%d)",TLV);
				l=8;
			}
		}
		LimpaEntrada();
		MenuProduto();
	}
}

void RelatorioCli(tpClientes TabCli[TF],int TLC)
{
	int i,j,l=7,c=31,pg=1,pos;
	
	if(TLC==0)
	{
		EscrMsg();
		printf("Nao Existem Clientes Cadastrados!");
		getch();
	}
	else
	{
		InicioTela(c,l);
		textcolor(9);
		gotoxy(3,13);
		printf("[E] Relatorio");
		textcolor(0);
		LimpaTela();
		gotoxy(42,6);
		printf("Relatorio de Clientes (%d)",TLC);
		l=8;
		for(i=0;i<TLC;i++)
		{
				gotoxy(c,l);
				printf("CPF: ");
				for(j=0;j<11;j++)
				{
					printf("%c",TabCli[i].cpf[j]);
					if((j!=8) && (j+1)%3==0)
						printf(".");
					if(j==8)
						printf("-");
				}
				l++;
				gotoxy(c,l);
				printf("Nome: %s",TabCli[i].NomeC);
				l++;
				gotoxy(c,l);
				printf("Quantidade de Compras: %d",TabCli[i].QtdeCompras);
				l++;
				gotoxy(c,l);
				printf("Valor Total Comprado: R$ %.2f",TabCli[i].ValorTotComp);
				l+=2;
				if((i+1)%2==0)
				{
					
					gotoxy(68,17);
					printf("Pagina: %d",pg);
					getch();
					pg++;
					LimpaTela();
					gotoxy(42,6);
					printf("Relatorio de Clientes (%d)",TLC);
					l=8;
				}
		}
		if(i%2!=0)
		{
			gotoxy(68,17);
			printf("Pagina: %d",pg);
			getch();
		}
		LimpaEntrada();
		MenuProduto();
	}
}

void ExcVenda(tpClientes TabCli[TF], int &TLC, tpVendas TabVendas[TF], tpVendas_Prod TabVP[TF], int &TLVP, int &TLV)
{
	int C,L,cod,pos,aux,i,j;
	char cpf[11];
	float TotMenos;
	
	if(TLV==0)
	{
		EscrMsg();
		printf("Nao Existem Vendas Cadastradas!");
		getch();
	}
	else
	{
		InicioTela;
		textcolor(9);
		gotoxy(3,13);
		printf("[E] Excluir Vendas");
		textcolor(0);
		InicioTela(C,L);
		printf("Exclusao de Vendas");
		L+=2;
		gotoxy(C,L);
		printf("Codigo da Venda: ");
		LimpaEntrada();
		ValidaInt(cod);
		if(cod!=0)
		{
			pos=BuscaVendaSeq(TabVendas,TLV,cod);
			InicioTela(C,L);
			printf("Exclusao de Vendas");
			L+=2;
			gotoxy(C,L);
			printf("Codigo da Venda: %d",TabVendas[pos].CodVenda);
			L++;
			strcpy(cpf,TabVendas[pos].cpf);
			aux=BuscaCPF(TabCli,TLC,cpf);
			gotoxy(C,L);
			printf("Cliente: %s",TabCli[aux].NomeC);
			L++;
			gotoxy(C,L);
			printf("CPF Cliente: ");
			for(j=0;j<11;j++)
					{
						printf("%c",TabCli[aux].cpf[j]);
						if((j!=8) && (j+1)%3==0)
							printf(".");
						if(j==8)
							printf("-");
					}
			L++;
			gotoxy(C,L);
			printf("Data: %d/%d/%d | Total: R$ %.2f",TabVendas[pos].DtVenda.d,TabVendas[pos].DtVenda.m,TabVendas[pos].DtVenda.a,TabVendas[pos].TotVenda);
			EscrMsg();
			printf("Confirma a Exclusao (S/N)?");
			if(toupper(getch())=='S')
			{
				TotMenos=TabVendas[pos].TotVenda;
				for(i=pos;i<TLV-1;i++)
				{
					TabVendas[i]=TabVendas[i+1];
					TabVendas[i].CodVenda-=1;
				}
				TLV--;
				TabCli[aux].QtdeCompras-=1;
				TabCli[aux].ValorTotComp-=TotMenos;
				pos=BuscaVenda(TabVP,TLVP,cod);
				i=pos;
					while(TabVP[i].CodVenda==cod)
					{
						while(i<TLVP-1)
						{
							TabVP[i]=TabVP[i+1];
							i++;
						}
						TLVP--;
						i=pos;
					}
					for(i=pos;i<=TLVP;i++){
						TabVP[i].CodVenda-=1;
						}
					EscrMsg();
					printf("Venda Excluida!");
	
			}
			else
			{
				EscrMsg();
				printf("Exclusao Cancelada!");
				getch();
			}
		}
	}
	LimpaEntrada();	
}

void ExcCli(tpClientes TabCli[TF],int &TLC)
{
	int pos,i,j,C,L,VCPF;
	char cpf[11];
	
	if(TLC==0)
	{
		EscrMsg();
		printf("Nao Existem Clientes Cadastrados!");
		getch();
	}
	else
	{
		InicioTela;
		textcolor(9);
		gotoxy(3,11);
		printf("[C] Exclusao");
		textcolor(0);
		InicioTela(C,L);
		printf("Exclusao de Clientes");
		L+=2;
		gotoxy(C,L);
		printf("CPF do Cliente: ");
		LimpaEntrada();
		strcpy(cpf,ValidaString());
		while(strcmp(cpf,"0"))
		{
			VCPF=ValidaCPF(cpf);
			if(VCPF==0)
			{
				EscrMsg();
				printf("CPF Invalido");
				getch();
			}
			else
			{
				pos=BuscaCPF(TabCli,TLC,cpf);
				if(pos==-1)
				{
					EscrMsg();
					printf("Cliente Nao Cadastrado");
					getch();
				}
				else
				{
					InicioTela(C,L);
					printf("Exclusao de Clientes");
					L+=2;
					gotoxy(C,L);
					printf("CPF: ");
					for(j=0;j<11;j++)
					{
						printf("%c",TabCli[pos].cpf[j]);
						if((j!=8) && (j+1)%3==0)
							printf(".");
						if(j==8)
							printf("-");
					}
					L++;
					gotoxy(C,L);
					printf("Nome: %s",TabCli[pos].NomeC);
					L++;
					gotoxy(C,L);
					printf("Quantidade de Compras: %d",TabCli[pos].QtdeCompras);
					L++;
					gotoxy(C,L);
					printf("Valor Total Comprado: R$ %.2f",TabCli[pos].ValorTotComp);
					EscrMsg();
					printf("Confirma a Exclusao (S/N)?");
					if(toupper(getch())=='S')
					{
						for(i=pos;i<TLC;i++)
							TabCli[i] = TabCli[i+1];
						EscrMsg();
						printf("Cliente Excluido!");
						getch();
						TLC--;
					}
					else
					{
						EscrMsg();
						printf("Exclusao Cancelada!");
						getch();
					}
				}	
			}
			if(TLC>0)
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("CPF do Cliente: ");
				LimpaEntrada();
				gets(cpf);
			}
			else
				strcpy(cpf,"0");
		}
	}
	LimpaEntrada();
}

void ExcProd(tpProdutos TabProd[TF],int &TLP,tpFornecedores TabForn[TF], int TLF,tpVendas_Prod TabVP[TF], int TLVP)
{
	int Cod,pos,posForn,i,C,L,posProdVenda;
	
	if(TLP==0)
	{
		EscrMsg();
		printf("Nao Existem Produtos Cadastrados");
		getch();
	}
	else
	{
		InicioTela;
		textcolor(9);
		gotoxy(3,11);
		printf("[C] Exclusao");
		textcolor(0);
		InicioTela(C,L);
		printf("Exclusao de Produtos");
		L+=2;
		gotoxy(C,L);
		printf("Codigo do Produto: ");
		LimpaEntrada();
		ValidaInt(Cod);
		while(Cod!=0)
		{
			pos=BuscaCodProd(TabProd,TLP,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Produto Nao Cadastrado");
				getch();
			}
			else
			{
				InicioTela(C,L);
				printf("Exclusao de Produtos");
				L+=2;
				gotoxy(C,L);
				printf("Codigo: %d",TabProd[pos].CodProd);
				L++;
				gotoxy(C,L);
				printf("Descricao: %s",TabProd[pos].Descr);
				L++;
				gotoxy(C,L);
				posForn=BuscaCodForn(TabForn,TLF,TabProd[pos].CodForn);
				printf("Fornecedor [%d] - %s",TabProd[pos].CodForn,TabForn[posForn].NomeForn);
				L++;
				gotoxy(C,L);
				printf("Estoque: %d   -   ",TabProd[pos].Estoque);
				printf("Preco: R$ %.2f",TabProd[pos].Preco);
				L++;
				gotoxy(C,L);
				printf("Validade: %d/%d/%d",TabProd[pos].DtValidade.d,TabProd[pos].DtValidade.m,TabProd[pos].DtValidade.a);
				EscrMsg();
				printf("Confirma a Exclusao (S/N)?");
				if(toupper(getche())=='S')
					if(TabProd[pos].Estoque == 0)
					{
						posProdVenda = BuscaProdVenda(TabVP,TLVP,Cod);
						if(posProdVenda==-1)
						{
							for(i=pos;i<TLP;i++)
								TabProd[i] = TabProd[i+1];
							EscrMsg();
							printf("Produto Excluido");
							getch();
							TLP--;
						}
						else
						{
							EscrMsg();
							printf("Nao E Possivel Excluir Este Produto");
							getch();
						}
					}
					else
					{
						EscrMsg();
						printf("Nao E Possivel Excluir Um Produto Em Estoque");
						getch();
					}
				else
				{
					EscrMsg();
					printf("Exclusao Cancelada");
					getch();
				}	
			}
			if(TLP>0)
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("Codigo do Produto: ");
				LimpaEntrada();
				ValidaInt(Cod);
			}
			else
				Cod=0;
		}
	}
	LimpaEntrada();
}

void ExcForn(tpFornecedores Tab[TF],int &TL,tpProdutos TabProd[TF], int TLP)
{
	int Cod,pos,posProd,i,C,L;
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados");
		getch();
	}
	else
	{
		InicioTela;
		textcolor(9);
		gotoxy(3,11);
		printf("[C] Exclusao");
		textcolor(0);
		InicioTela(C,L);
		printf("Exclusao de Fornecedores");
		L+=2;
		gotoxy(C,L);
		printf("Codigo do Fornecedor: ");
		LimpaEntrada();
		ValidaInt(Cod);
		while(Cod!=0)
		{
			pos=BuscaCodForn(Tab,TL,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Fornecedor Nao Cadastrado");
				getch();
			}
			else
			{
				InicioTela(C,L);
				printf("Exclusao de Fornecedores");
				L+=2;
				gotoxy(C,L);
				printf("Codigo: %d", Tab[pos].CodForn);
				L++;
				gotoxy(C,L);
				printf("Nome: %s", Tab[pos].NomeForn);
				L++;
				gotoxy(C,L);
				printf("Cidade: %s", Tab[pos].Cidade);
				L++;
				EscrMsg();
				printf("Confirma a Exclusao (S/N)?");
				if(toupper(getche())=='S')
				{
					posProd=BuscaFornProd(TabProd,TLP,Tab[pos].CodForn);
					if(posProd==-1)
					{
						for(i=pos;i<TL;i++)
							Tab[i] = Tab[i+1];
						EscrMsg();
						printf("Fornecedor Excluido");
						getch();
						TL--;
					}
					else
					{
						EscrMsg();
						printf("Nao E Possivel Excluir Fornecedor Com Produtos Ativos");
						getch();
					}
				}
				else
				{
					EscrMsg();
					printf("Exclusao Cancelada");
					getch();
				}	
			}
			if(TL>0)
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("Codigo do Fornecedor: ");
				LimpaEntrada();
				ValidaInt(Cod);
			}
			else
				Cod=0;
		}
	}
}

void AltForn(tpFornecedores Tab[TF],int TL,tpProdutos TabProd[TF],int TLP)
{
	int Cod,pos,C,L,posCod,AuxCod,i;
	char op, StrAux[30];
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao Ha Fornecedores Cadastrados");
		getch();
	}
	else
	{
		InicioTela(C,L);
		textcolor(9);
		gotoxy(3,12);
		printf("[D] Alteracao");
		textcolor(0);
		InicioTela(C,L);
		printf("Alteracao de Fornecedores");
		gotoxy(C,L);
		L+=2;
		gotoxy(C,L);
		printf("Codigo do Fornecedor: ");
		L++;
		LimpaEntrada();
		ValidaInt(Cod);
		while(TL<TF && Cod!=0)
		{
			pos=BuscaCodForn(Tab,TL,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Fornecedor Nao Encontrado");
				getch();
			}
			else
			{
				do
				{
					LimpaMsg();
					InicioTela(C,L);
					printf("Alteracao de Fornecedores");
					L+=2;
					gotoxy(C,L);
					printf("Codigo [%d] - ",Tab[pos].CodForn);
					printf("%s",Tab[pos].NomeForn);
					L++;
					gotoxy(C,L);
					printf("Cidade: %s",Tab[pos].Cidade);
					L+=2;
					gotoxy(C,L);
					printf("[A] Codigo do Fornecedor: ");
					L++;
					gotoxy(C,L);
					printf("[B] Nome Fantasia do Fornecedor: ");
					L++;
					gotoxy(C,L);
					L++;
					printf("[C] Cidade do Fornecedor: ");
					gotoxy(C,L);
					L++;
					printf("[R] Voltar: ");
					LimpaEntrada();
					op=toupper(getch());
					switch(op)
					{
						case 'A':
							InicioTela(C,L);
							printf("Alteracao de Fornecedores");
							L+=2;
							gotoxy(C,L);
							printf("Codigo: %d",Tab[pos].CodForn);
							L+=2;
							gotoxy(C,L);
							printf("Novo Codigo:");
							LimpaEntrada();
							ValidaInt(AuxCod);
							posCod=BuscaCodForn(Tab,TL,AuxCod);
							if(posCod==-1 || posCod==pos)
							{
								if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									Tab[pos].CodForn=AuxCod;
									EscrMsg();
									printf("Codigo Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
									getch();
								}
							}
							else
							{
								EscrMsg();
								printf("Codigo Indisponivel");
								getch();
							}
							break;
						case 'B':
							InicioTela(C,L);
							printf("Alteracao de Fornecedores");
							L+=2;
							gotoxy(C,L);
							printf("Nome: %s",Tab[pos].NomeForn);
							L+=2;
							gotoxy(C,L);
							printf("Novo Nome:");
							strcpy(StrAux,ValidaString());
							if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									strcpy(Tab[pos].NomeForn,StrAux);
									EscrMsg();
									printf("Nome Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							break;
						case 'C':
							InicioTela(C,L);
							printf("Alteracao de Fornecedores");
							L+=2;
							gotoxy(C,L);
							printf("Cidade: %s",Tab[pos].Cidade);
							L+=2;
							gotoxy(C,L);
							printf("Nova Cidade:");
							strcpy(StrAux,ValidaString());
							if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									strcpy(Tab[pos].Cidade,StrAux);
									EscrMsg();
									printf("Nome Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							break;
					}
					if(op!='R')
					{
						EscrMsg();
						printf("Realizar Nova Alteracao no Fornecedor (S/N)?");
						LimpaEntrada();
						if(toupper(getch())!='S')
							op='R';
					}
				}while(op!='R');
			}
			EscrMsg();
			printf("Alterar Outro Fornecedor (S/N)?");
			LimpaEntrada();
			if(toupper(getch())=='S')
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("Alteracao de Fornecedores");
				gotoxy(C,L);
				L+=2;
				gotoxy(C,L);
				printf("Codigo do Fornecedor: ");
				L++;
				LimpaEntrada();
				ValidaInt(Cod);
			}
			else
			{
				Cod=0;
			}
		}
		LimpaTela();
		MenuFornecedor();
		LimpaEntrada();
	}
}

void AltCli(tpClientes TabCli[TF],int TLC)
{
	int pos,C,L,posCPF,i;
	char CPF[11],op,StrAux[30],AuxCPF[30];
	
	if(TLC==0)
	{
		EscrMsg();
		printf("Nao Ha Clientes Cadastrados");
		getch();
	}
	else
	{
		InicioTela(C,L);
		textcolor(9);
		gotoxy(3,12);
		printf("[D] Alteracao");
		textcolor(0);
		InicioTela(C,L);
		printf("Alteracao de Clientes");
		gotoxy(C,L);
		L+=2;
		gotoxy(C,L);
		printf("CPF do Cliente: ");
		L++;
		LimpaEntrada();
		strcpy(CPF,ValidaString());
		while(TLC<TF && strcmp(CPF,"0"))
		{
			pos=BuscaCPF(TabCli,TLC,CPF);
			if(pos==-1)
			{
				EscrMsg();
				printf("Cliente Nao Encontrado");
				getch();
			}
			else
			{
				do
				{
					LimpaMsg();
					InicioTela(C,L);
					printf("Alteracao de Clientes");
					L+=2;
					gotoxy(C,L);
					printf("[A] CPF: ");
					for(i=0;i<11;i++)
					{
						printf("%c",TabCli[pos].cpf[i]);
						if((i!=8) && (i+1)%3==0)
							printf(".");
						if(i==8)
							printf("-");
					}
					L++;
					gotoxy(C,L);
					printf("[B] Nome: %s",TabCli[pos].NomeC);
					L+=2;
					gotoxy(C,L);
					printf("[R] Voltar: ");
					LimpaEntrada();
					op=toupper(getch());
					switch(op)
					{
						case 'A':
							InicioTela(C,L);
							printf("Alteracao de Clientes");
							L+=2;
							gotoxy(C,L);
							printf("CPF: ");
							for(i=0;i<11;i++)
							{
								printf("%c",TabCli[pos].cpf[i]);
								if((i!=8) && (i+1)%3==0)
									printf(".");
								if(i==8)
									printf("-");
							}
							L+=2;
							gotoxy(C,L);
							printf("Novo CPF:");
							LimpaEntrada();
							strcpy(CPF,ValidaString());
							posCPF=BuscaCPF(TabCli,TLC,CPF);
							if(posCPF==-1 || posCPF==pos)
							{
								if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									strcpy(TabCli[pos].cpf,AuxCPF);
									EscrMsg();
									printf("Codigo Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
									getch();
								}
							}
							else
							{
								EscrMsg();
								printf("CPF Ja Cadastrado");
								getch();
							}
							break;
						case 'B':
							InicioTela(C,L);
							printf("Alteracao de Clientes");
							L+=2;
							gotoxy(C,L);
							printf("Nome: %s",TabCli[pos].NomeC);
							L+=2;
							gotoxy(C,L);
							printf("Novo Nome:");
							strcpy(StrAux,ValidaString());
							if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									strcpy(TabCli[pos].NomeC,StrAux);
									EscrMsg();
									printf("Nome Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							break;
					}
					if(op!='R')
					{
						EscrMsg();
						printf("Realizar Nova Alteracao no Cliente (S/N)?");
						LimpaEntrada();
						if(toupper(getch())!='S')
							op='R';
					}
				}while(op!='R');
			}
			EscrMsg();
			printf("Alterar Outro Cliente (S/N)?");
			LimpaEntrada();
			if(toupper(getch())=='S')
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("Alteracao de Clientes");
				gotoxy(C,L);
				L+=2;
				gotoxy(C,L);
				printf("CPF do Cliente: ");
				L++;
				LimpaEntrada();
				strcpy(CPF,ValidaString());
			}
			else
			{
				strcpy(CPF,"0");
			}
		}
		LimpaTela();
		MenuFornecedor();
		LimpaEntrada();
	}
}

void AltProd(tpFornecedores Tab[TF],int TL,tpProdutos TabProd[TF],int TLP)
{
	int Cod,pos,C,L,posCod,AuxCod,i,posForn,AuxForn,AuxEstoque,AD,AM,AA;
	float AuxPreco;
	char op, StrAux[30];
	
	if(TLP==0)
	{
		EscrMsg();
		printf("Nao Ha Produtos Cadastrados");
		getch();
	}
	else
	{
		InicioTela(C,L);
		textcolor(9);
		gotoxy(3,12);
		printf("[D] Alteracao");
		textcolor(0);
		InicioTela(C,L);
		printf("Alteracao de Produtos");
		gotoxy(C,L);
		L+=2;
		gotoxy(C,L);
		printf("Codigo do Produto: ");
		L++;
		LimpaEntrada();
		ValidaInt(Cod);
		while(TLP<TF && Cod!=0)
		{
			pos=BuscaCodProd(TabProd,TLP,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Produto Nao Encontrado");
				getch();
			}
			else
			{
				do
				{
					LimpaMsg();
					InicioTela(C,L);
					gotoxy(C,L-1);
					printf("Alteracao de Produtos");
					gotoxy(C,L);
					printf("Produto [%d] - ",TabProd[pos].CodProd);
					printf("%s",TabProd[pos].Descr);
					L++;
					gotoxy(C,L);
					posForn=BuscaCodForn(Tab,TL,TabProd[pos].CodForn);
					printf("Fornecedor [%d] - ",TabProd[pos].CodForn);
					printf("%s",Tab[posForn].NomeForn);
					L++;
					gotoxy(C,L);
					printf("Estoque: %d",TabProd[pos].Estoque);
					gotoxy(C+25,L);
					printf("Preco: %.2f",TabProd[pos].Preco);
					L++;
					gotoxy(C,L);
					printf("Validade: %d/%d/%d",TabProd[pos].DtValidade.d,TabProd[pos].DtValidade.m,TabProd[pos].DtValidade.a);
					L+=2;
					gotoxy(C,L);
					printf("[A] Codigo do Produto: ");
					L++;
					gotoxy(C,L);
					printf("[B] Descricao do Produto: ");
					L++;
					gotoxy(C,L);
					printf("[C] Fornecedor: ");
					L++;
					gotoxy(C,L);
					printf("[D] Estoque: ");
					gotoxy(C+25,L);
					printf("[E] Preco: ");
					L++;
					gotoxy(C,L);
					printf("[F] Validade: ");
					gotoxy(C+25,L);
					printf("[R] Voltar: ");
					LimpaEntrada();
					op=toupper(getch());
					switch(op)
					{
						case 'A':
							InicioTela(C,L);
							printf("Alteracao de Produtos");
							L+=2;
							gotoxy(C,L);
							printf("Codigo: %d",Tab[pos].CodForn);
							L+=2;
							gotoxy(C,L);
							printf("Novo Codigo:");
							LimpaEntrada();
							ValidaInt(AuxCod);
							posCod=BuscaCodProd(TabProd,TLP,AuxCod);
							if(posCod==-1 || posCod==pos)
							{
								if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									TabProd[pos].CodProd=AuxCod;
									EscrMsg();
									printf("Codigo Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							}
							else
							{
								EscrMsg();
								printf("Codigo Indisponivel");
								getch();
							}
							break;
						case 'B':
							InicioTela(C,L);
							printf("Alteracao de Produtos");
							L+=2;
							gotoxy(C,L);
							printf("Descricao: %s",TabProd[pos].Descr);
							L+=2;
							gotoxy(C,L);
							printf("Nova Descricao:");
							strcpy(StrAux,ValidaString());
							if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									strcpy(TabProd[pos].Descr,StrAux);
									EscrMsg();
									printf("Descricao Alterada");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							break;
						case 'C':
							InicioTela(C,L);
							printf("Alteracao de Produtos");
							L+=2;
							gotoxy(C,L);
							printf("Fornecedor [%d] - ",TabProd[pos].CodForn);
							printf("%s",Tab[posForn].NomeForn);
							L+=2;
							gotoxy(C,L);
							printf("Novo Fornecedor:");
							LimpaEntrada();
							ValidaInt(AuxForn);
							posForn=BuscaCodForn(Tab,TL,AuxForn);
							if(posForn==-1)
							{
								EscrMsg();
								printf("Fornecedor Inexistente");
								getch();
							}
							else
							{
								if(ConfirmaAlt()==1)
									{
										LimpaEntrada();
										TabProd[pos].CodForn=AuxForn;
										EscrMsg();
										printf("Fornecedor Alterado");
										getch();
									}
									else
									{
										EscrMsg();
										printf("Operacao Cancelada");
									}
							}
							break;
						case 'D':
							InicioTela(C,L);
							printf("Alteracao de Produtos");
							L+=2;
							gotoxy(C,L);
							printf("Estoque: %d",TabProd[pos].Estoque);
							L+=2;
							gotoxy(C,L);
							printf("Novo Estoque:");
							LimpaEntrada();
							ValidaInt(AuxEstoque);
							if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									TabProd[pos].Estoque=AuxEstoque;
									EscrMsg();
									printf("Estoque Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							break;
						case 'E':
							InicioTela(C,L);
							printf("Alteracao de Produtos");
							L+=2;
							gotoxy(C,L);
							printf("Preco: %.2f",TabProd[pos].Preco);
							L+=2;
							gotoxy(C,L);
							printf("Novo Preco:");
							LimpaEntrada();
							ValidaFloat(AuxPreco);
							if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									TabProd[pos].Preco=AuxPreco;
									EscrMsg();
									printf("Estoque Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							break;
						case 'F':
							InicioTela(C,L);
							printf("Alteracao de Produtos");
							L+=2;
							gotoxy(C,L);
							printf("Validade: %d/%d/%d",TabProd[pos].DtValidade.d,TabProd[pos].DtValidade.m,TabProd[pos].DtValidade.a);
							L+=2;
							gotoxy(C,L);
							printf("Nova Validade:");
							LimpaEntrada();
							ValidaData(AD,AM,AA);
							if(ConfirmaAlt()==1)
								{
									LimpaEntrada();
									TabProd[pos].DtValidade.d=AD;
									TabProd[pos].DtValidade.m=AM;
									TabProd[pos].DtValidade.a=AA;
									EscrMsg();
									printf("Validade Alterado");
									getch();
								}
								else
								{
									EscrMsg();
									printf("Operacao Cancelada");
								}
							break;
					}
					if(op!='R')
					{
						EscrMsg();
						printf("Realizar Nova Alteracao no Produto (S/N)?");
						LimpaEntrada();
						if(toupper(getch())!='S')
							op='R';
					}
				}while(op!='R');
			}
			EscrMsg();
			printf("Alterar Outro Produto (S/N)?");
			LimpaEntrada();
			if(toupper(getch())=='S')
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("Alteracao de Produtos");
				gotoxy(C,L);
				L+=2;
				gotoxy(C,L);
				printf("Codigo do Produto: ");
				L++;
				LimpaEntrada();
				ValidaInt(Cod);
			}
			else
			{
				Cod=0;
			}
		}
		LimpaTela();
		MenuFornecedor();
		LimpaEntrada();
	}
}

void AumentoForn(tpProdutos TabProd[TF],int TLP,tpFornecedores TabForn[TF],int TLF)
{
	int C,L,i,Cod,posProd,posForn;
	float porc;
	
	if(TLP==TF)
	{
		EscrMsg();
		printf("Nao Ha Espaco Para Cadastro");
		getch();
	}
	else
	if(TLF!=0)
	{
		LimpaMsg();
		LimpaTela();
		textcolor(9);
		gotoxy(3,14);
		printf("[F] Aumento de Precos");
		textcolor(0);
		InicioTela(C,L);
		printf("Aumento de Precos de Fornecedores");
		gotoxy(C,L);
		L+=2;
		gotoxy(C,L);
		printf("Codigo do Fornecedor: ");
		L++;
		LimpaEntrada();
		ValidaInt(Cod);
		while(TLF<TF && Cod!=0)
		{
			posForn=BuscaCodForn(TabForn,TLF,Cod);
			if(posForn==-1)
			{
				EscrMsg();
				printf("Fornecedor Nao Encontrado");
				getch();
			}
			else
			{
				InicioTela(C,L);
				printf("Aumento de Precos de Fornecedores");
				L+=2;
				gotoxy(C,L);
				printf("Codigo [%d] - ",TabForn[posForn].CodForn);
				printf("%s",TabForn[posForn].NomeForn);
				L+=2;
				gotoxy(C,L);
				printf("Informe a porcentagem do aumento:");
				LimpaEntrada();
				ValidaFloat(porc);
				EscrMsg();
				printf("Confirma o aumento de %.2f%% (S/N)",porc);
				if(toupper(getch())=='S')
				{
					for(i=0;i<TLP;i++)
					{
						if(TabProd[i].CodForn==Cod)
							TabProd[i].Preco*=(1+(porc/100));
						EscrMsg();
						printf("Repasse Efetuado Com Sucesso");
						getch();
					}
				}
				else
				{
					EscrMsg();
					printf("Operacao Cancelada");
					getch();
				}
			}
			LimpaMsg();
			InicioTela(C,L);
			printf("Aumento de Precos de Fornecedores");
			gotoxy(C,L);
			L+=2;
			gotoxy(C,L);
			printf("Codigo do Fornecedor: ");
			L++;
			LimpaEntrada();
			ValidaInt(Cod);
		}
	}
}

void ConsultaCF(tpVendas_Prod TabVendaProd[TF],int TLVP,tpVendas TabVenda[TF],int TLV,tpClientes TabCli[TF],int TLC,tpProdutos TabProd[TF],int TLP)
{
	int Cod,C,L,i,posCPF,posProd,posCupom;
	if(TLV==0)
	{
		EscrMsg();
		printf("Nao Existem Cupons Fiscais Cadastrados");
		getch();
	}
	else
	{
		LimpaMsg();
		LimpaTela();
		textcolor(9);
		gotoxy(3,14);
		printf("[F] Consultar Cupom");
		textcolor(0);
		InicioTela(C,L);
		printf("Insira o Codigo da Venda");
		LimpaEntrada();
		ValidaInt(Cod);
		while(Cod!=0)
		{
			posCupom=BuscaCupom(TabVenda,TLV,Cod);
			if(posCupom==-1)
			{
				EscrMsg();
				printf("Cupom Fiscal Nao Encontrado");
				getch();
			}
			else
			{
				InicioTela(C,L);
				gotoxy(C,L-1);
				printf("CUPOM FISCAL [%d]",TabVenda[posCupom].CodVenda);
				gotoxy(67,L-1);
				printf("%d/%d/%d",TabVenda[posCupom].DtVenda.d,TabVenda[posCupom].DtVenda.m,TabVenda[posCupom].DtVenda.a);
				L++;
				gotoxy(C,L);
				posCPF=BuscaCPF(TabCli,TLC,TabVenda[posCupom].cpf);
				printf("CLIENTE %s - CPF: ",TabCli[posCPF].NomeC);
				for(i=0;i<11;i++)
				{
					printf("%c",TabVenda[posCupom].cpf[i]);
					if((i!=8) && (i+1)%3==0)
						printf(".");
					if(i==8)
						printf("-");
				}
				L++;
				gotoxy(C,L);
				printf("-----------------------------------------------");
				L++;
				gotoxy(C,L);
				printf("QTDE  ITEM  DESCR                       VALOR  ");
				for(i=0;i<TLVP;i++)
				{
					if(TabVendaProd[i].CodVenda==Cod)
					{
						L++;
						posProd=BuscaCodProd(TabProd,TLP,TabVendaProd[i].CodProd);
						gotoxy(C,L);
						printf("%d",TabVendaProd[i].Qtde);
						gotoxy(37,L);
						printf("%d",TabVendaProd[i].CodProd);
						gotoxy(43,L);
						printf("%s",TabProd[posProd].Descr);
						gotoxy(71,L);
						printf("%.2f",TabVendaProd[i].ValorUni);
					}
					if(L%16==0)
					{
						fflush(stdin);
						getch();
						InicioTela(C,L);
					}
				}
				if(L>14)
					InicioTela(C,L);
				L++;
				gotoxy(C,L);
				printf("-----------------------------------------------");
				L++;
				gotoxy(58,L);
				printf("TOTAL: R$ %.2f",TabVenda[posCupom].TotVenda);
				getch();
			}
			EscrMsg();
			printf("Deseja Consultar Outro Cupom (S/N)?");
			if(toupper(getch())=='S')
			{
				LimpaMsg();
				InicioTela(C,L);
				printf("Insira o Codigo da Venda");
				LimpaEntrada();
				ValidaInt(Cod);
			}
			else
				Cod=0;
		}
	}
}

int VerMenuSec(int op)
{
	if(op!='A' && op!='B' && op!='C' && op!='D' && op!='E' && op!='R')
		return -1;
	else
		return op;
}

int VerMenuVendas(int op)
{
	if(op!='A' && op!='B' && op!='C' && op!='D' && op!='E' && op!='F' && op!='R')
		return -1;
	else
		return op;
}

int VerMenuForn(int op)
{
	if(op!='A' && op!='B' && op!='C' && op!='D' && op!='E' && op!='F' && op!='R')
		return -1;
	else
		return op;
}

int VerMenuP(int op)
{
	if(op!='C' && op!='P' && op!='F' && op!='V' && op!='I' && op!=27)
		return -1;
	else
		return op;
}

void Venda(tpClientes TabCli[TF],int TLC,tpProdutos TabProd[TF],int TLP,tpFornecedores TabForn[TF],int TLF,tpVendas TabVenda[TF],int &TLV,tpVendas_Prod TabVendaProd[TF],int &TLVP)
{
	int C,L,i,posCPF,Cod,posProd,posForn,qtde,auxd,auxm,auxa,vpcpf;
	float totvendaprod,totvenda=0;
	char CPF[11];
	
	if(TLC==0)
	{
		EscrMsg();
		printf("Nao Existem Clientes Cadastrados");
		getch();
	}
	else
		if(TLP==0)
		{
			EscrMsg();
			printf("Nao Existem Produtos Cadastrados");
			getch();
		}
		else
			if(TLF==0)
			{
				EscrMsg();
				printf("Nao Existem Fornecedores Cadastrados");
				getch();
			}
			else
			{
				LimpaMsg();
				LimpaTela();
				textcolor(9);
				gotoxy(3,9);
				printf("[A] Realizar Venda");
				textcolor(0);
				InicioTela(C,L);
				printf("Venda");
				gotoxy(C,L);
				L+=2;
				gotoxy(C,L);
				printf("CPF do Cliente: ");
				L++;
				LimpaEntrada();
				strcpy(CPF,ValidaString());
				while(TLC<TF && strcmp(CPF,"0")!=0)
				{
					vpcpf=0;
					posCPF=BuscaCPF(TabCli,TLC,CPF);
					if(posCPF==-1)
					{
						EscrMsg();
						printf("Cliente Nao Cadastrado");
						getch();
					}
					else
					{
						InicioTela(C,L);
						printf("Venda: ");
						printf("%s",TabCli[posCPF].NomeC);
						L+=2;
						gotoxy(C,L);
						printf("Data da Venda: ");
						ValidaData(auxd,auxm,auxa);
						L++;
						gotoxy(C,L);
						printf("Codigo Do Produto: ");
						LimpaEntrada();
						ValidaInt(Cod);
						while(TLP<TF && Cod!=0)
						{
							posProd=BuscaCodProd(TabProd,TLP,Cod);
							if(posProd==-1)
							{
								EscrMsg();
								printf("Produto Nao Encontrado");
								getch();
							}
							else
							{
								totvendaprod=0;
								InicioTela(C,L);
								printf("Venda: ");
								printf("%s",TabCli[posCPF].NomeC);
								printf("     Data: %d/%d/%d",auxd,auxm,auxa);
								L+=2;
								gotoxy(C,L);
								printf("Codigo: %d",TabProd[posProd].CodProd);
								L++;
								gotoxy(C,L);
								printf("Descricao: %s",TabProd[posProd].Descr);
								L++;
								gotoxy(C,L);
								posForn=BuscaCodForn(TabForn,TLF,TabProd[posProd].CodForn);
								printf("Fornecedor [%d] - %s",TabProd[posProd].CodForn,TabForn[posForn].NomeForn);
								L++;
								gotoxy(C,L);
								printf("Estoque: %d   -   ",TabProd[posProd].Estoque);
								printf("Preco: R$ %.2f",TabProd[posProd].Preco);
								L++;
								gotoxy(C,L);
								printf("Validade: %d/%d/%d",TabProd[posProd].DtValidade.d,TabProd[posProd].DtValidade.m,TabProd[posProd].DtValidade.a);
								EscrMsg();
								printf("Confirma Produto (S/N)");
								if(toupper(getch())=='S')
								{
									LimpaMsg();
									L++;
									gotoxy(C,L);
									printf("Quantidade: ");
									L+=2;
									LimpaEntrada();
									ValidaInt(qtde);
									if(qtde>0 && TabProd[posProd].Estoque>=qtde)
									{
										EscrMsg();
										totvendaprod = qtde*TabProd[posProd].Preco;
										gotoxy(C,L);
										printf("Preco final: %.2f",totvendaprod);
										EscrMsg();
										printf("Confirma Venda (S/N)?");
										if(toupper(getch())=='S')
										{
											TabProd[posProd].Estoque-=qtde;
											TabVendaProd[TLVP].Qtde=qtde;
											TabVendaProd[TLVP].CodVenda=TLV+1;
											TabVendaProd[TLVP].CodProd=TabProd[posProd].CodProd;
											TabVendaProd[TLVP].ValorUni=TabProd[posProd].Preco;
											TLVP++;
											vpcpf++;
											totvenda+=totvendaprod;
											EscrMsg();
											printf("Venda Do Produto Realizada");
											getch();
											
										}
										else
										{
											EscrMsg();
											printf("Venda Do Produto Cancelada");
											getch();
										}
									}
									else
									{
										EscrMsg();
										printf("Quantidade Nao Disponivel no Estoque");
										getch();
									}
								}
								else
								{
									EscrMsg();
									printf("Produto Nao Adicionado");
									getch();
								}
							}
							EscrMsg();
							printf("Adicionar Outro Produto (S/N)?");
							if(toupper(getch())=='S')
							{
								LimpaMsg();
								if(TLV<TF)
								{
									InicioTela(C,L);
									printf("Venda: ");
									printf("%s",TabCli[posCPF].NomeC);
									gotoxy(C,L);
									printf("Codigo Do Produto: ");
									L++;
									LimpaEntrada();
									ValidaInt(Cod);
								}
							}
							else
								Cod=0;
						}
						if(vpcpf>0)
						{
							strcpy(TabVenda[TLV].cpf,TabCli[posCPF].cpf);
							TabVenda[TLV].DtVenda.d=auxd;
							TabVenda[TLV].DtVenda.m=auxm;
							TabVenda[TLV].DtVenda.a=auxa;
							TabVenda[TLV].TotVenda+=totvenda;
							TabVenda[TLV].CodVenda=TLV+1;
							TabCli[posCPF].QtdeCompras++;
							TabCli[posCPF].ValorTotComp+=totvenda;
							EscrMsg();
							printf("Venda Finalizada");
							getch();
							LimpaMsg();
							InicioTela(C,L);
							gotoxy(C,L-1);
							printf("CUPOM FISCAL");
							gotoxy(67,L-1);
							printf("%d/%d/%d",TabVenda[TLV].DtVenda.d=auxd,TabVenda[TLV].DtVenda.m=auxm,TabVenda[TLV].DtVenda.a=auxa);
							L++;
							gotoxy(C,L);
							printf("CLIENTE %s - CPF: ",TabCli[posCPF].NomeC);
							for(i=0;i<11;i++)
							{
								printf("%c",TabVenda[TLV].cpf[i]);
								if((i!=8) && (i+1)%3==0)
									printf(".");
								if(i==8)
									printf("-");
							}
							L++;
							gotoxy(C,L);
							printf("-----------------------------------------------");
							L++;
							gotoxy(C,L);
							printf("QTDE  ITEM  DESCR                       VALOR  ");
							for(i=0;i<TLVP;i++)
							{
								if(TabVendaProd[i].CodVenda==TabVenda[TLV].CodVenda)
								{
									L++;
									posProd=BuscaCodProd(TabProd,TLP,TabVendaProd[i].CodProd);
									gotoxy(C,L);
									printf("%d",TabVendaProd[i].Qtde);
									gotoxy(37,L);
									printf("%d",TabVendaProd[i].CodProd);
									gotoxy(43,L);
									printf("%s",TabProd[posProd].Descr);
									gotoxy(71,L);
									printf("%.2f",TabVendaProd[i].ValorUni);
								}
								if(L%16==0)
								{
									fflush(stdin);
									getch();
									InicioTela(C,L);
								}
							}
							if(L>14)
								InicioTela(C,L);
							L++;
							gotoxy(C,L);
							printf("-----------------------------------------------");
							L++;
							gotoxy(58,L);
							printf("TOTAL: R$ %.2f",TabVenda[TLV].TotVenda);
							getch();
							TLV++;
						}
						else
						{
							EscrMsg();
							printf("Nenhum Produto Vendido");
							
						}
					}
					EscrMsg();
					printf("Realizar Nova Venda (S/N)?");
					if(toupper(getch())=='S')
					{
						InicioTela(C,L);
						printf("Venda");
						gotoxy(C,L);
						L+=2;
						gotoxy(C,L);
						printf("CPF do Cliente: ");
						L++;
						LimpaEntrada();
						strcpy(CPF,ValidaString());
					}
					else
					{
						EscrMsg();
						printf("Menu de Vendas Encerrado!");
						LimpaEntrada();
						getch();
						strcpy(CPF,"0");
					}
				}
			}
}


int main(void)
{
	tpVendas TabVenda[TF];
	tpVendas_Prod TabVP[TF];
	tpClientes TabCli[TF];
	tpProdutos TabProd[TF];
	tpFornecedores TabForn[TF];
	int TL=0,CI=1,LI=1,CF=80,LF=20,CorT=15,CorF=1,TLCli=0,TLForn=0,TLProd=0,TLV=0,TLVP=0,C,L,VerMenu,d,m,a;
	char op;
	
	do
	{
		op = Menu();
		LimpaMsg();
		LimpaEntrada();
		if(VerMenuP(op)==-1)
			EntInv();
		else
			switch(op)
			{
				case 'P':
					do
					{
						MenuProduto();
						op = toupper(getch());
						if(VerMenuSec(op)==-1)
							EntInv();
						else
							switch(op)
							{
								case 'A':
									CadProd(TabProd,TLProd,TabForn,TLForn);
									break;
								case 'B':
									ConsultaProd(TabProd,TLProd,TabForn,TLForn);
									break;
								case 'C':
									ExcProd(TabProd,TLProd,TabForn,TLForn,TabVP,TLVP);
									break;
								case 'D':
									AltProd(TabForn,TLForn,TabProd,TLProd);
									break;
								case 'E':
									RelatorioProd(TabProd,TLProd,TabForn,TLForn);
									break;
							}
					}while(op!='R');
					break;
				case 'F':
					do
					{
						MenuFornecedor();
						op = toupper(getch());
						if(VerMenuForn(op)==-1)
							EntInv();
						else
						switch(op)
							{
								case 'A':
									CadForn(TabForn,TLForn);
									break;
								case 'B':
									ConsultaForn(TabForn,TLForn);
									break;
								case 'C':
									ExcForn(TabForn,TLForn,TabProd,TLProd);
									break;
								case 'D':
									AltForn(TabForn,TLForn,TabProd,TLProd);
									break;
								case 'E':
									RelatorioForn(TabForn,TLForn);
									break;
								case 'F':
									AumentoForn(TabProd,TLProd,TabForn,TLForn);
									break;
							}
					}while(op!='R');
					
					break;
				case 'C':
					do
					{
						MenuCliente();
						op = toupper(getch());
						if(VerMenuSec(op)==-1)
							EntInv();
						else
							switch(op)
							{
								case 'A':
									CadCli(TabCli,TLCli);
									break;
								case 'B':
									ConsultaCli(TabCli,TLCli);
									break;
								case 'C':
									ExcCli(TabCli,TLCli);
									break;
								case 'D':
									AltCli(TabCli,TLCli);
									break;
								case 'E':
									RelatorioCli(TabCli,TLCli);
									break;
							}
					}while(op!='R');
					break;
				case 'V':
					do
					{
						MenuVendas();
						op = toupper(getch());
						if(VerMenuVendas(op)==-1)
							EntInv();
						else
							switch(op)
							{
								case 'A':
									Venda(TabCli,TLCli,TabProd,TLProd,TabForn,TLForn,TabVenda,TLV,TabVP,TLVP);
									break;
								case 'B':
									RelatorioVP(TabVP,TLVP,TabCli,TLCli,TabProd,TLProd);
									break;
								case 'C':
									RelatorioVC(TabVenda,TLV,TabCli,TLCli);
									break;
								case 'D':
									RelatorioVendas(TabVenda,TLV,TabVP,TLVP,TabProd,TLProd,TabForn,TLForn);
									break;
								case 'E':
									ExcVenda(TabCli,TLCli,TabVenda,TabVP,TLVP,TLV);
									break;
								case 'F':
									ConsultaCF(TabVP,TLVP,TabVenda,TLV,TabCli,TLCli,TabProd,TLProd);
									break;
							}
					}while(op!='R');
					break;
				case 'I':
					InserirDados(TabProd,TLProd,TabCli,TLCli,TabForn,TLForn,TabVenda,TLV,TabVP,TLVP);
					break;
			} 
	}while(op!=27);
	
	gotoxy(1,27);
	return 0;
}
