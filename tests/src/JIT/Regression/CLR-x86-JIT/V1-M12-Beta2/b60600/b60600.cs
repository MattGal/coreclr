// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

using System;
internal unsafe class bug1
{
    public struct VT1
    {
        public double a;
    }
    public static double f(double* a0)
    {
        return *a0;
    }
    public static int Main()
    {
        VT1 vt = new VT1();
        double* a0 = stackalloc double[1];
        *a0 = 100;
        int[,,] arr3d = new int[5, 20, 4];
        arr3d[4, 6, 3] = 5;
        double val = f(a0);
        return (int)val;
    }
}
