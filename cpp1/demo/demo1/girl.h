//#pragma once

#ifndef __GIRL__
#define __GIRL__
#include <iostream>
using namespace std;

#include "boy.h"

class cboy;

class cgirl
{
public:
    string m_name;
    cboy* m_boy;
};

#endif