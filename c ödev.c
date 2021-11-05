#include<stdio.h>

    
/*Takimlar Struct'ý
dizi1 ve dizi2 maçlar girildiðinde karþýlaþtýrmak için.*/

typedef struct{

   char normalAd[13], dizi1[10], dizi2[10];
   char takmadi;
   int om, gs, ms, bs, ag, yg, avg, puan, i1, i2;
   char eo;

}takimlar;
/*Dosyadan girilen maçlarý karþýlaþtýra fonskiyon*/
void macEkle(takimlar takim[], char takimAdi1, char takimAdi2, int gol1, int gol2, int kacTakim){


         int j=0, i=0, sayac=0;

         for(j=0;j<kacTakim;j++){

            if(takim[j].takmadi==takimAdi1){
                sayac=0;
                for(i=0; i<takim[j].i1; i++){

                   if(takim[j].dizi1[i]==takimAdi2){
                      sayac=1;

                   }
                }
                if(sayac==0){

                    takim[j].ag+=gol1;
                    takim[j].yg+=gol2;
                    takim[j].om++;
                    takim[j].dizi1[takim[j].i1]=takimAdi2;
                    takim[j].i1++;
                    if(gol1>gol2){
                       takim[j].gs++;
                    }
                    else if(gol2==gol1){
                       takim[j].bs++;
                    }
                    else if(gol2>gol1){
                       takim[j].ms++;
                    }
                }
            }
            else if(takim[j].takmadi==takimAdi2){
                sayac=0;
                for(i=0; i<takim[j].i2; i++){

                   if(takim[j].dizi2[i]==takimAdi1){
                      sayac=1;

                   }
                }
                if(sayac==0){

                  takim[j].ag+=gol2;
                  takim[j].yg+=gol1;
                  takim[j].om++;
                  takim[j].dizi2[takim[j].i2]=takimAdi1;
                  takim[j].i2++;
                  if(gol2>gol1){
                      takim[j].gs++;
                  }
                  else if(gol1==gol2){
                      takim[j].bs++;
                  }
                  else if(gol1>gol2){
                      takim[j].ms++;
                  }
                }
            }

         }
         if(sayac==1){
                printf("Mac girisi yanlis...\n");
            }

}
/*Tablo ve takim bilgilerini ayarlama fonksiyonu.*/
void tabloAyar(takimlar takim[], int gp, int bp, int mp, int kacTakim){

      int j=0;
      for(j=0;j<kacTakim;j++){

         takim[j].avg=takim[j].ag-takim[j].yg;
         takim[j].puan=takim[j].gs*gp + takim[j].bs*bp + takim[j].ms*mp;

      }

}
/*Takma ada göre siralama fonksiyonu*/
void siralaTakma(takimlar takim[], int kacTakim){
        int j=0, i=0;
        takimlar temp;


        for(i=1;i<kacTakim;i++)
        {
             for(j=0;j<kacTakim-i;j++)
             {
                  if((int)takim[j].takmadi>(int)takim[j+1].takmadi)
                  {
                      temp=takim[j+1];
                      takim[j+1]=takim[j];
                      takim[j]=temp;
                  }
             }
        }

}
/*Puana göre siralama fonksiyonu*/
void siralaPuan(takimlar takim[], int kacTakim){
        int j=0, i=0;
        takimlar temp;


        for(i=1;i<kacTakim;i++)
        {
             for(j=0;j<kacTakim-i;j++)
             {
                  if(takim[j].puan<takim[j+1].puan)
                  {
                      temp=takim[j+1];
                      takim[j+1]=takim[j];
                      takim[j]=temp;
                  }
             }
        }

}
/*Takim normal adina göre siralama fonksiyonu*/
void siralaIsim(takimlar takim[], int kacTakim){
        int j=0, i=0, k=0;
        takimlar temp;


        for(i=1;i<kacTakim;i++)
        {
             for(j=0;j<kacTakim-i;j++)
             {
                  if(takim[j].normalAd[k]>takim[j+1].normalAd[k])
                  {
                      temp=takim[j+1];
                      takim[j+1]=takim[j];
                      takim[j]=temp;
                  }
             }
        }

}
/*Ekrana tablo yazdirma fonksiyonu*/
void yazdir(takimlar takim[], int kacTakim){

     int j=0;
     printf("Takma |       Isim      |   Om  |  Gs   |  Bs   |  Ms   |   Ag  |   Yg  |  Avj  |  Puan \n");
     printf("------------------------------------------------------------------------------------------\n");
     for(j=0;j<kacTakim;j++){

          printf("%4c  |  ",takim[j].takmadi);
          printf("%13s  |  ",takim[j].normalAd);
          printf("%3d  |  ",takim[j].om);
          printf("%3d  |  ",takim[j].gs);
          printf("%3d  |  ",takim[j].bs);
          printf("%3d  |  ",takim[j].ms);
          printf("%3d  |  ",takim[j].ag);
          printf("%3d  |  ",takim[j].yg);
          printf("%3d  |  ",takim[j].avg);
          printf("%3d ",takim[j].puan);
          printf("\n");
     }

}
/*Dosyaya tablo yazdirma fonksiyonu*/
void dosyayaYaz(takimlar takim[], int kacTakim, char dosyaAdi[]){

      FILE  *DosyaOku;
      DosyaOku = fopen(dosyaAdi,"w");
      int j=0;

      fprintf(DosyaOku,"Takma |       Isim      |   Om  |  Gs   |  Bs   |  Ms   |   Ag  |   Yg  |  Avj  |  Puan \n");
      fprintf(DosyaOku,"-----------------------------------------------------------------------------------------\n");
      for(j=0;j<kacTakim;j++){


          fprintf(DosyaOku,"%4c  |  ",takim[j].takmadi);
          fprintf(DosyaOku,"%13s  |  ",takim[j].normalAd);
          fprintf(DosyaOku,"%3d  |  ",takim[j].om);
          fprintf(DosyaOku,"%3d  |  ",takim[j].gs);
          fprintf(DosyaOku,"%3d  |  ",takim[j].bs);
          fprintf(DosyaOku,"%3d  |  ",takim[j].ms);
          fprintf(DosyaOku,"%3d  |  ",takim[j].ag);
          fprintf(DosyaOku,"%3d  |  ",takim[j].yg);
          fprintf(DosyaOku,"%3d  |  ",takim[j].avg);
          fprintf(DosyaOku,"%3d  |  ",takim[j].puan);
          fprintf(DosyaOku,"\n");

     }

     fclose(DosyaOku);

}


int main() {
      /*Dosyalari okuma*/
      FILE*maclar;
      maclar=fopen("maclar.txt","r");
      FILE*ayarlar;
      ayarlar=fopen("ayarlar.txt","r");
      FILE*takmlar;
      takmlar=fopen("takimlar.txt","r");
     
      int kacTakim, gp, mp, bp;
     /*ayarlar.txt dosyasindan verileri alma*/
      while(!feof(ayarlar))
      {
     	fscanf(ayarlar,"%d %d %d %d", &kacTakim, &gp, &bp, &mp);
      }
      takimlar takim[kacTakim];
    /*takimlar.txt dosyasindan verileri alma*/
      int i=0;
      while(!feof(takmlar))
	  {
    	fscanf(takmlar,"%s", takim[i].normalAd);
        i++;
      }
      
      int j=0;
      int k=65;
      for(k=65;k<65+kacTakim;k++){
    /*Bütün bilgilerin "0" olmasi*/
        takim[j].takmadi = (char)k;
        takim[j].om = 0;  takim[j].gs = 0;  takim[j].ms = 0;  takim[j].bs = 0;
        takim[j].ag = 0;  takim[j].yg = 0;  takim[j].avg = 0;  takim[j].puan = 0; takim[j].i1=0; takim[j].i2=0;
        j++;
      }

      char takimAdi1, takimAdi2;
      int gol1, gol2;
    /*maclar.txt dosyasindan verileri alma*/
      while(!feof(maclar))
	  {
    	fscanf(maclar,"%c %d %c %d\n", &takimAdi1, &gol1, &takimAdi2, &gol2);
        macEkle(takim, takimAdi1, takimAdi2, gol1, gol2, kacTakim);

	  }

	  tabloAyar(takim, gp, bp, mp, kacTakim);


    /*Program secenekleri*/
      printf("Mac Gir = 1 \n");
      printf("Takma Isime gore sirali olarak yazdir = 2\n");
      printf("Takimlarin alfabetik sirasina gore yazdir = 3\n");
      printf("Puan sirasina gore yazdir = 4\n");
      printf("Cikis = 5\n");
      /*Secenek döngüsü*/
      int secim, secim2;
      while(1){


       printf("\n");
       printf("Secim Yapiniz: ");
       scanf("%d", &secim);


       if(secim==1){

          printf("Mac Gir: ");
          char ta1, ta2;
          int g1, g2;
          scanf(" %c %d  %c %d", &ta1, &g1, &ta2, &g2);

          macEkle(takim, ta1, ta2, g1, g2, kacTakim);
          tabloAyar(takim, gp, bp, mp, kacTakim);
       }
       else if(secim==2){

         printf("Ekrana yaz= 1 \n");
         printf("Dosyaya yaz= 2 \n");
         printf("Giris: ");
         scanf("%d", &secim2);

         if(secim2==1){
            siralaTakma(takim, kacTakim);
            yazdir(takim, kacTakim);
         }
         else if(secim2==2){
            siralaTakma(takim, kacTakim);
            dosyayaYaz(takim,kacTakim,"TakimaGore.txt");
         }

       }
       else if(secim==3){

         printf("Ekrana yaz= 1 \n");
         printf("Dosyaya yaz= 2 \n");
         printf("Giris: ");
         scanf("%d", &secim2);

         if(secim2==1){
           siralaIsim(takim, kacTakim);
           yazdir(takim, kacTakim);
         }
         else if(secim2==2){
            siralaIsim(takim, kacTakim);
            dosyayaYaz(takim,kacTakim,"IsimeGore.txt");
         }
       }
       else if(secim==4){

         printf("Ekrana yaz= 1 \n");
         printf("Dosyaya yaz= 2 \n");
         printf("Giris: ");
         scanf("%d", &secim2);
         if(secim2==1){
           siralaPuan(takim, kacTakim);
           yazdir(takim, kacTakim);
         }
         else if(secim2==2){
           siralaPuan(takim, kacTakim);
           dosyayaYaz(takim,kacTakim,"PuanaGore.txt");
         }

       }
       else{
         break;
       }


     }

    return(0);
}
