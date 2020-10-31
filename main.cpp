#include <iomanip>
#include <iostream>   
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <clocale>
#include <string.h>
#include "Componente_Valor.h"
#include "Componente_Adj.h"
#include "Componente_Aresta.h"
#include "Componente_Vertice.cpp"

//Constantes definidas
const int TEMP = 0;
const int PERM = 1;
const int infinito = 9999;
const int MAX = 20;

//Variavel Global
int numColunas;

using namespace std;

//Estrutura do grafo, com suas respectivas informações
typedef struct TipoGrafo{
	  TipoAdj mAdj[MAX+1][MAX+1];
	  TipoAdj matrizAdjMin[MAX+1][MAX+1];
	  char matrizGrafo[4][50];
	  int numVertices;
} TipoGrafo;

//Declaração do grafo
TipoGrafo grafo;

int main();

//Procedure responsavel por adicionar as arestas no grafo previamente criado
void DesenharGrafo(TipoGrafo *Grafo, char lOrigem, char lDestino){
	
	//Se os parâmetros de origem e destino forem iguais às condicionais abaixo, é adicionada a aresta correspondente no grafo
	if(((lDestino == 'A') & (lOrigem == 'B')) || ((lDestino == 'B') & (lOrigem == 'A'))) {Grafo->matrizGrafo[1][0] = '|'; Grafo->matrizGrafo[2][0] = '|';}
	if(((lDestino == 'A') & (lOrigem == 'C')) || ((lDestino == 'C') & (lOrigem == 'A'))) {Grafo->matrizGrafo[0][1] = '-'; Grafo->matrizGrafo[0][2] = '-';}  
	if(((lDestino == 'A') & (lOrigem == 'D')) || ((lDestino == 'D') & (lOrigem == 'A'))) {Grafo->matrizGrafo[1][1] = '\\'; Grafo->matrizGrafo[2][2] = '\\';} 
	if(((lDestino == 'B') & (lOrigem == 'C')) || ((lDestino == 'C') & (lOrigem == 'B'))) {Grafo->matrizGrafo[2][1] = '/'; Grafo->matrizGrafo[1][2] = '/';} 
	if(((lDestino == 'B') & (lOrigem == 'D')) || ((lDestino == 'D') & (lOrigem == 'B'))) {Grafo->matrizGrafo[3][1] = '-'; Grafo->matrizGrafo[3][2] = '-';} 
	if(((lDestino == 'C') & (lOrigem == 'D')) || ((lDestino == 'D') & (lOrigem == 'C'))) {Grafo->matrizGrafo[1][3] = '|'; Grafo->matrizGrafo[2][3] = '|';} 
	if(((lDestino == 'C') & (lOrigem == 'E')) || ((lDestino == 'E') & (lOrigem == 'C'))) {Grafo->matrizGrafo[0][4] = '-'; Grafo->matrizGrafo[0][5] = '-';} 
	if(((lDestino == 'C') & (lOrigem == 'F')) || ((lDestino == 'F') & (lOrigem == 'C'))) {Grafo->matrizGrafo[1][4] = '\\'; Grafo->matrizGrafo[2][5] = '\\';} 
	if(((lDestino == 'D') & (lOrigem == 'E')) || ((lDestino == 'E') & (lOrigem == 'D'))) {Grafo->matrizGrafo[2][4] = '/'; Grafo->matrizGrafo[1][5] = '/';} 
	if(((lDestino == 'D') & (lOrigem == 'F')) || ((lDestino == 'F') & (lOrigem == 'D'))) {Grafo->matrizGrafo[3][4] = '-'; Grafo->matrizGrafo[3][5] = '-';} 
	if(((lDestino == 'E') & (lOrigem == 'F')) || ((lDestino == 'F') & (lOrigem == 'E'))) {Grafo->matrizGrafo[1][6] = '|'; Grafo->matrizGrafo[2][6] = '|';} 
	if(((lDestino == 'E') & (lOrigem == 'G')) || ((lDestino == 'G') & (lOrigem == 'E'))) {Grafo->matrizGrafo[0][7] = '-'; Grafo->matrizGrafo[0][8] = '-';} 
	if(((lDestino == 'E') & (lOrigem == 'H')) || ((lDestino == 'H') & (lOrigem == 'E'))) {Grafo->matrizGrafo[1][7] = '\\'; Grafo->matrizGrafo[2][8] = '\\';} 
	if(((lDestino == 'F') & (lOrigem == 'G')) || ((lDestino == 'G') & (lOrigem == 'F'))) {Grafo->matrizGrafo[2][7] = '/'; Grafo->matrizGrafo[1][8] = '/';} 
	if(((lDestino == 'F') & (lOrigem == 'H')) || ((lDestino == 'H') & (lOrigem == 'F'))) {Grafo->matrizGrafo[3][7] = '-'; Grafo->matrizGrafo[3][8] = '-';} 
	if(((lDestino == 'G') & (lOrigem == 'H')) || ((lDestino == 'H') & (lOrigem == 'G'))) {Grafo->matrizGrafo[1][9] = '|'; Grafo->matrizGrafo[2][9] = '|';} 
	if(((lDestino == 'G') & (lOrigem == 'I')) || ((lDestino == 'I') & (lOrigem == 'G'))) {Grafo->matrizGrafo[0][10] = '-'; Grafo->matrizGrafo[0][11] = '-';} 
	if(((lDestino == 'G') & (lOrigem == 'J')) || ((lDestino == 'J') & (lOrigem == 'G'))) {Grafo->matrizGrafo[1][10] = '\\'; Grafo->matrizGrafo[2][11] = '\\';} 
	if(((lDestino == 'H') & (lOrigem == 'I')) || ((lDestino == 'I') & (lOrigem == 'H'))) {Grafo->matrizGrafo[2][10] = '/'; Grafo->matrizGrafo[1][11] = '/';}
	if(((lDestino == 'H') & (lOrigem == 'J')) || ((lDestino == 'J') & (lOrigem == 'H'))) {Grafo->matrizGrafo[3][10] = '-'; Grafo->matrizGrafo[3][11] = '-';}  
	if(((lDestino == 'I') & (lOrigem == 'J')) || ((lDestino == 'J') & (lOrigem == 'I'))) {Grafo->matrizGrafo[1][12] = '|'; Grafo->matrizGrafo[2][12] = '|';} 
	if(((lDestino == 'I') & (lOrigem == 'K')) || ((lDestino == 'K') & (lOrigem == 'I'))) {Grafo->matrizGrafo[0][13] = '-'; Grafo->matrizGrafo[0][14] = '-';}
	if(((lDestino == 'I') & (lOrigem == 'L')) || ((lDestino == 'L') & (lOrigem == 'I'))) {Grafo->matrizGrafo[1][13] = '\\'; Grafo->matrizGrafo[2][14] = '\\';} 
	if(((lDestino == 'J') & (lOrigem == 'K')) || ((lDestino == 'K') & (lOrigem == 'J'))) {Grafo->matrizGrafo[2][13] = '/'; Grafo->matrizGrafo[1][14] = '/';}  
	if(((lDestino == 'J') & (lOrigem == 'L')) || ((lDestino == 'L') & (lOrigem == 'J'))) {Grafo->matrizGrafo[3][13] = '-'; Grafo->matrizGrafo[3][14] = '-';} 
	if(((lDestino == 'K') & (lOrigem == 'L')) || ((lDestino == 'L') & (lOrigem == 'K'))) {Grafo->matrizGrafo[1][15] = '|'; Grafo->matrizGrafo[2][15] = '|';} 
	
}

//Procedure responsável por mostrar o grafo, pode ser chamada em varias partes do programa
void MostraGrafo(TipoGrafo *Grafo){  
	int i, j, cont = 0;
	char letra;
	
	//Verifica a existência do grafo
	if(Grafo->numVertices == 0){
		cout << "\n \n Para prosseguir, é preciso criar o Grafo \n \n"<<endl;
		system("PAUSE");
		main();
	}
	//Preenche o grafo com um caracter qualquer
	for(j = 0; j < Grafo->numVertices * 3 / 2; j = j + 3){
		Grafo->matrizGrafo[0][j] = 'x';
	}
	for(j = 0; j < (Grafo->numVertices * 3 / 2) - 1; j = j + 3){
		Grafo->matrizGrafo[3][j] = 'x';
	}
	
	//Substitiu os caracteres padrão pelas letras, indicando casa vértice
	if(Grafo->matrizGrafo[0][0] == 'x') Grafo->matrizGrafo[0][0] = 'A' ;
	if(Grafo->matrizGrafo[3][0] == 'x') Grafo->matrizGrafo[3][0] = 'B' ;
	if(Grafo->matrizGrafo[0][3] == 'x') Grafo->matrizGrafo[0][3] = 'C' ;
	if(Grafo->matrizGrafo[3][3] == 'x') Grafo->matrizGrafo[3][3] = 'D' ;
	if(Grafo->matrizGrafo[0][6] == 'x') Grafo->matrizGrafo[0][6] = 'E' ;
	if(Grafo->matrizGrafo[3][6] == 'x') Grafo->matrizGrafo[3][6] = 'F' ;
	if(Grafo->matrizGrafo[0][9] == 'x') Grafo->matrizGrafo[0][9] = 'G' ;
	if(Grafo->matrizGrafo[3][9] == 'x') Grafo->matrizGrafo[3][9] = 'H' ;	
	if(Grafo->matrizGrafo[0][12] == 'x') Grafo->matrizGrafo[0][12] = 'I' ;
	if(Grafo->matrizGrafo[3][12] == 'x') Grafo->matrizGrafo[3][12] = 'J' ;
	if(Grafo->matrizGrafo[0][15] == 'x') Grafo->matrizGrafo[0][15] = 'K' ;
	if(Grafo->matrizGrafo[3][15] == 'x') Grafo->matrizGrafo[3][15] = 'L' ;
	
	cout << endl;
	
	//Imprime a matriz
	for(i=0;i<4;i++){
		cout << "     ";
		for(j=0;j<Grafo->numVertices*3/3;j++){
	        cout << Grafo->matrizGrafo[i][j];
	    }
		cout << endl;
	}
	cout << endl;
}

//Função responsavel por calcular a distância Manhattan
int CalcularManhattan(int *origem, int *destino, TipoGrafo *Grafo){	
	int mManhattan[3][Grafo->numVertices];
	int i, j, x1, y1, x2, y2, dManhattan;
	
	j=1;
	for(i = 1; i <= Grafo->numVertices; i++){
		mManhattan[1][i] = j;
		j = j + 2;
	}
	j=2;
	for(i = 1; i <= Grafo->numVertices; i++){
		mManhattan[2][i]=j;
		j = j + 2;
	}
	for(i = 1; i <= 2; i++){
		for(j = 1; j <= Grafo->numVertices; j++){
			if(mManhattan[i][j] == *origem){
				x1 = i;
				y1 = j;
			}
			if(mManhattan[i][j] == *destino){
				x2 = i;
				y2 = j;
			}
		}
	}
	//A função fabs retorna o valor de float/int absoluto, o valor sempre será positivo
	dManhattan = (fabs(x1 - x2) + fabs(y1 - y2));
	return(dManhattan);
}

/*Função responsavel por perguntar ao usuário os vertices de origem
*e destino para a distancia Manhattan poder ser calculada*/
void Manhattan(TipoGrafo *Grafo){
	
	int i, j, cont;
    int pi, pf, distanciaManhattan;
	char letraInicial, letraFinal;
	
	//Primeiro é necessário verificar se o grafo existe
	if(Grafo->numVertices==0){
		cout << "\n \n Para prosseguir, é preciso criar o Grafo \n \n" <<endl;
		system("PAUSE");
		main();
	}
	MostraGrafo(&grafo);
	
	//O usuário deve fornecer os pontos de origem e destino
    cout << "\n Digite o ponto inicial (origem): ";
    cin >> letraInicial;
    pi = ((int)(letraInicial-64)); //Atribui valor numérico ao ponto de origem
    
    cout << " Digite o ponto final (destino): ";
	cin >> letraFinal;
	pf = ((int)(letraFinal-64)); //Atribui valor numérico ao ponto de destino
	distanciaManhattan = CalcularManhattan(&pi, &pf, &grafo);
	
	//Se todas as condições forem respeitadas, a distância manhattan pode ser atribuida
	if(pi>=1 && pi<=Grafo->numVertices && pf>=1 && pf<=Grafo->numVertices){
		cout << "\nDistância Manhattan: " << distanciaManhattan;
	}
	else{
        cout << "\nO caminho não pôde ser construído" << endl;
    }
	cout << endl;
}

//Exibe a matriz minimizada
void MostraMatrizAdj(TipoGrafo *Grafo){
	
	//Verifica a existência do grafo
	if(Grafo->numVertices == 0){
		cout << "\n \n Para prosseguir, é preciso criar o Grafo \n \n"<<endl;
		system("PAUSE");
		main();
	}
	int i, j;
	char letra;
	cout << "      ";
	for(i = 1; i <= Grafo->numVertices; i++){
		letra = ((char) (i+64));
	    cout << letra << setw(6);
	}
	cout << endl;
	for(i = 1; i <= Grafo->numVertices; i++) {
	  	letra = ((char) (i+64));
	  	if(i==1){
	  		cout << setw(-6) << letra << setw(6);
		}
		else{
	   		cout << setw(-6) << letra << setw(11);
		}	
		for(j = 1; j <= Grafo->numVertices; j++){
	     	if(i <= j){
	     		cout << setprecision(2) << Grafo->matrizAdjMin[i][j] << setw(6);
	     	}
	     	else{
	     		cout << "      ";
			}
	    }
	    cout << endl;
	}
}

//Para criar a matriz de adjacências minimizada, é necessário criar a matriz completa
void MAdjacencia(TipoAresta *origem, TipoAresta *destino, TipoAdj *Peso, TipoGrafo *Grafo){

	int iDiagonal, jDiagonal=4;
	int iDiagonal2, jDiagonal2=3;
	int mDiagonal, nDiagonal=1;
	int mDiagonal2, nDiagonal2=2;
	Grafo->mAdj[*origem][*destino] = *Peso; //Atribui os pesos
	Grafo->mAdj[*destino][*origem] = *Peso;
	for (iDiagonal=1; iDiagonal <= Grafo->numVertices; iDiagonal = iDiagonal + 2) {
		if(Grafo->mAdj[iDiagonal][jDiagonal] == 1){
			Grafo->mAdj[iDiagonal][jDiagonal] = peso2;
		}
		jDiagonal = jDiagonal + 2;
	}
	for (iDiagonal2 = 2; iDiagonal2 <= Grafo->numVertices; iDiagonal2 = iDiagonal2 + 2) {
		if(Grafo->mAdj[iDiagonal2][jDiagonal2] == 1){
			Grafo->mAdj[iDiagonal2][jDiagonal2] = peso2;
		}
		jDiagonal2 = jDiagonal2 + 2;
	}
	for (mDiagonal = 4; mDiagonal <= Grafo->numVertices; mDiagonal = mDiagonal+2) {
		if(Grafo->mAdj[mDiagonal][nDiagonal] == 1){
			Grafo->mAdj[mDiagonal][nDiagonal] = peso2;
		}
		nDiagonal = nDiagonal + 2;
	}
	for (mDiagonal2 = 3; mDiagonal2 <= Grafo->numVertices; mDiagonal2 = mDiagonal2 + 2) {
		if(Grafo->mAdj[mDiagonal2][nDiagonal2] == 1){
			Grafo->mAdj[mDiagonal2][nDiagonal2] = peso2;
		} 
		nDiagonal2 = nDiagonal2 + 2;
	}
}


//Função responsavel por montar a matriz de adjacências minimizada
void MAdjacenciaMin(TipoAresta *origem, TipoAresta *destino, TipoAdj *Peso, TipoGrafo *Grafo){

	int iDiagonal, jDiagonal=4;
	int iDiagonal2, jDiagonal2=3;
	int mDiagonal, nDiagonal=1;
	int mDiagonal2, nDiagonal2=2;
	Grafo->matrizAdjMin[*origem][*destino] = *Peso;
	for (iDiagonal = 1; iDiagonal <= Grafo->numVertices; iDiagonal = iDiagonal + 2) {
		if(Grafo->matrizAdjMin[iDiagonal][jDiagonal] == 1){
			Grafo->matrizAdjMin[iDiagonal][jDiagonal] = peso2;
		}
		jDiagonal = jDiagonal + 2;
	}
	for (iDiagonal2 = 2; iDiagonal2 <= Grafo->numVertices; iDiagonal2 = iDiagonal2 + 2) {
		if(Grafo->matrizAdjMin[iDiagonal2][jDiagonal2] == 1){
			Grafo->matrizAdjMin[iDiagonal2][jDiagonal2] = peso2;
		}
		jDiagonal2 = jDiagonal2 + 2;
	}
	for (mDiagonal = 4; mDiagonal <= Grafo->numVertices; mDiagonal = mDiagonal + 2) {
		if(Grafo->matrizAdjMin[mDiagonal][nDiagonal] == 1){
			Grafo->matrizAdjMin[mDiagonal][nDiagonal] = peso2;
		}
		nDiagonal = nDiagonal + 2;
	}
	for (mDiagonal2 = 3; mDiagonal2 <= Grafo->numVertices; mDiagonal2 = mDiagonal2 + 2) {
		if(Grafo->matrizAdjMin[mDiagonal2][nDiagonal2] == 1){
			Grafo->matrizAdjMin[mDiagonal2][nDiagonal2]= peso2;
		}
		nDiagonal2 = nDiagonal2 + 2;
	}
}

//Função responsável por aplicar o algoritmo de Dijkstra ao programa
int Dijkstra(int origem, int destino, int caminho[MAX], float *mdistancia, TipoGrafo *Grafo){
	
    struct Vertices estado[MAX];
    int i, cont=0, atual, u, v;
    float min, novaDistancia;
    *mdistancia=0;
	for(i=1;i<=Grafo->numVertices;i++){
        estado[i].set_anterior(0);
        estado[i].set_distancia(infinito);
        estado[i].set_status(TEMP);
    }
	estado[origem].set_anterior(0);
    estado[origem].set_distancia(0);
    estado[origem].set_status(PERM);
    atual=origem;
	while(atual!=destino){
        for(i=1;i<=Grafo->numVertices;i++){
            if(Grafo->mAdj[atual][i] > 0 && estado[i].get_status() == TEMP){
                novaDistancia=estado[atual].get_distancia() + Grafo->mAdj[atual][i];
                if(novaDistancia < estado[i].get_distancia()){
                   	estado[i].set_anterior(atual);
                    estado[i].set_distancia(novaDistancia);
                }
            }
        }
        min=infinito;
        atual=0;
		for(i=1;i<=Grafo->numVertices;i++){
         	if(estado[i].get_status() == TEMP && estado[i].get_distancia() < min){
          	    min = estado[i].get_distancia();
           	    atual=i;
        	}
       	}
	    if(atual==0){
			return 0;
	    }
		estado[atual].set_status(PERM);
    }
	while( atual!=0 ){
        cont++;
        caminho[cont]=atual;
        atual=estado[atual].get_anterior();
    }
	for(i=cont;i>1;i--){
        u=caminho[i];
        v=caminho[i-1];
        *mdistancia+= Grafo->mAdj[u][v];
    }
	return (cont);
}

//Retorna o menor caminho no grafo montado
void MenorCaminho(TipoGrafo *Grafo){
	
	
	if(Grafo->numVertices==0) {
		cout << "\n \n Para prosseguir, é preciso criar o Grafo \n \n";
		system("PAUSE");
		main();
	}
	int i, j, cont;
    int verticeInicial, verticeFinal;
    int caminho[MAX];
    float menorDistancia;
    char letraInicial, letraFinal,letraCaminho;
	MostraGrafo(&grafo);
    cout << "\nDigite o Vértice Inicial: ";
    cin >> letraInicial;
    verticeInicial = ((int)(letraInicial-64));
    cout << "Digite o Vértice Final: ";
    cin >> letraFinal;
    verticeFinal = ((int)(letraFinal-64));
	cont = Dijkstra(verticeInicial, verticeFinal, caminho, &menorDistancia, &grafo);
	if(menorDistancia!=0){
       	cout << "\nDistância Percorrida: " << menorDistancia << endl;
        cout << "\nMenor Caminho: ";
		for(i=cont;i>1;i--){
			letraCaminho = ((char)(caminho[i]+64));
           	cout << letraCaminho << "->";
       	}
       	letraCaminho = ((char)(caminho[i]+64));
		cout << letraCaminho<<endl;
    }
    else{
     	cout << "\nNão existe um caminho válido."<<endl;
    }
}

//Função responsável por calcular o numero máximo de arestas que o grafo pode possuir
int arestaMaxima(TipoValor nVertices){
	
	int arestaMax, i, l=3, j=6;
	if(nVertices<=4){
		arestaMax=nVertices*(nVertices-1)/2;
	}
	else{
		for(i=5;i<=20;i++){
			if(i%2==0){
				j=j+5;
				if(i==nVertices){
					arestaMax=j;
				}
			}
			else{
				l=l+5;
				if(i==nVertices){
					arestaMax=l;
				}
			}
		}
	}
	return(arestaMax);
}

//Função 
void CriaGrafo(){
	
	int i, cont=0, aux=0, arestaMax;
	char letra, letraMax, letraOrigem, letraMais, letraMenos,letraDestino;
	system("cls");
	grafo.numVertices=0;
	memset(grafo.matrizAdjMin, 0, sizeof(grafo.matrizAdjMin));
	memset(grafo.mAdj, 0, sizeof(grafo.mAdj));
	memset(grafo.matrizGrafo, ' ', sizeof(grafo.matrizGrafo));
	cout << "Digite a quantidade de vértices do grafo:"<<endl;
	cout << endl;
	do{
		cout << "Digite a quantidade de Colunas (entre 2 e 6): ";
        cin >> numColunas;
	}while(numColunas<2 || numColunas>6);
	nVertices = numColunas * 3;
	grafo.numVertices = nVertices;
	MostraGrafo(&grafo);
	cout << endl;
	system("PAUSE");
	system("cls");
	cout <<"Insira as arestas no grafo abaixo."<<endl; 
	MostraGrafo(&grafo);
	cout <<endl;
	arestaMax=arestaMaxima(nVertices);
	if(nVertices==2){
		cout << "Informe a quantidade de arestas (digite " << arestaMax << "): ";
		cin >> nArestas;
	}
	else{
		do{
			cout << "Digite a quantidade de arestas (entre 1 e " << arestaMax << "): ";
			cin >> nArestas;
		
		}while(nArestas>arestaMax || nArestas<1);
	}
 	cout << endl;
	do{
		letra = (char) 64 + nVertices;
    	do{
       		cout << "Digite a origem da aresta(APENAS LETRA MAIÚSCULA): ";
       		cin >> letraOrigem;
       		origem = (int)letraOrigem - 64;
    	}while(origem<1 || origem>nVertices);

		if(origem % 2 == 0){
			if(origem==2){
				if(nVertices==3){
					letraMenos = (char) ((origem-1) +64);
					letraMais = (char) ((origem+1) +64);
					do{
	       				cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
	       				cin >> letraDestino;
	       				destino = (int)letraDestino -64;
					}while(destino<origem-1 || destino>origem+1 || destino==origem);
				}
				else if(nVertices==2){
					do{
	        			cout << "Digite o destino da aresta (Digite A): ";
	        			cin  >> letraDestino;
	        			destino = (int)letraDestino -64;
					}while(destino!=origem-1 || destino==origem);
				}
				else{
					letraMenos = (char) ((origem-1) +64);
					letraMais = (char) ((origem+2) +64);
					do{
	        			cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
	        			cin  >> letraDestino;
	        			destino = (int) letraDestino - 64;
					}while(destino<origem-1 || destino>origem+2 || destino==origem);
				}
			}
			else if(origem==nVertices){
				letraMenos = (char) ((origem-1) +64);
				letraMais = (char) ((origem-3) +64);
				do{
        			cout << "Informe o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        			cin >> letraDestino;
        			destino = (int) letraDestino - 64;
				}while(destino<origem-3 || destino>origem-1 || destino==origem);
			}
			else if(origem+1==nVertices){
				letraMenos = (char) ((origem-3) +64);
				letraMais = (char) ((origem+1) +64);
				do{
        			cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        			cin >> letraDestino;
        			destino = (int) letraDestino - 64;
				}while(destino<origem-3 || destino>origem+1 || destino==origem);
			}
			else{
				letraMenos = (char) ((origem-3) +64);
				letraMais = (char) ((origem+2) +64);
        		do{
        			cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        			cin >> letraDestino;
        			destino = (int) letraDestino - 64;
				}while(destino<origem-3 || destino>origem+2 || destino==origem);
			}
		}
		else{
			if(origem==1){
				if(nVertices==3){
					letraMenos = (char) ((origem+1) +64);
					letraMais = (char) ((origem+2) +64);
					do{
        				cout <<"Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        				cin >> letraDestino;
        				destino = (int) letraDestino - 64;
					}while(destino<origem+1 || destino>origem+2 || destino==origem);
				}
				else if(nVertices==2){
					do{
	        			cout<< "Digite o destino da aresta (Digite B): ";
	        			cin >> letraDestino;
	        			destino = (int) letraDestino - 64;
					}while(destino!=origem+1 || destino==origem);
				}
				else{
					letraMenos = (char) ((origem+1) +64);
					letraMais = (char) ((origem+3) +64);
					do{
	        			cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
	        			cin >> letraDestino;
	        			destino = (int) letraDestino - 64;
					}while(destino<origem+1 || destino>origem+3 || destino==origem);
				}
			}
			else if(origem==nVertices){
				letraMenos = (char) ((origem-2) +64);
				letraMais = (char) ((origem-1) +64);
				do{
        			cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        			cin >> letraDestino;
        			destino = (int) letraDestino - 64;
				}while(destino<origem-2 || destino>origem-1 || destino==origem);
			}
			else if(origem==nVertices-1){
				letraMenos = (char) ((origem-2) +64);
				letraMais = (char) ((origem+1) +64);
				do{
        			cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        			cin >> letraDestino;
        			destino = (int) letraDestino - 64;
				}while(destino<origem-2 || destino>origem+1 || destino==origem);
			}
			else if(origem==nVertices-2){
				letraMenos = (char) ((origem-2) +64);
				letraMais = (char) ((origem+2) +64);
				do{
        			cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        			cin >> letraDestino;
        			destino = (int) letraDestino - 64;
				}while(destino<origem-2 || destino>origem+2 || destino==origem);
			}
			else{
				letraMenos = (char) ((origem-2) +64);
				letraMais = (char) ((origem+3) +64);
				do{
					cout << "Digite o destino da aresta(APENAS LETRA MAIÚSCULA): ";
        			cin >> letraDestino;
        			destino = (int) letraDestino - 64;
        		}while(destino<origem-2 || destino>origem+3 || destino==origem);
			}
        }
        cont++;
        if(origem > destino){
        	aux = origem;
        	origem = destino;
        	destino = aux;
		}
        MAdjacencia(&origem, &destino, &peso1, &grafo);
        MAdjacenciaMin(&origem, &destino, &peso1, &grafo);
        DesenharGrafo(&grafo, letraOrigem, letraDestino);
        system("cls");
        cout << "Preencha as arestas desejadas no grafo"<<endl;
        MostraGrafo(&grafo);
       	cout << endl;
	}while(cont<nArestas);
}

//Procedure responsável por exibir o menu de opções
void menu(){
	printf("**IA - Grafos (BUSCA POR ALGORTIMO DE DIJKISTRA)**");
	printf("\n1 - Criar Grafo-------------------------");
	printf("\n2 - Exibir Grafo------------------------");
	printf("\n3 - Menor Caminho (Djkistra)------------");
	printf("\n4 - Distância Manhattan----------");
	printf("\n5 - Matriz de Adjacências minimizada----");
	printf("\n6 - Heurística--------------------------");
	printf("\n7 - Cancelar----------------------------");
}


int main (){
	system("cls"); 
	setlocale(LC_ALL, "Portuguese");
	int op;
	
	
	
	//Loop para o usuário escolher a operação desejada
	do{
		menu();
		cout << " \n\nDigite a operação:  ";
		cin >> op;	

		switch(op){
		  	case 1: {
			  	CriaGrafo(); //Cria o grafo
			  	system("PAUSE");
			  	system("cls");
		  		break;
			}
			case 2: {
				system("cls");
				cout << "Grafo Gerado" << endl;
				MostraGrafo(&grafo); //Exibe o grafo gerado anteriormente
				system("PAUSE");
				system("cls");
		  		break;
			}
			case 3: {
				system("cls");
				cout << "Menor Caminho Percorrido" << endl;
				MenorCaminho(&grafo); //Calcula e exibe o menor caminho entre dois vertices informados
				system("PAUSE");
				system("cls");
				break;	
			}
			case 4: {
				system("cls");
				cout << "Distância Manhattan" << endl;
				Manhattan(&grafo); //Calcula e exibe a distância Manhattan entre dois vertices informados
				system("PAUSE");
				system("cls");
		  		break;
			}
			case 5: {
				system("cls");
				cout << "Matriz de Adjacências\n" << endl;
				MostraMatrizAdj(&grafo); //Exibe a matriz de adjacências minimizada
				system("PAUSE");
				system("cls");
				break;
			}
			case 6: {
				system("cls");
				cout << "***ALGORITMO DE DJKISTRA***" <<endl; 
				system("PAUSE");
				system("cls");
				break;
			}
			case 7: {
				exit(0);
			}
			default:{
				cout << "Digite uma opção válida!" <<endl;
				system("PAUSE");
				system("cls");
				break;
			} 	
		}
	}while(op < 1 || op >7);
	main();
   	return 0;
}
