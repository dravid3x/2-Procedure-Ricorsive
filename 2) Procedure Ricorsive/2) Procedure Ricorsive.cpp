﻿using namespace std;

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <sdkddkver.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <windows.h>
#pragma execution_character_set( "utf-8" )

void ricerca_in_array(), cambiaDim(), scelta_riempimento(), riempimento_manuale(), riempimento_casuale(), scelta_min_max(), conta_elementi_positivi();
bool cerca_in_array(int arrNumeri[], int nRicercato, int pos, int dimLogica);
int conta_positivi(int* arrNumeri, int pos, int dimLogica, int nPositivi);

const int dim = 1000000;
int logic_dim = dim, minVal = 0, maxVal = 500;
int numeri[dim];

int main()
{
	SetConsoleOutputCP(65001);	//Imposto il char_set per mostrare i caratteri UTF-8
	srand(time(NULL));
	bool finito = false;
	while (!finito) {
		cout << "Procedure ricorsive\n";
		cout << "1) Ricerca intero\n";
		cout << "2) Conta elementi positivi\n";
		cout << "3) Riempi array di numeri\n";
		cout << "-1) Exit\n\n";
		cout << ">> ";
		int scelta;
		cin >> scelta;
		system("CLS");
		switch (scelta)
		{
		case 1:
			ricerca_in_array();
			system("PAUSE");
			break;
		case 2:
			conta_elementi_positivi();
			system("PAUSE");
			break;
		case 3:
			scelta_riempimento();
			break;
		case -1:
			finito = true;
		default:
			break;
		}
		system("CLS");
	}
	exit(0);
	return 0;
}

void conta_elementi_positivi() {
	cout << "Il numero di elementi positivi presenti nell'array è: " << conta_positivi(numeri, 0, logic_dim, 0) << " su " << logic_dim << " elementi\n";
}

int conta_positivi(int* arrNumeri, int pos, int dimLogica, int nPositivi) {
	//Funzione ricorsiva che controlla se il numero attuale è positivo o meno, incrementa la posizione e richiama se stessa
	if (pos >= dimLogica) return nPositivi;
	else {
		if (arrNumeri[pos] > 0) nPositivi++;
		pos++;
		conta_positivi(arrNumeri, pos, dimLogica, nPositivi);
	}
}

void ricerca_in_array() {
	cout << "Inserire il numero da ricercare\n\n>> ";
	int ricercato;
	cin >> ricercato;
	int pos = 0;
	cout << ((cerca_in_array(numeri, ricercato, 0, logic_dim)) ? "Il numero inserito è presente nell'array di numeri" : "Il numero inserito non è presente nell'array di numeri") << "\n";
}

bool cerca_in_array(int* arrNumeri, int nRicercato, int pos, int dimLogica) {
	//Funzione ricorsiva che controlla se il numero attuale corrisponde al numero ricercato, se si interrompe altrimenti richiama se stessa
	if (pos >= dimLogica) return false;
	else {
		if (nRicercato == arrNumeri[pos]) return true;
		else cerca_in_array(arrNumeri, nRicercato, ++pos, dimLogica);
	}
}

void cambiaDim() {
	//Funzione per il cambio di dimensione logica dell'array numeri
	cout << "Inserire la dimensione dell'array desiderata\n";
	cout << ">> ";
	int nuovaDim;
	cin >> nuovaDim;
	if (nuovaDim > 0 && nuovaDim <= dim) {
		logic_dim = nuovaDim;
		return;
	}
	else {
		system("CLS");
		cambiaDim();
	}
	return;
}

void scelta_riempimento() {
	cout << "Desidera riempire l'array\n1) Manualmente\n2) Casualmente\n";
	cout << ">> \n";
	int scelta;
	cin >> scelta;
	system("CLS");
	if (scelta == 1) riempimento_manuale();
	else if (scelta == 2) riempimento_casuale();
}

void riempimento_manuale() {
	//Funzione di riempimento del vettore numeri manualmente
	cout << "Inserire -- per terminare l'inserimento\n";
	int i = 0;
	bool finito = false;
	while (i < dim && !finito) {
		cout << "N." << i << " >> ";
		string numero;
		cin >> numero;
		try
		{
			int numeroInt = stoi(numero);
			numeri[i] = numeroInt;
			i++;
		}
		catch (const std::exception& exc)
		{
			if (numero == "--") finito = true;
		}
	}
	logic_dim = i;
}

void riempimento_casuale() {
	//Funzione di riempimento del vettore numeri con valori casuali
	cambiaDim();
	scelta_min_max();
	for (int i = 0; i < logic_dim; i++) numeri[i] = (rand() % (maxVal - minVal)) + minVal;
}

void scelta_min_max() {
	bool valido = false;
	while (!valido) {
		cout << "Inserire il valore minimo generabile >> ";
		string min;
		cin >> min;
		try
		{
			int minimo = stoi(min);
			minVal = minimo;
			valido = true;
		}
		catch (const std::exception& exc)
		{
			system("CLS");
		}
	}
	valido = false;
	while (!valido) {
		cout << "Inserire il valore massimo generabile >> ";
		string max;
		cin >> max;
		try
		{
			int massimo = stoi(max);
			maxVal = massimo;
			valido = true;
		}
		catch (const std::exception& exc)
		{
			system("CLS");
		}
	}
}
