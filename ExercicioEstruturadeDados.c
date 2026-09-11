//Feitor por:Pedro Henrique Ribeiro Mizukawa
#include <stdio.h>
#include <stdbool.h>
#define MAX 10
typedef struct{
int celular;
int creditoInternet;
int prox;
}noPlano; 
noPlano clientes[MAX]; 
int prim=-1; 
int dispo=0; 
int quant=0;

void inicializaClientes(){
    int i;
    for(i=0; i<MAX; i++){
        clientes[i].celular=0;
        clientes[i].creditoInternet=0;
        clientes[i].prox=i+1;
    }
    clientes[9].prox=-1;
}

void imprimirVetor(){
    int i;
    for(i=0;i<MAX;i++){
        printf("[%3d] ", i);
    }
    printf("\n");
    for(i=0;i<MAX;i++){
        printf("%5d ", clientes[i].celular);
    }
    printf("\n");
    for(i=0;i<MAX;i++){
        printf("%5d ", clientes[i].creditoInternet);
    }
    printf("\n");
    for(i=0;i<MAX;i++){
        printf("{%3d} ", clientes[i].prox);
    }
    printf("\n");
}

bool insereCliente(int numero, int credito){
    if (quant>MAX){
        return false;
    }else{
        int ant =-1;
        int atual = prim;
        int novo = dispo;
        dispo=clientes[novo].prox;
        while(atual!=-1 && clientes[atual].celular<numero){
            ant = atual;
            atual = clientes[atual].prox;
        }
        clientes[novo].celular=numero;
        clientes[novo].creditoInternet=credito;
        if(ant != -1){
            clientes[novo].prox=clientes[ant].prox;
            clientes[ant].prox=novo;
        }else{
            clientes[novo].prox=prim;
            prim=novo;
        }
        quant ++;
        return true;
    }
}

bool removeListaEncadeada(int numero){
    int ant = -1;
    int atual = prim;
    while(atual!=-1 && clientes[atual].celular!=numero){
        ant = atual;
        atual = clientes[atual].prox;
    }
    if (atual==-1){
        return false;
    }else{
        if (ant ==-1){
            prim = clientes[atual].prox;
        }else{
            clientes[ant].prox=clientes[atual].prox;
            
        }
        clientes[atual].prox = dispo;
        dispo=atual;
        clientes[atual].celular=0;
        clientes[atual].creditoInternet=0;
        quant --;
        return true;
    }
}

void imprimeOrdenada(){
    int i;
    int atual = prim;
    for(i=0; i<quant; i++){
        printf("[%3d] ", i);
    }
    printf("\n");
    while(atual!=-1){
        printf("%5d ", clientes[atual].celular);
        atual = clientes[atual].prox;
    } atual = prim;
    printf("\n");
    while(atual!=-1){
        printf("%5d ", clientes[atual].creditoInternet);
        atual = clientes[atual].prox;
    } atual = prim;
    printf("\n");
}

bool adicionaCreditos(int numero, int cred){
    int atual = prim;
    while(atual!=-1 && clientes[atual].celular!=numero){
        atual = clientes[atual].prox;
    }
    if (atual==-1){
        return false;
    }else{
        clientes[atual].creditoInternet += cred;
        return true;
    }
}

bool removeCreditos(int numero, int cred){
    int atual = prim;
    while(atual!=-1 && clientes[atual].celular!=numero){
        atual = clientes[atual].prox;
    }
    if (atual==-1){
        return false;
    }else{
        clientes[atual].creditoInternet -= cred;
        return true;
    }
}

int main(int argc, char *argv[]){
    int num, cred, escolha, i=0;
    inicializaClientes();
    while(i==0){
    printf("[0–sair][1–novo plano][2–cancela plano][3–gasto internet][4–venda credito]: ");
    scanf("%d", &escolha);
    switch(escolha){
        case 0: i=1; break;
        case 1: printf("Digite o numero do celular: ");
                scanf("%d", &num);
                printf("Digite os creditos: ");
                scanf("%d", &cred);
                insereCliente(num, cred);
                break;
        case 2: printf("Digite o numero do celular a ser excluído: ");
                scanf("%d", &num);
                removeListaEncadeada(num);
                break;
        case 3: printf("Digite o numero do celular: ");
                scanf("%d", &num);
                printf("Digite os creditos gastos: ");
                scanf("%d", &cred);
                removeCreditos(num, cred);
                break;
        case 4: printf("Digite o numero do celular: ");
                scanf("%d", &num);
                printf("Digite os creditos adicionados: ");
                scanf("%d", &cred);
                adicionaCreditos(num, cred);
                break;
    }
    imprimirVetor();
}
}