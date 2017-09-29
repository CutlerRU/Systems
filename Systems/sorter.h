//
//  Header.h
//  CompArc
//
//  Created by Tushar Sharma and Sam Cutler on 9/28/17.
//  Copyright © 2017 Tushar Sharma and Sam Cutler. All rights reserved.
//


// a struct with 3 arrays each holding the respected columns for each of the three data types char, int, float
struct CSV_row_{
    char** charVals;
    int** intVals;
    float** floatVals;
    };


typedef struct CSV_row_ CSV_row;

 /* Header_h */
