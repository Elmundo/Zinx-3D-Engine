#pragma once

#ifndef SYSTEMTIME_H
#define SYSTEMTIME_H
/*Bu class yaratýlmýyo
Sadece içerisindeki deltaTime sistem içerisinde kullanýlýyo

DAHA DA GELÝÞTÝRÝLMESÝ GEREKÝYO
SINGLATION YAPISINA BAK
*/

class __declspec(dllexport) SystemTime{
public:
	static float deltaTime;
};

#endif