/*
+-----------------------------------------------------------------------+
| Name:          Nathan Gawith                                          |
| Class:         COMPSCI303 Data Structures FS2018                      |
| Assignment:    Morse Code (Project #2)                                |
| Creation Date: November 6th, 2018                                     |
| Due Date:      December 26th, 2018         http://nate314.github.io/  |
+-----------------------------------+-----------------------------------+
|  __    __   __      __   ______   |     ____  __     ___   __   ___   |
| |NN\  |NN| |MM\    /MM| /GGGGGG|  |    /     /  \      |  |  |    |   |
| |NN|\ |NN| |MM|\  /|MM| |G| ____  |   |      \__      _|  |  |   _|   |
| |NN| \|NN| |MM| \/ |MM| |G|  |GG| |   |         \      |  |  |    |   |
| |NN|  \NN| |MM|    |MM| \GGGGGGG| |    \____ \__/    __|  |__|  __|   |
+-----------------------------------+-----------------------------------+
*/

#include "MorseCode.h"
#include<iostream>
using namespace std;

int main() {
	MorseCode mcode;
	string message = "Nathan";
	string encoded = mcode.encode(message);
	string decoded = mcode.decode(encoded);
	cout << "Message String: " << message << endl;
	cout << "Encoded String: " << encoded << endl;
	cout << "Decoded String: " << decoded << endl;
	system("pause");
	return 0;
}
