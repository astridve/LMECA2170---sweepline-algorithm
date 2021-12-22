#ifndef SWEEPLINE_H_
#define SWEEPLINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "geometry.h"
#include "point_tree.h"
#include "segment_tree.h"
#include "point_list.h"
#include "BOV.h"

typedef struct dataStruct{
    struct ListP *Intersections;
    struct Treenode *Q;
    struct Treeseg *Tau;
    struct Point *p;
    struct Segment *LM;
    struct Segment *RM;
    struct Segment* LN;
    struct Segment* RN;
    struct List* RLN;
} dataStruct;

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Create Data Structure
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
dataStruct* initDataStruct();

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Deletion / Insertion in the different elements
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
void delForC(Treeseg**, Listseg*, Point*);
void insertForC(Treeseg**, Listseg*, Point*);
void insertForU(Treeseg**, Listseg*, Point*);
void createQ(Listseg*, Treenode**);

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Algorithm Main Fonctions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
void findNewEvent(Segment*, Segment*, Point*, Treenode**, dataStruct*);
void HandleEventPoint(dataStruct*);
bool FindIntersections(List*, dataStruct*);
bool FindIntersections2(List*, dataStruct*, Point*);


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%% CONVERTERS Tab - Tree - List
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
List* fromTab2List(GLfloat[][2], GLsizei);
bool fromListP2Tab(ListP*, GLfloat[][2]);
bool fromTreeseg2Tab(Treeseg*, GLfloat[][2]);
bool fromTreenode2Tab(Treenode*, GLfloat[][2]);
bool fromTreeseg2ListP(ListP*, Treeseg*);
bool fromTreenode2ListP(ListP*, Treenode*);
int TreenodeSize(Treenode*);
int TreesegSize(Treeseg*);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%  Free Data Structure
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void freeDatastruct(dataStruct*);
#endif