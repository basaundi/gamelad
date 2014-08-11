// ANDER MARTINEZ 2014

#pragma once

#ifdef DEBUG

#include <iostream>
#include <iomanip>
#define LOG(x) std::clog << std::dec << x << std::endl;
#define LOGw(x) std::clog << std::dec << x;
#define LOGx(x) std::clog << "0x" << std::hex << x;
#define WAITR() std::cin.ignore();
#define LOGp(x) std::clog << std::dec << x << std::endl;

#else

#define LOG(x) ;
#define WAITR() ;
#define LOGw(x) ;
#define LOGx(x) ;
#define LOGp(x) ;

/*
#include <iostream>
#include <iomanip>
#undef LOGp
#define LOGp(x) std::clog << std::dec << x << std::endl;
//*/
#endif
