/* This structure tracks player information.
 * File:   Palacios_Gaddis_Ch11_6.h
 * Author: John Palacios
 *
 * Created on September 30, 2013, 5:46 PM
 */

#ifndef PLAYERSCORE_H
#define	PLAYERSCORE_H

#include<string>
using namespace std;

struct PlayerScore{
    string name;
    short num;
    int pointsScored;
};

#endif	/* PLAYERSCORE_H */