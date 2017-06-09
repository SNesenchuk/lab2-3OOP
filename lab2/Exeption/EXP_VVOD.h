#include "EXP.h"

using namespace std;
class EXP_VVOD : public EXP
{
public: EXP_VVOD(char *s, int kod) : EXP(s, kod){}
};
class EXP_FILE_OPEN : public EXP
{
public: EXP_FILE_OPEN(char *s, int kod) : EXP(s, kod){}
};
class EXP_FILE_EMPTY : public EXP
{
public: EXP_FILE_EMPTY(char *s, int kod) : EXP(s, kod){}
};