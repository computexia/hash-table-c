#include <stdio.h>
#include <stdlib.h>

struct Row{
	int index;
	char isim[8];
	struct Row *sonraki;
	};
	
struct Tablo{
	struct Row rw[8];
};

struct Tablo tablo;

void tabloformat()
{
    int k;
    for (k = 0; k < 8; k++)
    {
        tablo.rw[k].sonraki = NULL;		
        tablo.rw[k].index=-1; 
        sprintf(tablo.rw[k].isim, "%s", "NULL"); 
    }    
}

int hash(char isim[8])
{
    unsigned int hash = 0;
    for (int i=0;isim[i]!='\0';i++)
    {
        hash=16*hash+isim[i];
    }
    return hash;
}

void cakisma(char isim[8]){
	int indis=hash(isim);
	indis=indis%8;
	struct Row *iter=&tablo.rw[indis];
	while(iter!=NULL){
		iter=iter->sonraki;
		}
	iter = (struct Row *)malloc(sizeof(struct Row));
	iter->index=indis;
	sprintf(iter->isim, "%s", isim);
	iter->sonraki=NULL;
	printf("%d",iter->index);
}
	
void tabloyaEkle(char isim[8]){
	int indis=hash(isim);
	indis=indis%8;
	int kontrol=0;
	if(tablo.rw[indis].index==-1){
		tablo.rw[indis].index=indis;
		sprintf(tablo.rw[indis].isim, "%s", isim);
		return;
		}
	int i=0;
	for(i;i<8;i++){
		if(tablo.rw[indis].index==tablo.rw[i].index){
		kontrol=1;
		}
	if(kontrol==1){
		cakisma(isim);
		}
		}
}	
	
void tabloyuYazdir(){
	int i=0;
			printf("\n");
	for(i;i<8;i++){
		printf("%d - ",tablo.rw[i].index);
		printf("%s \n",tablo.rw[i].isim);
		struct Row *iter=&tablo.rw[i];
		if(iter->sonraki!=NULL){
			iter=iter->sonraki;
			}
		}
}
		
int main()
{	
	char disim[8];
	while(1){
	printf("(1) tabloyu formatla \n"
		   "(2) tabloya ekle \n"
		   "(3) dosyanın hash kodunu göster \n");
	int secim;
	scanf("%d",&secim);
	switch(secim){
		case 1:
		tabloformat();
		tabloyuYazdir();
		break;
		case 2:
		printf("dosya ismini girin: ");
		scanf("%s",disim);
		FILE *fp=fopen(disim,"r");
		if(fp==NULL){
			printf("dosya bulunamadı\n");
			}
		else {tabloyaEkle(disim);
		tabloyuYazdir();}
		case 3:
		printf("dosya ismini girin: ");
		scanf("%s",disim);
		FILE *fp2=fopen(disim,"r");
		if(fp2==NULL){
			printf("dosya bulunamadı\n");
			}
		else {
			printf("hash: %d\n",hash(disim));
			}
		break;
		}
	}
		return 0;
	}

