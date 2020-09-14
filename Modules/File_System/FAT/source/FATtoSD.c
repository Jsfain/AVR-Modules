#include <avr/io.h>
#include "../includes/sd_spi.h"
#include "../includes/sd_misc.h"
#include "../includes/fattosd.h"


void fat_ReadSingleSector( uint32_t address, uint8_t *sectorByteArray)
{
    DataBlock db;
    db = sd_ReadSingleDataBlock(address);
    for(int k = 0; k < 512; k++) { sectorByteArray[k] = db.data[k]; }
};


void fat_PrintSingleSector( uint8_t *sectorByteArray )
{
    sd_PrintDataBlock(sectorByteArray);
};