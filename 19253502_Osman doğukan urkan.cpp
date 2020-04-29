#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

FILE * data;
FILE * data2;

struct db
{
	int id;
	char soru[20];
	char a[20];
	char b[20];
	char c[20];
	char d[20];
	char dogru[2];
};
struct user
{
	char kullanici_cevap[20];
	int kullanici_skor;
	char kullanici_adi[20];
};

void ekle();
void sil();
void goster();
void guncelle();
void oyna();
void yuksek();

int main()
{
	int islem;

	printf("Lutfen yapmak istediginiz islemi seciniz.");

	do {
		printf("\n 1. Soru ekle");
		printf("\n 2. Soru sil");
		printf("\n 3. Sorulari Listele");
		printf("\n 4. Sorulari guncelle");
		printf("\n 5. Oyun oyna");
		printf("\n 6. En yuksek skorlari goster");
		printf("\n 7. Cikis");
		printf("\n");

		scanf("%d", &islem);

		if (islem == 1)
		{
			printf("isleminiz:Soru ekle.\n");
			ekle();
		}
		else if (islem == 2)
		{
			printf("isleminiz:Soru sil.\n");
			goster();
			sil();
		}
		else if (islem == 3)
		{
			printf("isleminiz:Listele.\n");
			goster();
		}
		else if (islem == 4)
		{
			printf("isleminiz:guncelle.\n");
			goster();
			guncelle();
		}
		else if (islem == 5)
		{
			printf("Ysleminiz:Oyun oyna.\n");
			oyna();
		}
		else if (islem == 6)
		{
			printf("isleminiz:En yuksek skorlari goster.\n");
			yuksek();
		}
		else {}
	}

	while (islem != 7);

}

void ekle()
{
	struct db db;
	FILE * data;
	printf("Eklemek istediginiz soru idsini giriniz: ");
	fflush(stdin);
	scanf("%d", &db.id);
	printf("Eklemek istediginiz sorunun metnini giriniz: ");
	printf(" ");
	gets(db.soru);
	gets(db.soru);
	printf("Eklemek istediginiz sorunun A cevabini giriniz: ");
	gets(db.a);
	printf("Eklemek istediginiz sorunun B cevabini giriniz: ");
	gets(db.b);
	printf("Eklemek istediginiz sorunun C cevabini giriniz: ");
	gets(db.c);
	printf("Eklemek istediginiz sorunun D cevabini giriniz: ");
	gets(db.d);
	printf("Eklemek istediginiz sorunun dogru cevabini giriniz: ");
	gets(db.dogru);
	data = fopen("data.txt", "a");
	if (data == NULL)
	{
		printf("Dosya bulunamadi.");
	}
	else
	{
		fprintf(data, "%d %s %s %s %s %s %s\n", db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		printf("Sorunuz basari ile kaydedilmistir.");

	}

	fflush(stdin);
	fclose(data);
}

void sil()
{
	FILE *data, *data2;
	int flag = 0;
	struct db db;
	int secilen;
	data = fopen("data.txt", "r");
	data2 = fopen("data2.txt", "w");
	printf("Silmek istediginiz sorunun idsini giriniz:");
	fflush(stdin);
	scanf("%d", &secilen);
	int secim;

	if (data == NULL)
	{
		printf("Dosya bulunamadi.");
		exit(1);

	}

	while (!feof(data))
	{
		fscanf(data, "%d %s %s %s %s %s %s\n", &db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		printf("asd");
		if (db.id == secilen)
		{
			if (feof(data))
			{
				flag = 1;
			}

			fscanf(data, "%d %s %s %s %s %s %s\n", db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		}

		if (flag)
			break;
		fprintf(data2, "%d %s %s %s %s %s %s\n", db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
	}

	fclose(data);
	fclose(data2);

	printf("Silme islemini onayliyor musunuz? (1:Evet 2:Hayir) ");
	scanf("%d", &secim);
	if (secim == 1)
	{
		remove("data.txt");
		rename("data2.txt", "data.txt");
	}
	else
	{
		remove("data2.txt");
	}
}

void goster()
{
	struct db db;
	data = fopen("data.txt", "r");
	if (data == NULL)
	{
		puts("Dosya acilamadi.");
		exit(1);
	}

	while (!feof(data))
	{
		fflush(stdout);

		fscanf(data, "%d %s %s %s %s %s %s\n", &db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		if (db.id != NULL)
		{
			printf("\n%d %s %s %s %s %s %s\n", db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		}
	}

	fclose(data);

}

void guncelle()
{
	struct db db;
	int id, durum = 0;
	printf("\nBilgilerini degistireceginiz sorunun idsini giriniz: ");
	scanf("%d", &id);
	data = fopen("data.txt", "r");
	data2 = fopen("data2.txt", "w");
	if (data == NULL)
	{
		puts("Dosya acilamadi");
		exit(1);
	}

	while (!feof(data))
	{
		fscanf(data, "%d %s %s %s %s %s %s\n", &db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		if (id != db.id)
		{
			fprintf(data2, "%d %s %s %s %s %s %s\n", db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		}
		else
		{
			fflush(stdin);
			printf("Yeni id giriniz : ");
			scanf("%d", &db.id);
			printf("soru metnini giriniz : ");
			gets(db.soru);
			gets(db.soru);
			printf("A cevabini giriniz : ");
			gets(db.a);
			printf("B cevabini giriniz : ");
			gets(db.b);
			printf("C cevabini giriniz : ");
			gets(db.c);
			printf("D cevabini giriniz : ");
			gets(db.d);
			printf("Dogru cevabi giriniz : ");
			gets(db.dogru);
			printf("\n");
			fprintf(data2, "%d %s %s %s %s %s %s\n", db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);	//verileri yedek dosyasyna yazdyr
			durum = 1;	// de?i?me yapyldy.
		}
	}

	fclose(data);
	fclose(data2);
	if (durum == 1)
	{
		//de?i?me islemi yapilirsa
		remove("data.txt");
		rename("data2.txt", "data.txt");
		puts("Ogrenci bilgileri degistirildi devam etmek icin bir tusa basin...");
	}
	else
	{
		remove("data2.txt");
		puts("Ilgili ogenci bulunamadi devam etmek icin bir tusa basin...");
	}

	fflush(stdin);
}

void oyna()
{
	struct db db;
	struct user user;
	FILE *data, *datakullanici;
	int rastgele[5];
	srand(time(NULL));
	int i = 1;
	int kullaniciskor = 0;
	data = fopen("data.txt", "r");

	rastgele[1] = 1 + rand() % 10;
	rastgele[2] = 1 + rand() % 10;
	rastgele[3] = 1 + rand() % 10;
	rastgele[4] = 1 + rand() % 10;
	rastgele[5] = 1 + rand() % 10;

	if (data == NULL)
	{
		puts("Dosya acilamadi");
		exit(1);
	}

	while (!feof(data))
	{
		fscanf(data, "%d %s %s %s %s %s %s\n", &db.id, db.soru, db.a, db.b, db.c, db.d, db.dogru);
		for (i = 1; i < 6; i++)
		{
			fflush(stdin);

			if (rastgele[i] == db.id)
			{
				printf("%s %s %s %s %s\n", db.soru, db.a, db.b, db.c, db.d);
				scanf("%s", &user.kullanici_cevap);

				if (strcmp(db.dogru, user.kullanici_cevap) == 0)
				{
					user.kullanici_skor = user.kullanici_skor + 1;

				}
				else
				{
					kullaniciskor = kullaniciskor;

				}
			}
		}
	}

	printf("%d", user.kullanici_skor);
	printf("Cevaplariniz kaydedilmistir.\n");

	datakullanici = fopen("datakullanici.txt", "a");
	printf("kullanici adi giriniz\n");
	scanf("%s", &user.kullanici_adi);
	fprintf(datakullanici, "%d %s\n", user.kullanici_skor, user.kullanici_adi);
	fclose(data);
	fclose(datakullanici);

}

void yuksek()
{
	struct user user;
	static struct user static_user[999];
	static struct user static_tempp;
	int sayac;
	int sayac2;
	int n = 0;
	FILE * datakullanici;
	datakullanici = fopen("datakullanici.txt", "r");
	fflush(stdin);
	fscanf(datakullanici, "%d %s\n", &user.kullanici_skor, user.kullanici_adi);
	while (!feof(datakullanici))
	{
		static_user[n] = user;
		n++;
		fscanf(datakullanici, "%d %s\n", &user.kullanici_skor, user.kullanici_adi);

	}

	for (sayac = 0; sayac < n; sayac++)
	{
		for (sayac2 = 0; sayac2 < n; sayac2++)
		{
			if (static_user[sayac2].kullanici_skor < static_user[sayac2 + 1].kullanici_skor)
			{
				static_tempp = static_user[sayac2 + 1];
				static_user[sayac2 + 1] = static_user[sayac2];
				static_user[sayac2] = static_tempp;
			}
		}
	}

	printf("%d %s\n", static_user[0].kullanici_skor, static_user[0].kullanici_adi);
	for (sayac = 1; sayac < n + 1; sayac++)
	{
		fflush(stdin);
		printf("%d %s\n", static_user[sayac].kullanici_skor, static_user[sayac].kullanici_adi);
		fflush(stdin);
	}

	fclose(datakullanici);

}
