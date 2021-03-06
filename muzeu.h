#ifndef LABORATOR_POO_MUZEU_H
#define LABORATOR_POO_MUZEU_H
#include "SalaMuzeu.h"
#include "MagazinSuveniruri.h"
#include "sala.h"
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>


class muzeu {

private:
	static const int nrzile=7;
    std::string nume;
	std::string ore_vizitare[nrzile]; // la fiecare pozitie (zi a sapt)
    //e interval orar de genul 11-18 sau - daca nu se poate vizita in acea zi
    std::string adresa;
    int pret_zile[nrzile];
	int fonduri_muzeu;

    double feedback_score;
    //map cu nume personal; departament: nume; numele sunt retinute in vector de stringuri
    std::unordered_map<std::string, std::vector<std::string> > nume_personal;

	muzeu();
	static muzeu* m;

protected:
	int nr_sali;
	//vector de pointeri la clasa de baza (sala); pe ultima pozitie e intotdeauna magazinul de suveniruri
	std:: vector< sala*> S;

public:

	~muzeu();
    void AdaugaPersonal(const std::string& departament,const std::string& nume);
    void FeedbackScore();
    void AfiseazaPersonal();
    void AdaugaDepartament(const std::string& departament);

    void AdaugaExponat(int nr_sala, const std::string& nume_exponate="-", const std::string& data_aducerii="-", int pret=0);

    int  PretZi(int nr_zi_saptamana);
    void StartTour();
    void ShowRoom(int nsala);
    void ReadRoomsData();
    void Despre() const ;
	void PrimesteDonatii(int valoare);

	//setteri
	void InchideSala(int nrsala);
	void DeschideSala(int nrsala);

	//getter
	int NrSali() const;
    //overload >>
    friend std::istream &operator >> (std::istream &in, muzeu &M);
    //overload <<
    friend std::ostream &operator <<(std::ostream &out, const muzeu &M);

    //sterg cc si op= pentru a nu putea duplica obiecte de tip muzeu
    muzeu(const muzeu&)=delete;
    muzeu& operator=(const muzeu&)=delete;

    static muzeu* get_museum(){
		if(m==nullptr)
			m=new muzeu;
		return m;
    }

};

#endif //LABORATOR_POO_MUZEU_H
