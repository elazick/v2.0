#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <exception>
#include <chrono>
#include <cstdlib>
#include <list>
#include <time.h>
#include <istream>


class zmogus {
protected:
	std::string vardas_;
	std::string pavarde_;

public:
	zmogus(std::string vardas, std::string pavarde) {
		vardas_ = vardas; pavarde_ = pavarde;
	};  //konstruktorius

	zmogus() {
		vardas_ = ""; pavarde_ = "";
	}

	virtual void Vardas(std::string vardas)  = 0;
	virtual void Pavarde(std::string pavarde)  = 0;

	//getteriai
	inline std::string getVardas() const { return vardas_; }
	inline std::string getPavarde() const { return pavarde_; }

};

class studentas : public zmogus {
private:
	std::vector<int> pazymiai_;
	int paz_sk_;
	int sum_;
	double egzas_;
	double galutinis_;

public:
	studentas() : zmogus() { 
		pazymiai_ = { 0 }, egzas_ = 0, galutinis_ = 0, sum_ = 0, paz_sk_ = 0;
	} //konstruktorius
	studentas(std::string vardas, std::string pavarde, std::vector<int> pazymiai, int egzas);

	//getteriai
	inline std::vector<int> getPazymiai() { return pazymiai_; }
	inline int getEgzas() { return egzas_; }
	inline int getPaz() { return paz_sk_; }
	inline int getSum() { return sum_; }
	inline double getRezultatas() { return galutinis_; }
	const std::string getVardas() const { return vardas_; }
	const std::string getPavarde() const { return pavarde_; }
	const std::vector<int> getPazymiai() const { return pazymiai_; }
	const int getEgzas() const { return egzas_; }
	const int getPaz() const { return paz_sk_; }
	const int getStum() const { return sum_; }
	const double getRezultatas() const { return galutinis_; }



	//setteriai
	void Vardas(std::string vardas) { vardas_ = vardas; }
	void Pavarde(std::string pavarde) { pavarde_ = pavarde; }

	inline void Pazymiai(std::vector<int>pazymiai) { pazymiai_ = pazymiai; }
	inline void Sum(int sum) { sum_ = sum; }
	inline void Egzas(int egzas) { egzas_ = egzas; }
	inline void Rezultatas(double galutinis) { galutinis_ = galutinis; }

	
	~studentas() { }; //destruktorius
};



class Timer {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	Timer() : start{ std::chrono::high_resolution_clock::now() } {}

	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}

	double elapsed() const {
		return std::chrono::duration<double>
			(std::chrono::high_resolution_clock::now() - start).count();
	}
};
double count_galutinis(std::vector<int> pazymiai, int sum, int egzas);
double count_mediana(std::vector<int>pazymiai, int egzas);
std::string egzo_rezultatas();
std::string pazGeneravimas();
bool palyginimas(const studentas& a, const studentas& b);
std::vector<int> vedimas_ranka(std::vector<int>duom);
std::vector<int> auto_generavimas(std::vector<int>duom);
studentas stud();
unsigned int countWordsInString(std::string const& str);
std::vector<studentas> read_from_file(std::string name, std::vector<studentas>stud, std::string metodas);
void write_to_file(std::vector<studentas>duom);
void stud_gen(int a);
std::vector<studentas> gen_nuskaitymas(std::vector<studentas> duom, int a, std::string metodas);
void gen_irasymas(std::vector<studentas> duom, std::string a);
double list1(int a, std::string metodas);
double list2(int a, std::string metodas);
double vector1(int a, std::string metodas);
double vector2(int a, std::string metodas);
double st_part(int a, std::string metodas);
double partition(int a, std::string metodas);

#endif
