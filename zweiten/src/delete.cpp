/*
 * delete.cpp
 *
 * Created: 21/11/2013 4:58:49 PM
 *  Author: Tullo
 */ 

void operator delete(void * p)
{
    // Can we just agree not to use the new and delete operators?
    // Unfortunately, I can't build without this fake implementation.
}

extern "C" void __cxa_pure_virtual() { while (1); }