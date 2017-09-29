//
//  mergesort.c
//  CompArc
//
//  Created by Tushar Sharma and Sam Cutler on 9/28/17.
//  Copyright © 2017 Tushar Sharma and Sam Cutler. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorter.h"

void merge(CSV_row* rows[], int col, int l, int r, int m, int type){
    int sizeL = m-l +1;
    int sizeR = r-m;
    
    CSV_row* tempL[sizeL];
    CSV_row* tempR[sizeR];
    int i;
    for(i = 0; i<sizeL; i++)
        tempL[i] = rows[l+i];
    int j;
    for(j = 0; j<sizeR; j++)
        tempR[j] = rows[m+1+j];
    
    int k=0;
    i=0;
    j=0;
    if(type==0){
        while (i<sizeL && j<sizeR){
            if (tempR[i]->charVals[col]<=tempL[j]->charVals[col]){
                rows[k] = tempR[i];
                i++;
                k++;
            }
            else{
                rows[k] = tempL[j];
                j++;
                k++;
            }
        }
        while(i<sizeL){
            rows[k] = tempR[i];
            i++;
            k++;
        }
        while(j<sizeR){
            rows[k] = tempL[j];
            j++;
            k++;
            
        }
    }
    if(type==1){
        while (i<sizeL && j<sizeR){
            if (tempR[i]->intVals[col]<=tempL[j]->intVals[col]){
                rows[k] = tempR[i];
                i++;
                k++;
            }
            else{
                rows[k] = tempL[j];
                j++;
                k++;
            }
        }
        while(i<sizeL){
            rows[k] = tempR[i];
            i++;
            k++;
        }
        while(j<sizeR){
            rows[k] = tempL[j];
            j++;
            k++;
            
        }
    }
    if(type==2){
        while (i<sizeL && j<sizeR){
            if (tempR[i]->floatVals[col]<=tempL[j]->floatVals[col]){
                rows[k] = tempR[i];
                i++;
                k++;
            }
            else{
                rows[k] = tempL[j];
                j++;
                k++;
            }
        }
        while(i<sizeL){
            rows[k] = tempR[i];
            i++;
            k++;
        }
        
        while(j<sizeR){
            rows[k] = tempL[j];
            j++;
            k++;
        }
    }
}

void mergeSort (CSV_row* rows[], int col, int l, int r, int type){
    int m;
    if (l<r){
        m = l+(r-l)/2;
        mergeSort(rows,col, l, m, type);
        mergeSort(rows, col, m+1, r, type);
        merge(rows, col, l, r, m, type);
    }
}
