//
// Fonctions utilitaires
//

#include <stdlib.h>
#include "util.h"

int alea(int min,int max)
{
//	return (new Random()).Next(min,max);
	return min+rand()%(max - min +1);
}

