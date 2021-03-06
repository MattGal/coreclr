//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information. 
//

/*=====================================================================
**
** Source:  exceptionsxs.c (exception_handling\pal_sxs\test1)
**
** Purpose: Test to make sure the PAL_EXCEPT block is executed
**          after an exception occurs in the PAL_TRY block with
**          multiple PALs in the process.
**
**
**===================================================================*/

extern "C" int InitializeDllTest1();
extern "C" int InitializeDllTest2();
extern "C" int DllTest1();
extern "C" int DllTest2();

int __cdecl main(int argc, char *argv[])
{
#ifndef __FreeBSD__
    if (0 != InitializeDllTest1())
    {
        return 1;
    }

    if (0 != InitializeDllTest2())
    {
        return 1;
    }

    DllTest2();
    DllTest1();
    DllTest2();
#endif
    return 0;
}
