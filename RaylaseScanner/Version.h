#pragma once

#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

#define VERSION_MAJOR	1
#define VERSION_MINOR	35
#define VERSION_BUILD	2
#define VERSION_REVISION	1329

#define VER_FILE_VERSION            VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD, VERSION_REVISION
#define VER_FILE_VERSION_STR        STRINGIZE(VERSION_MAJOR)        \
                                    "." STRINGIZE(VERSION_MINOR)    \
                                    "." STRINGIZE(VERSION_BUILD)    \
                                    "." STRINGIZE(VERSION_REVISION) \

#define VER_PRODUCT_VERSION         VER_FILE_VERSION
#define VER_PRODUCT_VERSION_STR	"1.35.2"

#define VER_PRODUCTNAME_STR         "RAYLASE.SPICE3.Native.ClientLib"
#define VER_ORIGINAL_FILENAME_STR   VER_PRODUCTNAME_STR ".dll"
#define VER_INTERNAL_NAME_STR       VER_ORIGINAL_FILENAME_STR
#define VER_COPYRIGHT_STR           "Copyright (C) 2015"
#define VER_FILE_DESCRIPTION_STR	"Native RAYLASE SPICE3 Client library"
#define VER_COMPANY_NAME_STR		"RAYLASE GmbH"
