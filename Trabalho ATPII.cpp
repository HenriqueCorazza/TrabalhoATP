#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>

#define TF 4

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
	char cpf[30], NomeC[30];
};

struct tpVendas
{
	int CodVenda;
	char cpf[14];
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
	
	textcolor(13);
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
	printf("# # #  S U P E R M E R C A D O   # # #");
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

void ValidaCod(int &Cod)
{
	int valido=0;
	while(valido!=1)
	{
		if(scanf("%d",&Cod)==1)
			valido=1;
		else
		{
			EscrMsg();
			printf("A Entrada Deve Ser Um Numero Inteiro");
			getch();
			LimpaMsg();
			LimpaEntrada();
		}
		fflush(stdin);
	}
}

void CadForn(tpFornecedores Tab[TF],int &TL_Forn)
{
	int Cod,pos,C,L;
	char op;
	
	if(TL_Forn==TF)
	{
		EscrMsg();
		printf("Nao Ha Espaco Para Cadastro");
		getch();
		LimpaMsg();
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
		LimpaMsg();
		LimpaEntrada();
		ValidaCod(Cod);
		while(TL_Forn<TF && Cod!=0)
		{
			pos=BuscaCodForn(Tab,TL_Forn,Cod);
			if(pos==-1)
			{
				Tab[TL_Forn].CodForn = Cod;
				gotoxy(31,10);
				printf("Nome Fantasia do Fornecedor: ");
				LimpaEntrada();
				strcpy(Tab[TL_Forn].NomeForn,ValidaString());
				gotoxy(31,11);
				printf("Cidade do Fornecedor: ");
				LimpaEntrada();
				strcpy(Tab[TL_Forn].Cidade,ValidaString());
				TL_Forn++;
				EscrMsg();
				printf("Fornecedor Cadastrado com Sucesso!");
				LimpaEntrada();
				getch();
			}
			else
			{
				EscrMsg();
				printf("Fornecedor Ja Cadastrado!");
				getch();
				LimpaMsg();
			}
			EscrMsg();
			printf("Realizar Novo Cadastro (S/N)?");
			LimpaEntrada();
			if(toupper(getche())=='S')
			{
				if(TL_Forn < TF)
				{
					InicioTela(C,L);
					printf("Cadastro de Fornecedores");
					gotoxy(31,9);
					printf("Codigo do Fornecedor: ");
					LimpaMsg();
					LimpaEntrada();
					ValidaCod(Cod);
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
		MenuFornecedor();
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
		LimpaMsg();
	}
	else
	if(TLF!=0)
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
		LimpaMsg();
		LimpaEntrada();
		ValidaCod(Cod);
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
					ValidaCod(CodForn);
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
					}
				}while(op!='S');
				gotoxy(C,L);
				printf("Descricao do Produto: ");
				L++;
				LimpaEntrada();
				strcpy(TabProd[TLP].Descr,ValidaString());
				gotoxy(C,L);
				printf("Quantidade em Estoque:");
				L++;
				LimpaEntrada();
				scanf("%d",&TabProd[TLP].Estoque);
				gotoxy(C,L);
				printf("Preco:");
				L++;
				LimpaEntrada();
				scanf("%f",&TabProd[TLP].Preco);
				gotoxy(C,L);
				printf("Data de Validade:");
				L++;
				LimpaEntrada();
				scanf("%d %d %d",&TabProd[TLP].DtValidade.d,&TabProd[TLP].DtValidade.m,&TabProd[TLP].DtValidade.a);
				TLP++;
				EscrMsg();
				printf("Produto Cadastrado com Sucesso!");
				LimpaEntrada();
				getch();
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
					ValidaCod(Cod);
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
	else
	{
		EscrMsg();
		printf("Nenhum Fornecedor Cadastrado");
		LimpaEntrada();
		getch();
		LimpaMsg();
	}
}

void ConsultaForn(tpFornecedores Tab[TF], int TLF)
{
	int i,C,L,Cod,pos;
	
	if(TLF==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados!");
		LimpaEntrada();
		getch();
		LimpaMsg();
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
		LimpaMsg();
		LimpaEntrada();
		ValidaCod(Cod);
		while(TLF<TF && Cod!=0)
		{
			pos=BuscaCodForn(Tab,TLF,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Fornecedor Nao Encontrado");
				LimpaEntrada();
				getch();
				LimpaMsg();
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
			printf("Cadastro de Fornecedores");
			gotoxy(31,9);
			printf("Codigo do Fornecedor: ");
			LimpaMsg();
			LimpaEntrada();
			ValidaCod(Cod);
		}
	}
}

void RelatorioForn(tpFornecedores Tab[TF], int TL)
{
	int i,l=7,c=31,pg=1;
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados!");
		getch();
		LimpaMsg();
		LimpaEntrada();
	}
	else
	{
		textcolor(9);
		gotoxy(3,13);
		printf("[E] Relatorio");
		textcolor(0);
		LimpaTela();
		gotoxy(50,6);
		printf("Relatorio de Fornecedores");
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
					gotoxy(50,6);
					printf("Relatorio de Fornecedores");
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
		LimpaMsg();
		LimpaEntrada();
	}
	else
	{
		textcolor(9);
		gotoxy(3,13);
		printf("[E] Relatorio");
		textcolor(0);
		LimpaTela();
		gotoxy(50,6);
		printf("Relatorio de Produtos");
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
				printf("Preco: %.2f",TabProd[i].Preco);
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
					gotoxy(50,6);
					printf("Relatorio de Produtos");
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

void ExcForn(tpFornecedores Tab[TF],int &TL)
{
	int Cod,pos,i,C,L;
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados!");
		LimpaEntrada();
		getch();
		LimpaMsg();
	}
	else
	{
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
		ValidaCod(Cod);
		while(Cod!=0)
		{
			pos=BuscaCodForn(Tab,TL,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Fornecedor Nao Cadastrado");
				getch();
				LimpaMsg();
				LimpaEntrada();
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
				gotoxy(C,L);
				EscrMsg();
				printf("Confirma a Exclusao (S/N))?");
				if(toupper(getche())=='S')
				{
					for(i=pos;i<TL;i++)
						Tab[i] = Tab[i+1];
					EscrMsg();
					printf("Fornecedor Excluido!");
					getch();
					LimpaMsg();
					LimpaEntrada();
					TL--;
				}
				else
				{
					EscrMsg();
					printf("Exclusao Cancelada!");
					getch();
					LimpaMsg();
					LimpaEntrada();
				}	
			}
			if(TL>0)
			{
				InicioTela(C,L);
				printf("Codigo do Fornecedor: ");
				LimpaEntrada();
				ValidaCod(Cod);
			}
			else
				Cod=0;
		}
	}
}

void AltForn(tpFornecedores Tab[TF],int TL)
{
	int Cod,pos,C,L,posCod,AuxCod;
	char op, StrAux[30];
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao Ha Fornecedores Cadastrados");
		LimpaEntrada();
		getch();
		LimpaMsg();
	}
	else
	{
		textcolor(9);
		gotoxy(3,12);
		printf("[D] Alteracao");
		gotoxy(3,13);
		textcolor(0);
		InicioTela(C,L);
		printf("Alteracao de Fornecedores");
		gotoxy(C,L);
		L+=2;
		gotoxy(C,L);
		printf("Codigo do Fornecedor: ");
		L++;
		LimpaEntrada();
		ValidaCod(Cod);
		while(Cod!=0)
		{
			pos=BuscaCodForn(Tab,TL,Cod);
			if(pos==-1)
			{
				EscrMsg();
				printf("Fornecedor Nao Encontrado");
				getch();
				LimpaMsg();
				LimpaEntrada();
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
							ValidaCod(AuxCod);
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
									LimpaMsg();
									LimpaEntrada();
								}
								else
									EscrMsg();
									printf("Operacao Cancelada");
							}
							else
							{
								EscrMsg();
								printf("Codigo Indisponivel");
								getch();
								LimpaMsg();
								LimpaEntrada;
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
									LimpaMsg();
									LimpaEntrada();
								}
								else
									EscrMsg();
									printf("Operacao Cancelada");
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
									LimpaMsg();
									LimpaEntrada();
								}
								else
									EscrMsg();
									printf("Operacao Cancelada");
							break;
					}
					EscrMsg();
					printf("Realizar Nova Alteracao (S/N)?");
					LimpaEntrada();
					if(toupper(getch())!='S')
						op='R';
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
				ValidaCod(Cod);
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

int VerMenuSec(int op)
{
	if(op!='A' && op!='B' && op!='C' && op!='D' && op!='E' && op!='R')
		return -1;
	else
		return op;
}

int VerMenuP(int op)
{
	if(op!='C' && op!='P' && op!='F' && op!=27)
		return -1;
	else
		return op;
}

int main(void)
{
	tpProdutos TabProd[TF];
	tpFornecedores TabForn[TF];
	int TL=0,CI=1,LI=1,CF=80,LF=20,CorT=15,CorF=1,TLForn=0,TLProd=0,C,L,VerMenu;
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
									break;
								case 'C':
									break;
								case 'D':
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
						if(VerMenuSec(op)==-1)
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
									ExcForn(TabForn,TLForn);
									break;
								case 'D':
									AltForn(TabForn,TLForn);
									break;
								case 'E':
									RelatorioForn(TabForn,TLForn);
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
									getch();
									break;
								case 'B':
									break;
								case 'C':
									break;
								case 'D':
									break;
								case 'E':
									break;
							}
					}while(op!='R');
					break;
				case 'D':
					LimpaTela();
					getch();
					break;
			} 
	}while(op!=27);
	
	gotoxy(1,27);
	return 0;
}
