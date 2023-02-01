#include "mnistReader.h"
#include "Network.h"

mnistReader::mnistReader(const char* filename)
{
    std::ifstream datafile(filename, std::ifstream::binary);

    // read magic number
    char magicNumber[4];
    datafile.read(magicNumber, 4*sizeof(char));
    int ndim = ParseMagicNumber(magicNumber);

    // parse image resolution
    char* dims_char = new char[ndim*sizeof(int)];
    datafile.read(dims_char, ndim*sizeof(int));
    ParseResolution(dims_char, ndim);
    delete[] dims_char;

    //Read bulk data
    int datasize = nrImages * imageRes * imageRes;
    char* chardata = new char[datasize];
    datafile.read(chardata, datasize * sizeof(char));
    data = (uint8_t*)chardata; // map char to unsigned char

    if (datafile)
      std::cout << "all characters read successfully." << std::endl;
    else
      std::cout << "error: only " << datafile.gcount() << " could be read" << std::endl;
    
    datafile.close();
}

mnistReader::~mnistReader()
{
    delete[] data;
}

int mnistReader::ParseMagicNumber(char* magicNumber){
    assert(magicNumber[0] == 0); // first 2 bytes of magic number must be 0
    assert(magicNumber[1] == 0);

    //Check datatype
    //0x08: unsigned byte
    //0x09: signed byte
    //0x0B: short (2 bytes)
    //0x0C: int (4 bytes)
    //0x0D: float (4 bytes)
    //0x0E: double (8 bytes)
    assert(magicNumber[2] == 8); // must be of type unsigned byte

    // Return the number of dimensions
    return static_cast<int>(magicNumber[3]);
}

void mnistReader::ParseResolution(char* data, int ndim){
    int* dims = char2int(data, ndim);
    
    nrImages = dims[0];
    imageRes = (ndim==1) ? 1 : dims[1];
    delete[] dims;
}

int* mnistReader::char2int(char* charr, const int nrints)
{
    int* output = new int(nrints);
    for (int i = 0; i < nrints; i++)
    {
        output[i] = char2int(charr + i*sizeof(int));
    }
    return output;
}

int mnistReader::char2int(char* charr)
{
    // swap little endian to big endian
    char charbuff[4];
    charbuff[3] = charr[0];
    charbuff[2] = charr[1];
    charbuff[1] = charr[2];
    charbuff[0] = charr[3];
    
    // Trick compiler to think charbuff is int
    int output = *(int*)charbuff;
    return output;

}

uint8_t mnistReader::operator()(int x, int y, int img)
{
    // Get row-wise stored pixels
    return data[y + (imageRes * x) + (imageRes * imageRes * img)];
}

uint8_t mnistReader::operator()(int idx)
{
    // Get row-wise stored pixels
    return data[idx];
}