#ifndef SSZipCommon
#define SSZipCommon

/* tm_unz contain date/time info */
typedef struct tm_unz_s
{
    unsigned int tm_sec;            /* seconds after the minute - [0,59] */
    unsigned int tm_min;            /* minutes after the hour - [0,59] */
    unsigned int tm_hour;           /* hours since midnight - [0,23] */
    unsigned int tm_mday;           /* day of the month - [1,31] */
    unsigned int tm_mon;            /* months since January - [0,11] */
    unsigned int tm_year;           /* years - [1980..2044] */
} tm_unz;

/* unz_global_info structure contain global data about the ZIPfile
 These data comes from the end of central dir */
typedef struct unz_global_info64_s
{
    uint64_t number_entry;          /* total number of entries in the central dir on this disk */
    uint32_t number_disk_with_CD;   /* number the the disk with central dir, used for spanning ZIP*/
    uint16_t size_comment;          /* size of the global comment of the zipfile */
} unz_global_info64;

typedef struct unz_global_info_s
{
    uint32_t number_entry;          /* total number of entries in the central dir on this disk */
    uint32_t number_disk_with_CD;   /* number the the disk with central dir, used for spanning ZIP*/
    uint16_t size_comment;          /* size of the global comment of the zipfile */
} unz_global_info;

/* unz_file_info contain information about a file in the zipfile */
/* https://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT */
typedef struct unz_file_info64_s
{
    uint16_t version;               /* version made by                 2 bytes */
    uint16_t version_needed;        /* version needed to extract       2 bytes */
    uint16_t flag;                  /* general purpose bit flag        2 bytes */
    uint16_t compression_method;    /* compression method              2 bytes */
    uint32_t dos_date;              /* last mod file date in Dos fmt   4 bytes */
    uint32_t crc;                   /* crc-32                          4 bytes */
    uint64_t compressed_size;       /* compressed size                 8 bytes */
    uint64_t uncompressed_size;     /* uncompressed size               8 bytes */
    uint16_t size_filename;         /* filename length                 2 bytes */
    uint16_t size_file_extra;       /* extra field length              2 bytes */
    uint16_t size_file_comment;     /* file comment length             2 bytes */
    
    uint32_t disk_num_start;        /* disk number start               4 bytes */
    uint16_t internal_fa;           /* internal file attributes        2 bytes */
    uint32_t external_fa;           /* external file attributes        4 bytes */
    
    uint64_t disk_offset;
    
    uint16_t size_file_extra_internal;
} unz_file_info64;

typedef struct unz_file_info_s
{
    uint16_t version;               /* version made by                 2 bytes */
    uint16_t version_needed;        /* version needed to extract       2 bytes */
    uint16_t flag;                  /* general purpose bit flag        2 bytes */
    uint16_t compression_method;    /* compression method              2 bytes */
    uint32_t dos_date;              /* last mod file date in Dos fmt   4 bytes */
    uint32_t crc;                   /* crc-32                          4 bytes */
    uint32_t compressed_size;       /* compressed size                 4 bytes */
    uint32_t uncompressed_size;     /* uncompressed size               4 bytes */
    uint16_t size_filename;         /* filename length                 2 bytes */
    uint16_t size_file_extra;       /* extra field length              2 bytes */
    uint16_t size_file_comment;     /* file comment length             2 bytes */
    
    uint16_t disk_num_start;        /* disk number start               2 bytes */
    uint16_t internal_fa;           /* internal file attributes        2 bytes */
    uint32_t external_fa;           /* external file attributes        4 bytes */
    
    uint64_t disk_offset;
} unz_file_info;

#endif
