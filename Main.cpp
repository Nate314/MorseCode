#include "MorseCode.h"
#include<iostream>
using namespace std;

/*
+----------------------------------------------------------------------------+
|                    Name: Nathan Gawith                                     |
|                   Class: COMPSCI101 Problem Solving & Programing I FS2017  |
|              Assignment: UMKC Directory (Assignment #5)                    |
|           Creation Date: November 27th, 2017                               |
|                Due Date: December 8th, 2017                                |
+-----------------------------------+----------------------------------------+
|  __    __   __      __   ______   |        ____  __           __           |
| |NN\  |NN| |MM\    /MM| /GGGGGG|  |       /     /  \      |  |  |  |       |
| |NN|\ |NN| |MM|\  /|MM| |G| ____  |      |      \__       |  |  |  |       |
| |NN| \|NN| |MM| \/ |MM| |G|  |GG| |      |         \      |  |  |  |       |
| |NN|  \NN| |MM|    |MM| \GGGGGGG| |       \____ \__/      |  |__|  |       |
+-----------------------------------+----------------------------------------+
*/

int main() {
	//._._._._._._._._._._._._._._
	cout << "Hello World!" << endl;
	MorseCode mcode;
	string encoded = mcode.encode("Nathan");
	string decoded = mcode.decode(encoded);
	cout << encoded << endl;
	cout << decoded << endl;
	system("pause");
	return 0;
}
