// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>

#include<image.h>

void medianFilter(const unsigned char input[][HEIGHT], unsigned char output[][HEIGHT], unsigned int width, unsigned int height)
{

    unsigned int x;
    for(x = 1; x < (width - 1); x++)
    {
        unsigned int y;
        for(y = 1; y < (height - 1); y++)
        {
            // Extract Neighbourhood
            unsigned char SORT[9];
            SORT[0] = input[y-1][x-1];
            SORT[1] = input[y-1][x  ];
            SORT[2] = input[y-1][x+1];
            SORT[3] = input[y  ][x-1];
            SORT[4] = input[y  ][x  ];
            SORT[5] = input[y  ][x+1];
            SORT[6] = input[y+1][x-1];
            SORT[7] = input[y+1][x  ];
            SORT[8] = input[y+1][x+1];

            // Sort it
            int min;
            int b;
            int i;
            for ( i = 0; i < 5; i++)
            {
                b = i;
                min = SORT[b];

                int j;
                for (j = i; j < 9; j++)
                {
                    if (SORT[j] < min)
                    {
                        b = j;
                        min = SORT[b];
                    }
                }
                SORT[b] = SORT[i];
                SORT[i] = min;
            }

            // Writeback of the Median:
            output[x][y] =SORT[4];
        }
    }
    return;
}

