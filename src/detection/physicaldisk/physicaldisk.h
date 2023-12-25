#include "fastfetch.h"

typedef enum FFPhysicalDiskType
{
    FF_PHYSICALDISK_TYPE_NONE = 0,

    // If neither is set, it's unknown
    FF_PHYSICALDISK_TYPE_HDD = 1 << 0,
    FF_PHYSICALDISK_TYPE_SSD = 1 << 1,

    FF_PHYSICALDISK_TYPE_FIXED = 1 << 2,
    FF_PHYSICALDISK_TYPE_REMOVABLE = 1 << 3,

    FF_PHYSICALDISK_TYPE_READWRITE = 1 << 4,
    FF_PHYSICALDISK_TYPE_READONLY = 1 << 5,
} FFPhysicalDiskType;

typedef struct FFPhysicalDiskResult
{
    FFstrbuf name;
    FFstrbuf interconnect;
    FFstrbuf serial;
    FFstrbuf devPath;
    FFstrbuf firmwareRev;
    FFPhysicalDiskType type;
    uint64_t size;
} FFPhysicalDiskResult;

const char* ffDetectPhysicalDisk(FFlist* result, FFPhysicalDiskOptions* options);
