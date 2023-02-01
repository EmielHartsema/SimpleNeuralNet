#pragma once
#include <iostream>
#include <fstream>
#include <bitset>
#include <cassert>

class mnistReader
{
private:
    /* data */
    int ParseMagicNumber(char* magicNumber);
    void ParseResolution(char* data, int ndim);
    int* char2int(char* charr, const int nrints);
    int char2int(char* charr);
public:
    int nrImages;
    int imageRes;
    uint8_t* data;
    mnistReader(const char* filename);
    ~mnistReader();
    uint8_t operator()(int x, int y, int img);
    uint8_t operator()(int idx);
};