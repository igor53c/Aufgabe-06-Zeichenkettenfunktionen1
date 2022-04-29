// Aufgabe 06 Zeichenkettenfunktionen1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
 * 9.   Schreiben sie eine Funktion replaceAll, die alle Vorkommen einer Zeichenfolge in 
 *      einer Zeichenkette durch eine andere Zeichenfolge ersetzt und diese zurückliefert.
 *
 * 		Beispiel: "viel vor und viel dahinter"
 *		"viel" durch "gar nichts" ersetzen	Ergebnis: 
 *      'gar nichts vor und gar nichts dahinter'
 *
 * 10. Schreiben sie eine Funktion subStringCount, welche die Anzahl von Vorkommen einer 
 *      angegebenen Zeichenfolge zurückliefert.    
 *
 *      Beispiel: 
 *      "viel vor viel dahinter, noch viel viel mehr vor, aber viel viel weniger dahinter"
 *      Für die Suche nach der Zeichenkette 'viel' lautet das Ergebnis: 6
 *
 * 11. Schreiben sie eine Funktion string toBinary(char), der sie einen Datentyp 'char' als  
 *     Argument übergeben und die als Rückgabewert den daraus resultierenden Binärwert als 
 *     Zeichenfolge zurückliefert.
 *     Beispiel: '?' (63)	Ergebnis: 00111111
 *     Beispiel: '*' (42)	Ergebnis: 00101010
 */

#include <iostream>
#include <string>

using namespace std;

string replaceAll(string, string, string);
int subStringCount(string, string);
string toBinary(char);
bool istNeuerText();

int main()
{
	locale::global(locale("German_germany"));

	do
	{
		string text, findText, ersatz;

		cout << endl << "Geben Sie den Text ein: ";
		getline(cin, text);

		cout << endl << "Geben Sie den zu suchenden Text ein: ";
		getline(cin, findText);

		cout << endl << "Geben Sie einen Ersatz ein: ";
		getline(cin, ersatz);

		cout << endl << "replaceAll: " << replaceAll(text, findText, ersatz) << endl;
		cout << endl << "subStringCount: " << subStringCount(text, findText) << endl;

		cout << endl << "Geben Sie ein Zeichen ein: ";
		getline(cin, text);

		cout << endl << "toBinary: " << toBinary(text[0]) << endl;

	} while (istNeuerText());

	
	return EXIT_SUCCESS;
}

string replaceAll(string text, string findText, string ersatz)
{
	while (true)
	{
		int position = text.find(findText);

		if(position == string::npos)
			break;

		text.replace(position, findText.length(), ersatz);
	}

	return text;
}

int subStringCount(string text, string findText)
{
	int retValue = 0; 
	int position = -1;

	while (true)
	{
		position = text.find(findText, position + 1);

		if (position == string::npos)
			break;

		retValue++;
	}

	return retValue;
}

string toBinary(char letter)
{
	string retValue;

	for (int i = 7; i >= 0; --i) 
		retValue += letter & (1 << i) ? '1' : '0';
	
	return retValue;
}

bool istNeuerText()
{
	string weiter;

	cout << endl << "Neuer Text? (J | N) : ";

	cin >> weiter;

	if (weiter.length() != 1 || (weiter[0] != 'J' && weiter[0] != 'j'))
		return false;

	cin.ignore();

	system("cls");

	return true;
}
