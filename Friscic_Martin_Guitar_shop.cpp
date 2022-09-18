
#include <iostream>
#include<cstring>
#include "biblioteka_vrijeme.cc"
using namespace std;
float iznos;

struct struktura1 {

		char ime_gitare[50];
		float cijena;
		char pickupovi[20];
		char tip[20];
		struktura1 *gitare;
};

struct struktura2 {

			char proizvodac_zica[30];
			float debljina_zica;
			float cijena_zica;
			struktura2 *zice;
};

struct struktura3 {
char efekt[40];
char proizvodac[40];
float cijena;
struktura3 *pedale;
};

void unos_gitara(struktura1 *gitare_lista) {

		struktura1 *zadnji, *novi;
		zadnji=gitare_lista;
		while(zadnji->gitare)		zadnji=zadnji->gitare;
		novi=new struktura1;
		zadnji->gitare=novi;
		novi->gitare=NULL;
		cout<<"Ime gitare: "; cin.getline(novi->ime_gitare,50);
		cout<<"Cijena gitare:  "; cin>>novi->cijena;
		cin.ignore();
		cout<<"Vrsta pickupova:  (EMG, DiMarzio, Single Coil, Humbucker.....):"<<endl;
		cin.getline(novi->pickupovi,20);
		cout<<"Tip gitare: (akusticna, elektricna, elektroakusticna): "<<endl;
		cin.getline(novi->tip,20);
}

void unos_zica(struktura2 *zice_lista) {
		struktura2 *zadnji, *novi;
		zadnji=zice_lista;
		while(zadnji->zice)		zadnji=zadnji->zice;
		novi=new struktura2;
		zadnji->zice=novi;
		novi->zice=NULL;
		cout<<"Proizvodac zica: "; cin.getline(novi->proizvodac_zica,30);
		cout<<"Debljina zica: "; cin>>novi->debljina_zica;
		cout<<"Cijena zica: "; cin>>novi->cijena_zica;
}

void unos_pedala(struktura3 *pedale_lista) {
			struktura3 *zadnji, *novi;
		zadnji=pedale_lista;
		while(zadnji->pedale)		zadnji=zadnji->pedale;
		novi=new struktura3;
		zadnji->pedale=novi;
		novi->pedale=NULL;
		cout<<"Efekt pedale: "; cin.getline(novi->efekt,40);
		cout<<"Proizvodac: "; cin.getline(novi->proizvodac,40);
		cout<<"Cijena pedale: "; cin>>novi->cijena;
}

void ispis_gitara (struktura1 *gitare_lista) {

		int zbroj=0;
		struktura1 *tekuci=gitare_lista->gitare;
		while(tekuci) {
		cout<<"--------------ISPIS---------- \n";
		cout<<"Ime gitare:  "<<tekuci->ime_gitare<<endl;
		cout<<"Cijena gitare: "<<tekuci->cijena<<endl;
		cout<<"Pickupovi:"<<tekuci->pickupovi<<endl;
		cout<<"Tip:"<<tekuci->tip<<endl;
		tekuci=tekuci->gitare;
		cout<<"--------------------------------\n";
		}
}

void ispis_zica(struktura2 *zice_lista) {
int zbroj=0;
		struktura2 *tekuci=zice_lista->zice;
		while(tekuci) {
		cout<<"--------------ISPIS---------- \n";
		cout<<"Proizvodac zica:  "<<tekuci->proizvodac_zica<<endl;
		cout<<"Debljina zica: "<<tekuci->debljina_zica<<endl;
		cout<<"Cijena zica:"<<tekuci->cijena_zica<<endl;
		tekuci=tekuci->zice;
		cout<<"--------------------------------\n";
		}
}

void ispis_pedala (struktura3 *pedale_lista) {
int zbroj=0;
		struktura3 *tekuci=pedale_lista->pedale;
		while(tekuci) {
		cout<<"--------------ISPIS---------- \n";
		cout<<"Efekt:  "<<tekuci->efekt<<endl;
		cout<<"Proizvodac: "<<tekuci->proizvodac<<endl;
		cout<<"Cijena pedale:"<<tekuci->cijena<<endl;
		tekuci=tekuci->pedale;
		cout<<"--------------------------------\n";
		}
		
}

void pretrazivanje_gitara(struktura1 *gitare_lista, char *kljuc) {

		struktura1 *tekuci=gitare_lista->gitare;
		bool nadjen=false;
		while(tekuci) {
		if(strcmp(tekuci->ime_gitare,kljuc)==0) {
		nadjen=true;
		cout<<"--------------ISPIS---------- \n";
		cout<<"Ime gitare:  "<<tekuci->ime_gitare<<endl;
		cout<<"Cijena gitare: "<<tekuci->cijena<<endl;
		cout<<"Pickupovi:"<<tekuci->pickupovi<<endl;
		cout<<"Tip:"<<tekuci->tip<<endl;
		cout<<"--------------------------------\n";
		}
		tekuci=tekuci->gitare;
		}
				if(!nadjen)  cout<<"Nema trazenog elementa u listi"<<endl;
}

void pretrazivanje_zica(struktura2 *zice_lista, char *kljuc) {
struktura2 *tekuci=zice_lista->zice;
		bool nadjen=false;
		while(tekuci) {
		if(strcmp(tekuci->proizvodac_zica,kljuc)==0) {
		nadjen=true;
		cout<<"--------------ISPIS---------- \n";
		cout<<"Proizvodac zica:  "<<tekuci->proizvodac_zica<<endl;
		cout<<"Debljina zica: "<<tekuci->debljina_zica<<endl;
		cout<<"Cijena zica:"<<tekuci->cijena_zica<<endl;
		cout<<"--------------------------------\n";
		}
				tekuci=tekuci->zice;
}
					if(!nadjen)		cout<<"Nema trazenog elementa u listi"<<endl;
					}

void pretrazivanje_pedala(struktura3 *pedale_lista, char *kljuc)
{
struktura3 *tekuci=pedale_lista->pedale;
		bool nadjen=false;
		while(tekuci) {
		if(strcmp(tekuci->efekt,kljuc)==0) {
		nadjen=true;
		cout<<"--------------ISPIS---------- \n";
		cout<<"Proizvodac pedala:  "<<tekuci->proizvodac<<endl;
		cout<<"Cijena pedale: "<<tekuci->cijena<<endl;
		cout<<"Efekt:"<<tekuci->efekt<<endl;
		cout<<"--------------------------------\n";
		}
		tekuci=tekuci->pedale;
     }
     
				if(!nadjen)		cout<<"Nema trazenog elementa u listi"<<endl;
}

void brisanje_gitara (struktura1 *gitare_lista, char *kljuc) {
struktura1 *brisi=gitare_lista->gitare, *prethodni=gitare_lista;
bool brisanje=false;
while(brisi) {
		if(strcmp(brisi->ime_gitare,kljuc)==0) {
				brisanje=true;
				prethodni->gitare=brisi->gitare;
				delete brisi;
				cout<<"Element je uspjesno obrisan"<<endl;
				break;
		}
			prethodni=brisi;
			brisi=brisi->gitare;
}
			if(!brisanje)			cout<<"Nema elementa koji zelite obrisati"<<endl;
}

void brisanje_zica(struktura2 *zice_lista , char *kljuc) {
		struktura2 *brisi=zice_lista->zice, *prethodni=zice_lista;
		bool brisanje=false;
		while(brisi) {
		if(strcmp(brisi->proizvodac_zica,kljuc)==0) {
				brisanje=true;
				prethodni->zice=brisi->zice;
				delete brisi;
				cout<<"Element je uspjesno obrisan"<<endl;
				break;
		}
		prethodni=brisi;
		brisi=brisi->zice;
		}
		if(!brisanje)		cout<<"Nema elementa koji zelite obrisati"<<endl;
}

void brisanje_pedala(struktura3 *pedale_lista, char *kljuc){
struktura3 *brisi=pedale_lista->pedale, *prethodni=pedale_lista;
		bool brisanje=false;
		while(brisi) {
		if(strcmp(brisi->proizvodac,kljuc)==0) {
				brisanje=true;
				prethodni->pedale=brisi->pedale;
				delete brisi;
				cout<<"Element je uspjesno obrisan"<<endl;
				break;
						}
				prethodni=brisi;
				brisi=brisi->pedale;
				}
				if(!brisanje)		cout<<"Nema elementa koji zelite obrisati"<<endl;
}

void kosarica(struktura1 *gitare_lista, struktura2 *zice_lista, struktura3 *pedale_lista)
{
		int kategorija;
		char dodavanje_artikla[50];
		
		cout<<"------------------------ \n";
		cout<<"Dobro dosli u kosaricu.. \n";
		cout<<"------------------------ \n";
		
		cout<<"Odaberite koju kategoriju artikla zelite dodati u kosaricu"<<endl;
		cout<<"1. Gitara \n 2. Zice \n 3. Pedala \n";
		cin>>kategorija;
		switch (kategorija) {
				case 1: {
							ispis_gitara(gitare_lista);
							
							cout<<"Napisite ime gitare koju zelite"<<endl;
							cin.ignore();
							cin.getline(dodavanje_artikla,50);
							struktura1 *tekuci=gitare_lista->gitare;
							bool nadjen=false;
							while(tekuci) {
							if(strcmp(tekuci->ime_gitare, dodavanje_artikla)==0) {
							nadjen=true;
							cout<<"--------------ISPIS---------- \n";
							cout<<"Ime gitare:  "<<tekuci->ime_gitare<<endl;
							cout<<"Cijena gitare: "<<tekuci->cijena<<endl;
							cout<<"Pickupovi:"<<tekuci->pickupovi<<endl;
							cout<<"Tip:"<<tekuci->tip<<endl;
							cout<<"--------------------------------\n";
							float stanje1=iznos-(tekuci->cijena);
							if(stanje1>0)
							cout<<"Preostalo vam je jos"<<" "<<stanje1<<" "<<"kuna"<<endl;
							else		cout<<"Nemate dovoljno novca"<<endl;
							iznos=stanje1;

							}
							tekuci=tekuci->gitare;
}
				if(!nadjen)		cout<<"Nema trazenog elementa u listi"<<endl;
				break;
}
				case 2: {
						ispis_zica(zice_lista);
						cout<<"Napisite ime zica koje hocete"<<endl;
						cin.ignore();
						cin.getline(dodavanje_artikla,50);
						struktura2 *tekuci=zice_lista->zice;
						bool nadjen=false;
						while(tekuci) {
							if(strcmp(tekuci->proizvodac_zica, dodavanje_artikla)==0) {
							nadjen=true;
							cout<<"--------------ISPIS---------- \n";
							cout<<"Proizvodac zica:  "<<tekuci->proizvodac_zica<<endl;
							cout<<"Cijena zica: "<<tekuci->cijena_zica<<endl;
							cout<<"Debljina zica: "<<tekuci->debljina_zica<<endl;
							cout<<"--------------------------------\n";
							float stanje2=iznos-(tekuci->cijena_zica);
							if(stanje2>0)
							cout<<"Preostalo vam je jos   "<<stanje2<<" "<<"kuna"<<endl;
							else cout<<"Nemate dovoljno novca"<<endl;
							
							iznos=stanje2;
							}
							tekuci=tekuci->zice;
				}
				if(!nadjen)		cout<<"Nema trazenog elementa u listi"<<endl;
				break;
				
}
			case 3: {
					ispis_pedala(pedale_lista);
					cout<<"Napisite efekt pedale koju zelite"<<endl;
					cin.ignore();
					cin.getline(dodavanje_artikla,50);
					struktura3 *tekuci=pedale_lista->pedale;
					bool nadjen=false;
					while(tekuci) {
						if(strcmp(tekuci->efekt, dodavanje_artikla)==0) {
							nadjen=true;
							cout<<"--------------ISPIS---------- \n";
							cout<<"Proizvodac pedala:  "<<tekuci->proizvodac<<endl;
							cout<<"Cijena pedale: "<<tekuci->cijena<<endl;
							cout<<"Efekt:"<<tekuci->efekt<<endl;
							cout<<"--------------------------------\n";
							float stanje3=iznos-(tekuci->cijena);
							if(stanje3>0)
							cout<<"Preostalo vam je jos   "<<stanje3<<" "<<"kuna"<<endl;
							else cout<<"Nemate dovoljno novca"<<endl;
							iznos=stanje3;

							
						}
						tekuci=tekuci->pedale;
					}
					if(!nadjen)			cout<<"Nema trazenog elementa u listi"<<endl;
					break;
					
			}
				
	}
}
int main(){

		struktura1 *gitare_lista=new struktura1;
		gitare_lista->gitare=NULL;
		
		struktura2 *zice_lista=new struktura2;
		zice_lista->zice=NULL;
		
		struktura3 *pedale_lista=new struktura3;
		pedale_lista->pedale=NULL;
		
		int izbor, precizni_odabir;
		char trazenje[80];
		cout<<"Unesite koliko imate novca"<<endl;
		cin>>iznos;
		
		do {
		cout<<"\n\n";
		
		cout<<"Unesite sto zelite: \n"<<"1. Gitare \n"<<"2. Zice za gitare \n"<<"3. Pedale \n"<<"4. Kosarica \n"<<
		"9. Izlaz iz programa"<<endl;
		cin>>izbor;
		switch(izbor) {
		
		case 1: {
						cout<<"Unesite radnju koju zelite izvrsiti"<<endl;
						cout<<"1. Unos nove gitare \n"<<"2. Ispis svih gitara \n"<<"3. Pretrazivanje modela gitara \n"<<
								"4. Brisanje neke od gitare s popisa \n";
								cin>>precizni_odabir;
								switch(precizni_odabir) {
										case 1:
										cin.ignore();
										unos_gitara(gitare_lista);
										break;
										
										case 2:
										ispis_gitara(gitare_lista);
										break;
										
										case 3: {
												cout<<"Unesite ime gitare koju zelite pronaci"<<endl;
												cin.ignore();
												cin.getline(trazenje,80);
												pretrazivanje_gitara(gitare_lista,trazenje);
												break;
										}
										
										case 4:
										cout<<"Unesite ime gitare koju zelite obrisati"<<endl;
										cin.ignore();
										cin.getline(trazenje,80);
										brisanje_gitara(gitare_lista, trazenje);
										break;
								}
										break;
		}
		
		case 2: {
						cout<<"Unesite radnju koju zelite izvrsiti"<<endl;
						cout<<"1. Unos novih zica \n"<<"2. Ispis svih zica \n"<<"3. Pretrazivanje zica \n"<<
						      "4. Brisanje nekih zica s popisa \n";
      						cin>>precizni_odabir;
						      switch(precizni_odabir) {
      						case 1:
						      cin.ignore();
      						unos_zica(zice_lista);
						      break;
      						
						      case 2:
      						cin.ignore();
						      ispis_zica(zice_lista);
      						break;
						      
      							case 3: {
												cout<<"Unesite ime zica koje zelite pronaci"<<endl;
												cin.ignore();
												cin.getline(trazenje,80);
												pretrazivanje_zica(zice_lista,trazenje);
												break;
							}
									case 4:
									cout<<"Unesite proizvodaca cije zice zelite obrisati"<<endl;
									cin.ignore();
									cin.getline(trazenje,80);
									brisanje_zica(zice_lista, trazenje);
									break;
      						}
						      break;
		}
				case 3: {
					cout<<"Unesite radnju koju zelite izvrsiti"<<endl;
						cout<<"1. Unos nove pedale \n"<<"2. Ispis svih pedala \n"<<"3. Pretrazivanje pedala \n"<<
					"4. Brisanje neke od pedala \n";
								cin>>precizni_odabir;
								switch(precizni_odabir) {
								case 1:
									cin.ignore();
								unos_pedala(pedale_lista);
								break;
								
								case 2:
								cin.ignore();
								ispis_pedala(pedale_lista);
								break;
								
								case 3: {
										cout<<"Unesite efekt pedale koju zelite pronaci"<<endl;
										cin.ignore();
										cin.getline(trazenje,80);
										pretrazivanje_pedala(pedale_lista,trazenje);
										break;
								}
								
								case 4: {
												cout<<"Unesite efekt pedale koju zelite obrisati"<<endl;
												cin.ignore();
												cin.getline(trazenje,80);
												brisanje_pedala(pedale_lista,trazenje);
												break;

												
								}
				
								}
								break;
		}
		

								
						case 4: {
						kosarica(gitare_lista, zice_lista, pedale_lista);
						break;
						}	
		}
		} while(izbor!=9);
		
		
	system("PAUSE");
}
  
