#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int elm;
    struct node *next;
}node;
 typedef struct{
    node *sommet;
 } Pile ;
int estvide (Pile P){
    if(P.sommet==NULL){
        return 0;
    }else
    return 1;
}
 int sommetelm (Pile P){
    if(estvide(P)==0){
        printf("la pile est vide ");
        exit(35);
    }else{
        return P.sommet->elm;
    }
 }
 void Empiler(Pile *P, int nbr){
        node *temp =malloc(sizeof(node));
        temp->elm=nbr;
        temp->next=P->sommet;
        P->sommet=temp;
 }
 void Depiler (Pile *P){
    if(estvide(*P)==0){
        printf("la pile est vide ");
        exit(35);
    }
    node*temp=P->sommet;
    P->sommet=P->sommet->next;
    free(temp);
 }
void reset(Pile*P){
    while(P->sommet){
        Depiler(P);
    }
}
typedef struct{
    node*premier;
    node*dernier;
}File;
File* Filevide( File *F){
    F->premier=NULL;
    F->dernier=NULL;
    return F;
}
int filestvide(File F){
    if(F.premier==NULL)
        return 1;
    else
        return 0;
}
int premierFile (File F){
    if(filestvide(F)){
        printf("Viiiiiiiiiide");
    exit(22);
    }
    return F.premier->elm;
}
File* Enfiler (File *F, int a){
    node*nv;
    nv=malloc(sizeof(node));
    nv->elm=a;
    nv->next=NULL;
    if(filestvide(*F)){
        F->premier=nv;
        F->dernier=nv;
    }else{
    F->dernier->next=nv;
    F->dernier=nv;
    }
    return F;
}
File*defiler(File*F){
node*c;
        if(filestvide(*F)){
        printf("Viiiiiiiiiide");
    exit(22);
    }else{
    c=F->premier;
    F->premier=F->premier->next;
    free(c);
    return (F);
    }
}

int main()
{   Pile  P;
    P.sommet=NULL;
    Empiler(&P,1);
    Empiler(&P,2);
    Empiler(&P,3);
    Empiler(&P,4);
    printf("le sommet est : %d \n",sommetelm(P));
    Depiler(&P);
    printf("le sommet est : %d \n",sommetelm(P));
    printf("Hello world!\n");
    File F;
    printf("le dernier est : %d \n",premierFile(F));
    return 0;
}
