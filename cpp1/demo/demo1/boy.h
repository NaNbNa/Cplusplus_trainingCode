//#pragma once

#ifndef __BOY__
#define __BOY__
#include <iostream>
using namespace std;

#include "girl.h"

class cgirl;

class cboy
{
public:
    string m_name;
    cgirl* m_girl;
};

#endif