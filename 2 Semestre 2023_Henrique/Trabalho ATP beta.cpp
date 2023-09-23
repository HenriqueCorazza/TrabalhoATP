#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>

#define TF 20

struct tpData
{
	int d,m,a;
};

struct tpProdutos
{
	int CodProd,Estoque, CodForn;
	float Preco;
	tpData DtValidade;
	char Descr[TF];
};

struct tpFornecedores
{
	int CodForn;
	char NomeForn[TF],Cidade[TF];	
};

struct tpClientes
{
	int QtdeCompras;
	float ValorTotComp;
	char CpfCli[TF], NomeCli[TF];
};

struct tpVendas
{
	int CodVenda;
	char CpfCli[TF];
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
	
	textcolor(1);
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
}

void EscrEntrada(void)
{
	LimpaEntrada();
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

void InicioTela(void)
{
	LimpaTela();
	gotoxy(31,7);
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
	LimpaMenu();
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
	printf("[ESC] Voltar");
	gotoxy(31,7);
	printf("Selecione uma operacao:");
	gotoxy(39,19);
}

void MenuCliente(void)
{
	LimpaMenu();
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
	printf("[ESC] Voltar");
	gotoxy(31,7);
	printf("Selecione uma operacao:");
	gotoxy(39,19);
}

void MenuProduto(void)
{
	LimpaMenu();
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
	printf("Selecione uma operacao:");
	gotoxy(39,19);
}


void MenuPrincipal(void)
{
	LimpaMenu();
	LimpaTela();
	LimpaMsg();
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
	printf("Selecione uma operacao:");
	EscrEntrada();
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
	
	EscrEntrada();
	return toupper(getch());
}

int BuscaCodForn(tpFornecedores Tab[TF], int TLP, int Cod)
{
	int pos=0;
	
	while(pos<TLP && Cod != Tab[pos].CodForn)
		pos++;
	if(pos<TLP)
		return pos;
	else
		return -1;
}

void CadForn(tpFornecedores Tab[TF],int &TL_Forn)
{
	int Cod,pos;
	char op;

	LimpaMsg();
	
	InicioTela();
	printf("# # # Cadastro de Fornecedores # # #");
	gotoxy(31,9);
	printf("Codigo do Fornecedor: ");
	EscrEntrada();
	scanf("%d",&Cod);
	
	while(TL_Forn<TF && Cod!=0)
	{
		pos=BuscaCodForn(Tab,TL_Forn,Cod);
		
		if(pos==-1)
		{
			Tab[TL_Forn].CodForn = Cod;
			gotoxy(31,10);
			printf("Nome ou Fantasia do Fornecedor: ");
			EscrEntrada();
			fflush(stdin);
			gets(Tab[TL_Forn].NomeForn);
			gotoxy(31,11);
			fflush(stdin);
			printf("Cidade do Fornecedor: ");
			EscrEntrada();
			gets(Tab[TL_Forn].Cidade);
			TL_Forn++;
			EscrMsg();
			printf("Fornecedor Cadastrado com Sucesso!");
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
		EscrEntrada();
		if(toupper(getche())=='S')
		{
			if(TL_Forn < TF)
			{
				InicioTela();
				printf("# # # Cadastro de Fornecedores # # #");
				gotoxy(31,9);
				printf("Codigo do Fornecedor: ");
				LimpaMsg();
				EscrEntrada();
				scanf("%d",&Cod);
			}
		}
		else
		{
			EscrMsg();
			printf("Menu de Cadastro Encerrado!");
			EscrEntrada();
			Cod=0;
		}
	}
	LimpaTela();
	MenuFornecedor();
	EscrEntrada();
}
	
void ConsultaForn(tpFornecedores Tab[TF], int TL)
{
	int Cod, pos;
	LimpaMsg();
	if (TL==0)
	{
		EscrMsg();
		printf("Nao ha fornecedores cadastrados!");
		getch();
		LimpaMsg();
		EscrEntrada();
	}
	else
	{
		InicioTela();
		printf("# # # Consulta de Fornecedores # # #");
		gotoxy(31,9);
		printf("Codigo do fornecedor: ");
		EscrEntrada();
		scanf("%d",&Cod);
		
		while(Cod!=0)
		{
			pos=BuscaCodForn(Tab,TL,Cod);
			
			if(pos==-1)
			{
				EscrMsg();
				printf("Fornecedor nao encontrado!!!");
				getch();
				LimpaMsg();
			}
			else
			{
				LimpaTela();
				InicioTela();
				printf("# # # Fornecedor Encontrado! # # #");
				gotoxy(31,9);
				printf("Codigo do Fornecedor: %d",Tab[pos].CodForn);
				gotoxy(31,10);
				printf("Nome do Fornecedor: %s",Tab[pos].NomeForn);
				gotoxy(31,11);
				printf("Cidade de Localizacao: %s",Tab[pos].Cidade);
				
			}
			EscrMsg();
			printf("Realizar Nova Consulta (S/N)?");
			EscrEntrada();
		
			if(toupper(getche())=='S')
			{
				if(TL < TF)
				{
					InicioTela();
					printf("# # # Cadastro de Fornecedores # # #");
					gotoxy(31,9);
					printf("Codigo do Fornecedor: ");
					LimpaMsg();
					EscrEntrada();
					scanf("%d",&Cod);
				}
			}
			else
			{
				EscrMsg();
				printf("Menu de Consulta Encerrado!");
				EscrEntrada();
				Cod=0;
			}
		}
	LimpaTela();
	MenuFornecedor();
	EscrEntrada();
	}
}


void RelatorioForn(tpFornecedores Tab[TF], int TL)
{
	int i,l=7,c=31,pg=1;
	LimpaMsg();
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao Existem Fornecedores Cadastrados!");
		getch();
		LimpaMsg();
		EscrEntrada();
	}
	else
	{
		LimpaTela();
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
					l=7;
				}				
		}
		getch();
		EscrEntrada();
		MenuFornecedor();
	}
}

void ExclusaoForn(tpFornecedores Tab[TF],int &TL)
{
	int Cod, pos,i;
	LimpaMsg();
	
	if(TL==0)
	{
		EscrMsg();
		printf("Nao ha fornecedores cadastrados!");
		getch();
		LimpaMsg();
		EscrEntrada();
	}
	else
		do
		{
			LimpaTela();
			InicioTela();
			printf(" # # # Exclusao de Fornecedores # # #");
			gotoxy(31,9);
			printf("Digite o Codigo que deseja excluir: ");
			EscrEntrada();
			scanf("%d",&Cod);
			pos = BuscaCodForn(Tab,TL,Cod);
			if(Cod != 0 && pos!=-1)
			{
				for(i=pos; i<TL; i++){
				Tab[i] = Tab[i+1];
				}
				printf("Fornecedor e suas informacoes excluidas!");
				TL--;
			}
			if (Cod != 0 && pos==-1)
			{
				EscrMsg();
				printf("Fornecedor não encontrado!");
				getch();
				EscrEntrada();				
			}
				
		}while(Cod!=0);
		
		EscrEntrada();
}

int main(void)
{
	tpFornecedores TabForn[TF];
	int TL=0,CI=1,LI=1,CF=80,LF=20,CorT=15,CorF=1,TLForn=0,C,L;
	char op;   
	
	do
	{
		op = Menu();
		switch(op)
		{
			case 'P':
				MenuProduto();
				do
				{
					op = toupper(getch());
					switch(op)
					{
						case 'A':
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
			case 'F':
				MenuFornecedor();
				do
				{
					op = toupper(getch());
					switch(op)
					{
						case 'A':
							CadForn(TabForn,TLForn);
							break;
						case 'B':
							ConsultaForn(TabForn,TLForn);
							break;
						case 'C':
							ExclusaoForn(TabForn,TLForn);
							break;
						case 'D':
							break;
						case 'E':
							RelatorioForn(TabForn,TLForn);
							break;
					}
				}while(op!='R');
				
				break;
			case 'C':
				MenuCliente(); // CRIAR FUNÇÃO DE CADASTRO DE PRODUTOS
				op = toupper(getch());
				getch();
				do
				{
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
	
	return 0;
}
